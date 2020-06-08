#include <iostream>

int main(){

	int v[]={5,4,1,3,2};
	bool ok = true;
	for(int i =0;i<4;i++){
		if(v[i] - v[i+1] >= 2){
			ok = false;	
		}	
	}
	if(!ok)
		std::cout << "no\n";
	else
		std::cout << "yes\n";


	
	return 0;
}
