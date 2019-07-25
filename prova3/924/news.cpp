#include <bits/stdc++.h>

using namespace std;

unordered_set<int> visitados;
map<int, list<int> > G;

int dias[2501];
int niveis[2501];

int bfs(int orig){
	queue<int> q;
	niveis[orig] = 1;	
	int temp,dia=0;
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

		for(auto &No: G[temp]){
			if( niveis[No] == 0)
				niveis[No] = niveis[temp] + 1;
			if(visitados.find(No) == visitados.end()){
				q.push(No);			
			}
		}
	}
}

void dfs(int a,int dia){
	visitados.insert(a);
	cout << a << ": " ;
	for(auto &i:G[a]){
		cout << i << endl;
		if(visitados.find(i) == visitados.end() || dia < dias[dia]){
			dias[dia]++;	
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
		memset(niveis,0,sizeof niveis);
		//dfs(c,0);
		bfs(c);
		/*
		
		*/
		for( int i=0;i<e;i++){
			dias[niveis[i]]++;
		}
		for(int i=0;i<10;i++){
			cout << dias[i] << " " ;
		}
		cout << endl;
		cout << endl;
		
	}
	
	return 0;
}
