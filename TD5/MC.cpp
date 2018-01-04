#include <iostream>
#include <random>
#include <algorithm>

#include "Header.h"

using namespace std;

MonteCarlo::MonteCarlo(Option & o, int _simulationNumber)
{
	double r = o.getr();
	double sigma = o.getSigma();
	double T = o.getT();
	double S = o.getS();
	Sinit = S * exp((r - 0.5 * sigma * sigma) * T);
	simulationNumber = _simulationNumber;
}


double MonteCarlo::europeanCall()
{
	default_random_engine generator;
	normal_distribution<double> distribution(0, 1);
	double r = o.getr();
	double sigma = o.getSigma();
	double T = o.getT();
	double K = o.getK();
	double Z;
	double Sk;
	double price = 0;
	for (int i = 0; i < simulationNumber; i++)
	{
		Z = distribution(generator);
		Sk = Sinit * exp( (r - pow(sigma, 2)/2)*T   + sigma * sqrt(T) * Z);
		price += max(Sk - K, 0.0);
	}
	return( (1/(double)simulationNumber) * exp(-r*T) * price );
}

double MonteCarlo::europeanPut()
{
	default_random_engine generator;
	normal_distribution<double> distribution(0, 1);
	double r = o.getr();
	double sigma = o.getSigma();
	double T = o.getT();
	double K = o.getK();
	double Z;
	double Sk;
	double price = 0;
	for (int i = 0; i < simulationNumber; i++)
	{
		Z = distribution(generator);
		Sk = Sinit * exp((r - pow(sigma, 2) / 2)*T + sigma * sqrt(T) * Z);
		price += max(K - Sk, 0.0);
	}
	return ( (1 / (double)simulationNumber) * exp(-r*T) * price) ;
}

double MonteCarlo::asianCall()
{
	default_random_engine generator;
	normal_distribution<double> distribution(0, 1);
	double r = o.getr();
	double sigma = o.getSigma();
	double T = o.getT();
	double K = o.getK();
	double Z;
	vector<double> Sk;
	double price = 0;
	for (int i = 0; i < simulationNumber; i++)
	{
		Z = distribution(generator);
		Sk[i] = Sinit * exp((r - pow(sigma, 2) / 2)*T + sigma * sqrt(T) * Z);
		price += asianPayoff();
	}
	return ((1 / (double)simulationNumber) * exp(-r*T) * price);
}


/*
double MontecarloPrice(double So, double t, double k, double r, double sigma, double n, int Opt, int Optype)
{
	double resul;
	double Price;
	double Sk;
	double listprice();
	//ReDim listprice(n)
	double Z;
	//Randomize utiliser pour initialiser des nombres vraiment aléatoire
	double Sinit = So * exp((r - 0.5 * sigma * sigma) * t);
	Price = 0;
	if (Optype = 0)
	{
		if (Opt = 0) {
			for (int i = 1; i <= n; i++)
			{
				Z = Application.WorksheetFunction.NormSInv(Rnd)
					Sk = Sinit * Exp(sigma * Sqr(t) * Z)
					Price = Price + Application.WorksheetFunction.Max((Sk - k), 0)
			}
		}
		If(Opt = 1) {
			For i = 1 To n{
				Z = Application.WorksheetFunction.NormSInv(Rnd)
				Sk = Sinit * Exp(sigma * Sqr(t) * Z)
				Price = Price + Application.WorksheetFunction.Max((k - Sk), 0)
			}
		}
	}
	If(Optype = 1) {
		If(Opt = 0) {
			For i = 1 To n{
				Z = Application.WorksheetFunction.NormSInv(Rnd)
				listprice(i) = Sinit * Exp(sigma * Sqr(t) * Z)
				Price = Price + AsianPayoff(k, listprice, i, 0)
			}
		}
		If(Opt = 1) {
			For i = 1 To n{
				Z = Application.WorksheetFunction.NormSInv(Rnd)
				listprice(i) = Sinit * Exp(sigma * Sqr(t) * Z)
				Price = Price + AsianPayoff(k, listprice, i, 1)
			}
		}
	}
	resul = (Exp(-r * t) / n) * Price
		MontecarloPrice = resul
}
*/