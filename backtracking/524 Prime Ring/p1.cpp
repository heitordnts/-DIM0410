#include <bits/stdc++.h>

using namespace std;

int v[16]={1};
bool mark[16]={1};;

bool isPrime(int n){
	for(int i=2; i<= n/2; i++){
		if(n%i == 0) return false;
	}
	return true;
}

int backtracking(int n,int j){	

	for(int i=2;i<=n;i++){
		if(mark[i] == 0){
			if(isPrime(i+j)){
				v[j] = i;
				mark[i] = 1;
				backtracking(n, j+1);	
				mark[i] = 0;
			}
		}
	}

}


int main(){

	int n;

	while(cin>>n){
		//backtracking();

	}

	return 0;
}
