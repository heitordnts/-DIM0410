#include <iostream>
#include <iomanip>

using namespace std;

#define INF 99999

int G[101][101];

void initFloyd(int n){
	for(int k=0;k<n;k++){	
		for(int i=0;i<n;i++){	
			G[k][i] = INF;	
		}
		G[k][k] = 0;	
	}
}

void floyd(int n){
	for(int k=0;k<n;k++){	
		for(int i=0;i<n;i++){	
			for(int j=0;j<n;j++){
				if(G[i][j] > G[i][k] + G[k][j]){
					G[i][j] = G[i][k] + G[k][j];
				}
			}	
		}	
	}	

}

void imp(int n){
cout << endl;
	for(int i=0;i<n;i++){	
		for(int j=0;j<n;j++){
			if(G[i][j] == INF){
				cout <<	setw(6) << "INF"  <<  " "; 
			}
			else
				cout <<	setw(6) << G[i][j] <<  " "; 
		}	
		cout << endl;
	}	
}

int main(){
	int t;

	cin >> t;
	int caso = 1;
	while(t--){
		cout << "Case " << caso++ << ": ";
		int n,r,a,b,s,d;
		//s == origem
		//d == destino
		//n == numero de edificios
		//r numero de arestas

		cin >> n >> r;

		initFloyd(n);

		for(int i=0;i<r;i++){
			cin >> a >> b;
			G[a][b] = 1;
			G[b][a] = 1;
		}
		cin >> s >> d;
		floyd(n);
		int resp = 0 ;
		for(int i =0;i< n;i++){
			if(resp < G[s][i]+G[i][d]){
				resp = G[s][i]+G[i][d];
			}
		}
		cout << resp << endl;

		//imp(n);
			
	}
	return 0;
}
