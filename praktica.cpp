#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	ofstream fout;
	ifstream fin;
	fin.open("1.txt");
	fout.open("2.txt");
	int n = 4;
	int m = 4;
	float **mas = new float*[n];// n - строк
	for (int i = 0; i < n; i++)
		mas[i] = new float[m];// m - столбцов
	// вывод матрицы
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			fin >> mas[i][j];
			if (j == m - 1)
				cout << " " << mas[i][j] << endl;
			else
				cout << " " << mas[i][j];
		}
		cout << endl;
		//вычисление нормы матрицы, по строкам
		float *tempmas = new float[n];
		float norma = 0;
		for (int i = 0; i < n; i++)
		{
			tempmas[i] = 0;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				tempmas[i] += abs(mas[i][j]);

		for (int i = 0; i < n; i++)
		{
			for (int j = i+1; j < n;j++)
				if (tempmas[i] >= tempmas[j])
					norma = tempmas[i];
				else
					norma = tempmas[j];
			
		}
		cout << endl;
		fout << "Норма исходной матрицы = ";
		cout << "norma = " << norma << endl;
		fout << norma;
		// характеристика столбцов
		cout << endl;
		float *haraktstolbS = new float[n];
		for (int count = 0; count < n; count++)
			haraktstolbS[count] = 0;

		for (int j = 0; j < n; j++)
		{
			int i = 0;
			int nomer = 1;
			while (nomer<n)
			{
				if (mas[2 * i + 1][j] < 0)
					haraktstolbS[j] += mas[2 * i + 1][j];
				i++;
				nomer = 2 * i + 1;
			}

		}
		// вывод характеристик столбцов
		for (int count = 0; count < n; count++)
			cout << " " << haraktstolbS[count];
		cout << endl;
		cout << endl;
		//перестановка столбцов
		for (int i = 0; i < n; i++)
		{
			for (int j = i+1; j < n; j++)
			{
				if (haraktstolbS[i]>haraktstolbS[j])
				for (int ii = 0; ii < n; ii++)
					swap(mas[ii][i], mas[ii][j]);
			}
		}
		// вывод матрицы
		for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			
			if (j == m - 1)
				cout << " " << mas[i][j] << endl;
			else
				cout << " " << mas[i][j];
		}
		cout << endl;
		fout << ".";
		fout << "Матрица после перестановки столбцов: ";
		for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{

			fout << mas[i][j];
			fout << " ";
		}
		fin.close();
		fout.close();
	for (int i = 0; i < n; i++)
		delete[] mas[i];
	delete[]tempmas;
	delete[]haraktstolbS;
	system("pause");
}