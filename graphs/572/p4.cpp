#include <iostream>
#include <cstring>


using namespace std;


int aux[100][100]={0};

int dfs(char G[][100], int m,int n,int o1,int o2){
	aux[o1][o2] = 1;
	for(int i=-1;i< 2;i++){
		for(int j=-1;j< 2;j++){
			//cout << o1+i << ", " << o2+j << ": ";
			if(!(o1 + i >= m || o1 + i < 0 || o2 + j >=n || o2 + j < 0)){
				if(G[o1+i][o2+j] == '@' && aux[o1+i][o2+j] == 0){
					dfs(G,m,n,o1+i,o2+j);
				}

			}
		}
	}
}

int main(){
	int m,n;
	char grid[100][100];
	
	while(cin >> m >> n && !(m==0 && n==0)){
		memset(aux,0,100*100);
		int oilPlots=0;
		for(int i=0;i<m;i++){
			cin >> grid[i];
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(grid[i][j] == '@' && aux[i][j] == 0){
					oilPlots++;
					dfs(grid,m,n,i,j);
				}
			}

		}

		cout << oilPlots << endl;
	}

	return 0;
}
