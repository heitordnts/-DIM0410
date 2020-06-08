#include <bits/stdc++.h>

using namespace std;
#define endl putchar('\n')

int main(){
	int n,m,d;
	int c[1001],sum=0;
	int ans[1001];
	scanf("%d %d %d",&n,&m,&d);

	for(int i=0;i<m;i++){
		scanf("%d",c+i);
		sum+=c[i];
	}

	int aux = 0;
	for(int i=m-1;i>=0;--i){
		aux += c[i];
		for(int j=0;j<c[i];j++){
			printf("%d \n",n+1 - aux);
			ans[n - aux + j] = i+1;
		}
	}

	if((n+1)/d < m)
		puts("NO");
	else{
		for(int i=0;i<n;++i){
			printf("%d ",ans[i]);
		}
		endl;
	}

	return 0;
}
