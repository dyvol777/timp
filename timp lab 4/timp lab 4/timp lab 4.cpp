// timp lab 4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
using namespace std;

void prym(int q, int* a, int n)
{
	for (int i = 0; i<n; i++)
		if (a[i] == q)
		{
			cout << i << " ";
			prym(i, a, n);
		}
}


void obr(int q, int* a, int n)
{
	for (int i = 0; i<n; i++)
		if (a[i] == q)
		{
			obr(i, a, n);
		}
	if (q != -1) cout << q << " ";
}

void sim(int q, int* a, int n)
{
	int w = 0;
	for (int i = 0; i<n; i++)
		if (a[i] == q)
		{
			sim(i, a, n);
			if ((!w) && (q != -1)) cout << q << " ";
			w++;
		}
	if (w == 0)
	{
		cout << q << " ";
	}
}


int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i<n; i++)
		cin >> a[i];
	prym(-1, a, n);
	cout << endl;
	obr(-1, a, n);
	cout << endl;
	sim(-1, a, n);
	cout << endl;
	system("pause");
	return 0;
}