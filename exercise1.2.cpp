#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;

int a[1000], n;

bool compare(int x, int y, int key){
	if (key == 0)
		return x > y;
	return x < y;
}

void InterchangeSort(int b[], int m, int key){
	rep(i,m) 
		rep(j, m){
			if (i < j && compare(b[i], b[j], key)){
				swap(b[i], b[j]);
			}
		}
}
void Sort(){
	int b[1000], m = 0, j;
	
	rep(i, n){
		if (a[i] % 2 == 0){
			b[m++] = a[i];
		}
	}
	InterchangeSort(b, m, 0);
	j = 0;

	rep(i, n){
		if (a[i] % 2 == 0)
			a[i] = b[j++];
	}

	m = 0;
	rep(i, n){
		if (a[i] % 2 == 1){
			b[m++] = a[i];
		}
	}
	InterchangeSort(b, m, 1);
	j = 0;

	rep(i, n){
		if (a[i] % 2 == 1)
			a[i] = b[j++];
	}
}

int main(int argc, char* argv[]){
	n = argc - 1;
	rep(i, n) a[i] = atoi(argv[i + 1]);
	Sort();

	rep(i, n) cout << a[i] << ' ';
	return 0;
}