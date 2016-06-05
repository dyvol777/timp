// timp lab 6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;
int main()
{
	int V;
	int E;
	cin >> V;
	cin >> E;
	int N;
	cin >> N;
	bool* visited;
	visited = new bool[V];

	int* distance;
	distance = new int[V];

	int** graf;
	graf = new int*[V];
	for (int i = 0; i < V; i++)
	{
		graf[i] = new int[V];
	}
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			graf[i][j] = 0;

		}
	}
	for (int i = 0; i < E; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		cin >> graf[v1][v2];
	}
	for (int i = 0; i<V; i++)
	{
		distance[i] = INT_MAX; visited[i] = false;
	}

	distance[N] = 0;

	int u = 0;
	for (int i = 0; i<V - 1; i++)
	{

		int min = INT_MAX;
		for (int i = 0; i < V; i++)
		{
			if (!visited[i] && distance[i] <= min)
			{
				min = distance[i]; u = i;
			}
		}

		visited[u] = true;
		for (int i = 0; i < V; i++)
		{
			if (!visited[i] && graf[u][i] && (distance[u] != INT_MAX) && distance[u] + graf[u][i] < distance[i])
			{
				distance[i] = distance[u] + graf[u][i];
			}
		}
	}

	cout << endl;
	for (int i = 0; i < V; i++)
		cout << distance[i] << "  ";
	system("pause");
	return 0;
}

