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
		int seeds;
	public:
		Apple() {
			ripe = true;
			color = "red";
			seeds = rand() % 11;
		}
		int getSeeds()
		{
			return seeds;
		}
};

class Tree
{
	private:
		vector <Apple> tree;
		int allSeeds;
	public:
		Tree(int n) {
			allSeeds = 0;
			if (n > 5000) n = 5000;
			for (int i = 0; i < n; i++)
			{
				tree.push_back(*(new Apple()));
				allSeeds += (tree.end()-1)->getSeeds();
			}
		}

		int grow() {
			int high = 5000;
			int x=rand();
			x=x-5000*(x/5000);
			if ((int)tree.size()+x>5000) x=5000-tree.size();
			for (int i=0; i!=x; i++)
			{
				tree.push_back(*(new Apple()));
				allSeeds += (tree.end()-1)->getSeeds();
			}
			return x;
		}

		int shake() {
			int x=rand();
			x=x-5000*(x/5000);
			if ((int)tree.size()-x < 0) x=tree.size();
			for (int i=0; i<x; i++)
			{
				allSeeds-=(tree.end()-1)->getSeeds();
				tree.pop_back();
			}
			return x;
		}

		int count() {
			return tree.size();
		}

		int countSeeds() {
			return allSeeds;
		}
};

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	Tree *tr = new Tree(0); 
	string cmd="";
	while (cmd!="quite")
	{
		cout << "Enter\ngrow  -- for new apples\ncount -- for count of apples\nshake -- for apples down\nseeds -- for count of seeds\nquite -- for quite" << endl;
		cin >> cmd;
		if (cmd=="grow") 
			cout << "Has grown " << tr->grow() << " apples" << endl;
		else if (cmd=="shake")
			cout << tr->shake() << " apples have down" << endl;
		else if (cmd=="count") 
			cout << "Tree has " << tr->count() << " apples" << endl;
		else if (cmd=="seeds")
			cout << "Count of seeds = " << tr->countSeeds() << endl;
		else if (cmd!="quite") cout << "Wrong command!" << endl;
	}
	return 0;
}

//в яблоко добавить количество косточек
//commit
//цвести дереву
//commit