#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/precipitation.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{

	// вспомогательная функция для создания одной записи
	precipitation* build_result(int month, double value)
	{
		precipitation* result = new precipitation;
		result->day.month = month;
		result->value = value;
		return result;
	}

	// вспомогательная функция для удаления массива тестовых данных
	void delete_result(precipitation* array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
	}

	TEST_CLASS(unittestproject)
	{
	public:
		
		TEST_METHOD(TestMethod1) // Стандартная ситуация 1
		{
			precipitation* results[3];
			results[0] = build_result(8, 2.123);
			results[1] = build_result(8, 2.123);
			results[2] = build_result(8, 2.123);
			Assert::AreEqual(6.369, process(results, 3, 8), 10);
			delete_result(results, 3);
		}

		TEST_METHOD(TestMethod2) // Стандартная ситуация 2
		{
			precipitation* results[3];
			results[0] = build_result(8, 3.123);
			results[1] = build_result(8, 2.123);
			results[2] = build_result(8, 2.123);
			Assert::AreEqual(7.369, process(results, 3, 8), 10);
			delete_result(results, 3);
		}

		TEST_METHOD(TestMethod3) // Стандартная ситуация 3
		{
			precipitation* results[3];
			results[0] = build_result(8, 8.4124);
			results[1] = build_result(8, 9.1241);
			results[2] = build_result(8, 10.1512);
			Assert::AreEqual(27.6877, process(results, 3, 8), 10);
			delete_result(results, 3);
		}

		TEST_METHOD(TestMethod4) // Нестандартный ввод 1
		{
			precipitation* results[3];
			results[0] = build_result(8, 8.4124);
			results[1] = build_result(8, 9.1241);
			results[2] = build_result(06, 10.1512);
			Assert::AreEqual(17.5365, process(results, 3, 8), 10);
			delete_result(results, 3);
		}

		TEST_METHOD(TestMethod5) // Нестандартный ввод 2
		{
			precipitation* results[3];
			results[0] = build_result(05, 8.4124);
			results[1] = build_result(8, 9.1241);
			results[2] = build_result(06, 10.1512);
			Assert::AreEqual(9.1241, process(results, 3, 8), 10);
			delete_result(results, 3);
		}

		TEST_METHOD(TestMethod6) // Нестандартный ввод 3
		{
			precipitation* results[3];
			results[0] = build_result(0, 8.4124);
			results[1] = build_result(0, 9.1241);
			results[2] = build_result(0, 10.1512);
			Assert::AreEqual(0.0, process(results, 3, 8), 10);
			delete_result(results, 3);
		}

		TEST_METHOD(TestMethod7) // Нестандартный ввод 4
		{
			precipitation* results[3];
			results[0] = build_result(-3, 8.4124);
			results[1] = build_result(-6, 9.1241);
			results[2] = build_result(-7, 10.1512);
			Assert::AreEqual(0.0, process(results, 3, 6), 10);
			delete_result(results, 3);
		}
	};
}
