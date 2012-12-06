#include <iostream>
#include "VirtualMachine.h"
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, char* argv[])
{
	if(argc >= 2)
	{
		string file;
		file = argv[1];
		VirtualMachine vm;
		vm.run_from_file(file);
	}
	else
	{
		VirtualMachine vm(10);
		string test;
		test = "+--------------------+\n| - x - - - - - - - | \n| - - - - x - - - - |";
		vm.run(test);
	}
	system("pause");
	return 0;
}