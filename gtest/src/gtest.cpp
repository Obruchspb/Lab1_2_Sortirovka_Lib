#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdint.h>
#include <vector>
#include "../../lib/static/static_lib.hpp"
#include "dll_that_connect.hpp"
#include <gtest/gtest.h>

TEST(first_tests, up_down_level)
{
	// тестирование обратно отсортированного массива
	ref_test_vector = {5, 4, 3, 2, 1};
	dll_fuction(ref_test_vector, 0, ref_test_vector.size()-1);
	ASSERT_EQ(test_vector == main_vector);

	// тестирование не отсортированного массива
	ref_test_vector = {3, 1, 5, 4, 2};
	dll_fuction(ref_test_vector, 0, ref_test_vector.size()-1);
	ASSERT_EQ(test_vector == main_vector);

	// тестирование прямо отсортированного массива
	ref_test_vector = {1, 2, 3, 4, 5};
	dll_fuction(ref_test_vector, 0, ref_test_vector.size()-1);
	ASSERT_EQ(test_vector == main_vector);
	
}

int main()
{
	//подключем динамическую библиотеку
	HINSTANCE sort_dll_lib = LoadLibrary("../../Laba_2/lib/dll/Debug/sort_dll");
	dll_fuction = (void(*) (std::vector<int> *ref_vector, int l_board, int r_board)) GetProcAddress(sort_dll_lib, "Fast_Sort");
	//создаем вектора для проведения тестов
	std::vector<int> main_vector = {1, 2, 3, 4, 5};
	std::vector<int> test_vector(5);
	//запускаем тесты
	std::vector<int>* ref_test_vector = &test_vector;
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}