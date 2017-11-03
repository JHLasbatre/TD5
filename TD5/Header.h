#include <iostream>

using namespace std;

class Option
{
private:
	double r;
	double sigma;
	double K;
	double T;
	double S;
	double b;
public:
	//Constructors
	Option(double _r, double _sigma, double _K, double _T, double _S, double _b);

	// Get, Set
		//Get
	double getr() { return r; }
	double getSigma() { return sigma; }
	double getK() { return K; }
	double getT() { return T; }
	double getS() { return S; }
	double getb() { return b; }

	void print();

};

class BnS
{
private:
	double d1;
	double d2;
public:
	BnS(Option o);
	//void print()

};