#include <bits/stdc++.h>

int main(){
	int q,n;
	scanf("%d",&q);
	while(q--){
		int heights[1000]={0};
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&heights[i]);
		}
		int maxSquare = -1;
		for(int i=0;i<n;++i){
			int c = 0;

			for(int j=0;j<n;++j){
				if(heights[i] <= heights[j]) c++;
			}
			
			if(c >= heights[i] && heights[i] > maxSquare ) 
				maxSquare = heights[i];		
			else if(c < heights[i] && c > maxSquare)
				maxSquare = c;
		}
		printf("%d\n",maxSquare);
	}
	return  0;
}
