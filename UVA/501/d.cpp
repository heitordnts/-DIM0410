#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
	map<string, string> figures;
	string code,name;
	int n,t;
	char a[32];
	cin >> n;
	cin.ignore();
	for(int i=0;i<n;i++){
		getline(cin, code);
		getline(cin, name);
		figures[code] = name;
	}
	
	cin >> t;
	cin.ignore();
	for(int i=0;i<t;i++){
		getline(cin,code);
		cout << figures[code] << endl;
	}
	return 0;

}
