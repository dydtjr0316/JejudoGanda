#include<iostream>

using namespace std;


int add(int a, int b)
{
	return a + b;
}
double add(double a, double b)
{
	return a + b;
}
long add(long a, long b)
{
	return a + b;
}

template <typename Type>

Type Tem_add(Type A, Type B)
{
	return A + B;
}
class A
{

public:
	int B;
};

template <typename T>
void safedelete(T* p)
{
	delete p;
	p = nullptr;
}
int main()
{

	A* temp = new A();

	safedelete(temp);
	int n1 = 1;
	int n2 = 2;
	
	
	double d1 = 1.1;
	double d2 = 2.1;


	long l1 = 1;
	long l2 = 2;
	cout << Tem_add(n1, n2) << endl;
	cout << Tem_add(d1, d2) << endl;
	cout << Tem_add(l1, l2) << endl;



	return 0;
}