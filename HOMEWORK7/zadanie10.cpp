#include <iostream>
#include <fstream>
#include <string>



using namespace std;


int main()
{

	ifstream file1;
	file1.open("zadanie10(input).txt");

	string x1, x2, x3;
	file1 >> x1 >> x2 >> x3;

	int a1 = x1[0] - 64 - 1;
	int a2 = x1[1] - 48 - 1;

	int b1 = x2[0] - 64 - 1;
	int b2 = x2[1] - 48 - 1;

	int c1 = x3[0] - 64 - 1;
	int c2 = x3[1] - 48 - 1;

	int d[8][8] = { 0 };
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j) {
			if (abs(a1 - j) == abs(a2 - i))
				d[i][j] = 1;
			else
				if (a1 == j || a2 == i)
					d[i][j] = 1;
				else
					if (b1 == j || b2 == i)
						d[i][j] = 1;
					else
						if ((abs(c1 - j) == 1 && abs(c2 - i) == 2) || (abs(c1 - j) == 2 && abs(c2 - i) == 1))
							d[i][j] = 1;
		}
	d[a2][a1] = 0;
	d[b2][b1] = 0;
	d[c2][c1] = 0;
	int ans = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j)
			if (d[i][j] == 1)
				++ans;
	}
	ofstream file2;
	file2.open("zadanie10(output).txt");
	file2 << ans;




	file1.close();
	file2.close();
}