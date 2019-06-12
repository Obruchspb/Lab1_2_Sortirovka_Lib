#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdint.h>
#include <vector>
#include "../../libraries/static/static_lib.hpp"
#include "dll_that_connect.hpp"
#include <gtest/gtest.h>

const std::vector<int> MainVector = { 1, 2, 3, 4, 5 };//опорный массив


TEST(All_test, One_test)
{
	// тестирование обратно отсортированного массива
	std::vector<int> TestVector = { 5, 4, 3, 2, 1 };
	std::vector<int>* TestVectorRef = &TestVector;
	Func_Fast_Sort(TestVectorRef, 0, TestVector.size()-1);
	ASSERT_TRUE(TestVector == MainVector);

	// тестирование не отсортированного массива
	std::vector<int> TestVector1= { 4, 2, 5, 1, 3 };
	std::vector<int>* TestVectorRef1 = &TestVector1;
	Func_Fast_Sort(TestVectorRef1, 0, TestVector1.size() - 1);
	ASSERT_TRUE(TestVector1 == MainVector);

	// тестирование прямо отсортированного массива
	std::vector<int> TestVector2 = { 1, 2, 3, 4, 5 };
	std::vector<int>* TestVectorRef2 = &TestVector2;
	Func_Fast_Sort(TestVectorRef2, 0, TestVector2.size() - 1);
	ASSERT_TRUE(TestVector2 == MainVector);
	
}

int main(int argc, char **argv)
{
	//подключем динамическую библиотеку
	HINSTANCE Lib_Dll_Sort = LoadLibrary("../../BuldSortirovka/libraries/dll/Debug/sort_dll");
	Func_Fast_Sort = (void(*) (std::vector<int> *VectorRef, int LeftBoard, int RightBoard)) GetProcAddress(Lib_Dll_Sort, "Func_Fast_Sort");
	//запускаем тесты
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}