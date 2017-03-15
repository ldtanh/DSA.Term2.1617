#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

int a[1000][1000], m, n;

void loang(int b[], int m, int n, int x, int &c){
	int i = x, j= x;
	while (j < n) a[i][j++]=b[c++];
	while (i < m) a[i++][j]=b[c++];
	while (j > x) a[i][j--]=b[c++];
	while (i > x) a[i--][j]=b[c++];
}

void QuickSort(int ar[], int l, int r){
	if (l >= r) return;
	int x, i, j;
	x = ar[(l+r)/ 2];
	i = l; j = r;
	while (i <= j){
		while (ar[i] < x && i < r) i++;
		while (ar[j] > x && j > l) j--;

		if (i <= j){
			swap(ar[i],ar[j]);
			i++; j--;
		}
	}
	if (l <= j) QuickSort(ar,l,j);
	if (i <= r) QuickSort(ar,i,r);
}

int main(){
	cin >> m >> n;
	int b[(m+2)*(n+2)];

	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			{
				cin >> a[i][j];
				b[(i-1)*n + j] = a[i][j];
			}
	QuickSort(b,1,m*n);

	int x = 1, mm = m, nn = n, c = 1;
	while (mm > m/2){
		loang(b, mm, nn, x, c);
		x++; mm--; nn--;
	}	
	if (m == n && m%2 == 1) a[m/2+1][m/2+1] = b[c];
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n ; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}

	return 0;
}