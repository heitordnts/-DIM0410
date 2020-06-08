#include <bits/stdc++.h>
using namespace std;

int isDominated(int *a,int start,int len){
	int *v = a + start;
	int max_seq = 0,total_max = -1;
	int x = v[0];
	printf("primeiro elemento x = %d\n",x);
	int flag = 1;
	for(int i=0;i<len;i++){
		printf("testando %d com %d\n",x,v[i]);
		if(v[i] == x){
			++max_seq;
		}
		else{
		 	if (max_seq == total_max) {
				flag = 0;
				printf("igual\n");
			}
			else if(max_seq > total_max){
				total_max=max_seq;
				flag = 1;
			}
			max_seq = 1;
			x = v[i];
		}
		printf("max_seq = %d\n",max_seq);
		printf("total_max = %d\n",total_max);
	}
	return flag;
}

int main(){
	int t;
	int n,a[20000];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		printf("%d\n",isDominated(a,0,n));
	}
	return 0;
}
