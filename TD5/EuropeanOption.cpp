#include "Header.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

EuropeanOption::EuropeanOption() {}
/*EuropeanOption::EuropeanOption(const CRRBinomialTree &opt,
const string _type) :CRRBinomialTree(opt.getSo(), opt.getK(), opt.getT(),
opt.getR(), opt.getSigma(), opt.getN()), type(_type) {
}*/
EuropeanOption::EuropeanOption(double So, double K, double T, double sigma, string type,
	const int N, double U, double D, double R) : CRR(So, K, T, sigma, N, U, D, R, type)
{

}

void EuropeanOption::display() {
	CRR::display();
	cout << " Value of European option " << type << " : " << price() << endl;
	cout << "----------------------------------" << endl;
}

double EuropeanOption::price() {
	const int nbcolumn = N + 1;
	const int nbrow = N + 1;
	int **tree;
	tree = new int*[nbrow];
	for (int i = 0; i < nbrow; i++)
	{
		tree[i] = new int[nbcolumn];
	}
	double q = riskNeutralProb();
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= i; ++j) {
			tree[i][j] = So * pow(U, j) * pow(D, (i - j));
		}
	}
	for (int i = 0; i <= N; ++i)
	{
		tree[N][i] = payOff(tree[N][i], K, type);
	}

	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = 0; j <= i; ++j)
		{
			tree[i][j] = 1 / R * (q * tree[i + 1][j + 1] + (1 - q) * tree[i + 1][j]);
		}
	}
	return tree[0][0];

}

EuropeanOption::~EuropeanOption() {

}