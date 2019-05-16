#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int memo[1000][1000];

int main(){
	stringstream ss;
	string s;
	memset(memo,-1,1000*1000);
	memo[0][0] = 1;
	int t,r,c,l,aux;
	cin >> t;
	while(t--){
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
		}


		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				cout << memo[i][j] << " ";
			cout << endl;
		}
	}


	return 0;
}
