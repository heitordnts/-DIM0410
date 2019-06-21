#include <bits/stdc++.h>

using namespace std;

unordered_set<int> visitados;
map<int, list<int> > G;

int dias[2501];

int bfs(int orig){
	queue<int> q;
	int temp,dia=0;
	int M=0;
	q.push(orig);
	while(!q.empty()){
		temp = q.front();
		q.pop();
		if(temp == -1){
			dia++;
			continue;
		}
		if(visitados.find(temp) != visitados.end()){
			continue;
		}
		else{
			visitados.insert(temp);
		}

		cout << temp <<": "<< endl;
			
		M=0;
		for(auto &No: G[temp]){
			cout << No << endl;
			if(visitados.find(No) == visitados.end()){
				q.push(No);			
				dias[dia]++;
			}
		}
		q.push(-1);
	}
}

void dfs(int a,int dia){
	visitados.insert(a);
	cout << a << ": " ;
	for(auto &i:G[a]){
		cout << i << endl;
		dias[dia]++;	
		if(visitados.find(i) == visitados.end()){
			dfs(i,dia+1);
		}
	}
}

void imp(){
	for(auto o : G){
		cout << o.first << ": ";
		for(auto &a : o.second){
			cout << a << " " ;
		}
		cout<< endl;
	}
}

int main(){
	int e,n,f,t,c;
	cin >> e;	
	for(int i=0;i<e;i++){
		cin>>n;		
		for(int j=0;j<n;j++){
			cin >> f;
			G[i].push_back(f);
		}

	}

		//imp();
	cin >> t;
	for(int j=0;j<t;j++){
		cin >> c;
		memset(dias,0,sizeof dias);
		//dfs(c,0);
		bfs(c);
		for(int i=0;i<10;i++){
			cout << dias[i] << " " ;
		}
		cout << endl;
		
	}
	
	return 0;
}
