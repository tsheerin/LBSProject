#include <vector>

//if additional instructions add here
enum IL_Instruction_type{ILI_ADD, ILI_IN, ILI_SUB, ILI_XOR, ILI_SWAP};

struct IL_Instruction{
	//indicates the actual instruction
	IL_Instruction_type instruction;

	//pretty sure viswath said all instructions 
	//were going to be ints
	int argument;

};

//this should grow as we find out what instructions we need
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
enum x86_Instruction_type{x86_MOV};

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
}

void IL_to_x86(std::vector<IL_Instruction*>& ILInstructions, std::vector<x86_Instruction*>& x86Instructions){

	//step through all the intermediate language instructions
	for(int i = 0; i < ILInstructions.size(); ++i){
		IL_Instruction* current = ILInstructions[i];

		//handle them by instruction type
		//and push the appropriate x86 sequence onto
		//the back of the other vector
		switch(current->instruction){

		}
	}
}
