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

void(std::vector<IL_Instruction*>& ILInstructions, std::vector<x86_Instruction*>& x86Instructions){

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
