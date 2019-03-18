#include <iostream>
#include <set>

using namespace std;

int main(){
	int N,M;
	set<int> s1,s2;

	while(cin >> N >> M ,N != 0 || M != 0){
		int cd, common_cds;
		common_cds = 0;
		for(int i=0;i<N;i++){		
			cin >> cd;
			s1.insert(cd);
		}

		for(int i=0;i<M;i++){
			cin >> cd;
			s2.insert(cd);
		}
		set<int>::iterator found;
		for(set<int>::iterator it=s1.begin(); it!=s1.end();it++){
//			cout << *it << " " << endl;
			if(s2.find(*it) != s2.end()) common_cds++;
		}
		cout << common_cds << endl;		
		s1.clear();
		s2.clear();
	}


	return 0;
}
