#include <iostream>

#include "Header.h"
using namespace std;

BnS::BnS(Option o, double t))
{
	double r = o.getr();
	double sigma = o.getSigma();
	double K = o.getK();
	double T = o.getT();
	double S = o.getS();
	double b = o.getb();

	d1 = (ln(S/K) + (r+1/2 * sigma* sigma)*(T-t))
}