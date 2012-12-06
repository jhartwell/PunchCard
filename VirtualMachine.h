#ifndef VIRTUALMACHINE_H_
#define VIRTUALMACHINE_H_
#include "Parser.h"
#include <vector>
#include <memory>

class VirtualMachine
{
private:
	std::unique_ptr<Parser> parser;
	std::unique_ptr<int[]> memory;
	int capacity;
	int jump_marker;
	int program_counter;
	int memory_counter;
	std::vector<int> instructions;
	void eval_next();
	void initialize_memory();
public:
	VirtualMachine();
	VirtualMachine(int size);
	void run(std::string source);
	void run_from_file(std::string const &file_name);
	void compile(std::string source, std::string output);
	void memory_dump();
	void instruction_dump();
};

#endif