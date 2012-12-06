#include "VirtualMachine.h"
#include <iostream>
#include <algorithm>
#include <memory>
#include <fstream>
#include <sstream>
using namespace std;

VirtualMachine::VirtualMachine()
{
	capacity = 3000;
	parser = unique_ptr<Parser>( new Parser);
	memory = unique_ptr<int[]>( new int[capacity]);
	memory_counter = 0;
	program_counter = 0;
	initialize_memory();
}

VirtualMachine::VirtualMachine(int size)
{
	capacity = size;
	parser = unique_ptr<Parser>( new Parser);
	memory = unique_ptr<int[]>( new int[capacity]);
	memory_counter = 0;
	program_counter = 0;
	initialize_memory();
}

void 
	VirtualMachine::initialize_memory()
{
	for(int i=0; i < capacity; i++)
	{
		memory[i] = 0;
	}
}

void
	VirtualMachine::eval_next()
{
	switch(instructions[program_counter])
	{
		case USER_MARKER: break;
		case JUMP_MARKER: 
			jump_marker = program_counter;
			break;
		case MOVE_NEXT:
			(++memory_counter == capacity) ? memory_counter = 0 : memory_counter++;
			break;
		case INCREMENT:
			memory[memory_counter]++;
			break;
		case DECREMENT:
			memory[memory_counter]--;
			break;
		case INPUT:
			int a;
			cin >> a;
			memory[memory_counter] = a;
			break;
		case OUTPUT:
			cout << memory[memory_counter];
			break;
		case JUMP_IF_ZERO:
			if(memory[memory_counter] == 0 && jump_marker > 0)
			{
				program_counter = jump_marker;
			}
			break;
		case JUMP_NOT_ZERO:
			if(memory[memory_counter] != 0 && jump_marker > 0)
			{
				program_counter = jump_marker;
			}
			break;
		case PRETTY_PRINT:
			cout << (char)memory[memory_counter];
	}
	program_counter++;
}

void 
	VirtualMachine::run(string source)
{
	instructions = parser->parse(source);
	while(program_counter < instructions.size())
	{
		eval_next();
	}
}

void
	VirtualMachine::run_from_file(string const &file_name)
{
	ifstream fin;
	stringstream file_contents(stringstream::in | stringstream::out);
	string line;
	fin.open(file_name,ios::in);
	if(fin.is_open())
	{
		while(fin.good())
		{
			getline(fin,line);
			file_contents << line << "\n";
		}
		run(file_contents.str());
	}
	else
	{
		cout << "Could not open " << file_name << " for processing.";
	}
	
}

void 
	VirtualMachine::memory_dump()
{
	for(int i=0; i< capacity; i++)
	{
		cout << memory[0] << endl;
	}
}

void 
	VirtualMachine::instruction_dump()
{
	cout << "Instruction dump: " << endl;
	for_each(instructions.begin(), instructions.end(), [](int i) {
		cout << i << endl;
	});
}