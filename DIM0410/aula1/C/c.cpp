#include <iostream>

int main(){
	int s;

	std::cin >> s;
	
	std::cout << s << ":\n";

	for(int i=2;i<=s/2 + 1;i++){
			int sum = 2*i - 1; //soma de i + (i-1)
			
			if(s % sum  == 0 || s % sum == i){
				std::cout << i << "," << i-1 << std::endl;
			}

		if(s % i == 0) 
			std::cout << i << "," << i << std::endl;
	
	
	}
	return 0;	
}
