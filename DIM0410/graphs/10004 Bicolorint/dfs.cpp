
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
