#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>

using namespace std;

#define INF 99999
#define MAX 30

int Gme[MAX][MAX];
int Gprof[MAX][MAX];

void initFloyd(int n){
	for(int k=0;k<n;k++){	
		for(int i=0;i<n;i++){	
			Gme[k][i] = INF;	
			Gprof[k][i] = INF;	
		}
		Gme[k][k] = 0;	
		Gprof[k][k] = 0;	
	}
}

void floyd(int n){
	for(int k=0;k<n;k++){	
		for(int i=0;i<n;i++){	
			for(int j=0;j<n;j++){
				if(Gprof[i][j] > Gprof[i][k] + Gprof[k][j] ){
					Gprof[i][j] = Gprof[i][k] + Gprof[k][j];
				}
				if(Gme[i][j] > Gme[i][k] + Gme[k][j] ){
					Gme[i][j] = Gme[i][k] + Gme[k][j];
				}
			}	
		}	
	}	
}

void imp(int A[][MAX],int n){
	cout << endl;
	for(int j=0;j<n;j++){
		cout  << setw(6) <<	char(j+'A')<< " " ;
	}
	cout << endl;
	for(int i=0;i<n;i++){	
		cout <<	char(i+'A')<< " " ;
		for(int j=0;j<n;j++){
			if(A[i][j] == INF){
				cout << setw(6) << "inf"  <<  " "; 
			}
			else
				cout << setw(6) << A[i][j] <<  " "; 
		}	
		cout << endl;
	}	
}

int main(){
	int n;

	while(cin >> n, n>0){
		char age,dir,x,y,me,prof;
		int e;

		vector<pair<int,int> > custos;

		initFloyd(MAX);

		for(int i=0;i<n;i++){
			cin >> age >> dir >> x >> y >> e;	
			//cout << age << dir << x << y << e << endl;
			if(x==y) e = 0;
			if(age == 'Y'){ 
				//cout << "jovem "; 
				if(dir == 'U'){
					//cout << "unidirecional ";
					Gme[x-65][y-65] = e;
				}
				else{
					//cout << "bidirecional ";
					Gme[x-65][y-65] = e;
					Gme[y-65][x-65] = e;
				}
			}
			else{

				//cout << "velho "; 
				if(dir == 'U'){
					//cout << "unidirecional ";
					Gprof[x-65][y-65] = e;
				}
				else{
					//cout << "bidirecional ";
					Gprof[x-65][y-65] = e;
					Gprof[y-65][x-65] = e;
				}
			}
			///cout << "de " <<x-65<< " para " << y-65<< " custo = " << e << endl;
		}

		cin >> me >> prof;
		me -= 'A';
		prof -= 'A';
		//imp(Gme,4);
		//imp(Gprof,4);
		floyd(MAX);
		//imp(Gme,MAX);
		//imp(Gprof,MAX);
		
		int resp=INF,local=0;	
		
		for(int i=0;i<MAX;i++){
			if(Gme[me][i]!=INF && Gprof[prof][i]!=INF){
				//cout << "comparando " << resp << " com" << (Gme[me][i] + Gprof[prof][i])<< endl;
				if(resp > (Gme[me][i] + Gprof[prof][i]) ){
					resp = Gme[me][i] + Gprof[prof][i];
					local = i;
				}
			}
			custos.push_back(make_pair(i,Gme[me][i] + Gprof[prof][i]));
		}
		sort(custos.begin(),custos.end());

			//for(auto& it: custos){
			//	cout << char(it.first + 'A') << "  " << it.second << endl;
			//}
		if(resp == INF)
			cout << "You will never meet." << endl;
		else{
			cout << resp  ;
			//cout << resp << " " << (char)(local+'A') << endl;
			for(auto& it: custos){
				if(it.second == resp){
					cout << " " << char(it.first + 65) ;
				}
			}
			cout<< endl;
		}

	}
	return 0;
}
