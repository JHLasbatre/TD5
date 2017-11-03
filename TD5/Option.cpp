#include <iostream>

#include "Header.h"
using namespace std;

Option::Option(double _r, double _sigma, double _K, double _T, double _S, double _b)
{
	r = _r;
	sigma = _sigma;
	K = _K;
	T = _T;
	S = _S;
	b = _b;
}

void Option::print()
{
	cout << "Option details" << endl;
	cout << "interest rate: " << r << endl;
	cout << "volatility: " << sigma << endl;
	cout << "Strike price: " << K << endl;
	cout << "Expiry date: " << T << endl;
	cout << "Underlying price: " << S << endl;
	cout << "Cost of carry: " << b << endl;
}

