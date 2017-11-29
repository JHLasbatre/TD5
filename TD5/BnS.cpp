#include <iostream>

#include "Header.h"

using namespace std;

#define M_PI 3.14159265358979323846


BnS::BnS(Option * o)
{
	this->o = o;

	double r = o.getr();
	double sigma = o.getSigma();
	double K = o.getK();
	double T = o.getT();
	double S = o.getS();
	double t = o.gett();

	d1 = ((log(S / K) + (r + 0.5 * sigma* sigma)*(T - t))) / (sigma* pow(T - t, 0.5));
	d2 = d1 - sigma* pow(T - t, 0.5);
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
	double t = o.gett();
	double S = o.getS();
	return(S*N(d1) - K*exp(-r*(T-t))*N(d2));
}

double BnS::Put()
{
	double r = o.getr();
	double sigma = o.getSigma();
	double K = o.getK();
	double T = o.getT();
	double t = o.gett();
	double S = o.getS();
	return(K * exp(-r*(T-t))*N(-d2) - S*N(-d1));
}