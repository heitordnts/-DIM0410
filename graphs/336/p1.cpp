#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <list>
#include <unordered_set>

using namespace std;
/*
struct Node{
	int id;
	int ttl=0;
};
*/
unordered_set<int> visitados;

int bfs(map<int,list<int>> &G, map<int,int> &nivel, int orig,int ttl){
	//inicia a fila com a orig
	queue<int> q;
	int temp;	
	int cont =0;	
	q.push(orig);
	while(!q.empty()){
		temp = q.front();
		q.pop();
		if(visitados.find(temp) != visitados.end()){
			continue;
		}
		else{
			visitados.insert(temp);
		}
				
		//if(nivel[temp] > ttl) cont++;
		for(auto &No : G[temp]){
			if(visitados.find(No) == visitados.end()){
				if(nivel[No] == 0)
					nivel[No] = nivel[temp]+1;
				q.push(No);	
			}
		}
	}
	for(auto &a: nivel){
		//cout << a.first << " " << a.second << endl;
		if(a.second > ttl || a.second ==0 )
			cont++;
	}
	return cont-1;
}

int main(){
	int nc;
	int e1,e2;
	map<int,list<int> > G;
	map<int,int> nivel;
	int casos=1;	
	while(cin >> nc, nc!=0){
		G.clear();
		
		for (int i=0;i<nc;i++){
			cin >> e1 >> e2;
			nivel[e2] = 0;
			nivel[e1] = 0;
			G[e1].push_back(e2);
			G[e2].push_back(e1);
		}
		while(1){	
			visitados.clear();
			cin >> e1 >> e2;
			
			nivel[e1] = 0;
			if(e1 == 0 && e2 == 0) break;	

			cout << "Case "<<casos++<<": ";
			cout << bfs(G,nivel,e1,e2) << " nodes not reachable from node " << e1 << " with TTL = " << e2 << "." << endl;

			nivel.clear();
			for(auto &a: G){
				nivel[a.first] =  0;
			}
		}
		cin.ignore();
	}
	return 0;
}
