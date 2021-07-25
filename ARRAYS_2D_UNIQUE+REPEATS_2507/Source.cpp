#include <iostream>
#include<Windows.h>
using namespace std;
#define UNIQUE_2D
//#define REPEATS_2D

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef UNIQUE_2D
	const int ROWS = 3;
	const int COLS = 5;
	int arr[ROWS][COLS]{};

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			bool unique;
			do
			{
				arr[i][j] = rand() % (ROWS * COLS);
				Sleep(500);
				system("CLS");
				for (int i = 0; i < ROWS; i++)
				{
					for (int j = 0; j < COLS; j++)
					{
						cout << arr[i][j] << "\t";
					}
					cout << endl;
				}

				unique = true;

				for (int a = 0; a <= i; a++)
				{
					for (int b = 0; b < (a == i ? j : COLS); b++)
					{
						if (arr[i][j] == arr[a][b])
						{
							unique = false;
							break;
						}

					}
				}


			} while (!unique);


		}
	}

	/*for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}*/
#endif // UNIQUE_2D

#ifdef REPEATS_2D
	const int ROWS = 3;
	const int COLS = 3;
	int arr[ROWS][COLS]{};

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % (ROWS * COLS);
		}

	}
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << "\t";
		}

		cout << endl;
	}

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			bool already_there = false;
			for (int a = 0; a <= i; a++)
			{
				for (int b = 0; b < (a == i ? j : COLS); b++)
				{
					if (arr[i][j] == arr[a][b])
					{
						already_there = true;
						break;
					}
				}
			}

			if (already_there)continue;
			int count = 1;
			for (int a = i; a < ROWS; a++)
			{
				for (int b = (a == i ? j + 1 : 0); b < COLS; b++)
				{
					if (arr[i][j] == arr[a][b]) count++;
				}
			}

			if (count > 1) printf("Значение %d встречается %d раз\n", arr[i][j], count);
		}
	}
#endif // REPEATS_2D


}