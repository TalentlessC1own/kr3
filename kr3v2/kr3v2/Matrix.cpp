#include "Matrix.h"
#include <algorithm>

int Matrix::GetNumberOflines()
{
	return number_of_lines;
}

void Matrix::SetNumberOfLines(int number)
{
	number_of_lines = number;
}



int Matrix::GetNumbersOfColums()
{
	return number_of_colums;
}

void Matrix::SetNumberOfColums(int number)
{
	number_of_colums = number;
}




std::vector<int> Matrix::GetDiagonalElements()
{
  std::vector<int> diagonal_elements;
  for (int i = 0; i <  std::min(number_of_lines,number_of_colums); i++)
  {
    diagonal_elements.push_back(matrix[i][i]);
  }
  return diagonal_elements;
}

void Matrix::SetMatrix(std::vector<std::vector<int>> matrix_)
{
	matrix = matrix_;
}

void Matrix::ChangeDiagonalElements(std::vector<int> diagonal_elements)
{
	for (int i = 0; i < std::min(number_of_lines, number_of_colums); i++)
	{
		matrix[i][i] = diagonal_elements[i];
	}
}

std::vector<std::vector<int>> Matrix::GetMatrix()
{
	return matrix;
}

void Matrix::Show()
{
	std::cout << "\n\n" << std::endl;
	for (int i = 0; i < number_of_lines; i++)
	{
		for (int j = 0; j < number_of_colums; j++)
		{
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n" << std::endl;
}





