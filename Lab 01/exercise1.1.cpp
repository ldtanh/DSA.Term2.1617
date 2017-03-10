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


int main(int argc, char* argv[]){

	n = atoi(argv[1]);
	srand(time(NULL));
	rep(i, n) source[i] = rand() % 30 + 1;

	InsertionSort(source, n);
	HeapSort(source, n);
	return 0;
}