#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
	int T,num_solved, problem_id;	

	cin >> T;
	for(int i=1;i<=T;i++){
		set<int> friends[3];
		vector<int> onlyIdid[3];
		cout << "Case #" << i << ":" << endl;
		//receber entrada caso i
		for(int j = 0;j < 3;j++){
			cin >> num_solved;
			for(int k=0;k < num_solved;k++){
				cin >> problem_id;
				friends[j].insert(problem_id);
			}
		}//fim de entrada
		
		//para cada problema num set, verifica se existe nos outros sets
		//se existir entao o problema não é exclusivo do amigo j
		//se nao existir entao colocamos num vetor para os problemas exclusivos

		int qtd=0, maior=-1;
		for(int s=0;s< 3;s++){
			qtd=0;
			for(auto it = friends[s].begin();it != friends[s].end();it++){
				int notfound = 0;
				for(int j=0;j<3;j++){
					if(s == j) continue;
					if(friends[j].find(*it) == friends[j].end()){
						notfound++;
					}
					else break;
				}
				if(notfound == 2){
					qtd++;		
					onlyIdid[s].push_back(*it);
				}
			}
			if (maior < qtd) maior = qtd;

		}
		vector<int>::iterator it;
		for(int j=0;j < 3;++j){
			int size = onlyIdid[j].size();
			if(size == maior)
				if(size <= 0)
					cout << j+1 << " " << size << endl;
				else{
					cout << j+1 << " " << size << " ";
					for(it=onlyIdid[j].begin();it+1!= onlyIdid[j].end();it++){
						cout << *it << " ";
					}
					cout << *it << endl;	
				}
		}
	}//casos testes
	return 0;
}
