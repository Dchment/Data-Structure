#include <iostream>
#include <ctime>
using namespace std;

bool col[6];
bool diag1, diag2;
int sum;
int row[6];

void print()
{
	for (int i = 0; i < 6; ++i)
	{
		char str[] = {"......\n"};
		str[row[i]] = '*';
		cout << str;
	}
	cout << "------" << endl;
}

void bingo(int k)
{
	if (k >= 6)
	{
		if (diag1 && diag2)
		{
			++sum;
			print();
		}
		return;
	}

	for (int i = 0; i < 6; ++i)
	{
		if (col[i])
		{
			continue;
		}
		if (i == k)
		{
			if (!diag1)
			{
				diag1 = true;
				col[i] = true;
				row[k] = i;
				bingo(k + 1);
				diag1 = false;
				col[i] = false;
			}
		}
		else if (i == 5 - k)
		{
			if (!diag2)
			{
				diag2 = true;
				col[i] = true;
				row[k] = i;
				bingo(k + 1);
				diag2 = false;
				col[i] = false;
			}
		}
		else
		{
			col[i] = true;
			row[k] = i;
			bingo(k + 1);
			col[i] = false;
		}
	}
}

int main()
{
	clock_t t0 = clock();
	bingo(0);
	cout << "Answer:" << sum << endl;
	clock_t t1 = clock();
	cout << "Time:" << double(t1 - t0) / CLOCKS_PER_SEC << "s" << endl;
	return 0;
}
