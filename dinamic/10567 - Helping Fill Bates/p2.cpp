#include <bits/stdc++.h>

using namespace std;

int matchq(const char *q,const char *s,int f,int &fi){
	int i,k;

	for( i=fi,k=f;q[i]!=0;i++,k++){
		if(q[i] != s[k])
			return -1;
	}
	
	while(s[k] == f) k++;

	return k;
}


int main(){
	char s[1000000];
	char q[3600];
	
	cin >> s;

	int t,k=0,fi=0;

	cin >> t;

	for(int i=0;i<t;i++){

		cin >> q;
		while(s[k]!=0 && k=){
			 k=matchq(q,s,k,fi);
		}

	}

	return 0;
}

