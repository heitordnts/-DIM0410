#include <iostream>
#include <cstring>
#include <climits>
#include <iomanip>

#define MAX(a,b) (a> b ?a:b)

using namespace std;

int G[101][101];

void imp(int n){
	for(int i=0;i<n;i++){	
		for(int j=0;j<n;j++){
			cout <<	setw(6) << G[i][j] <<  " "; 
		}	
		cout << endl;
	}	
}

float floyd(int n){
	for(int k=1;k<=n;k++){	
		for(int i=1;i<=n;i++){	
			for(int j=1;j<=n;j++){
				if(G[i][j] > G[i][k] + G[k][j]){
					G[i][j] = G[i][k] + G[k][j];
				}
			}	
		}	
	}	

	float soma = 0;
	float c=0;
	for(int i=1;i<=n;i++){	
		for(int j=1;j<=n;j++){
			if(G[i][j] != 99999 && i!=j){
				soma = G[i][j];
				c++;
			}
		}
	}	
	
	return (float)soma/c;
}



int main(){
	int a,b,casos=1;
	int maior;
	while(1){
		for(int i=0;i<101;i++){	
			for(int j=0;j<101;j++){
				G[i][j] = 99999; 
			}	
			G[i][i] = 0; 
		}	
		cin >> a >> b;
		maior = MAX(a,b);
		if(a==0){
			break; }
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
		//imp(maior);
		//cout << "Case " << casos++ << ": average length between pages = " << floyd(maior) << " clicks" << endl;
		cout << "Case " << casos++ << ": average length between pages = " << setprecision(3) << fixed << floyd(maior) << " clicks\n";
		//imp(maior);
	}
	return 0;
}
