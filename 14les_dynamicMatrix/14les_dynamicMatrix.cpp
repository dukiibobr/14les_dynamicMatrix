#include <iostream>
#include <iomanip>
using namespace std;

void initAr(int** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 90 + 10;
		}
	}
}
void showAr(int** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(4) << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "----------------------------------------------------" << endl;
}

void fillOneRow(int* arr, int cols) {
	for (int i = 0; i < cols; i++)
	{
		arr[i] = rand() % 10;
	}
}

int** addToEnd(int** arr, int& rows, int cols) {
	int** temp = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		temp[i] = arr[i];
	}
	temp[rows] = new int[cols];
	fillOneRow(temp[rows], cols);
	delete[]arr;
	rows++;
	return temp;
}

int** addByPos(int** arr, int& rows, int cols, int pos) {
	int** temp = new int* [rows + 1];
	for (int i = 0; i < pos; i++)
	{
		temp[i] = arr[i];
	}
	temp[pos] = new int[cols];
	fillOneRow(temp[pos], cols);
	for (int i = pos + 1; i < rows + 1; i++)
	{
		temp[i] = arr[i - 1];
	}
	delete[]arr;
	rows++;
	return temp;
}

int** addColToEnd(int** arr, int rows, int& cols) {
	int** temp = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		temp[i] = new int[cols + 1];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			temp[i][j] = arr[i][j];
		}

	}
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[]arr;
	for (int i = 0; i < rows; i++)
	{
		temp[i][cols] = 5;
	}
	cols++;
	return temp;
}

int** deleteRow(int** arr, int& rows, int cols) {
	int** temp = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr[rows - 1];
	delete[]arr;
	rows--;
	return temp;
}











int** addToStart(int** arr, int& rows, int cols) {
	int** temp = new int* [rows + 1];
	temp[0] = new int[cols];
	fillOneRow(temp[0], cols);
	for (int i = 0; i < rows; i++)
	{
		temp[i + 1] = arr[i];
	}

	delete[]arr;
	rows++;
	return temp;
}

int** deleteFromStart(int** arr, int& rows, int cols) {
	int** temp = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		temp[i] = arr[i + 1];
	}
	delete[] arr[0];
	delete[]arr;
	rows--;
	return temp;
}

//int** addByPos(int** arr, int& rows, int cols, int pos) {
//	int** temp = new int* [rows + 1];
//	for (int i = 0; i < pos; i++)
//	{
//		temp[i] = arr[i];
//	}
//	temp[pos] = new int[cols];
//	fillOneRow(temp[pos], cols);
//	for (int i = pos + 1; i < rows + 1; i++)
//	{
//		temp[i] = arr[i - 1];
//	}
//	delete[]arr;
//	rows++;
//	return temp;
//}

int** deleteFromPosition(int** arr, int& rows, int cols, int pos) {
	int** temp = new int* [rows - 1];
	for (int i = 0; i < pos; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr[pos];
	for (int i = pos; i < rows-1; i++)
	{
		temp[i] = arr[i + 1];
	}
	delete[]arr;
	rows--;
	return temp;
}


int** addColToStart(int** arr, int rows, int& cols) {
	int** temp = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		temp[i] = new int[cols + 1];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			temp[i][j+1]=arr[i][j] ;
		}

	}
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[]arr;
	for (int i = 0; i < rows; i++)
	{
		temp[i][0] = 5;
	}
	cols++;
	return temp;
}

int** addColToPos(int** arr, int rows, int& cols,int pos) {
	int** temp = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		temp[i] = new int[cols + 1];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (j<pos)
			{
				temp[i][j] = arr[i][j];
			}
			else
			{
				temp[i][j + 1] = arr[i][j];
			}
		}

	}
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[]arr;
	for (int i = 0; i < rows; i++)
	{
		temp[i][pos] = 5;
	}
	cols++;
	return temp;
}


int** deleteColbyPos(int** arr, int rows, int& cols,int pos) {
	int** temp = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		temp[i] =new int[cols-1];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (j<pos)
			{
				temp[i][j] = arr[i][j];
			}
			else if (j>pos)
			{
				temp[i][j-1] = arr[i][j];

			}
		}
	}
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

	delete[]arr;
	cols--;
	return temp;
}
int main()
{

	//int *arr=new int[10];
	//delete[]arr;



	//int rows = 3;
	//int cols = 4;
	////cout << "enter rows: "; cin >> rows;
	////cout << "enter cols: "; cin >> cols;

	//int** arr = new int* [rows];
	//for (int i = 0; i < rows; i++)
	//{
	//	arr[i] = new int[cols];

	//}
	//initAr(arr, rows, cols);
	//showAr(arr, rows, cols);

	//arr = addToEnd(arr, rows, cols);
	//showAr(arr, rows, cols);

	//arr = addToEnd(arr, rows, cols);
	//showAr(arr, rows, cols);

	//arr = addByPos(arr, rows, cols,2);
	//showAr(arr, rows, cols);

	//arr = addColToEnd(arr, rows, cols);
	//showAr(arr, rows, cols);

	//arr = deleteRow(arr, rows, cols);
	//showAr(arr, rows, cols);

	//arr = deleteRow(arr, rows, cols);
	//showAr(arr, rows, cols);

	//for (int i = 0; i < rows; i++)
	//{
	//	delete[] arr[i];
	//}
	//delete[]arr;




	//1 temp rows-1, for temp[i]=arr[i+1] delete[]arr[0]


	int rows = 4;
	int cols = 4;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	initAr(arr, rows, cols);
	showAr(arr, rows, cols);

	//arr = addToStart(arr, rows, cols);
	//showAr(arr, rows, cols);
	//2
	//arr = deleteFromStart(arr, rows, cols);
	//showAr(arr, rows, cols);
	//3
	//arr = deleteFromPosition(arr, rows, cols, 2);
	//showAr(arr, rows, cols);
	//4
	//arr=addColToStart(arr, rows, cols);
	//showAr(arr, rows, cols);
	//5
	//arr = addColToPos(arr, rows, cols,2);
	//showAr(arr, rows, cols);
	//6
	arr=deleteColbyPos(arr, rows, cols, 2);
	showAr(arr, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

}

