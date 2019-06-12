#include "static_lib.hpp"

void Func_Read_File(std::string NameOfFile, std::vector<int> *RefVector)
{
	char TmpChar;
	int TmpInt;
	int i;
	std::ifstream WorkFile;
	WorkFile.open(NameOfFile);
	WorkFile.seekg (0, std::ios::end);
  	int Lenght = WorkFile.tellg();
	WorkFile.seekg (0, std::ios::beg);
	for(i=0;i<Lenght;i++)
	{
		WorkFile >> TmpChar;
		TmpInt = TmpChar - '0';
		(*RefVector).push_back(TmpInt);
	}
	WorkFile.close();
}

void Func_Write_File(std::string NameOfFile, std::vector<int> *RefVector)
{
	std::ofstream OutFile(NameOfFile);
	for (int i = 0; i < (*RefVector).size(); i++)
	{
		OutFile << (*RefVector)[i];
	}
	OutFile.close();
}