#include <bits/stdc++.h>

using namespace std;

int main(){
	int c;

	cin >> c;
	while(0 < c--){
		int n,t,m,arrival_time;
		string bank;
		char ferry='l';
		queue<int> right, left;
		cin >> n >> t >> m;
		for(int i=0;i<m;i++){
			cin >> arrival_time;
			cout << "bank:";
			cin >> bank;

			if(bank[0] = 'l'){
				left.push(arrival_time);
			}
			if(bank[0] = 'r'){
				right.push(arrival_time);
			}
		}
		int time=0;
		int num=0;
		while(!(right.empty() && left.empty())){
			//verify left
			num=0;
			while(!left.empty() && left.front() <= time && num < n){
				num++;
				left.pop();
			}
			time+=t;
			ferry='r';
			while(num-- > 0) cout << time << endl;
			num=0;
			while(!right.empty() && right.front() <= time && num < n){
				num++;
				right.pop();
			}
			time+=t;
			ferry='l';
			while(num-- > 0) cout << time << endl;
		}






	}


}
