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

dll_func Func_Fast_Sort;

dll_func get_function(LPSTR wey_to_dll, LPSTR name_function)
{
	HINSTANCE Lib_Dll_Sort = LoadLibrary(wey_to_dll);
	Func_Fast_Sort = (dll_func)GetProcAddress(Lib_Dll_Sort, name_function);
	return Func_Fast_Sort;
}

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

TEST(New_test, two_test)
{
	std::vector<int> test_one_vector = {1,1,1,1,1,1,1,1,1,1,};
	std::vector<int> TestVector1 = { 1,1,1,1,1,1,1,1,1,1, };
	std::vector<int>* TestVectorRef1 = &TestVector1;

	Func_Fast_Sort(TestVectorRef1, 0, TestVector1.size() - 1);

	ASSERT_TRUE(TestVector1 == test_one_vector);


	std::vector<int> test_mach_vector = {0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5};
	std::vector<int> TestVector2 = {5,4,3,2,1,0,0,1,2,3,4,5,2,3,1,0,5,4};
	std::vector<int>* TestVectorRef2 = &TestVector2;

	Func_Fast_Sort(TestVectorRef2, 0, TestVector2.size() - 1);

	ASSERT_TRUE(TestVector2 == test_mach_vector);
}

int main(int argc, char **argv)
{
	LPSTR wey_dll_sort = "../../libraries/dll_relise/sort_dll";
	LPSTR func_name = "Func_Fast_Sort";
	//подключем динамиче1скую библиотеку
	Func_Fast_Sort = get_function(wey_dll_sort,func_name);
	//запускаем тесты
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}