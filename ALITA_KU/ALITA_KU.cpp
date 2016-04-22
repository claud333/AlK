#include "stdafx.h" 
#include <iostream> 
#include <fstream> 
#include <vector> 
using namespace std;
struct komn
{
	char name[20];
	int a;
	int b;
	int S;
	int P;
};



bool schitivanie(vector<komn> &a, char *name) //открытие фаила 
{
	ifstream fin;
	fin.open(name);
	if (!fin.is_open())
	{
		cout << "error open";
		system("pause");
		return false;
	}


	int ball, i = 0;
	komn dop;
	while (!fin.eof())
	{

		fin >> dop.name;
		fin >> dop.a;
		fin >> dop.b;
		a.push_back(dop);
		a[i].S = (a[i].a)*(a[i].b);
		a[i].P = 2 * (a[i].a + a[i].b);
		i++;
	}
	fin.close();
	return true;
}
void vivod(vector<komn> &a)//вывод на экран / в фаил 
{
	cout << "1-¬ фаил\n2-Ќа экран" << endl;
	int x;
	cin >> x;


	int maxS = 0, maxSi;
	int minS = a[0].S, minSi = 0;
	int maxP = 0, maxPi;
	int minP = a[0].P, minPi = 0;
	for (int i = 0;i < a.size();i++)
	{
		if (maxS < a[i].S) { maxS = a[i].S;maxSi = i; }
		if (minS > a[i].S) { minS = a[i].S;minSi = i; }
		if (maxP < a[i].P) { maxP = a[i].P;maxPi = i; }
		if (minP > a[i].P) { minP = a[i].P;minPi = i; }
	}

	if (x == 2)
	{
		cout << "максимальна€ площадь = " << a[maxSi].name << " " << maxS << endl
			<< "минемальна€ площадь = " << a[minSi].name << " " << minS << endl
			<< "максимальный периметр = " << a[maxPi].name << " " << maxP << endl
			<< "максимальный периметр = " << a[minPi].name << " " << minP << endl;
	}
	else
	{
		cout << "¬ведите им€ фаила \n";
		char name[20];
		cin >> name;
		ofstream fout(name);
		fout << "максимальна€ площадь = " << a[maxSi].name << " " << maxS << endl
			<< "минемальна€ площадь = " << a[minSi].name << " " << minS << endl
			<< "максимальный периметр = " << a[maxPi].name << " " << maxP << endl
			<< "максимальный периметр = " << a[minPi].name << " " << minP << endl;
		fout.close();
	}
	system("pause");
}

int main()////
{
	setlocale(0, "rus");
	char file[20];
	cout << "¬ведите им€ фаила" << endl;
	cin >> file;
	vector<komn> a;
	if (!schitivanie(a, file)) { return 0; }
	vivod(a);

	return 0;
}


