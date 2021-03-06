/* Script2 (TM) @version 0.x
@link    https://github.com/KabukiStarship/Script2.git
@file    /BIn.inl
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2015-20 Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain
one at <https://mozilla.org/MPL/2.0/>. */

#include <_Config.h>

#if SEAM >= SCRIPT2_CRABS

#include "BIn.hpp"
//
//#include "Binary.hpp"
#include "BSeq.h"
#include "Hash.hpp"
#include "Op.h"
//#include "TypeValue.h"

#if SEAM == SCRIPT2_CRABS
#include "_Debug.inl"
#define CLEAR(origin, stop) \
  while (origin <= stop) *origin++ = ' ';
#else
#include "_Release.inl"
#define CLEAR(origin, stop)
#endif

namespace _ {

inline CHA* BInBegin(BIn* bin) { return TPtr<CHA>(bin) + sizeof(BIn); }

CHA* BInEnd(BIn* bin) { return TPtr<CHA>(bin) + bin->size; }

ISW SlotLength(CHA* origin, CHA* stop, IUW size) {
  return stop - origin;
}

ISW SlotSpace(CHA* origin, CHA* stop, IUW size) {
  return size - (stop - origin);
}

ISC BInSpace(BIn* bin) {
  CHA* txb_ptr = TPtr<CHA>(bin);
  return (ISC)SlotSpace(txb_ptr + bin->origin, txb_ptr + bin->stop, bin->size);
}

ISC BinBufferLength(BIn* bin) {
  CHA* origin = BInBegin(bin);
  return (ISC)SlotLength(origin + bin->origin, origin + bin->stop, bin->size);
}

#if USING_SCRIPT2_TEXT == YES_0
const CHA** STRBInStates() {
  static const CHA* kStateStrings[] = {
      "Address",       //< 0
      "Args",          //< 1
      "UTF-8",         //< 2
      "UTF-16",        //< 3
      "UTF-32",        //< 4
      "Varint",        //< 5
      "CObj",          //< 6
      "Hash",          //< 7
      "Error",         //< 8
      "Disconnected",  //< 9
      "ACK",           //< 10
      "Locked",        //< 11
      "POD"            //< 12
  };
  return kStateStrings;
}
#endif

/* Used to return an erroneous result from a B-Output.
@param error The error type.
@return Returns a Static Error Op Result. */
inline const Op* BInError(BIn* bin, Error error) {
  D_COUT("\nBIn " << STRError(error) << " error!");
  return reinterpret_cast<const Op*>(error);
}

/* Used to return an erroneous result from a B-Output.
@param bin    The source BIn.
@param error   The error type.
@param header  The B-Sequence Header.
@param offset  The offset to the type in error in the B-Sequence.
@param address The address of the IUA in error.
@return         Returns a Static Error Op Result. */
inline const Op* BInError(BIn* bin, Error error, const ISC* header) {
  D_COUT("\nBIn %s error!", STRError(error));
  return reinterpret_cast<const Op*>(error);
}

/* Used to return an erroneous result from a B-Output.
@param bin    The source BIn.
@param error   The error type.
@param header  The B-Sequence Header.
@param offset  The offset to the type in error in the B-Sequence.
@param address The address of the IUA in error.
@return         Returns a Static Error Op Result. */
inline const Op* BInError(BIn* bin, Error error, const ISC* header,
                          ISC offset) {
  D_COUT("\nBIn " << STRError(error) << " error!");
  return reinterpret_cast<const Op*>(error);
}

/* Used to return an erroneous result from a B-Output.
@param bin    The source BIn.
@param error   The error type.
@param header  The B-Sequence Header.
@param offset  The offset to the type in error in the B-Sequence.
@param address The address of the IUA in error.
@return         Returns a Static Error Op Result. */
inline const Op* BInError(BIn* bin, Error error, const ISC* header, ISC offset,
                          CHA* address) {
  D_COUT("\nBIn " << STRError(error) << " error!");
  return reinterpret_cast<const Op*>(error);
}

BIn* BInInit(IUW* socket, ISC size) {
  D_ASSERT(size >= cSlotSizeMin);

  BIn* bin = reinterpret_cast<BIn*>(socket);
  bin->size = size - sizeof(BIn);
  bin->origin = 0;
  bin->stop = 0;
  bin->read = 0;

#if D_THIS == 1
  MemoryClear(BInBegin(bin), size);
#endif
  return bin;
}

ISC BInStreamByte(BIn* bin) {
  CHA *origin = BInBegin(bin), *stop = origin + bin->size - 1;
  CHA *open = (CHA*)origin + bin->read, *origin = origin + bin->origin,
      *origin = origin;

  ISC length = (ISC)((origin < open) ? open - origin + 1
                                     : (stop - origin) + (open - origin) + 2);

  if (length < 1) {
    BInError(bin, cErrorBufferOverflow, TParams<1, cSTR>(), 2, origin);
    return -1;
  }
  // IUA b = *cursor;
  bin->stop = (++origin >= stop) ? TDelta<ISC>(origin, stop)
                                 : TDelta<ISC>(origin, origin);
  return 0;
}

BOL BInIsReadable(BIn* bin) { return BinBufferLength(bin) > 0; }

const Op* BInRead(BIn* bin, const ISC* params, void** args) {
  D_COUT_BSQ("\nReading ", params);
  D_COUT_BIN(" from B-Input:", bin);

  if (!bin) {
    return BInError(bin, cErrorImplementation);
  }
  if (!params) {
    return BInError(bin, cErrorImplementation);
  }
  if (!args) {
    return BInError(bin, cErrorImplementation);
  }
  IUA  iua;                   //< Temp variable.
  IUB  iub;                   //< Temp variable.
  IUC  iuc;                   //< Temp variable.
  IUD  iud;                   //< Temp variable.
  CHA* iua_ptr;               //< Pointer to a cIUA.
  // IUB* iub_ptr;            //< Pointer to a cIUB.
  IUC* iuc_ptr;               //< Pointer to a cIUC.
  IUD* iud_ptr;               //< Pointer to a cIUA.
  ISC  type,                  //< The current type being read.
       size,                  //< Size of the ring socket.
       length,                //< Length of the data in the socket.
       count,                 //< Argument length.
       index,                 //< Index in the params.
       arg_index = 0,         //< Index in the args.
       value,                 //< Temp variable.
       num_params = *params;  //< Number of params.
  IUB  hash;                  //< Hash of the incoming data.

  if (num_params == 0) return 0;  //< Nothing to do.

  hash = PRIME_LARGEST_IUB;
  size = bin->size;

  CHA *origin = BInBegin(bin),             //< The beginning of the socket.
      *stop = origin + size - 1,           //< The stop of the socket.
          *origin = origin + bin->origin,  //< The origin of the data.
              *stop = origin + bin->stop;  //< The stop of the data.
                                           // const ISC* param = params + 1;
                                           // //< The current param.

  length = (ISC)SlotLength(origin, stop, size);

  // When we scan, we are reading from the beginning of the Slot socket.

  for (index = 1; index <= num_params; ++index) {
    type = params[index];
    D_COUT("\nparam:" << arg_index + 1 << " type:" << STRType(type)
                      << " start:" << TDelta<>(origin, start) << " stop:"
                      << TDelta<>(origin, stop) << " length:" << length);
    switch (type) {
      case cNIL:
        return BInError(bin, cErrorInvalidType, params, index, origin);
      case cISA:  //< _R_e_a_d__1__B_y_t_e__T_y_p_e_s________________
      case cIUA:
      case cBOL:
#if USING_SCRIPT2_1_BYTE_TYPES
        if (length-- == 0)
          return BInError(bin, cErrorBufferUnderflow, params, index, origin);

        // Load next pointer and increment args.
        iua_ptr = reinterpret_cast<CHA*>(args[arg_index]);
        if (!iua_ptr) break;

        // Read type;

        // Byte 1
        iua = *origin;  //< Read
        D_COUT(" '" << iua << "', ");
        hash = HashIUB(iua, hash);             //< Hash
        if (++origin >= stop) origin -= size;  //< Increment
        *iua_ptr = iua;                        //< Write
        break;
#else
        return BInError(bin, cErrorInvalidType, params, index, origin);
#endif
      case cISB:  //< _R_e_a_d__1_6_-_b_i_t__T_y_p_e_s_______________
      case cIUB:
      case cFPB:
#if USING_SCRIPT2_2_BYTE_TYPES
        if (length < 2)
          return BInError(bin, cErrorBufferUnderflow, params, index, origin);
        length -= 2;

        // Load next pointer and increment args.
        iua_ptr = reinterpret_cast<CHA*>(args[arg_index]);
        if (!iua_ptr) break;

        // Read type

        // Byte 1
        iua = *origin;                         //< Read
        hash = HashIUB(iua, hash);             //< Hash
        if (++origin >= stop) origin -= size;  //< Increment
        *iua_ptr = iua;                        //< Write

        // Byte 2
        iua = *origin;                         //< Read
        hash = HashIUB(iua, hash);             //< Hash
        if (++origin >= stop) origin -= size;  //< Increment
        *(iua_ptr + 1) = iua;                  //< Write
        break;
#else
        return BInError(bin, cErrorInvalidType, params, index, origin);
#endif
      case cISC:  //< _R_e_a_d__3_2_-_b_i_t__T_y_p_e_s_______________
      case cIUC:
      case cFPC:
#if USING_SCRIPT2_4_BYTE_TYPES
        if (length < 4)
          return BInError(bin, cErrorBufferUnderflow, params, index, origin);
        length -= 4;

        // Load next pointer and increment args.
        iua_ptr = reinterpret_cast<CHA*>(args[arg_index]);
        if (!iua_ptr) break;

        // Read type

        for (value = sizeof(IUC); value > 0; --value) {
          // Byte 1
          iua = *origin;                         //< Read
          hash = HashIUB(iua, hash);             //< Hash
          if (++origin >= stop) origin -= size;  //< Increment
          *iua_ptr++ = iua;                      //< Write
        }
#else
        return BInError(bin, cErrorInvalidType, params, index, origin);
#endif
      case cISD:  //< _R_e_a_d__6_4_-_b_i_t__T_y_p_e_s_______________
      case cIUD:
      case cFPD:
#if USING_SCRIPT2_8_BYTE_TYPES
        if (length < 8)
          return BInError(bin, cErrorBufferUnderflow, params, index, origin);
        length -= 8;

        // Load next pointer and increment args.
        iua_ptr = reinterpret_cast<CHA*>(args[arg_index]);
        if (!iua_ptr) break;

        // Read type
        for (value = sizeof(IUD); value > 0; --value) {
          // Byte 1
          iua = *origin;                         //< Read
          hash = HashIUB(iua, hash);             //< Hash
          if (++origin >= stop) origin -= size;  //< Increment
          *iua_ptr++ = iua;                      //< Write
        }
        break;
#else
        return BInError(bin, cErrorInvalidType, params, index, origin);
#endif
      case cSTR:  //< _R_e_a_d__S_t_r_i_n_g_-_8____________________
        // Load buffered-type argument length and increment the index.
        ++num_params;
        count = params[++index];
        //< @todo Replace with pointer arithmetic.
        // Load next pointer and increment args.
        iua_ptr = reinterpret_cast<CHA*>(args[arg_index]);
        if (iua_ptr == nullptr)
          return BInError(bin, cErrorImplementation, params, index, origin);
        D_COUT("\nReading cSTR:0x" << Hexf(iua_ptr) << " with length:" << 
               count);
        // Read CHA.
        iua = *origin;
        hash = HashIUB(iua, hash);
        if (++origin >= stop) origin -= size;
        *iua_ptr = iua;
        ++iua_ptr;
        D_COUT(iua);
        while ((iua != 0) && (count != 0)) {
          --count;
          if (count == 0)  //< Reached count:0 before nil-term CHA.
            return BInError(bin, cErrorBufferUnderflow, params, index, origin);
          iua = *origin;  // Read IUA from ring-socket.
          hash = HashIUB(iua, hash);
          if (++origin >= stop) origin -= size;
          *iua_ptr++ = iua;  // Write IUA to destination.
          D_COUT(iua);
        }
        D_COUT("\" success!\n");
        if (type != cADR) {
          *iua_ptr = 0;
          // No need to hash 0.
        }
        break;
      case cSVI:  //< _R_e_a_d__S_i_g_n_e_d__V_a_r_i_n_t______________
      case cUVI:  //< _R_e_a_d__U_n_s_i_g_n_e_d__V_a_r_i_n_t___________
#if ALU_SIZE <= 16
                 // Load next pointer and increment args.
        iub_ptr = reinterpret_cast<IUB*>(args[arg_index]);
        if (iub_ptr == nullptr)
          return BInError(bin, cErrorImplementation, params, index, origin);
        // SScan IUA 1.
        iua = *origin;
        if (++origin >= stop) origin -= size;
        hash = HashIUB(iua, hash);
        iub = iua;
        temp = 7;   //< Number of bits to shift iua to the left.
        count = 5;  //< The max number_ of Varint4 bytes.
        while (iua >> 7 == 0) {
          if (length-- == 0)
            return BInError(bin, cErrorBufferUnderflow, params, index, origin);
          iua = *origin;
          if (++origin >= stop) origin -= size;
          hash = HashIUB(iua, hash);
          iuc |= ((IUC)(iua & 0x7F)) << temp;
          //< @todo I'm starting to second guess if we need to mask iua
          //< because we're packing them up and will overwrite.
          temp += 7;
          if (--count == 0)
            return BInError(bin, cErrorVarintOverflow, params, index, origin);
        }
        if (count == 5)  //< If there is only one IUA we need to
          iuc &= 0x7F;   //< mask off the terminating varint bit.
        if (type == SVI) iuc = TypeUnpackVarint<IUC>(iuc);
        *iuc_ptr = iuc;
        break;
#else
                 // Load next pointer and increment args.
        iuc_ptr = reinterpret_cast<IUC*>(args[arg_index]);
        if (iuc_ptr == nullptr)
          return BInError(bin, cErrorImplementation, params, index, origin);

        // SScan IUA 1.
        iua = *origin;
        if (++origin >= stop) origin -= size;
        hash = HashIUB(iua, hash);
        iuc = iua;
        iub = 7;    //< Number of bits to shift iua to the left.
        count = 5;  //< The max number_ of Varint4 bytes.
        while (iua >> 7 == 0) {
          if (length-- == 0)
            return BInError(bin, cErrorBufferUnderflow, params, index, origin);
          iua = *origin;
          if (++origin >= stop) origin -= size;
          hash = HashIUB(iua, hash);
          iuc |= ((IUC)(iua & 0x7F)) << iub;
          //< @todo I'm starting to second guess if we need to mask iua
          //< because we're packing them up and will overwrite.
          iub += 7;
          if (--count == 0)
            return BInError(bin, cErrorVarintOverflow, params, index, origin);
        }
        if (count == 5)  //< If there is only one IUA we need to
          iuc &= 0x7F;   //< mask off the terminating varint bit.
        if (type == SVI) iuc = TypeUnpackVarint<IUC>(iuc);
        *iuc_ptr = iuc;
        break;
#endif
      case SV8:  //< _R_e_a_d__V_a_r_i_n_t__8____________________
      case UV8:
        // Load next pointer and increment args.
        iud_ptr = reinterpret_cast<IUD*>(args[arg_index]);
        if (!iud_ptr) {
          return BInError(bin, cErrorImplementation, params, index, origin);
        }
        // SScan IUA 1.
        iua = *origin;
        if (++origin >= stop) origin -= size;
        hash = HashIUB(iua, hash);
        iud = iua;
        iub = 7;    //< Number of bits to shift iua to the left.
        count = 9;  //< The max number_ of Varint8 bytes.
        while (iua >> 7 == 0) {
          if (length-- == 0)
            return BInError(bin, cErrorBufferUnderflow, params, index, origin);
          iua = *origin;
          if (++origin >= stop) origin -= size;
          hash = HashIUB(iua, hash);
          if (count == 1) {
            // Varint 8 differs from Varint 2 and 4 in that on the
            // last IUA, IUA 9 of 9, there is no terminating
            // varint bit.
            iud |= ((IUD)(iua)) << iub;
            break;
          }
          iud |= ((IUD)(iua & 0x7F)) << iub;
          //< @todo I'm starting to second guess if we need to mask
          //< iua because we're packing them up and will overwrite.
          iub += 7;
          if (--count == 0)
            return BInError(bin, cErrorVarintOverflow, params, index, origin);
        }
        if (count == 9)  //< If there is only one IUA we need to
          iud &= 0x7F;   //< mask off the terminating varint bit.
        if (type == SV8) iud = TypeUnpackVarint<IUD>(iud);
        *iud_ptr = iud;
        break;
      case cBSQ:  //< _B_-_S_e_q_u_e_n_c_e__S_t_r_i_n_g______________
#if USING_BSQ
        iua_ptr = reinterpret_cast<CHA*>(args[arg_index]);
        if (iua_ptr == nullptr)
          return BInError(bin, cErrorImplementation, params, index, origin);
        iua = *origin;
#endif
      default: {  //< It's an Array
        D_COUT("\nIt's an array!\n");
#if USING_SCRIPT2_ARRAY
        switch (type & 0x60) {
          case 0: {
            if ((type < cLST) && (type < cMAP))
              return BInError(bin, cErrorInvalidType, params, index, origin);
            if (length < 1)  // 1 IUA for the width word.
              return BInError(bin, cErrorBufferUnderflow, params, index,
                              origin);

            iua_ptr = reinterpret_cast<CHA*>(args[arg_index]);
            if (iua_ptr == nullptr)
              return BInError(bin, cErrorImplementation, params, index, origin);

            iua = *origin;
            if (++origin >= stop) origin -= size;
            hash = HashIUB(iua, hash);
            if (iua > length - 1)
              return BInError(bin, cErrorBufferOverflow, params, index, origin);
            length = length - count - 1;
            count = (IUW)iua;
            break;
          }
          case 1: {
            if (length < 2)  // 2 IUA for the width word.
              return BInError(bin, cErrorBufferUnderflow, params, index,
                              origin);
            length -= 2;
            iub_ptr = reinterpret_cast<IUB*>(args[arg_index]);
            if (iub_ptr == nullptr)
              return BInError(bin, cErrorImplementation, params, index, origin);

            for (temp = 0; temp <= sizeof(IUB); temp += 8) {
              iua = *origin;
              if (++origin >= stop) origin -= size;
              hash = HashIUB(iua, hash);
              iub |= ((IUB)iua) << temp;
            }
            if (iub > length)
              return BInError(bin, cErrorBufferOverflow, params, index, origin);
            length -= count;
            count = (IUW)iub;
            iua_ptr = reinterpret_cast<CHA*>(iub_ptr);
            break;
          }
          case 2: {
            if (length < 4)  // 4 IUA for the width word.
              return BInError(bin, cErrorBufferUnderflow, params, index,
                              origin);
            length -= 4;
            iuc_ptr = reinterpret_cast<IUC*>(args[arg_index]);
            if (iuc_ptr == nullptr)
              return BInError(bin, cErrorImplementation, params, index, origin);

            for (temp = 0; temp <= sizeof(IUC); temp += 8) {
              iua = *origin;
              if (++origin >= stop) origin -= size;
              hash = HashIUB(iua, hash);
              iuc |= ((IUC)iua) << temp;
            }
            if (iuc >= length)
              return BInError(bin, cErrorBufferOverflow, params, index, origin);
            length -= count;
            count = (IUW)iuc;
            iua_ptr = reinterpret_cast<CHA*>(iuc_ptr);
            break;
          }
          case 3: {  // 8 IUA for the width word.
            if (length < 9)
              return BInError(bin, cErrorBufferUnderflow, params, index,
                              origin);
            length -= 8;
            iud_ptr = reinterpret_cast<IUD*>(args[arg_index]);
            if (iud_ptr == nullptr)
              return BInError(bin, cErrorImplementation, params, index, origin);

            for (temp = 0; temp <= sizeof(IUD); temp += 8) {
              iua = *origin;
              if (++origin >= stop) origin -= size;
              hash = HashIUB(iua, hash);
              iud |= ((IUD)iua) << temp;
            }
            if (iud > length)
              return BInError(bin, cErrorBufferOverflow, params, index, origin);
            length -= count;
            count = (IUW)iud;
            iua_ptr = reinterpret_cast<CHA*>(iud_ptr);
            break;
          }
          default:
            return BInError(bin, cErrorImplementation, params, index, origin);
        }

        if (length < count)
          return BInError(bin, cErrorBufferOverflow, params, index, origin);
        if (count == 0) break;  //< Not sure if this is an error.
        if (origin + count >= stop) {
          for (; size - count > 0; --count) {
            iua = *origin;
            if (++origin >= stop) origin -= size;
            hash = HashIUB(iua, hash);
            *iua_ptr = iua;
            ++iua_ptr;
          }
          stop = origin - 1;
          for (; count > 0; --count) {
            iua = *origin;
            if (++origin >= stop) origin -= size;
            hash = HashIUB(iua, hash);
            *iua_ptr = iua;
            ++iua_ptr;
          }
          break;
        }
        for (; count > 0; --count) {
          iua = *origin;
          if (++origin >= stop) origin -= size;
          hash = HashIUB(iua, hash);
          *iua_ptr = iua;
          ++iua_ptr;
        }
        break;
#endif  //< D_THIS
      }
    }
    ++arg_index;
    D_COUT(" |");
  }
  D_COUT("\nHash expected:0x" << Hexf(hash));
  if (length < 2)
    return BInError(bin, cErrorBufferUnderflow, params, index, origin);
  iub = *origin;
  if (++origin >= stop) origin -= size;
  iua = *origin;
  if (++origin >= stop) origin -= size;
  iub |= (((IUB)iua) << 8);
  D_COUT("found:0x" << Hexf(iub));
  if (hash != iub)
    return BInError(bin, cErrorInvalidHash, params, index, origin);

  D_COUT("\nDone reading\n");
  CLEAR(origin, stop)

  // Convert pointer back to offset
  bin->origin = TDelta<ISC>(origin, origin);

  return 0;
}

#if USING_SCRIPT2_TEXT
UTF1& Print(UTF1& utf, BIn* bin) {
  D_ASSERT(bin);

  ISC size = bin->size;
  return utf << Line('_', 80) << " size:" << bin->size
             << " start:" << bin->origin << " stop:" << bin->stop
             << " read:" << bin->read
             << Socket(BInBegin(bin), size + sizeof(BIn));
}
#endif

}  // namespace _

#endif
