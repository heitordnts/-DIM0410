#include <iostream>
#include <queue>

using namespace std;


int main(){
	int n=1;
	queue<int> q;
	
	while(n > 0){
		cin >> n;
		for(int i=0;i<n;i++){
			q.push(i+1);
		}
		if( n==0) break;
		cout << "Discarded cards: ";	
		while(q.size() > 1){
			
			cout << q.front();
			if(q.size() != 2){
				cout << ", ";
			}
			q.pop();
			q.push(q.front());
			q.pop();
		}
		cout<<endl<< "Remaining card: " << q.front() << endl;
		q.pop();
	}
	return 0;
		}
