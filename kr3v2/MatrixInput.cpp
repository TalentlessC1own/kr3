#include "MatrixInput.h"

int  MatrixInput(Matrix* matrix)
{

	std::cout << "1 - matrix byhand input " << std::endl
		<< "2 - matrix random input " << std::endl
		<< "3 - matrix file input" << std::endl;
	InputMode mode = static_cast<InputMode>(InputCheck::CheckMenu(3));
	switch (mode)
	{
	case InputMode::ConsoleByHand:
		ConsoleInput(matrix);
		break;

	case InputMode::ConsoleRandom:
		RandomInput(matrix);
		break;

	case InputMode::File:
		FileInput(matrix);
		break;

		
	}
	return static_cast<int>(mode);
}

void ConsoleInput(Matrix *matrix)
{
	
		std::cout << "Enter order ." << std::endl;;
		matrix -> SetNumberOfLines(InputCheck::CheckIntValuePlus());
		matrix->SetNumberOfColums(matrix->GetNumberOflines());

		std::vector<std::vector<int>> matrix_;

		for (int i = 0; i < matrix->GetNumberOflines(); i++)
		{
			matrix_.push_back(std::vector<int>{});
			for (int j = 0; j < matrix->GetNumbersOfColums(); j++)
			{
				std::cout << "Enter [" << i + 1 << "] [" << j + 1 << "] ." << std::endl;
				matrix_[i].push_back(InputCheck::CheckIntValue());
			}
		}
		matrix->SetMatrix(matrix_);
}

void FileInput(Matrix* matrix)
{
	std::string file_name = "";
	std::ifstream file;
	std::vector<std::vector<int>> matrix_;
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	while (true)
	{
		std::cout << "Enter file name. " << std::endl << "ENTER : ";
		std::cin >> file_name;
		if (file_name.find(".txt") >= std::string::npos) {
			std::cout << "Wrong data type\n" << std::endl;
			continue;
		}
		try
		{
			file.open(file_name);
			std::cout << "Sucefull file open " << std::endl;
		}
		catch (const std::exception&)
		{
			std::cout << "Incorrect file name or way.Try again ." << std::endl;
			continue;

		}

		try
		{
			matrix->SetNumberOfLines(InputCheck::CheckLineInt(file));
			matrix->SetNumberOfColums(InputCheck::CheckLineInt(file));
		

			for (int i = 0; i < matrix->GetNumberOflines(); i++)
			{
				matrix_.push_back(std::vector<int>{});
				for (int j = 0; j < matrix->GetNumbersOfColums(); j++)
				{
					matrix_[i].push_back( InputCheck::CheckLineInt(file));
				}
			}
		}
		catch (std::exception&)
		{
			file.close();
			continue;
		}
		std::cin.clear();
		std::cin.ignore();
		file.close();
		matrix->SetMatrix(matrix_);
		break;
	}
}

void RandomInput(Matrix* matrix)
{
	srand(static_cast<unsigned>(time(nullptr)));
	std::cout << "Enter order ." << std::endl;;
	int ord = InputCheck::CheckIntValue();

	matrix->SetNumberOfLines(ord);

	matrix->SetNumberOfColums(ord);

	std::vector<std::vector<int>>	matrix_; 

	for (int i = 0; i < matrix->GetNumberOflines(); i++)
	{
		matrix_.push_back(std::vector<int>{});
		for (int j = 0; j < matrix->GetNumbersOfColums(); j++)
		{
			matrix_[i].push_back(std::rand() % 101 - 50);
		}
	}
	matrix->SetMatrix(matrix_);
}

