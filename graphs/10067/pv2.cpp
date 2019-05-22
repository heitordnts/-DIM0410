#include <iostream>
#include <cstring>
#include <queue>
#include <unordered_set>

using namespace std;

#define ToINT(X) (X.data[0]*1000 + X.data[1]*100 + X.data[2]*10 + X.data[3])

struct Node{
	int data;
	int level;
};

queue<Node> q;
//unordered_set<int> visited;
int visited[10001];
int pot10[] = {1000,100,10,1};

//void printS(Node &state){
//	for(int i=0;i<4;i++)
//		cout << state.data[i] << " ";
//	cout << endl;
//}

inline bool success(Node &a,Node &b){
	return a.data == b.data;
}

int bfs(Node orig, Node targ){
	q.push(orig);
	int current_lvl = 0;
	int newValue,d;
	Node aux,temp;
	while(!q.empty() &&  current_lvl < 15){
		temp = q.front();
		current_lvl = temp.level;
		q.pop();
		visited[temp.data] = 1;
		if(current_lvl %13 == 0) 
			cout << "filhos de " << temp.data << " nivel " << temp.level << " queue size: " << q.size() << endl;
		//printS(temp);
		if(success(temp,targ)) return temp.level;
		//for(int i=0;i<4;i++){
		//	aux = temp;
		//	d = ((aux.data / (pot10[i])) % 10 );
		//	//cout << aux.data << "/" << pot10[i] << "%" << 10 << " = " << d << endl;
		//	if(d == 9){
		//		newValue = (aux.data - 9*pot10[i]);
		//	}
		//	else{
		//		newValue = (aux.data + pot10[i]);
		//	}
		//	aux.data = newValue;
		//	//cout << temp.data << " -> " << aux.data << endl;
		//	aux.level = temp.level+1;
		//		
		//	//if(visited.find(aux.data) == visited.end()){
		//	if(visited[newValue] == 0){
		//		//visited[newValue] = 1;
		//		q.push(aux);
		//		//printS(aux);
		//	}
		//}
		//cout << endl;
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
			//cout << temp.data << " -> " << aux.data << endl;
			aux.level = temp.level+1;

			//if(visited.find(aux.data) == visited.end()){// && 
			if(visited[newValue] == 0){
				q.push(aux);
				//printS(aux);
			}
				//printS(aux);
		}
	}
		
	cout << "done\n";

	return -1;
}


int main(){
	Node origin,target;
	int t, n_fbd,a;
	int aux=0;	
	origin.data = target.data = 0;
	cin >> t;
	while(t--){
		memset(visited,0,10000);
		origin.level = 0;
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
			cout << aux << endl;
			visited[aux] = 1;
			//visited.insert(aux);	
		}	
		cout <<	bfs(origin, target) << endl;


		cin.ignore();
		//visited.clear();
		q = queue<Node>();
	}

	
	return 0;
}
