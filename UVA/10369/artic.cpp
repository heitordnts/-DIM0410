#include <bits/stdc++.h>

using namespace std;

#define INF 99999

double G[500][500];




void initFloyd(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			G[i][j] = INF:
		}
			G[i][i] = 0:
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
	double menor=INF+1;
	for(int k=0;k<n;k++){
		if(menor > G	

	}
	
}

double dist(int x,int y, int w,int z){
	return sqrt((x-w)*(x-w) + (y-z)*(y-z));
}

int main(){
	int n,s,p;
	int x,y,w,z;
	cin >> n;
	while(n--){
		cin >> s >> p;
		cin >> x >> y >> w >> z;
		
		//cout << dist(x,y,w,z) << endl;

	}
	return 0;

}
