#include <iostream>

using namespace std;

int main()
{

	int a[10]{ 1,2,3,4,5,6,7,8,9,10 };

	int k, zd;
	cout << "k= ";
	cin >> k;

	int size = sizeof(a) / sizeof(a[0]);

	for (int i = 0; i < k; i++)
	{
		zd = a[0];
		for (int j = 0; j < size; j++)
		{
			a[j] = a[j + 1];
		}
		a[size - 1] = zd;
	}
	for (int i = 0; i < size; i++)
		cout << a[i];
	cout << endl;
}