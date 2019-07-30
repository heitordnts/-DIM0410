#include <bits/stdc++.h>

using namespace std;


int closest(int *sums,int n,int q){
	int i=0;
	int diff=1000000000;
	int close;
	for(i=0;i<n*n-n;i++){
		//cout << "diff: "<< q << " - " << sums[i] << " = "  << diff ;
		//cout << " close: " << close << endl;
		
		if( abs(q-sums[i])  < diff){
			diff = abs(q-sums[i]) ;	
			close = sums[i];
		}	
	}

	return close;
}
int main(){
	int n,m,x,q,c=1;
	int sums[1000000];
	int numbers[1000];

	while(cin >> n, n!=0){
		cout << "Case " << c++ << ":\n";
		for(int i=0;i<n;i++){
			cin>>x;
			numbers[i] = x;
		}
		int k=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j==i)continue;	
				sums[k++] = numbers[i] + numbers[j];	
			}
		}//todas as somas possiveis em sums
		
		cin >> m;

		for(int i=0;i<m;i++){
			cin >> q;
			cout << "Closest sum to " << q << " is " << closest(sums,n,q) << "." << endl;
		}
	}


	return 0;
}
