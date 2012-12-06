#ifndef PARSER_H_
#define PARSER_H_
#include <string>
#include <vector>

enum command_t {
	USER_MARKER = -1,
	JUMP_MARKER = 0,
	MOVE_NEXT = 1,
	INCREMENT = 2,
	DECREMENT = 3,
	INPUT = 4,
	OUTPUT = 5,
	JUMP_IF_ZERO = 6,
	JUMP_NOT_ZERO = 7
};

class Parser
{
private:
	std::string source;
	void remove_spaces(std::string &line);
	int calculate_command(std::string const &line);
public:
	std::vector<int> parse(std::string program);
};

#endif