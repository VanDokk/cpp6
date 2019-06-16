#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <string>

using namespace std;

struct CLASS
{
	string fio, number_of_group;
	int academic_perfomance[3], scholarship;
};


int main()
{
	const int SIZE = 4;

	ofstream fout("test1.txt", ios_base::binary);
	ifstream fin("test1.txt", ios_base::binary);
	CLASS cclass[SIZE];	
	
	cclass[0] = { "Gorohovsky Igor Vitalievich", "LAT-183", {90,90,90}, 1369 };
	cclass[1] = { "Bihnevich Konstantin Igorevich", "AT-183", {75,86,68}, 0 };
	cclass[2] = { "Gromov Vladislav Konstantinovich", "AT-183", {60,63,62}, 1200 };
	cclass[3] = { "Levdikov Miroslav Batikovich", "AT-183", {85,87,93}, 1600 };

	cout << "--------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------" << endl;
	for (int i = 0; i < SIZE; i++)
	{		
		int countOfScore = 0;
		fout.write((char*)&cclass[i], sizeof(cclass[i]));
		for (int j = 0; j < 3; j++)
		{
			if (cclass[i].academic_perfomance[j] >= 80) countOfScore++;
		}

		if (countOfScore == 3)
		{
			cout << cclass[i].fio << endl << cclass[i].number_of_group << endl << cclass[i].scholarship << endl << endl;
			cout << "Perfomance: " << endl << endl << "Math: " << cclass[i].academic_perfomance[0] << endl << "Physics: " << cclass[i].academic_perfomance[1] << endl << "c++: " << cclass[i].academic_perfomance[2] << endl;
			cout << "--------------------------------------------------------------" << endl;
			cout << "--------------------------------------------------------------" << endl;
		}
		
	}
	fout.close();
}

