#include <iostream>

namespace Duggoo
{

	__declspec(dllimport) void printWelcome();

}

// ^^^^
// |||| This import is just for now

void main()
{
	Duggoo::printWelcome();
	system("pause");
}