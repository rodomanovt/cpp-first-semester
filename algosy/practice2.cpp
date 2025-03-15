// Вариант 4: простая вставка, Шелла со смещениями Д. Шелла
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <random>
#include <Windows.h>
#include <chrono>
using namespace std;

void insertionSort(int* arr, uint64_t size, uint64_t& C, uint64_t& M){
	for (uint64_t i = 1; i < size; i++){
		M += 1;

		int key = arr[i]; // достаем элемент из массива
		M += 1;
		uint64_t j = i-1;
		M += 1;
		C += 1;
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
			C += 1;
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
	M += 2;

	int* larr = new int[lsize]; // левый и правый подмассивы
	int* rarr = new int[rsize];
	M += 2;


	for (int i = 0; i < lsize; i++){ // копируем данные в подмассивы
		C += 1;
		larr[i] = arr[left+i];
		M += 1;
	}
	for (int i = 0; i < rsize; i++){
		C += 1;
		rarr[i] = arr[mid+1+i];
		M += 1;
	}

	int i = 0, j = 0, k = left; // i - индекс левого подмассива, j - правого, k - исходного
	M += 3;
	C += 1;
	while(i < lsize && j < rsize){
		C += 1;
		C += 1;
		if (larr[i] <= rarr[j]){
			arr[k] = larr[i]; // сначала ставим в основной массив меньший из элементов
			i += 1; // больше не рассматриваем этот индекс в подмассиве 
			M += 2;
		}
		else{
			arr[k] = rarr[j];
			j += 1;
			M += 2;
		}
		k += 1; // переходим на следующий индекс основного массива
		M += 1;
	}

	C += 1;
	while (i < lsize){ // копируем оставшиеся элементы из подмассивов в основной (если есть)
		C += 1;
		arr[k] = larr[i];
		i += 1;
		k += 1;
		M += 3;
	}
	C += 1;
	while (j < rsize){
		C += 1;
		arr[k] = rarr[j];
		j += 1;
		k += 1;
		M += 3;
	}

	delete[] larr;
	delete[] rarr;
	M += 2;
}


void mergeSort(int* arr, int left, int right, uint64_t& C, uint64_t& M){
	C += 1;
	if (left >= right){
		return;
	} 

	int mid = left + (right-left) / 2;
	M += 1;
	mergeSort(arr, left, mid, C, M);
	mergeSort(arr, mid+1, right, C, M);

	merge(arr, left, mid, right, C, M);
}


void naturalMergeSort(int* arr, uint64_t size, uint64_t& C, uint64_t& M){
	
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
	uniform_int_distribution<> distrib(0, 100); // 0, 100'000'000
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
	// int size = 10;
	// int* arr = new int[size];
	// uint64_t C = 0; 
	// uint64_t M = 0;
	// fillArray(arr, size);
	// printArray(arr, size);
	// //mergeSort(arr, 0, size-1, C, M);
	// naturalMergeSort(arr, size, C, M);
	// printArray(arr, size);
	// delete[] arr;


	Sleep(5000); // warmup
	for (uint64_t size = 100'000; size <= 500'000; size += 100'000){
		cout << "size = " << size << endl;
		int* arr1 = new int[size], * arr2 = NULL, * arr3 = NULL, * arr4 = NULL;
		fillArray(arr1, size);
		arr2 = copyArray(arr1, size);
		arr3 = copyArray(arr1, size);
		arr4 = copyArray(arr1, size);

		// insertion sort
		// average
		uint64_t insertionAverageC = 0;
		uint64_t insertionAverageM = 0;
		auto start = chrono::steady_clock::now();
		insertionSort(arr1, size, insertionAverageC, insertionAverageM);
		auto end = chrono::steady_clock::now();
		chrono::duration<double> insertionAverageTime = end - start;
		// best
		uint64_t insertionBestC = 0;
		uint64_t insertionBestM = 0;
		start = chrono::steady_clock::now();
		insertionSort(arr1, size, insertionBestC, insertionBestM);
		end = chrono::steady_clock::now();
		chrono::duration<double> insertionBestTime = end - start;
		// worst
		reverseArray(arr1, size);
		uint64_t insertionWorstC = 0;
		uint64_t insertionWorstM = 0;
		start = chrono::steady_clock::now();
		insertionSort(arr1, size, insertionWorstC, insertionWorstM);
		end = chrono::steady_clock::now();
		chrono::duration<double> insertionWorstTime = end - start;
		cout << "Average insertion: C = " << insertionAverageC << "; M = " << insertionAverageM << "; T = " << insertionAverageTime.count() << endl;
		cout << "Best insertion: C = " << insertionBestC << "; M = " << insertionBestM << "; T = " << insertionBestTime.count() << endl;
		cout << "Worst insertion: C = " << insertionWorstC << "; M = " << insertionWorstM << "; T = " << insertionWorstTime.count() << endl;

		// shell sort
		// average
		uint64_t shellAverageC = 0;
		uint64_t shellAverageM = 0;
		start = chrono::steady_clock::now();
		shellSort(arr2, size, shellAverageC, shellAverageM);
		end = chrono::steady_clock::now();
		chrono::duration<double> shellAverageTime = end - start;
		// best
		uint64_t shellBestC = 0;
		uint64_t shellBestM = 0;
		start = chrono::steady_clock::now();
		shellSort(arr2, size, shellBestC, shellBestM);
		end = chrono::steady_clock::now();
		chrono::duration<double> shellBestTime = end - start;
		// worst
		reverseArray(arr2, size);
		uint64_t shellWorstC = 0;
		uint64_t shellWorstM = 0;
		start = chrono::steady_clock::now();
		shellSort(arr2, size, shellWorstC, shellWorstM);
		end = chrono::steady_clock::now();
		chrono::duration<double> shellWorstTime = end - start;
		cout << "Average shell: C = " << shellAverageC << "; M = " << shellAverageM << "; T = " << shellAverageTime.count() << endl;
		cout << "Best shell: C = " << shellBestC << "; M = " << shellBestM << "; T = " << shellBestTime.count() << endl;
		cout << "Worst shell: C = " << shellWorstC << "; M = " << shellWorstM << "; T = " << shellWorstTime.count() << endl;

		// merge sort
		// average
		uint64_t mergeAverageC = 0;
		uint64_t mergeAverageM = 0;
		start = chrono::steady_clock::now();
		mergeSort(arr3, 0, size-1, mergeAverageC, mergeAverageM);
		end = chrono::steady_clock::now();
		chrono::duration<double> mergeAverageTime = end - start;
		// best
		uint64_t mergeBestC = 0;
		uint64_t mergeBestM = 0;
		start = chrono::steady_clock::now();
		mergeSort(arr3, 0, size-1, mergeBestC, mergeBestM);
		end = chrono::steady_clock::now();
		chrono::duration<double> mergeBestTime = end - start;
		// worst
		reverseArray(arr3, size);
		uint64_t mergeWorstC = 0;
		uint64_t mergeWorstM = 0;
		start = chrono::steady_clock::now();
		mergeSort(arr3, 0, size-1, mergeWorstC, mergeWorstM);
		end = chrono::steady_clock::now();
		chrono::duration<double> mergeWorstTime = end - start;
		cout << "Average merge: C = " << mergeAverageC << "; M = " << mergeAverageM << "; T = " << mergeAverageTime.count() << endl;
		cout << "Best merge: C = " << mergeBestC << "; M = " << mergeBestM << "; T = " << mergeBestTime.count() << endl;
		cout << "Worst merge: C = " << mergeWorstC << "; M = " << mergeWorstM << "; T = " << mergeWorstTime.count() << endl;


		delete[] arr1;
		delete[] arr2;
		delete[] arr3;
		delete[] arr4;
	}
    return 0;
}