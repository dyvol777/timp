// timp lab 1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream> 
#include <iostream> 
#include <string> 
using namespace std;


void compare(ifstream& f1, ifstream& f2, string name) {
	string s1, s2;
	int i = 0;
	while (!f1.eof()) 
	{
		i++;
		getline(f1, s1);

		while (!f2.eof()) 
		{
			getline(f2, s2);
			if (s1 == s2) break;
			if (f2.eof())
				cout << "in file " << name << " " << i << " str unic: " << s1 << endl;
		}
		f2.seekg(0);
	}
	f1.seekg(0);
}


void main()
{
	ifstream f1("file1.txt");
	ifstream f2("file2.txt");

	compare(f1, f2, "file1.txt");
	compare(f2, f1, "file2.txt");
	system("pause");
	return;
}
