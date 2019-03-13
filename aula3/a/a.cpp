#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	
	string text;
	int G = 1;;
	while(G != 0){
		cin >> G >> text;
		if(G == 0) break;
		for(int i=0; i <= text.size()/G + 1 ; i+=G){
			reverse(text.begin() + i, text.begin() + i + G );

		}

		cout << text << endl;
	}
}
