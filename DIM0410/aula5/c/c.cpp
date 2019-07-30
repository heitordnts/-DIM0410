#include <iostream>
#include <map>

using namespace std;

int main(){
	map<int,int> qid_time;
	char b[32];
	int qid, time, num_queries;

	while(cin >> b, b[0] != '#'){
		cin >> qid >> time;
		qid_time[qid] = time;
	}
	cin >> num_queries;

	int timer=1;
	while(timer <= 3000){
			
		for(map<int,int>::iterator it=qid_time.begin(); it!=qid_time.end(); it++){
			if(timer % it->second == 0){
				cout << it->first << endl;
				num_queries--;
			}
			if(num_queries <= 0) break;
		}
		timer++;
		if(num_queries <= 0) break;
	}
	return 0;
}
