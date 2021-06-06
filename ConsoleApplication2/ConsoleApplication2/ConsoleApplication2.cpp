/*
Kiselev Ilia
homework 7
Code::Blocks + MinGW
*/

#include <iostream>
#include <cstdlib>
#include <random>

#define CHEK_NUMBER(x,y) (((x) >= 0 && (x) < (y))? true : false) // Task - 1 //
#define ROWS 10
#define COLUMNS 10
#define SIZE 12
#define ARRAY_ALEMENT_VALUE(name, x, y) (*(*(name + (x)) + (y))) // Task - 2 //
#define ARRAY_LENGHT(link, type) (sizeof(*(link)) / sizeof(type)) // Task - 3 //

void array_random_int(int**, int, int);
void print_array(int**, int, int);

int main(int argc, char** argv)
{
	using namespace std;
	// Task - 1 ======================================================================

	int num_1 = 5;
	int num_2 = 10;

	cout << CHEK_NUMBER(num_1, num_2) << endl;

	// Task - 2 ======================================================================

	int** arr = new int* [ROWS];
	for (int i = 0; i < ROWS; i++) {
		arr[i] = new int[COLUMNS * sizeof(int)];
	}

	array_random_int(arr, ROWS, COLUMNS);

	print_array(arr, ROWS, COLUMNS);

	cout << ARRAY_ALEMENT_VALUE(arr, 5, 7) << endl;

	for (int i = 0; i < ROWS; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	// Task - 3 ======================================================================

	int array_1[SIZE];

	cout << ARRAY_LENGHT(&array_1, int) << endl;

	return 0;
}

void array_random_int(int** array, int rows, int columns) {

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, 99);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			array[i][j] = dist(mt);
		}
	}
}

void print_array(int** array, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << array[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}