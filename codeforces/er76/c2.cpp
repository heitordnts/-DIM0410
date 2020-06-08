#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	int n;
	int past[20000];
	cin >> t;
	while(t--){
		cin >> n;
		memset(past,-1,(n+1)*sizeof(int));
		int minLen = n+2;
		int a;
		for(int i=0;i<n;++i){
			cin >> a;
			if(past[a] != -1){
				minLen = min(minLen,i - past[a] + 1);
			}
			past[a] = i;
		}
		if(minLen > n){
			minLen = -1;
		}
		printf("%d\n", minLen);
	}
	return 0;
}
/*
int main(){
	int t;
	int n;
	int a[20000],past[20000];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(past,-1,(n+1)*sizeof(int));
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		if(n < 2){
			printf("-1\n");
			continue;
		}	

		int minLen = n+1,len,ret = -1;
		for(int i=0;i<n;++i){
			if(past[a[i]] != -1){
				len = i - past[a[i]] + 1;
				minLen = min(minLen,len);
				ret = minLen;
			}
			past[a[i]] = i;
		}
		printf("%d\n", ret);
	}
	return 0;
}
*/
