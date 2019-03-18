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

	int timer=0;

	for(int i = 0; i < num_queries;++i){
		while(1){
			qid_time.find(timer);
		}

		cout << "\n\n\n";
	}

	return 0;
}
