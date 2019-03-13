#include <iostream>

int main(){
	int T,a,b,c;

	std::cin >> T;

	for(int i=1;i<=T;i++){
		std::cin >> a >> b >> c;

		if(a>b && a>c){
			if(b>c)
				std::cout << "Case " << i << ": "  << b << std::endl;
			else		
				std::cout << "Case " << i << ": "  << c << std::endl;
		}
		
		if(b>a && b>c){
			if(a>c)
				std::cout << "Case " << i << ": "  << a << std::endl;
			else
				std::cout << "Case " << i << ": "  << c << std::endl;
		}
		if(c>b && c>a){
			if(b>a)
				std::cout << "Case " << i << ": "  << b << std::endl;
			else
				std::cout << "Case " << i << ": "  << a << std::endl;
		}
	}
	
	return 0;
}
