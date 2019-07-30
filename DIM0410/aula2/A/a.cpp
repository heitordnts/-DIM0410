#include <iostream>

using namespace std;

int main(){
	int m,n,c=1,mines;
	char field[100][100];

	while(1){
		cin >> n >> m;

		if(n == 0 && m == 0) break;

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> field[i][j];
			}
		}
		//processar o field
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				mines=0;
				if(field[i][j] == '*') continue;

				for(int k=-1;k<=1;k++){
					for(int l=-1;l<=1;l++){
						if(k==0 && l ==0) continue;

						if(field[i+k][j+l] == '*') mines++;
					}
				}
				field[i][j] = mines+48;
			}
		}

		cout << "Field #" << c++ << ":\n"; 

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout << field[i][j];	
			}
			cout << endl;
		}
		cout << endl;
	}
	
	return 0;
}
