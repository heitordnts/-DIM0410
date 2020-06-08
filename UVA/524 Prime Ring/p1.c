#include <stdio.h>

int v[128]={1};
int mark[128]={1};;

int isPrime(int n){
	for(int i=2; i <= n/2; i++){
		if(n%i == 0) return 0;
	}
	return 1;
}

int backtracking(int n,int j){	
	if(j == n){
		if(isPrime(v[0] + v[j-1])){
			for(int i=0;i<n;i++)
				printf("%d ",v[i]);
			printf("\n");
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

}


int main(){

	int n,c=1;

	while(1){
		scanf("%d",&n);
		if(feof(stdin))break;
		printf("Case %d:\n",c++);
		backtracking(n,1);
		printf("\n");
	}

	return 0;
}
