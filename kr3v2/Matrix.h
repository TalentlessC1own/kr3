#pragma once
#include <iostream>
#include "Names.h"
#include "InputCheck.h"
#include <cstdlib>
#include <string>
#include<ctime>
#include<vector>

class Matrix
{
private:
	int number_of_lines{0};
	int number_of_colums{0};
	std::vector<std::vector<int>> matrix;
public:

	int GetNumberOflines();
	void SetNumberOfLines(int number);
	int GetNumbersOfColums();
	void SetNumberOfColums(int number);
	std::vector<int> GetDiagonalElements();
	void SetMatrix(std::vector<std::vector<int>> matrix_);
	void ChangeDiagonalElements(std::vector<int> diagonal_elements);
	std::vector<std::vector<int>> GetMatrix();
	void Show();

	
};

