// Вариант 4: простая вставка, Шелла со смещениями Д. Шелла
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <random>
#include <Windows.h>
using namespace std;

void insertionSort(int* arr, uint64_t size, uint64_t& C, uint64_t& M){
	for (uint64_t i = 1; i < size; i++){
		M += 1;

		int key = arr[i]; // достаем элемент из массива
		M += 1;
		uint64_t j = i-1;
		M += 1;
		while (j >= 0 && arr[j] > key){ // сдвигаем элементы, которые больше key, на одну позицию вправо
			C += 1;
			arr[j+1] = arr[j];
			M += 1;
			j -= 1;
		}
		
		arr[j+1] = key; // ставим key на место
		M += 1;
	}
}


void shellSort(int* arr, uint64_t size, uint64_t& C, uint64_t& M){
	for (uint64_t gap = size/2; gap > 0; gap /= 2){ // устанавливаем размер смещения
		M += 1;

		for (uint64_t i = gap; i < size; i++){ // 
			M += 1;

			int key = arr[i]; // достаем элемент из массива
			M += 1;
			uint64_t j = i;
			M += 1;
			while (j >= gap && arr[j-gap] > key){ // сдвигаем элементы, которые больше key, на gap позиций вправо
				C += 1;
				arr[j] = arr[j-gap];
				M += 1;
				j -= gap;
			}
			arr[j] = key; // ставим key на место
			M += 1;
		}
	}
}

void merge(int* arr, int left, int mid, int right, uint64_t& C, uint64_t M){
	int lsize = mid - left + 1; // размер подмассивов
	int rsize = right - mid;

	int* larr = new int[lsize]; // левый и правый подмассивы
	int* rarr = new int[rsize];


	for (int i = 0; i < lsize; i++){ // копируем данные в подмассивы
		larr[i] = arr[left+i];
	}
	for (int i = 0; i < rsize; i++){
		rarr[i] = arr[mid+1+i];
	}

	int i = 0, j = 0, k = left; // i - индекс левого подмассива, j - правого, k - исходного
	while(i < lsize && j < rsize){
		if (larr[i] <= rarr[j]){
			arr[k] = larr[i]; // сначала ставим в основной массив меньший из элементов
			i += 1; // больше не рассматриваем этот индекс в подмассиве 
		}
		else{
			arr[k] = rarr[j];
			j += 1;
		}
		k += 1; // переходим на следующий индекс основного массива
	}

	while (i < lsize){ // копируем оставшиеся элементы из подмассивов в основной (если есть)
		arr[k] = larr[i];
		i += 1;
		k += 1;
	}
	while (j < rsize){
		arr[k] = rarr[j];
		j += 1;
		k += 1;
	}

	delete[] larr;
	delete[] rarr;
}


void mergeSort(int* arr, int left, int right, uint64_t& C, uint64_t& M){
	if (left >= right){
		return;
	} 

	int mid = left + (right-left) / 2;
	mergeSort(arr, left, mid, C, M);
	mergeSort(arr, mid+1, right, C, M);

	merge(arr, left, mid, right, C, M);
}


void naturalMergeSort(int* arr, uint64_t size, uint64_t& C, uint64_t& M){
	int* temp = new int[size];

    // // Находим адаптированные длины подмассивов
    // int start = 0; // начало подмассива
    // while (start < size) {
    //     int end = start;
    //     while (end + 1 < size && arr[end] <= arr[end + 1]) { // продолжает ли текущее значение быть <= следующего
    //         end++;
    //     }

    //     // Теперь у нас есть подмассив arr[start..end]
    //     start = end + 1;
    // }

    // Поочередное слияние
    for (uint64_t s = 1; s < size; s *= 2) {
        for (uint64_t leftStart = 0; leftStart < size - 1; leftStart += 2 * s) {
            int middle = min(leftStart + s - 1, size - 1);
            int rightEnd = min((leftStart + 2 * s - 1), (size - 1));
            if (middle < rightEnd) {
                merge(arr, leftStart, middle, rightEnd, C, M);
            }
        }
    }
	delete[] temp;
}


int* copyArray(int* arr, uint64_t size){
	int* arr2 = new int[size];
	for (uint64_t i = 0; i < size; i++){
		arr2[i] = arr[i];
	}
	return arr2;
}


void reverseArray(int* arr, uint64_t size){
	int reversedArr[size] = {};
	for (int64_t i = size-1; i >= 0; i--){
		reversedArr[size-1-i] = arr[i];
	}
	for (uint64_t i = 0; i < size; i++){
		arr[i] = reversedArr[i];
	}
}



void fillArray(int* arr, uint64_t size) {
	random_device rd;
	mt19937 g(rd());
	uniform_int_distribution<> distrib(0, 100); 
	for (uint64_t i = 0; i < size; i++)
		arr[i] = distrib(g);
}


void printArray(int* arr, uint64_t size) {
	for (uint64_t i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	int size = 10;
	int* arr = new int[size];
	uint64_t C = 0; 
	uint64_t M = 0;
	fillArray(arr, size);
	printArray(arr, size);
	//mergeSort(arr, 0, size-1, C, M);
	naturalMergeSort(arr, size, C, M);
	printArray(arr, size);
	delete[] arr;


	//Sleep(5000);
	// for (uint64_t size = 100'000; size <= 500'000; size += 100'000){
	// 	size = 10; // REMOVE
	// 	cout << "size = " << size << endl;
	// 	int* arr1 = new int[size], * arr2 = NULL, * arr3 = NULL, * arr4 = NULL;
	// 	fillArray(arr1, size);
	// 	arr2 = copyArray(arr1, size);
	// 	arr3 = copyArray(arr1, size);
	// 	arr4 = copyArray(arr1, size);

	// 	printArray(arr1, size);
	// 	printArray(arr4, size);

	// 	delete[] arr1;
	// 	delete[] arr2;
	// 	delete[] arr3;
	// 	delete[] arr4;
	// 	break; // REMOVE
	// }
    // return 0;
}