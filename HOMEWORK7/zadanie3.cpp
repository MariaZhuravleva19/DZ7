#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int n, k;

	ifstream file1;
	file1.open("zadanie3(input).txt");

	file1 >> n;
	file1 >> k;

	ofstream file2;
	file2.open("zadanie3(output).txt");

	for (int x = 1; ; x++)
	{
		int v = x, c = 0;
		for (; v > 0; c++)
		{
			if (c > n)
				break;
			int t = v;
			v -= v / n;
			v -= t % n;
			if (t % n != k)
				break;
		}
		if (c == n)
		{
			file2 << x;
			break;
		}
	}


	file1.close();
	file2.close();

}