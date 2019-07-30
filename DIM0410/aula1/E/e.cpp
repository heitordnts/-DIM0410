#include <iostream>
#include <string.h>

using namespace std;

void swapLetters(char *word,int i,int j){
	char temp = word[i];
	word[i] = word[j];
	word[j] = temp;
}

int main(){
	char a[10000],b[10000];
	int i,j,T;

	cin >> T;


	while(T>0){
		cin >> a >> b;
		
		for(i=0;a[i]!=0;i++){
			for(j=i;b[j] != 0; j++){
				if(a[i] == b[j]){
					swapLetters(b,i,j);
					break;
				}
			}
			if(b[j] == 0){
				break;
			}
		}
		cout << i << endl;
		T--;
	}




	return 0;	
}
