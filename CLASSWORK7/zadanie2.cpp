#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Remove(vector<int>& v) //удаляет дубликаты
{
	auto end = v.end();
	for (auto x = v.begin(); x != end; ++x)
	{
		end = remove(x + 1, end, *x);
	}

	v.erase(end, v.end());
}

int main()
{
	vector<int>a1{ 1,5,7,9,11,12 };
	vector<int>a2{ 2,4,5,6,9,10 };

	vector<int>b1;
	vector<int>b2;
	vector<int>b3;


	for (int i = 0; i < a1.size(); i++)
	{
		for (int j = 0; j < a2.size(); j++)
		{
			if (a1[i] == a2[j]) //пересечение
			{
				b2.push_back(a1[i]);
			}
			if (a1[i] != a2[j]) //объединение 
			{
				b1.push_back(a1[i]);
				b1.push_back(a2[j]);
			}
		}
	}

	Remove(b1);
	sort(b1.begin(), b1.end());
	Remove(b2);

	set_difference(a1.begin(), a1.end(), a2.begin(), a2.end(), inserter(b3, b3.end()));//разность

	for (int i = 0; i < b1.size(); i++)
	{
		cout << b1[i] << " "; //объединение 
	}
	cout << endl;

	for (int i = 0; i < b2.size(); i++)
	{
		cout << b2[i] << " "; // пересечение
	}
	cout << endl;

	for (int i = 0; i < b3.size(); i++)
	{
		cout << b3[i] << " "; //разность 
	}
	cout << endl;

}