
#include <bits/stdc++.h>
using namespace std;

/*
	x == 1 -> 1 
	x == 2 -> 1 or 3
	x == 3 -> 2
	x == 4 -> 3 or 6
	x == 5 -> 4
	x == 6 -> 5 or 9
	x == 7 -> 6
	...
 */



int main(){
	int t;
	int x,y;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&x,&y);
		bool flag = x > 3 || x == y || ((x == 2 || x == 3) && y < 4);
		puts(flag ? "YES" : "NO");
		//if(x > 3 || x == y || ((x == 2 || x == 3) && y < 4)){
		//	puts("YES");
		//}
		//else{
		//	puts("NO");
		//}
	}
	return 0;
}
