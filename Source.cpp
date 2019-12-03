#include <iostream>
#include <conio.h>
#include "Header.h"
using namespace std;
int back() {
	int code;
	cout << "Нажмите SPACE, если хотите в меню";
	code = _getch();
	if (code == 32) { main(); }
	else return 0;
}
int l5p()
{
	setlocale(LC_ALL, "Russian");
	int size = 0;
	char* word = new char[size];
	cout << "Алфавит: a;b;c" << endl;
	cout << "Введите слово: ";
	cin >> word;
	cout << endl;
	size = strlen(word);

	for (;;)
	{
		if (strstr(word, "aa"))
		{
			cout << "aa -> a";
			for (int i = 0; i < size - 1; i++)
			{
				if (word[i] == 'a' && word[i + 1] == 'a')
				{
					word[i] = 'a';
					for (int j = i + 1; j < size - 1; j++)
					{
						word[j] = word[j + 1];
					}
					size--;
					word[size] = '\0';
					break;
				}
			}
			cout << "   " << word << endl;
			continue;
		}
		if (strstr(word, "ab"))
		{
			cout << "ab -> aa";
			for (int i = 0; i < size - 1; i++)
			{
				if (word[i] == 'a' && word[i + 1] == 'b')
				{
					word[i] = 'a';
					word[i + 1] = 'a';
					break;
				}
			}
			cout << "   " << word << endl;
			continue;
		}
		if (strstr(word, "bb"))
		{
			cout << "bb -> aa";
			for (int i = 0; i < size - 1; i++)
			{
				if (word[i] == 'b' && word[i + 1] == 'b')
				{
					word[i] = 'a';
					word[i + 1] = 'a';
					break;
				}
			}
			cout << "   " << word << endl;
			continue;
		}

		if (strstr(word, "ba"))
		{
			cout << "ba -> a";
			for (int i = 0; i < size - 1; i++)
			{
				if (word[i] == 'b' && word[i + 1] == 'a')
				{
					word[i] = 'a';
					for (int j = i + 1; j < size - 1; j++)
					{
						word[j] = word[j + 1];
					}
					size--;
					word[size] = '\0';
					break;
				}
			}
			cout << "    " << word << endl;
			continue;
		}
		if (strstr(word, "cc"))
		{
			cout << "cc -> $7";
			for (int i = 0; i < size - 1; i++)
			{
				if (word[i] == 'c' && word[i + 1] == 'c')
				{
					word[i] = '$';
					word[i + 1] = '7';
					break;
				}
			}
			cout << "   " << word << endl;
			continue;
		}
		if (strstr(word, "$7"))
		{
			cout << "$7 -> |";
			for (int i = 0; i < size - 1; i++)
			{
				if (word[i] == '$' && word[i + 1] == '7')
				{
					word[i] = '|';
					for (int j = i + 1; j < size - 1; j++)
					{
						word[j] = word[j + 1];
					}
					size--;
					word[size] = '\0';
					break;
				}
			}
			cout << "    " << word << endl;
			continue;
		}back();
	}
	
}
int l5m()
{
	setlocale(LC_ALL, "Russian");
	int a[1000], d[1000], n, s = 0;
	char b[1000] = { '\0' }, c[1000] = { '\0' };
	cout << "Введите количество цифр" << endl;
	cin >> n;
	cout << "Заполните последовательность натуральными числами" << endl;
	for (int i = 0; i < n; i++)
	{
		while (a[i] < 0) { cin >> a[i]; }
		d[i] = a[i];

	}
	for (int i = 1; i < n - 1; i++)
	{
		int t = a[i];
		int maxi = a[i];
		int nummax = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] > maxi)
			{
				maxi = a[j];
				nummax = j;
			}
		}
		a[i] = maxi;
		a[nummax] = t;
	}
	int sum = a[1];
	for (int i = 1; i < n; i++)
	{
		if (abs(s - sum + a[i]) > abs(s - sum - a[i]))
		{
			sum = sum + a[i];
			for (int j = 1; j < n; j++)
			{
				if (a[i] == d[j])
				{
					b[j - 1] = '+';
				}
			}
		}
		else
		{
			sum = sum - a[i];
			for (int j = 1; j < n; j++)
			{
				if (a[i] == d[j])
				{
					b[j - 1] = '-';
				}
			}
		}
	}
	if (sum == s)
	{
		for (int i = 0; i < n; i++)
		{
			cout << d[i] << b[i];
		}
		cout << "=" << s;
	}
	else
	{
		cout << "Не получилось"<<endl;
	}
	back();
	return 0;
}