#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>



using namespace std;


int main()
{
	vector <int> a;
	a.clear();
	int n, k;
	ifstream file1;
	file1.open("zadanie2(input).txt");

	file1 >> n;

	for (int i = 0; i < n; i++)
	{
		file1 >> k;
		a.push_back(k);
	}

	int maxx = -101;
	int minn = 101;

	for (int i = 0; i < n; i++)
	{
		int count = std::count(a.begin(), a.end(), a[i]);
		maxx = max(count, maxx);
	}

	for (int i = 0; i < n; i++)
	{
		int count = std::count(a.begin(), a.end(), a[i]);
		if (count == maxx)
			minn = min(minn, a[i]);
	}

	int c = 0;

	for (int j = 0; j < a.size(); ++j)
	{
		if (a[j] == minn)
		{
			a.erase(a.begin() + j);
			c += 1;
			--j;

		}
	}

	for (int i = 0; i < c; i++)
	{
		a.push_back(minn);
	}

	ofstream file2;
	file2.open("zadanie2(output).txt");

	for (int i = 0; i < a.size(); i++)
	{
		file2 << a[i] << " ";
	}

	file1.close();
	file2.close();

}