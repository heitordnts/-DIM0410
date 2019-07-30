#include <stack>
#include <iostream>
#include <string>

using namespace std;

int diamonds(string line){
	stack<char> pilha;
	char c, topo;
	int d = 0;
	for(int i=0; i< line.size();i++){
		c = line[i];
		if(c == '.') continue;
		
		if(c == '<')
			pilha.push(c);
		
		if(!pilha.empty()){
			if(c == '>' && pilha.top() == '<'){

				pilha.pop();
				d++;
			}
		}
	}
	return d;

}

int main(){
	string line;
	int N;

	cin >> N; 
	while(N--){
		cin >> line;
		cout << diamonds(line) << endl;
	}


	return 0;
}
