#include <iostream>

#include <string>
#include <math.h>
#include "Header.h"
using namespace std;

CRR::CRR() {

}
CRR::CRR(double _So, double _K, double _T, double _sigma, const int _N, double _U, double _D,
	double _R, string _type)
{
	So = _So;
	K = _K;
	T = _T;
	sigma = _sigma;
	N = _N;
	U = _U;
	D = _D;
	R = _R;
	type = _type;
}

CRR::CRR(Option & o, const int _N, double _U, double _D, double _R)
{
	So = o.getS();
	K = o.getK();
	T = o.getT();
	sigma = o.getSigma();
	N = _N;
	U = _U;
	D = _D;
	R = _R;
	type = o.getType();
}


/*CRR & CRR::operator=(const CRRBinomialTree & opt) {
So = opt.So;
K = opt.K;
T = opt.T;
r = opt.r;
sigma = opt.sigma;
N = opt.N;
return *this;
}*/
double CRR::price()
{
	cout << "Option type is not defined" << endl;
	return(0);
}

double CRR::payOff(double S, double K, const string type)const
{
	double price;
	if (type == "call")
		if ((S - K) > 0)
			price = S - K;
		else
			price = 0;
	else
		if ((K - S) > 0)
			price = K - S;
		else
			price = 0;
	return price;
}
void CRR::display()
{

	cout << "Current price (So) : " << So << endl;
	cout << "Strike(K)          : " << K << endl;
	cout << "Maturity(T)        : " << T << endl;
	cout << "Risk-free rate(r)  : " << r << endl;
	cout << "Volatility(sigma)  : " << sigma << endl;
	cout << "Number of steps(N) : " << N << endl;
}
double CRR::riskNeutralProb()const {
	return (R - D) / (U - D);
}


void CRR::setSigma(double sigma) {
	this->sigma = sigma;
}

double CRR::getSigma() const {
	return sigma;
}


void CRR::setT(double T) {
	this->T = T;
}

double CRR::getT() const {
	return T;
}

void CRR::setK(double K) {
	this->K = K;
}

double CRR::getK() const {
	return K;
}

void CRR::setSo(double So) {
	this->So = So;
}

double CRR::getSo() const {
	return So;
}
void CRR::setN(int N) {
	this->N = N;
}

int CRR::getN() const {
	return N;
}

void CRR::setType(std::string type) {
	this->type = type;
}
string CRR::getType() const {
	return type;
}
CRR::~CRR() {

}