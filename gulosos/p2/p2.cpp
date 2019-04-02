#include <bits/stdc++.h>

using namespace std;

int main(){ 
	int n;

	cin >> n;

	while(n--){	
		int m,c;
		vector<int> coins;
		cin >> m;
		for(int i=0;i<m;i++){
			cin >> c;
			coins.push_back(c);
		}//fim de entrada

		int x = coins.back() * 2 - 1;
		int count = 0;

		auto p = coins.rbegin();
		
		for(;p != coins.rend();p++){
			if(x - *p < 0) continue;
			else {
				x = x - *p;
				count ++;
			}
		}
		cout << count << endl;	
	}
	return 0;
}


