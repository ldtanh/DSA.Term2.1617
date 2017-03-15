#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;

void InsertionSort(long*, long);
void MergeSort(long*, long, long);
void QuickSort(long*, long, long);
void RadixSort(long*, long);

int main()
{
	long Arr1[10000];
	for (int i = 1; i <= 10000; i++)
		Arr1[i - 1] = i;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	InsertionSort(Arr1, 10000);
	//MergeSort(Arr1, 0, 9999);
	//QuickSort(Arr1, 0, 9999);
	//RadixSort(Arr1, 10000);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(t2 - t1).count();
	cout << duration << endl;


	//long Arr2[10000];
	//for (int i = 0; i < 10000; i++)
	//	Arr2[i] = 10000 - i;
	//high_resolution_clock::time_point t1 = high_resolution_clock::now();
	//InsertionSort(Arr2, 10000);
	////MergeSort(Arr2, 0, 9999);
	////QuickSort(Arr2, 0, 9999);
	////RadixSort(Arr2, 10000);
	//high_resolution_clock::time_point t2 = high_resolution_clock::now();
	//auto duration = duration_cast<microseconds>(t2 - t1).count();
	//cout << duration << endl;


	//long Arr3[10000];
	//srand(time(NULL));
	//high_resolution_clock::time_point t1 = high_resolution_clock::now();
	//for (int rep = 0; rep < 10; rep++)
	//{
	//	for (int i = 0; i < 10000; i++)
	//		Arr3[i] = rand() % 10000 + 1;		
	//	InsertionSort(Arr3, 10000);
	//	//MergeSort(Arr3, 0, 9999);
	//	//QuickSort(Arr3, 0, 9999);
	//	//RadixSort(Arr3, 10000);	
	//}
	//high_resolution_clock::time_point t2 = high_resolution_clock::now();
	//auto duration = duration_cast<microseconds>(t2 - t1).count();
	//cout << duration << endl;


	//long Arr4[20000];
	//srand(time(NULL));
	//high_resolution_clock::time_point t1 = high_resolution_clock::now();
	//for (int rep = 0; rep < 10; rep++)
	//{
	//	for (int i = 0; i < 20000; i++)
	//		Arr4[i] = rand() % 20000 + 1;
	//	InsertionSort(Arr4, 20000);
	//	//MergeSort(Arr4, 0, 19999);
	//	//QuickSort(Arr4, 0, 19999);
	//	//RadixSort(Arr4, 20000);	
	//}
	//high_resolution_clock::time_point t2 = high_resolution_clock::now();
	//auto duration = duration_cast<microseconds>(t2 - t1).count();
	//cout << duration << endl;


	//long Arr5[30000];
	//srand(time(NULL));
	//high_resolution_clock::time_point t1 = high_resolution_clock::now();
	//for (int rep = 0; rep < 10; rep++)
	//{
	//	for (int i = 0; i < 30000; i++)
	//		Arr5[i] = rand() % 30000 + 1;
	//	InsertionSort(Arr5, 30000);
	//	//MergeSort(Arr5, 0, 29999);
	//	//QuickSort(Arr5, 0, 29999);
	//	//RadixSort(Arr5, 30000);	
	//}
	//high_resolution_clock::time_point t2 = high_resolution_clock::now();
	//auto duration = duration_cast<microseconds>(t2 - t1).count();
	//cout << duration << endl;


	//long *Arr6 = new long[5000000];;
	//srand(time(NULL));
	//high_resolution_clock::time_point t1 = high_resolution_clock::now();
	//for (int rep = 0; rep < 10; rep++)
	//{
	//	for (int i = 0; i < 5000000; i++)
	//		Arr6[i] = rand() % 5000000 + 1;
	//	InsertionSort(Arr6, 5000000);
	//	//MergeSort(Arr6, 0, 4999999);
	//	//QuickSort(Arr6, 0, 4999999);
	//	//RadixSort(Arr6, 5000000);	
	//}
	//high_resolution_clock::time_point t2 = high_resolution_clock::now();
	//auto duration = duration_cast<microseconds>(t2 - t1).count();
	//cout << duration << endl;
	//

	//delete Arr6;

	return 0;
}

void Swap(long &value1, long &value2)
{
	long Temp = value1;
	value1 = value2;
	value2 = Temp;
}

void InsertionSort(long* arr, long size)
{
	long key, i, j;
	for (i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;
		while ((j >= 0) && (arr[j] > key))
			arr[j + 1] = arr[j--];
		arr[j + 1] = key;
	}
}

void Merge(long* arr, long left, long mid, long right)
{
	long *Temp = new long[right - left + 1];
	long i, j, k;
	for (i = 0, j = left, k = mid + 1; (j <= mid && k <= right); i++)
	{
		if (arr[j] < arr[k])
			Temp[i] = arr[j++];
		else
			Temp[i] = arr[k++];
	}
	while (j <= mid)
		Temp[i++] = arr[j++];
	while (k <= right)
		Temp[i++] = arr[k++];
	for (i = 0; i <= right - left; i++)
		arr[i + left] = Temp[i];
	delete Temp;
}

void MergeSort(long* arr, long left, long right)
{
	long mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge(arr, left, mid, right);
	}
}

long Partition(long* arr, long left, long right)
{
	long pivot = (left + right) / 2;
	long i = left;
	long j = right;
	while (i < j)
	{
		while (arr[i] < arr[pivot])
			i++;
		while (arr[j] > arr[pivot])
			j--;
		if (i < j)
		{
			Swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	return pivot;
}

void QuickSort(long* arr, long left, long right)
{
	if (left < right)
	{
		long p = Partition(arr, left, right);
		QuickSort(arr, left, p);
		QuickSort(arr, p + 1, right);
	}
}

void RadixSort(long* arr, long size)
{
	long i, m = arr[0], exp = 1;
	long *Temp = new long[size];
	for (i = 0; i < size; i++)
	{
		if (arr[i] > m)
			m = arr[i];
	}
	while (m / exp > 0)
	{
		long bucket[10] = { 0 };
		for (i = 0; i < size; i++)
			bucket[arr[i] / exp % 10]++;
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (i = size - 1; i >= 0; i--)
			Temp[--bucket[arr[i] / exp % 10]] = arr[i];
		for (i = 0; i < size; i++)
			arr[i] = Temp[i];
		exp *= 10;
	}
	delete Temp;
}