#include<iostream>
#include<vector>
#include"tag.h"
using namespace std;



const int& GetReference(const int & key)
{
	return key;
}

int Get(const int& key)
{
	return key;
}

int GetConst(const int& key)
{
	return key;
}

int main()
{
	//int n1 = 1;
	//int n2 = 2;
	//int n3 = 3;

	//cout << GetReference(n1) << endl;
	//cout << Get(n2) << endl;
	//cout << GetConst(n3) << endl;


	return 0;
}