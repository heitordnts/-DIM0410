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
	int i=9;
	int count =0;
	while(n - table[i] < 0){	
		i--;	
	}
	int sum=0;
	while(sum < n){
		int fat = table[i];
		sum += fat;	
		count++;
		if(sum > n){
			count--;
			sum-=fat;
			i--;
		}
	}
	return

}

int main(){
	int n;
	
	lluint table_fat[10];
	for(int i=1;i<=10;i++){
		table_fat[i-1] = fatorial(i);
	}

	while(cin >> n){
		
	}	
	return 0;
}
