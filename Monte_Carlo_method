#include <iostream>
#include <string>
#include <bitset>
#include <ctime>
using namespace std;
string code[32767];
int adpt[32767];

int main()
{
	setlocale(LC_ALL, "russian");
	const int L = 15;

	string maxS, old_maxS;
	int i = 0, max = 0, N, old_max;
	srand(time(NULL));

	cout << "Ландшафт поиска:\n\n  кодировка        приспособленность\n" << endl;
	for (int i = 0; i < 32767; i++)
	{
		adpt[i] = i;
		code[i] = bitset<L>(i).to_string();
	}
	for (int i = 0; i < 32; i++)
	{
		cout << code[i] << "       " << adpt[i] << endl;
	}
	cout << "\nВведите число шагов N: ";
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		if (i < N)
		{
			cout << "\nНомер шага i= " << i << ", max = " << max << ", maxS = " << maxS << endl;
			int tmp = rand() % 32767;
			cout << "Случайная кодировка: " << code[tmp] << " и ее приспособленность: " << tmp << endl;
			if (max < tmp)
			{
				old_max = max;
				old_maxS = maxS;
				max = tmp;
				maxS = code[tmp];
				cout << "Произошла смена max:   " << old_max << " --> " << max << "  и maxS:   " << old_maxS << " --> " << maxS << endl;
			}

		}
		else break;
	}
	cout << "\nИтоговый результат:\n" << maxS << "    " << max << endl;
	return 0;
}
