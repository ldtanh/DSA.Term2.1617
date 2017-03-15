#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int N = 2e6;
int a[N], n;

void qs(int l, int r){
	if (l >= r) return;
	//cout << l << ' ' << r << endl;
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

int main(){

	n = 1000000;
	for(int i = 1; i <= n; i++) a[i]=n-i+1;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

	qs(1,n);
	
	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();

	auto time = duration_cast<miliseconds>(t2-t1).count();
	//for(int i = 1; i <= 10; i++) cout << a[i] << ' ';
	cout << time;
	return 0;
}