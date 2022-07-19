#include "Matrix.h"
#include <iostream>
#include <memory>
#include <vector>
#include "ISort.h"
#include "MatrixInput.h"
#include "ComparisonTable.h"
#include "InitialMatrixFileOutput.h"
#include"SaveData.h"




int main()
{
	int sorts_count = 5;
	int input_type;
	const int byhands = 1;
	const int random = 2;
	const int yes = 1;
	const int no = 2;
	int choiñe = 0;
	int continue_choice = 0;
	while (true)
	{
		std::cout << "Ershov Alex 415 var 9 kr 2 " << std::endl
			<< "Sort the diagonal elements of the matrix by ascending." << std::endl;
		
		std::vector < std::shared_ptr<ISort>> sort_case;

		Matrix matrix;
		input_type = MatrixInput(&matrix);
		std::vector < std::shared_ptr<Matrix>> sorts_matrices;

		for (int i = 0; i < sorts_count; i++)
		{
			sorts_matrices.emplace_back(std::make_shared<Matrix>(matrix));
		}
		matrix.Show();
		ComparisonTable(sort_case, sorts_matrices);

		for (int i = 0; i < sorts_count; i++)
		{
			std::string temp_name = typeid(*sort_case[i]).name();
			temp_name.erase(0, 6);
			std::cout << "\n" << temp_name << std::endl;;
			sorts_matrices[i]->Show();
		}

		if (input_type == byhands || input_type == random)
		{
			std::cout << "Do you want to save the original matrix data to a file ?" << std::endl; 
			std::cout << "1 - yes\n2 - no" << std::endl;
			choiñe = InputCheck::CheckMenu(2);
			if (choiñe == yes)
				InitialMatrixFileOutput(matrix);			
		}

		std::cout << "Do you want to save the sort comparison table to a file ?" << std::endl;
		std::cout << "1 - yes\n2 - no" << std::endl;
		choiñe = InputCheck::CheckMenu(2);
		if (choiñe == yes)
			SaveData(sort_case,matrix);

		system("pause");
		
		std::cout << "Continue?" << std::endl;
		std::cout << "1 - yes\n2 - no" << std::endl;
		continue_choice = InputCheck::CheckMenu(2);
		if (continue_choice == no) return 0;
	}
}