#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int main(){
	int n,nq;
	set<int> friends[3];
	vector<int> onlyidid[3];
	cin >> n;
	int cases=0;
	while(n--){
	cases++;
		for(int i=0;i<3;i++){
			int q;
			cin >> nq;
			for(int j=0;j<nq;j++){
				cin >> q;
				friends[i].insert(q);
			}
	
		}//recebida a entrada
		//processar caso teste
		cout << "Case #" << cases << ":" << endl;
		set<int>::iterator it;	

		bool only = true;
		int v[3];
		int maior = -1;;
		int nonly =0;
		for(int i=0;i<3;i++){
			nonly =0;
			for(it = friends[i].begin();friends[i].end() != it;it++){
				only = true;
				for(int j=0;j<3 ;j++){
					if(j == i) continue;
					if(friends[j].find(*it) != friends[j].end()){
//						cout << i << "procurando em " << j << "achou " << *it << endl;
						only = false;
						break;
					}
				}
				if(only){
					nonly++;
					 onlyidid[i].push_back(*it);
				}
			}
			if(nonly >= maior){
				maior = nonly;
			}	
		}
		for(int i=0;i<3;i++){
			if(onlyidid[i].size() == maior){
				cout << i+1 <<" "<<	maior << " ";
				sort(onlyidid[i].begin(), onlyidid[i].end());
				for(vector<int>::iterator a =onlyidid[i].begin();a!=onlyidid[i].end();a++)
					cout << *a<< " ";	
				cout << "\r";
				cout << endl;
			}
	}
		
		for(int i=0;i<3;i++){
			friends[i].clear();
			onlyidid[i].clear();
}
	}

	return 0;
}
