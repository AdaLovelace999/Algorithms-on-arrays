#include <iostream>
using namespace std;

int** createArray(int& rows, int& cols) // функция создает и заполняет двумерный массив (ввод пользователя)
{
	cout << "Введите количество строк:" << endl;
	cin >> rows;
	cout << "Введите количество столбцов:" << endl;
	cin >> cols;

	int** arr = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "Элемент arr[" << i << "][" << j << "]" << "\t";
			cin >> arr[i][j];
		}
		cout << endl;
	}

	return arr;
}

void printArray(int** arr, int rows, int cols) // функция выводит элементы двумерного массива на экран
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

void deleteArray(int** arr, int rows) // функция освобождает память, выделенную под массив
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;
}

void deleteRow(int** arr, int& rows, int& cols) // удаляет строку
{
	int k;
	cout << endl << "Индекс удаляемой строки k = ";
	cin >> k;
	if (k >= rows || k < 0)
	{
		cout << "error" << endl;
	}
	else
	{
		delete[] arr[k]; // освобождаем память, выделенную для k-й строки массива

		for (int i = k; i < rows - 1; i++)
		{
			arr[i] = arr[i + 1]; // ?переадресуем указатели, начиная с k-й строки (сдвигаем строки на 1 позицию вверх, начиная с k-й строки)
		}

		arr[rows - 1] = NULL; // указатель на (rows-1)-ю строку обнуляем (т. е. на последнюю)
		--rows; // уменьшаем текущее количество строк
		cout << "Ваш массив после удаления " << k << "-й строки:" << endl;
		printArray(arr, rows, cols); // выводим измененный массив
	}
}

void deleteCol(int** arr, int& rows, int& cols) // удаляет столбец
{
	int k;
	cout << endl << "Индекс удаляемого столбца k = ";
	cin >> k;
	if (k >= cols || k < 0)
	{
		cout << "error" << endl;
	}
	else
	{
		// выполняем поэлементный сдвиг столбцов
		for (int j = k; j < cols - 1; ++j)
		{
			for (int i = 0; i < rows; ++i)
			{
				arr[i][j] = arr[i][j + 1];
			}
		}

		--cols; // уменьшаем текущее количество столбцов в массиве
		cout << "Ваш массив после удаления " << k << "-го столбца:" << endl;
		printArray(arr, rows, cols); // выводим измененный массив
	}
}


void insertRow() // вставляет строку
{

}


void insertCol() // вставляет столбец
{

}


int main()
{
	setlocale(LC_ALL, "ru");
	int rows, cols;
	int** myArr = createArray(rows, cols);
	cout << "Ваш массив:" << endl;
	printArray(myArr, rows, cols);
	//deleteRow(myArr, rows, cols);
	//deleteCol(myArr, rows, cols);
	deleteArray(myArr, rows);

	return 0;
}
