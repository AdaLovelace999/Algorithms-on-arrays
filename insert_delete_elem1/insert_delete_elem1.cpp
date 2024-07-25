#include <iostream>
using namespace std;

void deleteElem(int* arr, int& size, int& capacity)
{
	int k;
	cout << endl << "Индекс удаляемого элемента k = ";
	cin >> k;
	if (k >= capacity || k < 0)
	{
		cout << "error" << endl;
	}
	else
	{
		if (capacity == size) //если в массиве заполнены все ячейки
		{
			for (int i = k; i < size - 1; i++)
			{
				arr[i] = arr[i + 1]; //сдвигаем элементы массива влево начиная с (k+1)-го элемента
			}
			arr[capacity - 1] = NULL; //в последнюю освободившуюся ячейку присваиваем 0, 
			//чтобы уничтожить значение, уже скопированное в предыдущую ячейку
			capacity--; //уменьшаем количество элементов массива на 1
		}
		else
		{
			for (int i = k; i < size - 1; i++)
			{
				arr[i] = arr[i + 1]; //сдвигаем элементы массива влево начиная с (k+1)-го элемента
			}
			capacity--; //уменьшаем количество элементов массива на 1
		}

	}
}

void insertElem(int*& arr, int& size, int& capacity)
{
	int k, value;
	cout << endl << "Индекс вставляемого элемента k = " << endl;
	cin >> k;
	cout << endl << "Значение вставляемого элемента value = " << endl;
	cin >> value;
	if (k > capacity || k < 0)
	{
		cout << "error" << endl;
	}
	else
	{
		if (capacity == size) //если в массиве заполнены все ячейки 
		{
			int* newArray = new int[size * 2]; //создаем новый массив с размером вдвое большим прежнего

			for (int i = 0; i < size; i++)
			{
				newArray[i] = arr[i]; //копируем значения в новый массив
			}

			delete[] arr; //освобождаем память из под старого массива
			arr = newArray; //устанавливаем указатель на новый массив
			size *= 2; //удваиваем переменную отвечающую за размер массива

			for (int i = size - 1; i > k; i--)
			{
				newArray[i] = newArray[i - 1]; //сдвигаем элементы нового массива вправо начиная с конца
			}

			newArray[k] = value; //присваиваем на освободившееся k-е место нужное значение
			capacity++; //увеличиваем количество элементов массива на 1
		}
		else // если в массиве еще есть пустые ячейки
		{
			for (int i = size - 1; i > k; i--)
			{
				arr[i] = arr[i - 1]; //сдвигаем элементы массива вправо начиная с конца
			}
			arr[k] = value; //присваиваем на освободившееся k-е место нужное значение
			capacity++; //увеличиваем количество элементов массива на 1
		}

	}
}

void fillArray(int* arr, int size) //заполнение массива ввод пользователя
{

	for (int i = 0; i < size; i++)
	{
		cout << "Введите " << i << "-й элемент массива: " << endl;
		cin >> arr[i];
	}

}

void printArray(int* arr, int& size) //вывод элементов массива
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
}


int main()
{
	setlocale(LC_ALL, "ru");
	int size, capacity;
	cout << "Введите максимальный размер массива " << endl;
	cin >> size;
	int* arr = new int[size];
	cout << "Введите количество элементов, которое должно быть в массиве " << endl;
	cin >> capacity;

	fillArray(arr, capacity);
	cout << "Ваш массив: " << "size = " << size << " capacity = " << capacity << endl;
	printArray(arr, size);

	deleteElem(arr, size, capacity);
	cout << "Ваш массив после удаления элемента: " << "size = " << size << " capacity = " << capacity << endl;
	printArray(arr, size);

	insertElem(arr, size, capacity);
	cout << "Ваш массив после вставки элемента: " << "size = " << size << " capacity = " << capacity << endl;
	printArray(arr, size);

	delete[] arr;
	return 0;
}
