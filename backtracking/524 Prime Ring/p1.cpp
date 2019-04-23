#include <bits/stdc++.h>

using namespace std;


bool isPrime(int n){
	for(int i=2; i<= n/2; i++){
		if(n%i == 0) return false;
	}
	return true;
}

int *v;
bool *mark;

int main(){

	int n;

	while(cin>>n){
		//backtracking();

	}

	return 0;
}
