#include <iostream>

#include "Header.h"
using namespace std;


void testBnS()
{
	Option o = Option(100, 95, 1, 0.05, 0.2);
	o.print();
	BnS b = BnS(o);

	//cout << "N: " << b.N(0.5) << endl;

	cout << "result call: " << b.Call() << endl;
	cout << "result put: " << b.Put() << endl;

}

void testMC()
{
	Option o = Option(100, 95, 1, 0.05, 0.2);
	o.print();
	MonteCarlo m = MonteCarlo(o, 1000);
	cout << "result call: " << m.europeanCall() << endl;
	cout << "result put: " << m.europeanPut() << endl;
}

int main()
{
	//testBnS();
	testMC();
	return 0;
}