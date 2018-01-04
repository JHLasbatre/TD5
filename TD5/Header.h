#include <iostream>


using namespace std;


class Option
{
protected:
	double S;
	double K;
	double T;
	double t;
	double r;
	double sigma;

public:
	//Constructors
	Option(double _S, double _K , double _T, double _r, double _sigma);
	Option();

	// Get
	double getr() { return r; }
	double getSigma() { return sigma; }
	double getK() { return K; }
	double getT() { return T; }
	double getS() { return S; }

	// Others
	void print();
	

};


class Pricer
{
protected:
	Option o;

public:
	Pricer(Option o);
	Pricer();
};


class BnS : public Pricer
{
private:
	double d1;
	double d2;

public:
	//Constructor
	BnS(Option o);

	//Other
	double Call();
	double Put();
	double N(double x);
	
};


class MonteCarlo : public Pricer
{
private:
	double Sinit;
	int simulationNumber;

public:
	MonteCarlo(Option & o, int _simulationNumber);
	double europeanCall();
	double europeanPut();
	double asianCall();
	double asianPut();
};

/*
class CRR : public Pricer
{
private:
	double Sinit;

public:
	CRR(Option & o);
};
*/
