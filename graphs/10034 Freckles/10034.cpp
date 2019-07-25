#include <bits/stdc++.h>

using namespace std;

struct Aresta{
	int v1,v2;
	double custo;

	bool operator<(const Aresta& other){
		return this->custo < other.custo;
	}
};

inline double distancia(double x1,double y1,double x2, double y2){
	return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
//GLOBAIS ================================================
vector<Aresta> arestas;
double P[101][2];
int union_find[101];


int find_set(int point,int &h){
	h++;
	if(union_find[point] == point){
		return point;
	}
	else{
		return find_set(union_find[point],h);
	}
}

double make_union(const Aresta &a){
	int h1=0,h2=0;
	int r1 = find_set(a.v1,h1);
	int r2 = find_set(a.v2,h2);
	if (r1 != r2){
		if(h1 > h2){
			union_find[r2] = r1;
		}
		else{
			union_find[r1] = r2;
		}
	}
	else{
		return 0;
	}
	return a.custo;
}

int main(){
	int t;
	Aresta temp;
	
	cin >> t;

	cin.ignore();//linha em branco

	while(t--){
		int n;
		double d;
		//memset(P,0,sizeof P);
		
		cin >> n;

		for(int i=0;i< n;i++){
			union_find[i] = i;//inicializa o unionfind
		}
		arestas.clear();


		for( int i=0;i<n;i++){
			cin >> P[i][0];//x
			cin >> P[i][1];//y
			for(int j=i-1;j>=0;j--){
				d = distancia(P[i][0],P[i][1],P[j][0],P[j][1]);
				//cout << i << " -> " << j << " <=> " << d << endl;
				temp.v1 = i;
				temp.v2 = j;
				temp.custo = d;

				arestas.push_back(temp);
			}
		}
		sort(arestas.begin(),arestas.end());
		double best = 0;	
		for(auto &a:arestas){
			best += make_union(a);
		}
				
		
		cout << fixed << setprecision(2) << best << endl;
		if(t != 0)
			cout << endl;
	}

	return 0;
}


