#include <iostream>

using namespace std;

int dfs(Node G[][200], int n,int orig){
	cout <<"No: " << orig << endl; 
	cout <<"Cor: " << COR(G[orig][0].cor) << endl; 
	for(int i=0;i< n;i++){
		if(G[orig][i].temAresta && visitados[i] == 0){
			cout << orig << " -> " << i << endl;
			visitados[i] = 1;
			if(G[i][0].cor == SEMCOR){
				colore(G,n,i,G[orig][0].cor);	
			}
			//printG(G,n);
			dfs(G,n,i);
		}
	}

}
int oilPlots(){


}

int main(){
	int m,n;
	char grid[100][100];
	
	map<int,list<int> > G;
	map<int,int> nivel;
	while(cin >> m >> n && !(m==0 && n==0)){
		for(int i=0;i<m;i++){
			cin >> grid[i];
		}
		
		cout << oilPlots() << endl;

	}

	return 0;
}
