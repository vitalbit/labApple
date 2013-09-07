// TPlab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <time.h>
#include <iostream>

using namespace std;

class Apple
{
	private:
		bool ripe;
		string color;
	public:
		Apple() {
			ripe = true;
			color = "red";
		}
};

class Tree
{
	private:
		vector <Apple> tree;
	public:
		Tree(int n) {
			if (n>5000) n=5000;
			for (int i=0; i<n; i++)
				tree.push_back(*(new Apple()));
		}

		int grow() {
			int high = 5000;
			int x=rand();
			x=x-5000*(x/5000);
			if (tree.size()+x>5000) x=5000-tree.size();
			for (int i=0; i!=x; i++)
				tree.push_back(*(new Apple()));
			return x;
		}

		int count() {
			return tree.size();
		}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Tree *tr = new Tree(0); 
	string cmd="";
	srand(time(NULL));
	while (cmd!="quite")
	{
		cout << "Enter\ngrow  -- for new apples\ncount -- for count of apples\nquite -- for quite" << endl;
		cin >> cmd;
		if (cmd=="grow") 
			cout << "Has grown " << tr->grow() << " apples" << endl;
		else if (cmd=="count") 
			cout << "Tree has " << tr->count() << " apples" << endl;
		else if (cmd!="quite") cout << "Wrong command!" << endl;
	}
	return 0;
}

