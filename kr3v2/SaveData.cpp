#include "SaveData.h"
#include <fstream>
#include"InputCheck.h"
#include"SaveData.h"
#include "Matrix.h"

void SaveData(std::vector<std::shared_ptr<ISort>>& sorts_case,Matrix matrix)
{
	const int this_file = 1;
	std::string name;
	std::ofstream  FileRecorder;
	FileRecorder.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	std::ifstream CheckFileExist;
	CheckFileExist.exceptions(std::ifstream::badbit | std::ifstream::failbit);

	std::vector <int> array_for_sort = matrix.GetDiagonalElements();

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
		FileRecorder<< std::string(15,' ') << "Comparison" << "\t" << "Swap" << std::endl;
		for (int i = 0; i < sorts_case.size(); i++)
		{
			std::string temp_name = typeid(*sorts_case[i]).name();
			temp_name.erase(0, 6);
			FileRecorder << temp_name << std::string(15 - temp_name.size(),' ') << sorts_case[i]->GetComprasionCounter() << "\t\t" << sorts_case[i]->GetSwapCountrt() << std::endl;;
		}
		for (int i = 0; i < array_for_sort.size(); i++)
			FileRecorder << array_for_sort[i] << " ";
		FileRecorder.close();
}
