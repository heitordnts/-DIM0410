#include <bits/stdc++.h>

using namespace std;

int main(){
	int setc=1;	

	while(!cin.eof()){
		cout << "Set #" << setc++ << endl;
		int c,s,spec;
		double ma=0;

		cin >> c >> s;

		vector<int> specimens;
		vector< vector<int> > chambers;	
		for(int i=0;i<c;i++){
			vector<int> chamb;
			chambers.push_back(chamb);
		}
		for(int i=0;i<s;i++){
			cin >> spec;
			ma += spec;
			specimens.push_back(spec);
		}
		ma = ma/c;
		sort(specimens.begin(), specimens.end());
			
		int aux = s / 2;
		int sobra = s % 2;
		int j=0,k=s-1-sobra,i;
		double imbalance = 0;

		for(i=0;i<aux;i++){
			for(;j<k;j++,k--){
				int a,b;
				a = specimens[j];
				b = specimens[k];
				chambers[i].push_back(specimens[j]);
				chambers[i].push_back(specimens[k]);
				imbalance += abs( (a+b) - ma ); 
				k--;
				j++;
				break;
			}
		}
		if(sobra){
			imbalance += abs( (specimens[s-1]) - ma ); 
			chambers[i].push_back(specimens[s-1]);	
		}

		for(int l=0;l<c;l++){
			cout << " " << l << ": ";
			for(auto spc : chambers[l]){
				cout << spc << " ";	
			}
			cout << endl;
		}
		cout << "IMBALANCE = " << setprecision(5)  << fixed << imbalance << endl << endl;
	}

	return 0;
}
