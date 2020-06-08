#include <iostream>

using namespace std;

int main(){
	char w[10000],bit;
	int q,i,j,max, min,n=1;// number of queries
	bool isNot;
	while(1){
		cin >> w;	
		if(cin.eof()) break;
		cout << "Case " << n <<  ":\n";

		cin >> q;

		for(int c=0;c<q;c++){
			cin >> i >> j;
			
			min = i>j ? j : i;
			max = i>j ? i : j;

			bit = w[min];
			isNot = false; 
			for(int k=min;k<=max;k++){
				if(w[k] != bit){
					isNot = true;
					cout << "No\n";
					break; 
				}
			}
			if(!isNot) cout << "Yes\n";
		}
		n++;
		
	}

	return 0;
}
