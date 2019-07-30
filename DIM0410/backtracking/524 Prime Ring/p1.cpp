#include <bits/stdc++.h>

using namespace std;

int v[128]={1};
bool mark[128]={1};

bool isPrime(int n){
	for(int i=2; i <= n/2; i++){
		if(n%i == 0) return false;
	}
	return true;
}

int backtracking(int n,int j){	
	if(j == n){
		if(isPrime(v[0] + v[j-1])){
			for(int i=0;i<n-1;i++)
				cout << v[i] << " ";
				
			cout<< v[n-1] << endl;
		}
		return 0;

	}
	for(int i=2;i<=n;i++){
		if(mark[i] == 0){
			if(isPrime(i+v[j-1])){
				v[j] = i;
				mark[i] = 1;
				backtracking(n, j+1);	
				mark[i] = 0;
			}
		}
	}
	return 0;
}


int main(){

	int n,c=1;

	while(cin>>n){
		if(c != 1)
			cout << endl;
		cout << "Case " << c++ << ":\n";
		backtracking(n,1);
	}

	return 0;
}
