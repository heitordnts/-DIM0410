#include <iostream>
#include <cstring>


#define MAX(a,b) (a> b ?a:b)
using namespace std;

int G[100][100];
void imp(int n){
	for(int i=0;i<n;i++){	
		for(int j=0;j<n;j++){
			cout <<	G[i][j] << " "; 
		}	
		cout << endl;
	}	
}
float floyd(int n){
	for(int k=0;k<n;k++){	
		for(int i=0;i<n;i++){	
			for(int j=0;j<n;j++){
				if(G[i][j] < G[i][k] + G[k][j]){
					G[i][j] = G[i][k] + G[k][j];
				}
			}	
		}	
	}	
}

int main(){
	int a,b,casos=1;
	int maior;
	while(1){
		memset(G,0,sizeof G);
		cin >> a >> b;
		maior = MAX(a,b);
		if(a==0){
			break;
		}
		else{
			do{
				G[a][b] = 1;			
				cin >> a >> b;
				if(MAX(a,b) > maior){
					maior = MAX(a,b);
				}
			}while(a!=0);
		}
		cout << maior << endl;
		cout << "Case " << casos++ << ": average length between pages = " << floyd(maior) << " clicks" << endl;
		imp(maior);
	}

	return 0;
}
