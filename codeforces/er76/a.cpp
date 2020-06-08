#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	int n,x,a,b;
	int dist1,dist2,maxSwaps;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d %d",&n,&x,&a,&b);

		if(abs(a-b) + x > n-1) printf("%d\n",n-1);
		else				   printf("%d\n",abs(a-b)+x);

	}
	return 0;
}
