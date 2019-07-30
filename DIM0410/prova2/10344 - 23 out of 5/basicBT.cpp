#include <iostream>
#include <vector>

using namespace std;

vector<int> subset;
int n = 3;
int v[1024] = {1,2,3,4,5};

int mask[1024] = {0};//mascara que mostra quais elementos estao disponiveis para serem escolhidos

int count = 0;
void permutations(int k){
	if( k == n ){
		count++;
		//for(auto i : subset){
		//	cout << i << " " ;
		//}
		//cout << endl;
	}
	else{
		for(int i=0;i<n;i++){
			if(mask[i]==0){
				subset.push_back(v[i]);
				mask[i] = 1;
				permutations(k+1);
				subset.pop_back();
				mask[i] = 0;
			}
		}
	}
}



int main(){
	cin >> n;
	permutations(0);
	cout << "numero de combinacoes: " << count << endl;
}
