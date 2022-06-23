#include <iostream>
#include <string>
#include <cmath>

typedef long long ll;

using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//-------------------------------------------
	
	int n;
	cin >> n;
	int* ar = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n -i-1; j++)
		{
			if (ar[j + 1] < ar[j])
			{
				int temp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << ar[i] << " ";
	}
	return 0;
}