#include <iostream>

using namespace std;


int** AllocMemory(int);
void DisplayMatrix(int**, int);
void FreeHeap(int**, int);
void EnterMatrix(int**, int);
int MaxForSector(int**, int, int, int, int);
void MatrixB(int**, int**, int);


int main()
{
	while (true)
	{
		int n;
		cout << "Enter n - number of lines: " << endl;
		cin >> n;

		system("cls");

		cout << "The matrix A is: " << endl;
		int **a = AllocMemory(n);
		EnterMatrix(a, n);
		system("cls");
		cout << "The matrix A is: " << endl;
		DisplayMatrix(a, n);

		int **b = AllocMemory(n);
		cout << endl << "The matrix B is: " << endl;
		MatrixB(a, b, n);
		DisplayMatrix(b, n);

		system("pause");
		system("cls");

		FreeHeap(a, n);
		FreeHeap(b, n);

		char yes;
		cout << "Would you like to countinie? Press y/Y: " << endl;
		cin >> yes;
		if (yes == 'y' || yes == 'Y')
			continue;
		break;
	}
	return 0;
}

int** AllocMemory(int n)
{
	int **a = new int *[n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	return a;
}

void DisplayMatrix(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(20);
			cout << a[i][j];
		}
		cout << endl;
	}
}

void FreeHeap(int** a, int n)
{
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
}

void EnterMatrix(int** a, int n)
{
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		cout << "a[" << (i + 1) << "][" << (j + 1) << "]=";
		cin >> a[i][j];
	}
}

int MaxForSector(int** a, int n, int row, int col)
{
	int first = col, last = col;
	int max = 0;
	for (int i = row; i < n; i++)
	{
		for (int j = first; j <= last; j++)
		{

			if (a[i][j] > max)
				max = a[i][j];
		}
		if (first > 0) first--;
		if (last < n - 1) last++;
	}
	return max;
}

void MatrixB(int** a, int**b, int n)
{
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		b[i][j] = MaxForSector(a, n, i, j);

}
