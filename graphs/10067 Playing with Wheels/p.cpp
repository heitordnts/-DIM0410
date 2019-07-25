#include <iostream>
#include <cstring>
#include <queue>
#include <unordered_set>

using namespace std;

#define ToINT(X) (X.data[0]*1000 + X.data[1]*100 + X.data[2]*10 + X.data[3])

struct Node{
	int data[4];
	int level;
};

queue<Node> q;
unordered_set<int> forbidden;
unordered_set<int> visited;

void printS(Node &state){
	for(int i=0;i<4;i++)
		cout << state.data[i] << " ";
	cout << endl;
}

bool success(Node &a,Node &b){
	return ToINT(a) == ToINT(b);
}


int bfs(Node orig, Node targ){
	q.push(orig);
	int current_lvl = 0;
	while(!q.empty() &&  current_lvl < 15){
		Node temp = q.front();
		current_lvl = temp.level;
		q.pop();
		cout << "filhos de " << ToINT(temp) << " nivel " << temp.level << " queue size: " << q.size() << endl;
		//printS(temp);
		if(success(temp,targ)) return temp.level;
		for(int i=0;i<4;i++){
			Node aux = temp;
			int newValue = (aux.data[i] + 1)%10;
			aux.data[i] = newValue;
			aux.level = temp.level+1;
				
			if(visited.find(ToINT(aux)) == visited.end()){
				q.push(aux);
				//printS(aux);
				if(aux.data[i] == targ.data[i]){
					break;
				}

			}
		}
		for(int i=0;i<4;i++){
			Node aux = temp;
			int newValue = (aux.data[i] - 1 + 10)%10;
			aux.data[i] = newValue;
			aux.level = temp.level+1;
			if(visited.find(ToINT(aux)) == visited.end()){// && 
				//forbidden.find(ToINT(aux)) == forbidden.end()){
				q.push(aux);
				if(aux.data[i] == targ.data[i]){
					break;
				}
				//printS(aux);
			}
		}
		
	}
	cout << "done\n";

	return -1;
}


int main(){
	Node origin,target;
	int t, n_fbd;
	Node aux;	
	cin >> t;
	while(t--){
		origin.level = 0;
		for(int i=0;i<4;i++)
			cin >> origin.data[i];
		for(int i=0;i<4;i++)
			cin >> target.data[i];

		cin >> n_fbd;
		
		for(int i=0;i<n_fbd;i++){
			for(int j=0;j<4;j++){
				cin >> aux.data[j];	
			}
			visited.insert(ToINT(aux));	
		}	
		cout <<	bfs(origin, target) << endl;


		cin.ignore();
		visited.clear();
		q = queue<Node>();
	}

	
	return 0;
}
