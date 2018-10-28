#include <iostream>

namespace Duggoo
{

	__declspec(dllimport) void start();

}

// ^^^^
// |||| This import is just for now

void main()
{
	Duggoo::start();
	system("pause");
}