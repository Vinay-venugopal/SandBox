#include<iostream>
using namespace std;

class base
{
public:
	base()
	{
		//std::cout << "Base Cons" << std::endl;
	}
	~base()
	{
		//std::cout << "Base Dest" << std::endl;
	}

	virtual void display() = 0;


};

class derived : public base
{
public:
	derived()
	{
		//std::cout << "Derived Cons" << std::endl;
	}
	~derived()
	{
		//std::cout << "Derived Dest" << std::endl;
	}

	void display()
	{
		cout << "display from derived!";
	}
};

void test_fun()
{
	base *b = new derived();

	b->display();

}

void test_display(int &x, int& y)
{
	cout << x << endl << y << endl;
}

int main()
{
	int a = 10;
	int b = 20;

	int &c = a;

	test_display(a, b);


	return 0;
}
