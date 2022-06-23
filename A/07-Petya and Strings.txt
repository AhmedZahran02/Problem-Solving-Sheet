// made by ahmed zahran 2021

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <cstring>
#include <list>
#include <math.h>
#include <cctype>
#include <climits>
#include <stdio.h>

const double pi = 22.0 / 7.0;

using namespace std;

int main()
{
	string x, y;
	cin >> x;
	cin >> y;
	int sum1 = 0, sum2 = 0;
	for (int  i = 0; i < x.size(); i++)
	{
		x[i]=tolower(x[i]);
		y[i] = tolower(y[i]);
	 if (x[i] > y[i]) {
	cout << 1 << endl;
	return 0;
	}
	else if(x[i]<y[i]){
	cout << -1 << endl;
	return 0;
	}

	}
		cout << 0 << endl;
	
	return 0;
}