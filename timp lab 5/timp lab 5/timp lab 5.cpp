// timp lab 5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;

void add(vector<int>& a) 
{
	int k, i;
	cin >> k;
	if (a.size() == 0)
		a.insert(a.begin(), k);
	else 
	{
		for (i = 0; i < a.size(); i++) 
		{
			if (k <= a[i]) 
			{
				a.insert(a.begin() + i, k);
				break;
			}
		}
		if (i == a.size())
			a.push_back(k);
	}
}

int main()
{
	vector<int> tree;
	string data;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> data;
		if (data == "add")
			add(tree);
		if (data == "get")
			cout << tree[0] << endl;
		if (data == "del")
			tree.erase(tree.begin());
	}
	system("pause");
	return 0;
}
