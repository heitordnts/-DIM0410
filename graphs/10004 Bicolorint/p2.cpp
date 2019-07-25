#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define COR(X) (X==1 ? "PRETO" : (X==2 ? "BRANCO" : "SEMCOR"))
#define OUT(X) (X==1 ? "BICOLORABLE." : "NOT BICOLORABLE.") 

enum Cores {SEMCOR, PRETO, BRANCO};

struct Node{
	int temAresta;
	Cores cor=SEMCOR;
};

int visitados[200];
queue<int> q;

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

int bfs(Node G[][200], int n,int orig){
	//inicia a fila com a orig
	int temp;	
		
	q.push(orig);
	while(!q.empty()){
		temp = q.front();
		q.pop();
		if(visitados[temp] == 1){
			continue;
		}
		else{
			visitados[temp] = 1;
		}
				
		//cout << "No " << temp << endl;
		//cout << "Cor " << COR(G[temp][0].cor) << endl;
		//cout << "queue size: " << q.size()<< endl;

		//if(visitados[temp] == 1) continue;
		for(int i=0;i<n;i++){
			if(G[temp][i].temAresta == 1 ){

				if(G[i][0].cor == SEMCOR){
					colore(G,n,i,G[temp][0].cor);
				}
				else if(G[temp][0].cor == G[i][0].cor){
					return 0;
				}
				if(visitados[i] == 0){
					q.push(i);
				}
			}
		}
	}
	return 1;
}

int main(){
	int n,l;
	Node G[200][200];
	int e1,e2;
	
	while(cin >> n, n!=0){
		q = queue<int>();
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

		//visitados[e1] = 1;
		//printG(G,n);
		cout << OUT(bfs(G,n,e1)) << endl;

	}
	return 0;
}
