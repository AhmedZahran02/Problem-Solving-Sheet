// made by ahmed zahran 2021 all rights reserved

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

int getnum(string x, int size) {
	int count = 0;
	for (int i = 0; i < size-1; i++)
	{
		if (x[i]==x[i+1])
		{
			count++;
		}
	}
	return count;
}

int main() {
	int nr;
	int num;
	cin >> num;
	string color;
	cin >> color;
	nr = getnum(color,color.length());
	cout << nr << endl;

	return 0;
}