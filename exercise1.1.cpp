#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <chrono>

#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;

const int N = 1e6 + 10;

int n, source[N], h[N], a[N];

void InsertionSort(int A_[], int n){

	cout << " Excuting Insertion Sort with N = " << n << endl;
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	rep(i, n) a[i] = A_[i];

	rep(i,n)
		rep(j, n){
			if (i < j && a[i] > a[j]){
				swap(a[i], a[j]);
			}
	
		}
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	cout << " -> Running Time: ";
	cout << setprecision(5) << fixed << (double)chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0 << endl;
}


void Heapify(int x, int len){
	int k = x, l = 2 * x + 1, r = 2 * x + 2;
	if (l < len && h[l] < h[k])
		k = l;
	if (r < len && h[r] < h[k])
		k = r;
	swap(h[k], h[x]);
	if (k != x) Heapify(k, len);
}

void HeapSort(int a[], int n){
	cout << " Excuting Heap Sort with N = " << n << endl;
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	memset(h, -1, sizeof(h));
	rep(i, n) h[i] = a[i];
	
	for (int i = (n - 1) / 2; i >= 0; i--)
		Heapify(i, n);
	
	while (n > 0) {
		swap(h[0], h[n - 1]);
		n--;
		Heapify(0, n);
	}
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	cout << " -> Running Time: ";
	cout << setprecision(5) << fixed << (double)chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0 << endl;
}

void qs(int l, int r){
	if (l >= r) return;
	int x, i, j;
	x = a[(l+r)/ 2];
	i = l; j = r;
	while (i <= j){
		while (a[i] < x && i < n) i++;
		while (a[j] > x && j > 1) j--;

		if (i <= j){
			swap(a[i],a[j]);
			i++; j--;
		}
	}
	if (l <= j) qs(l,j);
	if (i <= r) qs(i,r);
}

void QuickSort(int source[], int n){
	cout << " Excuting Quick Sort with N = " << n << endl;
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	rep(i,n) a[i+1]=source[i]; //QuickSort - Array start from 1
	qs(1,n);

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	cout << " -> Running Time: ";
	cout << setprecision(5) << fixed << (double)chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0 << endl;
}

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void CountSort(int arr[], int n, int exp)
{
    int b[n];
    int i, count[100];
    memset(count, 0, sizeof(count));

 
    for (i = 0; i < n; i++)
        count[(arr[i]/exp)%10 ]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--)
    {
        b[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = b[i];
}
 

void RadixSort(int arr[], int n)
{
	cout << " Excuting Radix Sort with N = " << n << endl;
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	int m = getMax(arr, n);
	for (int exp = 1; m/exp > 0; exp *= 10)
        CountSort(arr, n, exp);

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	cout << " -> Running Time: ";
	cout << setprecision(5) << fixed << (double)chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0 << endl;
}

int main(int argc, char* argv[]){

	n = atoi(argv[1]);
	srand(time(NULL));
	rep(i, n) source[i] = rand() % N + 1;

	if (n <= 50000) InsertionSort(source, n);
	HeapSort(source, n);
	QuickSort(source, n);
	RadixSort(source, n);
	return 0;
}