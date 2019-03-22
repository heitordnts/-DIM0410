#include <iostream>
#include <map>
#include <string>
#include <cstdio>

using namespace std;

int main(){
	int n,pop=0;

	string tree;

	cin >> n;	
		
	cin.ignore();
	cin.ignore();
	while(n--){
		map<string,int> m;
		map<string, int>::iterator it;
		pop = 0;
		
		while(getline(cin,tree),tree!=""){
				m[tree] += 1;
			pop++;
		
		}
		for(it=m.begin();it!=m.end();it++){
			cout << it->first ;
			printf(" %.4f\n",(float)it->second*100/(float)pop);

		}
		cout << endl;
	}
	return 0;
}
