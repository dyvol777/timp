// timp lab 2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;

int main()
{
	string buf;
	ifstream file("text.txt");
	getline(file, buf, '\0');
	//cout << buf<<endl<<"nasha rabota"<<endl;
	file.close();
	int size = buf.length();
	int i = 0;

	while(i<size)
	{
		if ((buf[i] == '/') && (buf[i+1] == '*') && (buf[i+2] == '*'))
		{
			i += 3;
			while (buf[i] != '\\')
			{
				i++;
			}

			while ((buf[i] != ' ') && (buf[i] != '\n'))
			{
				i++;
			}
			i++;

			while ((buf[i] != '*') || (buf[i + 1] != '/'))
			{
				if (buf[i] == '\n') cout << ' ';
				else cout<<buf[i];
				i++;
			}
			cout << endl;
			i++;
		}
		i++;
	}
	system("pause");
    return 0;
}

