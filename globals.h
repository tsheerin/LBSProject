#ifndef __GLOBALS_H_
#define __GLOBALS_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
The intermediate language is a stackless, one accumulator
system (which stores the results of all computations).

The statements in the intermediate language are:
  IN [num] -  Reads num bytes from the input stream to the 
              accumulator
  OUT [num] - Writes num bytes to the output stream from 
              the accumulator 
  ADD [num] - Adds num to the accumulator
  SUB [num] - Subtracts num
  XOR [num] - XORs num with the accumulator 
  SWAP      - Swaps the first and second halves of the accumulator
  LAST      - Not really an instruction. Just kept as the last value
              for the enum to make selecting a random value simpler
*/
enum IL_Command {IN, OUT, ADD, SUB, XOR, SWAP, LAST};

/*
An IL statement is a command followed by an integer operand.
If the command is SWAP then the operand is set to 0 but not used.
*/
struct IL_Statement
{
	IL_Command command;
	int operand;
};

#endif