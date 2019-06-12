#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
extern "C"
{
	__declspec(dllexport) void Func_Fast_Sort(std::vector<int> *RefVector, int LeftBoard, int RightBoard);
}

