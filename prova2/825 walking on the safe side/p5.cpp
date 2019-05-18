#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int memo[20000][20000];

int bt(int x, int y){
	if(x < 0 || y < 0) return 0;
	if(memo[x][y] != -1 || memo[x][y] == 0){
		return memo[x][y];
	}
	else{
		memo[x][y] = bt(x-1,y) + bt(x,y-1);
		return memo[x][y];
	}
}

int main(){
	stringstream ss;
	string s;
	int t,r,c,l,aux;
	cin >> t;
	cin.ignore();
	while(t--){
		memset(memo,-1,1000*1000);
		memo[0][0] = 1;
		cin >> r >> c;
		cin.ignore();
		for(int i=0;i<r;i++){
			//cout << "line:";
			getline(cin, s);	
			ss.str(s);
			ss >> l;
			//cout << l << endl;
			while(ss.good()){
				ss >> aux;
				//cout << ss.str() << endl;
				memo[l-1][aux-1]=0;
			}
			ss.clear();
		}//end of input
		cin.ignore();
		cout << bt(r-1, c-1) << endl;
		if(t!=0) cout << endl;	
//		for(int i=0;i<r;i++){
//			for(int j=0;j<c;j++){
//				cout << memo[i][j] << " " ;
//			}
//			cout << endl;
//		}
	}


	return 0;
}
