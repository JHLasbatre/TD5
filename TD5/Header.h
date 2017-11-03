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
	Option(double _r, double _sigma, double _K, double _T, double _S, double _b);
	void print();
};