#include <iostream>
#include <cstring>


using namespace std;

int visitados[200];
enum Cores {SEMCOR, PRETO, BRANCO};
#define COR(X) (X==1 ? "PRETO" : (X==2 ? "BRANCO" : "SEMCOR"))
struct Node{
	int temAresta;
	Cores cor=SEMCOR;
};

void printG(Node G[][200],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout << "("<< G[i][j].temAresta << ", " << G[i][j].cor << ") ";
		cout << endl;
	}
	cout << endl;
}

void colore(Node G[][200], int n, int no,Cores c){
	for(int i=0;i<n;i++){
		if(c == PRETO)
			G[no][i].cor = BRANCO;
		else if(c == BRANCO)
			G[no][i].cor = PRETO;
	}
}


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
int main(){
	int n,l;
	Node G[200][200];
	int e1,e2;
	
	while(cin >> n, n!=0){
		memset(G,0,200*200);
		memset(visitados,0,200);
		cin >> l;
		for (int i=0;i<l;i++){
			cin >> e1 >> e2;
			G[e1][e2].temAresta = 1;
			G[e2][e1].temAresta = 1;
		}
		for (int i=0;i<n;i++)
			G[e1][i].cor = BRANCO;
		visitados[e1] = 1;
		printG(G,n);
		dfs(G,n,e1);
	}
	return 0;
}
