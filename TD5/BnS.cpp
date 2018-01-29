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

double BnS::N_p(double x)
{
	return( 1.0/pow(M_PI*2, 0.5) * exp(-0.5*pow(x,2)));
}

double BnS::N(double x)
{
	double k = 1.0/(1.0 + 0.2316419*x);
	double k_sum = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937 + k*(-1.821255978 + 1.330274429*k))));

	if (x >= 0.0)
	{
		return (1.0 - (1.0 / (pow(2 * M_PI, 0.5)))*exp(-0.5*x*x) * k_sum);
	}
	else
	{
		return 1.0 - N(-x);
	}
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
	double K = o.getK();
	double T = o.getT();
	double S = o.getS();
	return(K*exp(-r*T)*N(-d2) - S*N(-d1));
}