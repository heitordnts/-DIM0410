#include <iostream>
#include <iomanip>
#include <map>
#include <list>

using namespace std;

#define INF 99999

struct Node{
	bool youngs;
	int cost;
};

Node Gme[30][30];
Node Gprof[30][30];

void initFloyd(int n){
	for(int k=0;k<n;k++){	
		for(int i=0;i<n;i++){	
			G[k][i].cost = INF;	
		}
		G[k][k].cost = 0;	
	}
}

void floyd(int n){
	for(int k=0;k<n;k++){	
		for(int i=0;i<n;i++){	
			for(int j=0;j<n;j++){
				if(G[i][j].cost > G[i][k].cost + G[k][j].cost &&){
					G[i][j].cost = G[i][k].cost + G[k][j].cost;
				}
			}	
		}	
	}	

}
/*
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
*/
int main(){
	int n;

	while(cin >> n, n>0){
		char age,dir,x,y,e,me,prof;

		initFloyd(30);

		for(int i=0;i<n;i++){
			cin >> age >> dir >> x >> y >> e;	
			Node temp;
			temp.cost = e;
			if(age == 'Y'){ 
				if(dir == 'U')
					G[x-65][y-65] = temp;
				else{
					G[x-65][y-65] = temp;
					G[y-65][x-65] = temp;
				}
			}
			}
		}
		cin >> me >> prof;
		floyd(30);
		int totalCost =0	
		for(int i=0;i<30;i++){
			if(G[prof]
			profToi = G[prof][i];
			meToi = G[me][i];
			if(
			
			


		}

	}
	return 0;
}
