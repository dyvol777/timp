// timp lab 7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;

int main()
{
	string lib;
	cin >> lib;

	HINSTANCE h;

	void(*add) (int);
	void(*get) ();
	void(*del) ();

	if (lib == "ocher") h = LoadLibrary(TEXT("ocher.cpp"));
	if (lib == "prior") h = LoadLibrary(TEXT("prior.cpp"));
	if (!h)
	{
		printf("cannot find this lib\n");
		system("pause");
		return 0;
	}
	else {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			string command;
			cin >> command;
			if (command == "add") {
				int n;
				cin >> n;
				add = (void(*) (int))GetProcAddress(h, "add");
				add(n);
			}
			if (command == "get") {
				get = (void(*) ())GetProcAddress(h, "get");
				get();
			}
			if (command == "del") {
				del = (void(*) ())GetProcAddress(h, "del");
				del();
			}
		}
	}

	FreeLibrary(h);

	return 0;
}
