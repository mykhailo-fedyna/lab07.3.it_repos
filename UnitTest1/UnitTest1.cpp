#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.3(it).cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
int FindFirstRowWithoutPositive(double** matrix, const int size);
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestFindFirstRowWithoutPositive)
		{
			int size = 3;
			double** matrix = new double* [size];
			for (int i = 0; i < size; i++)
				matrix[i] = new double[size];
			matrix[0][0] = -1; matrix[0][1] = -2; matrix[0][2] = -3;
			matrix[1][0] = 4;  matrix[1][1] = 5;  matrix[1][2] = 6;
			matrix[2][0] = -7; matrix[2][1] = -8; matrix[2][2] = 9;
			int rowWithoutPositive = FindFirstRowWithoutPositive(matrix, size);
			Assert::AreEqual(0, rowWithoutPositive);
			for (int i = 0; i < size; i++)
				delete[] matrix[i];
			delete[] matrix;
		}
	};
}

