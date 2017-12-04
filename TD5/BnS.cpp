#include <iostream>
#include <math.h>
#include "Header.h"

using namespace std;

#define M_PI 3.14159265358979323846


BnS::BnS(Option o)
{
	double r = o.getr();
	double sigma = o.getSigma();
	double K = o.getK();
	double T = o.getT();
	double S = o.getS();

	d1 = ((log(S / K) + (r + 0.5 * sigma* sigma)*T)) / (sigma* pow(T, 0.5));
	d2 = d1 - sigma* pow(T, 0.5);
}

double BnS::N(double x)
{
	return( 0.5*erfc(-x/pow(2*M_PI  , 0.5))  );
}

double BnS::Call()
{
	double r = o.getr();
	double sigma = o.getSigma();
	double K = o.getK();
	double T = o.getT();
	double S = o.getS();
	return(S*N(d1) - K*exp(-r*T)*N(d2));
}

double BnS::Put()
{
	double r = o.getr();
	double sigma = o.getSigma();
	double K = o.getK();
	double T = o.getT();
	double S = o.getS();
	return(K * exp(-r*T)*N(-d2) - S*N(-d1));
}