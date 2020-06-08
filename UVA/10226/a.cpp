#include <iostream>
<<<<<<< HEAD
#include <string>
#include <map>
=======
#include <map>
#include <string>
>>>>>>> gulosos
#include <cstdio>

using namespace std;

int main(){
<<<<<<< HEAD
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

=======
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
>>>>>>> gulosos
}
