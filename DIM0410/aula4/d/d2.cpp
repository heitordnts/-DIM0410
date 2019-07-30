#include <iostream>

using namespace std;

int main(){
	int N;
	int v[1000];
	while(cin >> N, N > 0){
		int c;



		for(int i=0;i<N;i++){
			if(cin >> c, c == 0) break;
			v[i] = c;
		}





		for(int i=0 ;i<N-1;i++){
			if(v[i] - v[i+1] >= 2){
				cout << "No" << endl;
				break;
			}
		}
	}


	return 0;
}
