#include <bits/stdc++.h>

using namespace std;

#define INF 99999

int G[101][101];
vector<int> v;

void initFloyd(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			G[i][j] = INF;
		}
	}
}

void floyd(int n){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(G[i][j] > G[i][k] + G[k][j]){
					G[i][j] = G[i][k] + G[k][j];
				}
			}
		}
	}
	
}

void imp(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << G[i][j] << " " ;

		}

	cout << endl;
	}

}

int main(){
	int n,s,e,l;
	while(cin >> n && n!=0){
		initFloyd(101);
		while(cin >> s && s!=0){
			while(cin >> e && e!=0){
				G[s][e] = 1;
			}
		}
		//imp(n);
		floyd(n);
		//imp(n);
		cin >> l;
		for(int i=0;i<l;i++){
			cin >> e;
			int qtd=0;
			v.clear();
			for(int j=1;j<=n;j++){
				if(G[e][j] >= INF){
					qtd++;
					v.push_back(j);
				}
			}
			cout << qtd;

			for(auto it=v.begin();it!=v.end();it++) cout << " " << *it;

			cout << endl;
		}
	}
	return 0;

}
