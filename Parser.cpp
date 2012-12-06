#include "Parser.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

void
	Parser::remove_spaces(string &line)
{
	string temp;

	for_each(line.begin(), line.end(), [&temp](char c){
			if(c != ' ')
			{
				temp.push_back(c);
			}
	});
	swap(temp,line);
}

int
	Parser::calculate_command(string const &line)
{
	int command = 0;
	int line_size = line.size();
	if(line[0] != '+')
	{ 
		if(line[0] == '|')
		{
			for(int i = 1; i < line_size; i++)
			{
				if(line[i] == 'x')
				{
					command += i;
				}
			}
		}
	}
	else
	{
		command = -1;
	}
	return command;
}

vector<int>
	Parser::parse(string program)
{
	vector<int> i;
	string line;
	stringstream ss(stringstream::in | stringstream::out);
	ss << program;
	while(std::getline(ss,line))
	{
		remove_spaces(line);
		i.push_back(calculate_command(line));
	}
	return i;
}