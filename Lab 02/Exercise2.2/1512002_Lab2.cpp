#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define MIN(x,y) ((x < y) ? x : y)
const int N = 1e6 + 10;

vector<pair<string,string> > data;

bool comparision(pair<string,string> x, pair<string,string> y){
	string s, t;
	s = x.first; t = y.first;
	for(int i = 0; i < MIN(s.length(), t.length()); i++){
		if (s[i] < t[i]) return true;
		if (s[i] > t[i]) return false;
	}
	if (s.length() < t.length()) return true;
	return false;
}

void readFile(){
	freopen("English-Vietnamese Dictionary.dat","r",stdin);
	string s;
	data.clear();
	while (1){
		s = "";
		getline(cin,s);
		if (s == "") break;
		size_t pos = s.find(":");
		data.push_back(pair<string,string>(s.substr(0,pos), ""));
		s = s.erase(0,pos+1);
		data[data.size() - 1].second = s;
	}
}

void initData(){
	sort(data.begin(), data.end());
}

int Search(string x){
	int l = 0, r = data.size() - 1, mid;
	while (l <= r){
		mid = (l+r)/2;
		if (x.compare(data[mid].first) == 0) 
			return mid;
		else
			if (x.compare(data[mid].first) < 0)
				r = mid - 1;
			else
				l = mid+1;
	}
	return -1;
}

string convertToStr(char *s){
	string ans = "";
	for(int i = 0; i < strlen(s); i++)
		ans += s[i];
	return ans;
}

int main(int argc, char* argv[]){
	readFile();
	initData();

	freopen(argv[argc-1], "w", stdout);
	for(int i = 1; i < argc-1; i++){
		string w = convertToStr(argv[i]);
		int pos = Search(w);
		while (pos == -1){
			if (i == argc - 2) {
				cout << w << ": Not found!\n";
				return 0;
			}
			i++;
			w = w + " " + convertToStr(argv[i]);
			pos = Search(w);
		}
		cout << data[pos].first << ":" << data[pos].second << endl;
	}
	return 0;
}

