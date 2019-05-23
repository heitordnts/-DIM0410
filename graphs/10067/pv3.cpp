#include <iostream>
#include <cstring>
#include <queue>
#include <unordered_set>

using namespace std;

struct Node{
	int data;
	int level;
};

queue<Node> q;
unordered_set<int> visited;
//int visited[10001];
int pot10[] = {1000,100,10,1};

inline bool success(Node &a,Node &b){
	return a.data == b.data;
}

int bfs(Node orig, Node targ){
	q.push(orig);
	int current_lvl = 0;
	int newValue,d;
	Node aux,temp;
	while(!q.empty() /*&&  current_lvl < 15*/){
		temp = q.front();
		//current_lvl = temp.level;
		q.pop();
		if(visited.find(temp.data) != visited.end())
			continue;
		else
			visited.insert(temp.data);

		if(success(temp,targ)) return temp.level;

		for(int i=0;i<4;i++){
			aux = temp;
			d = ((aux.data / (pot10[i])) % 10 );
			if(d == 9){
				newValue = (aux.data - 9*pot10[i]);
			}
			else{
				newValue = (aux.data + pot10[i]);
			}
			aux.data = newValue;
			aux.level = temp.level+1;
				
			if(visited.find(aux.data) == visited.end()){
				q.push(aux);
			}
		}
		for(int i=0;i<4;i++){
			aux = temp;
			d = (aux.data / (pot10[i]) % 10 );
			if(d == 0){
				newValue = (aux.data + 9*pot10[i]);
			}
			else{
				newValue = (aux.data - pot10[i]);
			}
			aux.data = newValue;
			aux.level = temp.level+1;

			if(visited.find(aux.data) == visited.end()){// && 
				q.push(aux);
			}
		}
	}
	return -1;
}


int main(){
	Node origin,target;
	int t, n_fbd,a;
	int aux=0;	
	cin >> t;
	while(t--){
		origin.level = 0;
		origin.data = target.data = 0;
		for(int i=0;i<4;i++){
			cin >> a;
			origin.data+=pot10[i]*a;
		}
		for(int i=0;i<4;i++){
			cin >> a;
			target.data+=pot10[i]*a;
		}
		cin >> n_fbd;
		
		for(int i=0;i<n_fbd;i++){
			aux=0;
			for(int i=0;i<4;i++){
				cin >> a;
				aux+=pot10[i]*a;
			}
			if(aux != origin.data)
				visited.insert(aux);
			//visited[aux] = 1;
		}	
		cout <<	bfs(origin, target) << endl;

		cin.ignore();
		visited.clear();
		q = queue<Node>();
	}
	return 0;
}
