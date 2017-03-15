#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

struct employ{
	int id, b_year;
	string name;
};

employ a[1000];
int n;


bool _less(int i, int x, string y){
	if (a[i].b_year < x) return true;
	//if (a[i].b_year == x && a[i].name < y) return true;
	return false; 
}

bool _greater(int i, int x, string y){
	if (a[i].b_year > x) return true;
	//if (a[i].b_year == x && a[i].name < y) return true;
	return false;
}

void put(int i){
	cout << a[i].b_year << ' ' << a[i].name << ' ' << a[i].id << endl;
}

void _swap(int i, int j){
	swap(a[i], a[j]);
}


void QuickSort(int a[], string s[], int l, int r){
	if (l >= r) return;

	int x, i, j;
	x = a[(l+r)/2];
	string y = s[(l+r)/2];

	i = l; j = r;

	while (i <= j){

		while ((i < r) && (a[i] < x) || ((a[i]==x && s[i][0] < y[0]))) i++;
		while ((j > l) && (a[j] > x) || ((a[j]==x && s[j][0] > y[0]))) j--;

		if (i <= j){
			swap(a[i], a[j]);
			swap(s[i], s[j]);
			_swap(i,j);
			i++; j--;
		}
	}


	if (l < j) QuickSort(a, s, l, j);
	if (i < r) QuickSort(a, s, i, r);
}

int main(){
	freopen("employee.txt","r",stdin);
	freopen("sortedemponage.txt","w",stdout);
	string s;
	getline(cin, s);

	while (1){
		s = ""; 
		getline(cin, s);
		if (s == "") break;

		size_t pos = 0;
		n++;
		
		pos = s.find(",");
		a[n].id = convert2int(s.substr(0, pos));
		s.erase(0, pos+1);
		
		pos = s.find(",");
		a[n].name = s.substr(0, pos);
		s.erase(0, pos+1);

		a[n].b_year = convert2int(s);
	}

	int year[n+10];
	string name[n+10];

	for(int i = 1; i <= n; i++) {
		year[i] = a[i].b_year;
		name[i] = a[i].name;
	}

	QuickSort(year, name, 1, n);

	for(int i = 1; i <= n; i++)
		//cout << year[i] << endl;
		cout << a[i].b_year << ' ' << a[i].name << ' ' << a[i].id << endl;

	return 0;
}