#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct NumberNode
{
	int value;
	int numChildren = 0;
	NumberNode *children[10];

	NumberNode(int value) : value(value)
	{
		for (int i = 0; i < 10; i++)
		{
			children[i] = nullptr;
		}
	}

	~NumberNode()
	{
		for (int i = 0; i < 10; i++)
		{
			delete children[i];
		}
	}

	bool HasChild(int val)
	{
		return children[val] != nullptr;
	}

	NumberNode *GetNode(int id)
	{
		if (HasChild(id))
		{
			return children[id];
		}

		NumberNode *node = new NumberNode(id);
		children[id] = node;
		numChildren++;
		return node;
	}

	int CountDescendants()
	{
		int count = numChildren;
		for (int i = 0; i < 10; i++)
		{
			if (children[i])
			{
				count += children[i]->CountDescendants();
			}
		}

		return count;
	}
};

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/
int main()
{
	NumberNode root(-1);

	int N;
	cin >> N; cin.ignore();
	for (int i = 0; i < N; i++) {
		string telephone;
		cin >> telephone;
		cin.ignore();

		NumberNode *node = &root;
		for (string::iterator it = telephone.begin(); it != telephone.end(); it++)
		{
			int n = *it - '0';
			node = node->GetNode(n);
		}
	}

	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;

	cout << root.CountDescendants() << endl; // The number of elements (referencing a number) stored in the structure.
}