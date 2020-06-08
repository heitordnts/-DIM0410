#include <iostream>


int main(){
	int T,a,b,c,safe;

	std::cin >> T;

	for(int i=1;i<=T;i++){
		std::cin >> a >> b >> c;
		
		if(a>b && b>c || c>b && b>a) safe = b;
		else if(a>c && c>b || b>c && c>a) safe = c;
		else if(b>a && a>c || c>a && a>b) safe =a ;
		

		std::cout << "Case " << i << ": " << safe << std::endl;
	}
	return 0;
}
