#include <iostream>
#include <vector>


using namespace std;
int Convert_first(int in, int num) //перевод в 10 сс
{
	int t = 0, dec = 0;
	for (int n = num; n >= 1; n /= 10)
	{
		dec += (n % 10) * int(pow(in, t++));
	}
	return dec;
}

string Convert_second(int end_base, int n) //перевод из 10 в любую сс
{
	string alpha = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string res;
	while (n > 0)
	{
		res = alpha[n % end_base] + res;
		n = n / end_base;
	}
	cout << res << endl;
}

int main()
{
	int a, b, n1 = 0, n2;
	cin >> a >> b;
	vector <int> chis{ 1, 1, 1, 0, 0 };
	for (int i = 0; i < chis.size(); i++)
	{
		n1 *= 10;
		n1 += chis[i];
	}

	n2 = Convert_first(a, n1);
	Convert_second(b, n2);
}