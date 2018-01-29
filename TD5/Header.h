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
	string type;

public:
	//Constructors
	Option(double _S, double _K , double _T, double _r, double _sigma);
	Option(double _S, double _K, double _T, double _r, double _sigma, string _type);
	Option();

	// Get
	double getr() { return r; }
	double getSigma() { return sigma; }
	double getK() { return K; }
	double getT() { return T; }
	double getS() { return S; }
	string getType() { return type; };

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
	double N_p(double x);
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


class CRR
{
protected:
	double So;    // prix actuel du sous-jacent
	double K;     // prix d'exercice
	double r;     // taux d'interet
	double R;	  //risk-free security
	double T;     // maturité
	double sigma; // volatilité
	int N;        // Nombre d'itération
	int U;		  // facteur up
	int D;		  // facteur down
	string type;
	double payOff(double S, double K, string type)const;

public:
	CRR();
	CRR(double _So, double _K, double _T, double _sigma, const int _N, double _U, double _D, double _R, string _type );
	CRR(Option & o, const int _N, double _U, double _D, double _R);
	//CRRBinomialTree & operator=(const CRRBinomialTree & opt);
	virtual double price();
	virtual void display();
	double riskNeutralProb()const;
	double getSigma() const;
	void setSigma(double sigma);
	double getT() const;
	void setT(double T);
	double getK() const;
	void setK(double K);
	double getSo() const;
	void setSo(double So);
	int getN() const;
	void setN(int N);
	string getType() const;
	void setType(string type);
	virtual ~CRR();

	
};

class EuropeanOption : public CRR {
public:
	EuropeanOption();
	EuropeanOption(double So, double K, double T,
	double sigma, const string type , int n, double U, double D, double R );
	//EuropeanOption(const CRRBinomialTree& opt, const string type = "call");
	double price();
	void display();
	virtual ~EuropeanOption();
};