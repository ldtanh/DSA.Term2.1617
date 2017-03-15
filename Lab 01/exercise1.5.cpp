#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>
#include <iomanip>
#include <vector>

using namespace std;

#define rep(i,n) for(int i = 1; i <= n; i++)

struct candidate{
	string name;
	float sc1, sc2, avg;
	int op[1000];
	bool selected;
};

int m, opt[1000], n;
candidate a[1000];
vector<int> v[1000], reject;

bool compare(int i, int j, int type){
	if (type == 0){
		if (a[i].avg < a[j].avg) return true;
		if (a[i].avg == a[j].avg){
			if (a[i].sc1 < a[j].sc1) return true;
			if (a[i].sc1 == a[j].sc1 && a[i].sc2 <= a[j].sc2) return true;
			return false;
		}
		return false;
	}
	if (type == 1){
		if (a[i].avg > a[j].avg) return true;
		if (a[i].avg == a[j].avg){
			if (a[i].sc1 > a[j].sc1) return true;
			if (a[i].sc1 == a[j].sc1 && a[i].sc2 >= a[j].sc2) return true;
			return false;
		}
		return false;
	}
	return false;
}

void InsertionSort(int ar[], int l, int r){ //using Insertion Sort
	for(int i = l ; i <= r ; i++)
		for(int j = i + 1; j <= r; j++)
			if (compare(ar[i],ar[j],0))
				swap(ar[i],ar[j]);
}

float convert2float(string s){
	float ans = 0;
	float key = 1;
	for(int i = 0; i < s.length(); i++)
		if (!(s[i] >= '0' && s[i] <= '9') && s[i] != '.') continue;
	else
		if (s[i] == '.') 
			key = 0.1;
		else
			if (key == 1) 
				ans = ans * 10.0 + float(s[i] - '0');
			else{
				ans += key * float(s[i] - '0');
				key *= 0.1;
			}
	return ans;
}

int convert2int(string s){
	int ans = 0;
	for(int i = 0; i < s.length(); i++)
		ans = ans*10 + (int)(s[i] - '0');
	return ans;
} 

void refill(int p[]){
	rep(i,n) p[i] = i;
	p[0] = 0; p[n+1] = n+1;	
}

int main(){
	cin >> m;
	rep(i,m) {
		int x;
		cin >> x;
		cin >> opt[x];
	}

	string s;
	getline(cin,s);
	n = 0;

	while (1){
		s = "";
		getline(cin, s);
		if (s == "") break;

		size_t pos = 0;

		pos = s.find(",");
		a[++n].name = s.substr(0, pos);
		s.erase(0, pos+1);

		pos = s.find(",");
		a[n].sc1 = convert2float(s.substr(0,pos));
		s.erase(0, pos+1);

		pos = s.find(",");
		a[n].sc2 = convert2float(s.substr(0,pos));
		s.erase(0, pos+1);

		rep(i,m-1){
			pos = s.find(",");
			a[n].op[i]=convert2int(s.substr(0,pos));
			s.erase(0,pos+1);
		}

		a[n].op[m] = convert2int(s);
	}

	rep(i,n){ 
		a[i].avg = ( a[i].sc1 + a[i].sc2 ) / 2.00;
		a[i].avg = (float (( a[i].avg * 100.0 ) / 100.0));  
		a[i].selected = false;
	}

	int pos[n+10];
	refill(pos);
	InsertionSort(pos, 1, n);

	rep(i,n) 
		if (a[i].avg < 5.00) { // Check whether i-th is rejected or not
			a[i].selected = true; //Assume that i-th is selected for not selecting anymore
			reject.push_back(i); //push_back to be sort then
		}

	rep(j, m){
		int key = 1; //Start at option 1
		rep(p, n){
			int i = pos[p];

			if (opt[j] == 0) {
				//Find another <key'> for this person
				for(int _key = key + 1; _key <= m; _key ++)
					if (opt[a[i].op[_key]] > 0){
						a[i].selected;
						opt[a[i].op[_key]] --;
						v[a[i].op[_key]].push_back(i);
						break;
					}
				break; //If Option j is full, don't choose
			}
			
			if (a[i].selected) continue; //if Pos[p]th is selected, select another one
			if (a[i].op[key] == j){ // If Option key-th is j, select ok
				v[j].push_back(i); //push to answer
				a[i].selected = true;
				opt[j]--; //Minus option j by one
			}
		}
		key ++; //Select at Option key + 1
	}


	cout << setprecision(2);
	rep(j, m){
		cout << "Successful candidates for option " << j << ": \n";
		if (v[j].empty()){
			cout << "(none)\n";
			continue;
		}
		for(int i = 0; i < v[j].size(); i++)
			cout << i+1 << ". " << a[v[j][i]].name << " " << fixed << a[v[j][i]].avg << endl;
	}

	//Sorting the Rejected List

	for(int i = 0; i < reject.size(); i++)
		pos[i+1] = reject[i];
	InsertionSort(pos, 1, reject.size());

	cout << "Unsuccessfull Candidates: \n";
	rep(i,reject.size())
		cout << i << ". " << a[pos[i]].name << " " << a[pos[i]].avg << endl;
	if (reject.empty())
		cout << "(none)";
	return 0;
}