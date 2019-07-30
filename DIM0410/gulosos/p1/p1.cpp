#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100000

typedef long long int lluint;

lluint fatorial(int x){
	lluint fat = 1;
	if(x == 0) return 1;
	while(x>=1 ){
		fat *= x;
		x--;
	}	
	return fat;
}

int minimo(int n, lluint *table){
	int i=8;
	int count =0;
	while(n - table[i] < 0){	
		i--;	
	}
	while(1){
		if(n-table[i] >= 0){
			n = n - table[i];	
			count ++;
		}
		else
			i--;
		if(n ==0) return count;
	}
}

int main(){
	int n;
	
	lluint table_fat[9];
	for(int i=0;i<=8;i++){
		table_fat[i] = fatorial(i);
	}

	while(cin >> n){
		cout << minimo(n,table_fat) << endl;	
	}	
	return 0;
}
