#include <iostream>

#include "Header.h"
using namespace std;


void test()
{
	Option o = Option(0.025, 10, 25, 2, 21, 0.5);
	o.print();
}
int main()
{
	test();
	return 0;
}