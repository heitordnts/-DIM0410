#include <iostream>

using namespace std;

int forbidden[10000][4];

void printS(int *state){
	for(int i=0;i<4;i++)
		cout << state[i] << " ";
	cout << endl;
}

int main(){
	int origin[4],target[4];
	int t, n_fbd;
	cin >> t;
	while(t--){
		for(int i=0;i<4;i++)
			cin >> origin[i];
		for(int i=0;i<4;i++)
			cin >> target[i];

		cin >> n_fbd;
		
		for(int i=0;i<n_fbd;i++){
			for(int j=0;j<4;j++){
				cin >> forbidden[i][j]; }
		}	

		//for(int j=0;j<n_fbd;j++){
			//printS(forbidden[j]);
		//}
	}

	
	return 0;
}
