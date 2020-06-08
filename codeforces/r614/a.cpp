#include <bits/stdc++.h>

using namespace std;

int off[3] = {-1,0,1};

int main(){
	int n,q,row,col;
	scanf("%d%d",&n,&q);
	
	bool cells[2][100001];

	memset(cells,0,sizeof(cells));

	int walls = 0;

	for(int i=0;i<q;i++){
		scanf("%d%d",&row,&col);
		row--;	col--;

		cells[row][col] = !cells[row][col];	

		bool is_blocked = cells[row][col];

		for(int j = 0;j<3;j++){
			int c = col + off[j];

			if(c < 0 || c > n) continue;

			if(cells[!row][c]){
				walls += 2*is_blocked - 1;
			}
		}
		puts(!walls?"YES":"NO");	
	}

	return 0;
}
