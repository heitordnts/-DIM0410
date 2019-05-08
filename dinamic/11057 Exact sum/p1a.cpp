#include <iostream>
#include <algorithm>

using namespace std;

inline int ABS(int x){
	return x < 0 ? -1*x : x;
}
int main(){
	int n;
	int books[10001];
	int money,diff=999999;
	int sol1,sol2,x,y;
	while(cin >> n){
		for(int i=0;i<n;i++) cin >> books[i];
		cin >> money;
		sort(books,books+n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){

				if(j == i) continue;

				x = books[i];
				y = books[j];

				if(x+y == money){
					//cout << x << " + " << y << " = " << x + y;
					//cout << "  diff = " << ABS(x-y) << endl;
					if(ABS(x-y) < diff){
						diff = ABS(x-y);
						sol1 = x;
						sol2 = y;
					}
				}
			}
		}
		cout << "Peter should buy books whose prices are " << sol1 << " and " << sol2 << ".\n\n";
		diff = 9999999;

	}

	return 0;
}
