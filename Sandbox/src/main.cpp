#include <iostream>


	__declspec(dllimport) void start();

// ^^^^
// |||| This import is just for now

int main()
{
	start();
	system("pause");

	return 0;
}