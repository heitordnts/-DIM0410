#include <bits/stdc++.h>


int bs(int *v,int n,int t){
	int l=0,r=n-1;
	int mid;

	while(r >= l){
		mid = l + (r-l)/2;
		printf("%d - %d\n",l,r);
		if(v[r] < t) return r;

		if(v[mid]==t) return mid;
		else if(v[mid] > t) r = mid-1;
		else l = mid + 1;
	}
	return 0;
}


int main(){
	int q,n;
	int m[1000];//array for test if a number was already tested
	scanf("%d",&q);
	while(q--){
		int heights[1000]={0};
		memset(m,0,sizeof(m));
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&heights[i]);
		}
		std::sort(heights,heights+n);
		int maxSquare = -1;
		for(int i=0;i<n;++i){
			int c = 0;
			if(!m[heights[i]]){
				m[heights[i]] = 1;
				//search the first idx that less than h[i]
				int idx = bs(heights,n, heights[i]-1);
				printf("%d\n",idx);
				c = n - idx; 
			}
			if(heights[i] <= c && maxSquare < heights[i]){
				maxSquare = heights[i];
			}
			else if(heights[i] > c && maxSquare < c){
				maxSquare = heights[i];
			}
		}
		printf("%d\n",maxSquare);
	}
	return  0;
}
