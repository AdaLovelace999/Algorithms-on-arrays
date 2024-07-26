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

void printArray(int** arr, int &rows, int &cols) // функция выводит элементы двумерного массива на экран
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

void deleteArray(int** arr, int &rows) // функция освобождает память, выделенную под массив
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


void insertRow(int**& arr, int& rows, int& cols) // вставляет строку
{
	int k;
	cout << endl << "Индекс вставляемой строки k = ";
	cin >> k;
	if (k > rows || k < 0)
	{
		cout << "error" << endl;
	}
	else
	{
		int** newArray = new int* [2 * rows]; // создаем новый массив с удвоенным количеством строк
		for (int i = 0; i < rows; i++)
		{
			newArray[i] = new int[cols]; 
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				newArray[i][j] = arr[i][j]; // копируем значения в новый массив
			}
		}
		deleteArray(arr, rows); //освобождаем память из под старого массива
		arr = newArray; //устанавливаем указатель на новый массив

		// выполняем сдвиг строк вниз, начиная с последней до k-й
		for (int i = rows; i > k; --i) 
		{
			newArray[i] = newArray[i - 1];
		}
		++rows; // увеличиваем текущее количество строк в массиве
		
		// выделяем память под новую строку массива и заполняем ее
		newArray[k] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			cout << "newArray[" << k << "][" << j << "] = ";
			cin >> newArray[k][j];
		}
		cout << "Ваш массив после добавления " << k << "-й строки:" << "число строк = " << rows << " число столбцов = " << cols << endl;
		printArray(newArray, rows, cols); // выводим измененный массив
	}
}


void insertCol(int** &arr, int& rows, int& cols) // вставляет столбец
{
	int k;
	cout << endl << "Индекс вставляемого столбца k = ";
	cin >> k;
	if (k > cols || k < 0)
	{
		cout << "error" << endl;
	}
	else 
	{
		int** newArray = new int* [rows]; // создаем новый массив
		
		for (int i = 0; i < rows; i++)
		{
			newArray[i] = new int[2 * cols]; // в новом массиве удваиваем количество столбцов
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++) 
			{
				newArray[i][j] = arr[i][j]; // копируем значения в новый массив
			}
		}
		deleteArray(arr, rows); //освобождаем память из под старого массива
		arr = newArray; //устанавливаем указатель на новый массив
		
		// выполняем поэлементный сдвиг столбцов вправо, начиная с последнего до k-го
		for (int j = cols; j > k; --j)
		{
			for (int i = 0; i < rows; i++) 
			{
				newArray[i][j] = newArray[i][j - 1]; //?
			}
		}
		++cols; // увеличиваем текущее количество столбцов в массиве на 1

		for (int i = 0; i < rows; i++) // вводим новые данные в k-й столбец 
		{
			cout << "newArray[" << i << "][" << k << "] = ";
			cin >> newArray[i][k]; //?
		}
		cout << "Ваш массив после добавления " << k << "-го столбца:" << "число строк = " << rows << " число столбцов = " << cols << endl;
		printArray(newArray, rows, cols); // выводим измененный массив
	}
}


int main()
{
	setlocale(LC_ALL, "ru");
	int rows, cols;
	int** myArr = createArray(rows, cols);
	cout << "Ваш массив " << "число строк = "<< rows << " число столбцов = " << cols << endl;
	printArray(myArr, rows, cols);
	//deleteRow(myArr, rows, cols);
	//deleteCol(myArr, rows, cols);
	//insertCol(myArr, rows, cols);
	//insertRow(myArr, rows, cols);
	deleteArray(myArr, rows);

	return 0;
}
