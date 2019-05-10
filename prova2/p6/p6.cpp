#include <bits/stdc++.h>

using namespace std;

string sol = "";
int conta1s(int x,int N){
	int uns = 0;
	for(int i=0;i<N;i++){
		if((x>>i) & 1 != 0){
			uns++;
			sol="1"+sol;
		}
		else{
			sol="0"+sol;
		}
	}
	return uns;
}


int main(){
	
	int t,N,H;
	scanf("%d", &t);
	cin.ignore();
	for(int i=0;i<t;i++){
		//scanf("%*c");
		scanf("%d %d",&N,&H);
		if(i!=0) printf("\n");	
	//	cout << conta1s(H,N)<< endl;

		for(int j=0;j<(1<<N);j++){
			if(conta1s(j,N) == H){
				cout << sol << endl;
				//printf("%s\n",sol.c_str());
			}
				sol="";
//			cout << conta1s(j,N) << "  " << j << endl;
		}

	}

	return 0;

}
