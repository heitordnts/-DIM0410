#include <iostream>
#include <cstring>

using namespace std;

int aux[100][100]={0};

int m,n;
char grid[100][100];

int ivar[]={1,1,1,-1,-1,-1,0,0};
int jvar[]={1,0,-1,1,0,-1,1,-1};

void dfs(int o1,int o2){
	aux[o1][o2] = 1;
	int id1,id2;
	for(int i=0;i< 8;i++){
		id1 = o1 + ivar[i];
		id2 = o2 + jvar[i];
		if(id1 < m && id1 >= 0 && id2 < n && id2 >= 0 ){//valida indice
			if(aux[id1][id2] == 0){
				aux[id1][id2] = 1;
				if(grid[id1][id2] == '@'){
					dfs(id1,id2);
				}
			}
		}
	}
}

int main(){
	
	while(cin >> m >> n && !(m==0)){
		memset(aux,0,100*100);
		memset(grid,0,100*100);

		int oilPlots=0;
		
		for(int i=0;i<m;i++){
			cin >> grid[i];
		}

		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if( aux[i][j] == 0){
					aux[i][j] = 1;
					if(grid[i][j] == '@'){
						oilPlots++;
						dfs(i,j);
					}
				}
			}
		}

		cout << oilPlots << endl;
	}

	return 0;
}
