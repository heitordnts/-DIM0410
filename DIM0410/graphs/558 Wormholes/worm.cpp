#include <iostream>
#include <vector>

using namespace std;

#define INF 999999

struct Aresta{
	int orig,dest,custo;
};

vector<Aresta> universe;

bool relaxa(Aresta &a,int dist[]){
	if(dist[a.dest] > dist[a.orig] + a.custo){
		dist[a.dest] = dist[a.orig] + a.custo;
		return true;
	}
	return false;
}


bool bellford(int n,int m){
	int dist[n];
	for(int i=0;i<n;i++){
		dist[i] = INF;
	}
	dist[0] = 0;	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			relaxa(universe[j],dist);
		}	
	}

	for(int j=0;j<m;j++){
		if(relaxa(universe[j],dist)){
			return true;	
		}
	}	
	
	return false;

	for(int i=0;i<n;i++){
		cout << dist[i] << " ";
	}
	cout << endl;

}

int main(){
	int c;
	Aresta temp;
	cin >> c;

	while(c--){
		int n,m;

		cin >> n >> m;
		
		int x,y,t;

		universe.clear();
		for(int i=0;i<m;i++){
			cin >> x >> y >> t;	
			temp.orig = x;
			temp.dest = y;
			temp.custo = t;
			universe.push_back(temp);
		}
	
		if(bellford(n,m)){
			cout << "possible" << endl;
		}else{
			cout << "not possible" << endl;
		}

	}

	return 0;
}
