#include <iostream>
#include <vector>
#include "LinkedList.h"
using namespace std;
void insertAfter(int first, int second, vector <int> &vec);
LinkedList create(vector<int> v);

int main()
{
	int n, v, v1, v2;
	cout << "Enter a number: ";
	cin >> n;
	vector <int> vec;
	
	for (int i = 0; i < n; i++)
	{
		cout << "Enter element " << i + 1 << ": ";
		cin >> v;
		vec.push_back(v);
	}

	cout << "Enter first value: ";
	cin >> v1;
	cout << "Enter second value: ";
	cin >> v2;

	insertAfter(v1, v2, vec);

	create(vec).printAll();
	cout << endl << "sum: " << create(vec).sum();

	return 0;
}

void insertAfter(int first, int second, vector <int> &vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == first)
			vec.insert(vec.begin()+i+1, second);
	}
}

LinkedList create(vector<int> vec)
{
	LinkedList l;
	for (int i = 0; i < vec.size(); i++)
	{
		if (!l.isFound(vec[i]))
		{
			l.addNode(vec[i]);
		}
	}
	return l;
}



