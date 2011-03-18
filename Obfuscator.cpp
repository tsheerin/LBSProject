#include <vector>
#include "globals.h"

/***************************************************************************
 * THESE ARE NO LONGER NECERSSARY SINCE WE HAVE VISHWATH'S VERSION! ********
 * *************************************************************************
//if additional instructions add here
enum IL_Instruction_type{ILI_ADD, ILI_IN, ILI_SUB, ILI_XOR, ILI_SWAP};

struct IL_Instruction{
    //indicates the actual instruction
    IL_Instruction_type instruction;

    //pretty sure viswath said all instructions 
    //were going to be ints
    int arg;

};
*/

//Other x86 instructions we probably need and instruction syntax:
//I'm really just taking a stab at finding useful instructions
//Instr OpCode      Op1     Op2     Op3
//-----------------------------------
//MOV:  88 /r       r/m8    r8
//      89 /r       r/m16   r16
//      89 /r       r/m32   r32
//      8A /r       r8      r/m8
//      8B /r       r16     r/m16
//      8B /r       r32     r/m32
//      There are probably others that we need, for segment registers
//      and such
//ADD:  04 ib       AL      imm8
//      05 iw       AX      imm16
//      05 id       EAX     imm32
//      80 /0 ib    r/m8    imm8
//      81 /0 iw    r/m16   imm16
//      81 /0 id    r/m31   imm32
//SUB:  1C ib       AL      imm8
//      1D iw       AX      imm16
//      1D id       EAX     imm32
//      80 /3 ib    r/m8    imm8
//      81 /3 iw    r/m16   imm16
//      81 /3 id    r/m31   imm32
//XOR:  34 ib       AL      imm8
//      35 iw       AX      imm16
//      35 id       EAX     imm32
//      80 /6 ib    r/m8    imm8
//      81 /6 iw    r/m16   imm16
//      81 /6 id    r/m31   imm32
//
//      I'm not really sure what the /(0|3|6) means, I think the r/m means
//      registers or memory locations.
//
//      We probably only need the 32 bit instructions, but I'm not sure if we
//      would rather use the 16 or 8 bit versions depending on the number of
//      bytes we're dealing with. We should probably iron that out a bit with
//      Vishwath and John.
//
// shifts might come in helpful to... SAR SHR SAL SHL
// ones with A are arithmatic shifts and preserve the sign
// ones with H are logical and don't.  I don't knwo which ones
// are useful...there are ALOT of special cases...the table is 
// two pages long in the reference manual...
// starts on page 361 pdf 359 book
//
// ands and ors might also be useful for masking and the like...
// they are on page volume 2 17 pdf (or) and volume 1 page 136 pdf (and)
//
// AND:   24 ib         AL      imm8
//    25 iw       AX      imm16
//    25 id       EAX     imm32
//    80 /4 ib    r/m8    imm8
//    81 /4 iw    r/m16   imm16
//    81 /4 id    r/m32   imm32
//
// OR: 0C ib        AL      imm8
//     0D iw        AX      imm16
//     0D id        EAX     imm32
//     80 /1 ib     r/m8    imm8
//     81 /1 iw     r/m16   imm16
//     81 /1 id     r/m32   imm32
//     
//     there are more that do register-regester args
//     as I assume there are with the ones you posted but 
//     I figure we will only need the immdiate ones anyway



enum x86_Instruction_type{x86_MOV, x86_XOR, x86_OR, x86_ADD, x86_SUB, x86_RSHIFT x86_LSHIFT};

//this might not work unless we can come up with a way to 
//indicate dereferencing...that sytax could be complex other wise
//leading to LOTS of values
//
//we might be able to pair each arg with a char flag to 
//indicate if it is a registerm a dereferenced register
//or a literal value...but then how do you handle things like
//[EAX + 4]?  that would require another value "offset" for 
//each arg...it seems like there should be a simpler way to do
//this but x86 assembly syntax is so hella complex, 
//I'm not sure there is
enum x86_registers{REG_EAX, REG_EBX, REG_ECX, REG_EDX};

struct x86_Instruction{
    x86_Instruction_type instruction;

    //some how need to indicate args
    //not sure how we should do that
    x86_Instruction(x86_Instruction_type type);
}

x86_Instruction::x86_Instruction(x86_Instruction_type type)
{
    instruction = type;
}

void IL_to_x86(std::vector<IL_Statement*>& ILInstructions, std::vector<x86_Instruction*>& x86Instructions){

    //represents the number of bytes we 
    //are currently operationg on
    int bytesInBuffer;
    int start, end;
    const REGISTER_WIDTH = 4;

    //step through all the intermediate language instructions
    for(int i = 0; i < ILInstructions.size(); ++i){
        IL_Statement* current = ILInstructions[i];

        //handle them by instruction type
        //and push the appropriate x86 sequence onto
        //the back of the other vector
        switch(current->command){
            case IN:
                {
                    //push instructions to write out 
                    //current buffer content

                    bytesInBuffer = current->operand;
                    start = end;
                    end += bytesInBuffer;

                    //push instructions to read in
                    //new bytes

                    break;
                }
            case ADD:
                {
                     for(int i = 0; i < bytesInBuffer; i += 4)
                     {
                        if(bytesInBuffer <= REGISTER_WIDTH){
                       }else if(bytesInBuffer > REGISTER_WIDTH){
                           //we only have to deal with the least four bytes because 
                           //right now args cant be over four bytes.
                           //however if interger overflow occurs we some how need to
                           //deal with higher stuff in the buffer...
                           //
                           //I suppose we could test overflowPoint - currnt4Bytes to
                           //see
                           //if it is greater than the add argument, then if it is 
                           //compute the carry
                           //into the next four bytes and do it all again until we 
                           //get to the end of the 
                              //buffer...
                            //insert prepratory instructions
                            x86_instruction* movFromMem = 
                                new x86_instruction(x86_MOV);

                            //insert the add instruction
                            x86_instruction* add = new x86_instruction(x86_ADD);

                            //set args

                            x86_instruction* movToMem = 
                                new x86_instruction(x86_MOV);

                            //push on list
                            x86Instructions.push_back(movFromMem);
                            x86Instructions.push_back(add);
                            x86Instructions.push_back(movToMem);

                            //mask off the top register_with - bytesInBuffer 
                            //bytes
                       }
                     }

                     //if bytesinbuffer mod 4 != 0 we will have to handle it here

                    break;
                }
            case SUB:
                {
                    if(bytesInBuffer <= REGISTER_WIDTH){ 
                        //insert the subtract instruction
                        //mask off the top register_with - bytesInBuffer bytes
                    }else if(bytesInBuffer > REGISTER_WIDTH){
                        //we only have to deal with the least four bytes because 
                        //right now args cant be over four bytes.
                        //however if interger wraparound occurs we some how need 
                        //to
                        //deal with higher stuff in the buffer...
                        //
                        //I suppose we could test wraparoundPoint - currnt4Bytes 
                        //to see
                        //if it is greater than the add argument, then if it is 
                        //compute the carry
                        //into the next four bytes and do it all again until we 
                        //get to the end of the 
                        //buffer...
                    }
                    break;
                }
            case XOR:
                {
                    //the trouble with this one is I think we need to be 
                    //performed at a byte
                    //by byte level. split the buffer in half then xor firsthalf 
                    //secondhalf
                    //keep the second half stor the result of the xor in the 
                    //first half
                    //
                    //if bytes in buffer != a power of the register width this 
                    //could really suck

                    break;
                }
            case SWAP:
                {
                    //for (multiples of two) times the register width this is 
                    //easy.
                    //for odd  multiples of the register width you will have to 
                    //copy
                    //the middle register mask the top half of one and the bottom
                    //half
                    //and or them together
                    //
                    //if the don't send only multiples of the register width this
                    //is going 
                    //to require a shit ton of byte shuffling
                    //
                    //for instance if the register with is 4 and they send 10 
                    //bytes...
                    //everything would halve to be shifted down a byte make the 
                    //thing symmetric
                    //then we weould need to just swap the tow ends and shift 
                    //everry thing to 
                    //the opposite side of the register.

                    break;
                }
            default:
                //unknown IL instruction; let caller know; terminate;
        }
    }
}
/* vi: set tabstop=3 expandtab shiftwidth=3 softtabstop=3: */
