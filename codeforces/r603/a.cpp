#include <bits/stdc++.h>

using namespace std;


void order(int &h,int &m, int &l){
	int v[] = {h,m,l};
	sort(v,v+3);
	h = v[2];
	m = v[1];
	l = v[0];
}

int solve(){
	int h,m,l;
	scanf("%d %d %d",&h,&m,&l);
	order(h,m,l);
	int aux = l-(l%2==0);
	return aux + min(h-aux/2,m-aux/2);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--) printf("%d\n",solve());	
	return 0;
}
