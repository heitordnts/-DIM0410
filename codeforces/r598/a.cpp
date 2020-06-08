#include <bits/stdc++.h>

using namespace std;

int main(){
	long long q,a,b,n,s;
	scanf("%lld",&q);
	//1 3 4 2
	for(int i=0;i<q;i++){
		scanf("%lld %lld %lld %lld",&a,&b,&n,&s);	

		if(a*n + b < s || (s/n) * n + b < s ) puts("NO");
		else puts("YES");
	}

	return 0;
}
