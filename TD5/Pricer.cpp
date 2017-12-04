#include <iostream>

#include <math.h>
#include "Header.h"

using namespace std;

Pricer::Pricer(Option _o) 
{
	o = _o;
}

Pricer::Pricer()
{
	o = Option();
}



