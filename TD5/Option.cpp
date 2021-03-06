#include <iostream>
#include <string>

#include "Header.h"
using namespace std;

Option::Option(double _S, double _K, double _T, double _r, double _sigma)
{
	r = _r;
	sigma = _sigma;
	K = _K;
	T = _T;
	S = _S;
}

Option::Option(double _S, double _K, double _T, double _r, double _sigma, string _type)
{
	r = _r;
	sigma = _sigma;
	K = _K;
	T = _T;
	S = _S;
}


Option::Option()
{
	r = 0.05;
	sigma = 0.2;
	K = 95;
	T = 1;
	S = 100;
}

void Option::print()
{
	cout << "Option details\n" << "----------------------------" << endl;

	cout << "interest rate: " << r << endl;
	cout << "volatility: " << sigma << endl;
	cout << "Strike price: " << K << endl;
	cout << "Expiry date: " << T << endl;
	cout << "Underlying price: " << S << endl;
}

