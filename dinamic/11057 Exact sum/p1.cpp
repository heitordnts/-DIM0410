#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n;
	int books[10001];
	int money;

	while(cin >> n){
		for(int i=0;i<n;i++) cin >> books[i];
		cin >> money;

		sort(books,books+n);
			
	}


	return 0;
}
