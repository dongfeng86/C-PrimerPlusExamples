// CommandLine.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

// argument_definitions.cpp
// compile with: /EHsc
#include <iostream>
#include <string.h>

using namespace std;
int main(int argc, char *argv[], char *envp[]) 
{
	printf("\nargv cout:%d", argc);

	int iNumberLines = 0;    // Default is no line numbers.

	// If /n is passed to the .exe, display numbered listing
	// of environment variables.

	if ((argc == 2) && _stricmp(argv[1], "/n") == 0)
		iNumberLines = 1;

	// Walk through list of strings until a NULL is encountered.
	for (int i = 0; envp[i] != NULL; ++i) {
		if (iNumberLines)
			cout << i << ": " << envp[i] << "\n";
	}
}
