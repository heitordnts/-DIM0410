#include <iostream>
#include <string>
#include <map>
#include <cstdio>

using namespace std;

int main(){
	int n;

	map<string, int> dict;
	map<string, int>::iterator it;
	string tree;
	int pop;
	
	cin >> n;
	cin.ignore();
	cin.ignore();
	while(n>0){
		pop = 0;

		while(getline(cin,tree),tree!=""){
			dict[tree] += 1;
			pop++;
		}
		for(it=dict.begin(); it != dict.end(); it++){
			float rf = 100*(float(it->second)/float(pop));
			cout << it->first;
			printf(" %.4f\n",rf );
		}
		dict.clear();
		if(n != 1) putchar('\n');
		n--;
	}

	return 0;

}
