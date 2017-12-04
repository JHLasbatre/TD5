#include <iostream>

#include "Header.h"
using namespace std;


void test()
{
	Option o = Option(100, 95, 1, 0.05, 0.2);
	o.print();
	BnS b = BnS(o);

	//cout << "N: " << b.N(0.5) << endl;

	cout << "result call: " << b.Call() << endl;
	cout << "result put: " << b.Put() << endl;

}


int main()
{
	test();
	return 0;
}