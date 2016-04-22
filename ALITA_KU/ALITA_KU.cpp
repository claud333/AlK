#include "stdafx.h" 
#include <iostream> 
#include <fstream> 
#include <cstdlib>
using namespace std;
struct komn
{
	char name[20];
	int a;
	int b;
	int S;
	int P;
};



komn* schitivanie(komn *st, char *name,int &i) //�������� ����� 
{
	ifstream fin;
	fin.open(name);
	if (!fin.is_open())
	{
		cout << "error open\n";
		system("pause");
		exit(0);
	}


	int ball;
	
	while (!fin.eof())
	{
		st = (komn*)realloc(st,((i + 1)*sizeof(komn)));
		fin >> st[i].name;
		fin >> st[i].a;
		fin >> st[i].b;
		st[i].S = (st[i].a)*(st[i].b);
		st[i].P = 2 * (st[i].a + st[i].b);
		i++;
	}
	fin.close();

	return st;
	
}
void vivod(komn *a,int dlinna)//����� �� ����� / � ���� 
{
	cout << "1-� ����\n2-�� �����" << endl;
	int x;
	cin >> x;


	int maxS = 0, maxSi;
	int minS = a[0].S, minSi = 0;
	int maxP = 0, maxPi;
	int minP = a[0].P, minPi = 0;
	for (int i = 0;i <dlinna;i++)
	{
		if (maxS < a[i].S) { maxS = a[i].S;maxSi = i; }
		if (minS > a[i].S) { minS = a[i].S;minSi = i; }
		if (maxP < a[i].P) { maxP = a[i].P;maxPi = i; }
		if (minP > a[i].P) { minP = a[i].P;minPi = i; }
	}

	if (x == 2)
	{
		cout << "������������ ������� = " << a[maxSi].name << " " << maxS << endl
			<< "����������� ������� = " << a[minSi].name << " " << minS << endl
			<< "������������ �������� = " << a[maxPi].name << " " << maxP << endl
			<< "������������ �������� = " << a[minPi].name << " " << minP << endl;
	}
	else
	{
		cout << "������� ��� ����� \n";
		char name[20];
		cin >> name;
		ofstream fout(name);
		fout << "������������ ������� = " << a[maxSi].name << " " << maxS << endl
			<< "����������� ������� = " << a[minSi].name << " " << minS << endl
			<< "������������ �������� = " << a[maxPi].name << " " << maxP << endl
			<< "������������ �������� = " << a[minPi].name << " " << minP << endl;
		fout.close();
	}
	system("pause");
}

int main()////
{
	setlocale(0, "rus");
	char file[20];
	cout << "������� ��� �����" << endl;
	cin >> file;
	komn* st;
	st = (komn*)malloc(1);
	int dlinna;
	int i = 0;
	st=schitivanie(st, file,i);
	vivod(st,i);

	return 0;
}


