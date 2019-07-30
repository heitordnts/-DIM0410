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
unordered_set<int> forbidden;
unordered_set<int> visited;
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
	while(!q.empty() &&  current_lvl < 1){
		Node temp = q.front();
		current_lvl = temp.level;
		q.pop();
		//cout << "filhos de " << temp.data << " nivel " << temp.level << " queue size: " << q.size() << endl;
		//printS(temp);
		if(success(temp,targ)) return temp.level;
		for(int i=0;i<4;i++){
			Node aux = temp;
			d = ((aux.data / (pot10[i])) % 10 );
			cout << aux.data << "/" << pot10[i] << "%" << 10 << " = " << d << endl;
			if(d == 9){
				newValue = (aux.data - 9*pot10[i]);
			}
			else{
				newValue = (aux.data + pot10[i]);
			}
			aux.data += newValue;
			cout << temp.data << " -> " << aux.data << endl;
			aux.level = temp.level+1;
				
			if(visited.find(aux.data) == visited.end()){
				q.push(aux);
				//printS(aux);
			}
		}
		cout << endl;
		for(int i=0;i<4;i++){
			Node aux = temp;
			d = (aux.data / (pot10[i]) % 10 );
			if(d == 0){
				newValue = (aux.data + 9*pot10[i]);
			}
			else{
				newValue = (aux.data - pot10[i]);
			}
			aux.data += newValue;
			cout << temp.data << " -> " << aux.data << endl;
			aux.level = temp.level+1;

			if(visited.find(aux.data) == visited.end()){// && 
				//forbidden.find(ToINT(aux)) == forbidden.end()){
				q.push(aux);
			}
				//printS(aux);
		}
	}
		
	cout << "done\n";

	return -1;
}

int f(int n,int d){
	char dir;
	cout << "< | >"<< endl;
	cin >> dir;
	switch(dir){
		case '<':
			if(	n % pot10[d] == 0)
				return (n + 9*pot10[d]);
			else
				return (n - pot10[d]);
			break;
		case '>':
			if(	n % pot10[d] == 9)
				return (n - 9*pot10[d]);
			else
				return (n + pot10[d]);
			break;
	}
}

int main(){
	int n,d;
	char o;
	cout << "digite o numero base: ";
	cin >> n;

	while(1){
		cout << "digito :";
		cin >> d;

		n = f(n,d);	
		cout << n << endl;
	}



	return 0;
}
