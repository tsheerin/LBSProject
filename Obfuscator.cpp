#include <vector>

//if additional instructions add here
enum IL_Instruction_type{ILI_ADD, ILI_IN, ILI_SUB, ILI_XOR, ILI_SWAP};

struct IL_Instruction{
	//indicates the actual instruction
	IL_Instruction_type instruction;

	//pretty sure viswath said all instructions 
	//were going to be ints
	int arg;

};

//this should grow as we find out what instructions we need
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
}

void IL_to_x86(std::vector<IL_Instruction*>& ILInstructions, std::vector<x86_Instruction*>& x86Instructions){

	//represents the number of bytes we 
	//are currently operationg on
	int bytesInBuffer;
	const REGISTER_WIDTH = 4;

	//step through all the intermediate language instructions
	for(int i = 0; i < ILInstructions.size(); ++i){
		IL_Instruction* current = ILInstructions[i];

		//handle them by instruction type
		//and push the appropriate x86 sequence onto
		//the back of the other vector
		switch(current->instruction){
			case ILI_IN:
				{
					//push instructions to write out 
					//current buffer content

					bytesInBuffer = current->arg;

					//push instructionss to read in
					//new bytes
 
					break;
				}
			case ILI_ADD:
				{
					if(bytesInBuffer <= REGISTER_WIDTH){
						//insert prepratory instructions

						//insert the add instruction
						x86_instruction* temp = new x86_instruction;
						temp->instruction = x86_ADD;

						//set args
						
						//push on list
						x86Instructions.push_back(temp);

						//mask off the top register_with - bytesInBuffer bytes

					}else if(bytesInBuffer > REGISTER_WIDTH){
						//we only have to deal with the least four bytes because 
						//right now args cant be over four bytes.
						//however if interger overflow occurs we some how need to
						//deal with higher stuff in the buffer...
						//
						//I suppose we could test overflowPoint - currnt4Bytes to see
						//if it is greater than the add argument, then if it is compute the carry
						//into the next four bytes and do it all again until we get to the end of the 
						//buffer...
					}
					break;
				}
			case ILI_SUB:
				{
					if(bytesInBuffer <= REGISTER_WIDTH){ 
						//insert the subtract instruction
						//mask off the top register_with - bytesInBuffer bytes
					}else if(bytesInBuffer > REGISTER_WIDTH){
						//we only have to deal with the least four bytes because 
						//right now args cant be over four bytes.
						//however if interger wraparound occurs we some how need to
						//deal with higher stuff in the buffer...
						//
						//I suppose we could test wraparoundPoint - currnt4Bytes to see
						//if it is greater than the add argument, then if it is compute the carry
						//into the next four bytes and do it all again until we get to the end of the 
						//buffer...
					}
					break;
				}
			case ILI_XOR:
				{
					//the trouble with this one is I think we need to be performed at a byte
					//by byte level. split the buffer in half then xor firsthalf secondhalf
					//keep the second half stor the result of the xor in the first half
					//
					//if bytes in buffer != a power of the register width this could really suck

					break;
				}
			case ILI_SWAP:
				{
					//for (multiples of two) times the register width this is easy.
					//for odd  multiples of the register width you will have to copy
					//the middle register mask the top half of one and the bottom half
					//and or them together
					//
					//if the don't send only multiples of the register width this is going 
					//to require a shit ton of byte shuffling
					//
					//for instance if the register with is 4 and they send 10 bytes...
					//everything would halve to be shifted down a byte make the thing symmetric
					//then we weould need to just swap the tow ends and shift everry thing to 
					//the opposite side of the register.

					break;
				}
			defalut:
				//unknown IL instruction; let caller know; terminate;
		}
	}
}
