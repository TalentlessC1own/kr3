#include "InitialMatrixFileOutput.h"

void InitialMatrixFileOutput(Matrix matrix)
{
	const int this_file = 1;
	std::string name;
	std::ofstream  FileRecorder;
	FileRecorder.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	std::ifstream CheckFileExist;
	CheckFileExist.exceptions(std::ifstream::badbit | std::ifstream::failbit);

	while (true)
	{
		std::cout << "Enter file name or full way." << std::endl << "ENTER:";
		std::getline(std::cin, name);
		if (name.find(".txt") >= std::string::npos) {
			std::cout << "Wrong data type\n" << std::endl;
			continue;
		}
		try
		{
			CheckFileExist.open(name);
			std::cout << "A file with the same name already exists. " << std::endl
				<< "1 - Save in this file " << std::endl
				<< "2 - Chose another name " << std::endl;
			int var = InputCheck::CheckMenu(2);
			if (var == this_file)
			{
				FileRecorder.open(name);
				CheckFileExist.close();
			}
			else
			{
				CheckFileExist.close();
				continue;
			}
		}
		catch (const std::exception&)
		{
			try
			{
				FileRecorder.open(name);
			}
			catch (const std::exception&)
			{
				std::cout << "Access error" << std::endl;
				continue;
			}

		}
		break;


	}

	int _number_of_lines = matrix.GetNumberOflines();
	int _number_of_colums = matrix.GetNumbersOfColums();
	std::vector<std::vector<int>> _matrix = matrix.GetMatrix();

	FileRecorder << _number_of_lines << std::endl;
	FileRecorder << _number_of_colums << std::endl;
	for (int i = 0; i < _number_of_lines; i++)
	{
		for (int j = 0; j < _number_of_colums; j++)
		{
			FileRecorder << _matrix[i][j] << std::endl;
		}
	}
	FileRecorder.close();
}

