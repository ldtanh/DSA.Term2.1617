#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e6 + 10;

int n, a[N], pos[N];
vector<int> ans;

void readFile(char* fileName){
	freopen(fileName,"r",stdin);
	cin >> n;
	for(int i = 0; i < n; i++) 
		cin >> a[i];
}


void LinearSearch(int x){
	bool found = false;
	for(int i = 0; i < n; i++)
		if (a[i] == x) {
			ans.push_back(i);
			found = true;
		}
}

void LinearSearchWithSentinel(int x){
	int i = 0;
	bool found = false;
	a[n] = x;
	//Because "x" value is not unique, so have to do many "find" with sentinal
	while (1){
		while (a[i] != x) i++;
		if (i == n) break;
		ans.push_back(i);
		found = true;
		i++;
	}
}

int Search(int x){
	int l, r, mid;
	l = 0; r = n - 1;
	while (l <= r){
		mid = (l+r)/ 2;
		if (a[mid] == x) return mid;
		else
			if (a[mid] > x) r = mid - 1;
			else
				l = mid + 1;
	}
	return -1;
}

void QuickSort(int l, int r){
	if (l >= r) return;
	int x, i, j;
	x = a[(l+r)/ 2];
	i = l; j = r;
	while (i <= j){
		while (a[i] < x && i < r) i++;
		while (a[j] > x && j > l) j--;

		if (i <= j){
			swap(a[i],a[j]);
			swap(pos[i], pos[j]);
			i++; j--;
		}
	}
	if (l <= j) QuickSort(l,j);
	if (i <= r) QuickSort(i,r);
}

void BinarySearch(int x){
	for(int i = 0; i <= n; i++) pos[i] = i;
	QuickSort(0,n-1);
	int key = Search(x);
	if (key == -1){
		return;
	}
	while (key > 0 && a[key-1] == x) key--;
	while (a[key] == x){
		ans.push_back(pos[key]);
		key++;
	}
}

void writeAnswer(char* fileName){
	freopen(fileName, "w", stdout);
	if (ans.size() == 0) cout << -1;
	else{
		for(int i = ans.size() - 1; i > 0; i--)
			cout << ans[i] << ' ';
		cout << ans[0];
	}
}

int main(int argc, char* argv[]){
	readFile(argv[3]);
	int key = atoi(argv[2]);
	ans.clear();
	switch (atoi(argv[1])){
		case 1: LinearSearch(key);
		break;
		case 2: LinearSearchWithSentinel(key);
		break;
		case 3: BinarySearch(key);
		break;
	}
	writeAnswer(argv[4]);
	return 0;
}