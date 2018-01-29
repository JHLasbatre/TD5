#include <iostream>

#include "Header.h"
using namespace std;


void testBnS()
{
	Option o = Option(100, 95, 1, 0.05, 0.2);
	o.print();
	BnS b = BnS(o);


	cout << "result call: " << b.Call() << endl;
	cout << "result put: " << b.Put() << endl;

}

void testMC()
{
	Option o = Option(100, 95, 1, 0.05, 0.2);
	o.print();
	MonteCarlo m = MonteCarlo(o, 10000);
	cout << "result call: " << m.europeanCall() << endl;
	cout << "result put: " << m.europeanPut() << endl;
}

void testCRR()
{
	EuropeanOption e = EuropeanOption(100, 95, 1, 0.2, "put", 100, 0.03, -0.03, 0);
	e.display();
}

int main()
{
	testBnS();
	testMC();
	testCRR();
	return 0;
}