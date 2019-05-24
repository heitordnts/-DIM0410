#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <list>
#include <unordered_set>

using namespace std;

struct Node{
	int id;
	int ttl=0;
};

unordered_set<int> visitados;
queue<int> q;

int bfs(map<int,list<int>> &G, map<int,int> &ttls, int orig){
	//inicia a fila com a orig
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
				
		cout << "No " << temp << endl;
		cout << "ttl " << ttls[temp] << endl;
		//cout << "queue size: " << q.size()<< endl;
		if(ttls[temp] < 0) cont++;
		//if(visitados[temp] == 1) continue;
		for(auto &No : G[temp]){
			if(visitados.find(No) == visitados.end()){
				ttls[No] = ttls[temp] - 1;
				q.push(No);	
			}
			else{
				int aux = ttls[temp] - 1;
				if(ttls[No] < aux && aux >= 0){
					visitados.erase(No);
					q.push(No);
				}
			}
		}
	}
	return cont;
}

int main(){
	int nc;
	int e1,e2;
	map<int,list<int> > G;
	map<int,int> ttls;
	int casos=1;	
	Node aux,aux2;
	while(cin >> nc, nc!=0){
		G.clear();
		q = queue<int>();
		visitados.clear();
		
		for (int i=0;i<nc;i++){
			cin >> e1 >> e2;
			G[e1].push_back(e2);
			G[e2].push_back(e1);
		}
		while(1){	
			ttls.clear();
			cin >> e1 >> e2;
			ttls[e1] = e2;
			if(e1 == 0 && e2 == 0) break;	

			cout << "Case "<<casos++<<": ";
			cout << bfs(G,ttls,e1) << " nodes not reachable from node " << e1 << " with TTL = " << e2 << "." << endl;

		}
		cin.ignore();
	}
	return 0;
}
