#include <iostream>
#include <stack>
#include <queue>


int main(){
	stack<int> pilha;
	vector<int> line;
	int N;

	while(cin >> N, N > 0){
		int c;
		for(int i=0;i<N;i++){
			if(cin >> c, c == 0) break;
			//else
			line.push_back(c);
		}
		//verificar permutacao
		int j=1;
		for(int i=0;i<N;i++){
			int atual = line[i];
			
			for(;j<=N;j++){
				pilha.push(j);
				if(j==atual){
					pilha.pop();
					break;
				}
			}

		}
		//--
		line.clear();
	}


	return 0;
}
