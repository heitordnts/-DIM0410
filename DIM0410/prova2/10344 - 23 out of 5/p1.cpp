#include <iostream>
#include <vector>

using namespace std;

char av_ops[] = {'+','-','*'};//available operations
char all_ops[81][4];
char ops[4];
int v[5] = {0,0,0,0,0};

bool stillImpossible = true;
int mask[5] = {0};//mascara que mostra quais elementos estao disponiveis para serem escolhidos

vector<int> sol;


void make_ops(){
	int line=0;
	for(int i=0;i<3;i++){
	for(int k=0;k<3;k++){
	for(int j=0;j<3;j++){
	for(int p=0;p<3;p++){
		all_ops[line][0] = av_ops[i];
		all_ops[line][1] = av_ops[k];
		all_ops[line][2] = av_ops[j];
		all_ops[line++][3] = av_ops[p];
	}
	}
	}
	}

}

int operate(int x, int y, int op){
	switch(op){
		case '+':
			return x + y;
			break;
		case '-':
			return x - y;
			break;
		case '*':
			return x * y;
			break;
		default:
			break;
	}
}

int calc(int v[], char ops[]){
	int result = v[0];
	for(int i=0;i<4;i++){
		result = operate(result,v[i+1],ops[i]);	
	}
	return result;
}

void permutations(int k){
	if(stillImpossible == false)
		return ;
	if( k == 5 ){
		for(int j=0;j<81;j++){
			if(calc(sol.data(),all_ops[j]) == 23){
				stillImpossible = false;
				return;
			}
		}
	}
	else{
		for(int i=0;i<5 && stillImpossible;i++){
			if(mask[i]==0){
				sol.push_back(v[i]);
				mask[i] = 1;
				permutations(k+1);
				sol.pop_back();
				mask[i] = 0;
			}
		}
	}
}
int main(){
	make_ops();
	while(1){
		stillImpossible = true;
		for(int i=0;i<5;i++){
			cin >> v[i];
		}
		if(!(v[0] || v[1] || v[2] || v[3] || v[4])) break;
		permutations(0);
		if(stillImpossible) cout << "Impossible\n";
		else cout << "Possible\n";
	}
	return 0;
}
