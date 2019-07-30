#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	int heads[20000], knights[20000];

	while(cin >> n >> m , !(m==0 && n == 0)){
		int head, knight_height;
		for(int i=0;i<n;i++){
			cin >> head;
			heads[i] = head;
		}

		for(int i=0;i<m;i++){
			cin >> knight_height;
			knights[i] = knight_height;
		}
		
		sort(heads,heads+n);
		sort(knights,knights + m);

		if(m < n){
			cout << "Loowater is doomed!" << endl;
			continue;
		}
		bool slayed = true;
		int j=0,cost = 0;;	
		for(int i=0;i<n;i++){

			while(knights[j] < heads[i] && j < m){
				j++;
			}
			cost += knights[j++];
			
			if(j > m && i<n){
				slayed = false;
				break;
			}
		}
		if(slayed){
			cout << cost <<endl;
		}
		else
			cout << "Loowater is doomed!" << endl;



	}

	return 0;
}
