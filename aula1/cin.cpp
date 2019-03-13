#include <iostream>

int main(){
	
	int i;
	while(1){
	
		std::cin >> i;
		
		std::cout << "good bit: " << (std::cin.good()) <<std::endl;
		std::cout << "fail bit: " << (std::cin.fail()) <<std::endl;
		std::cout << "eof bit: " << (std::cin.eof()) <<std::endl;
		std::cout << "bad bit: " << (std::cin.bad()) <<std::endl;
		std::cin.clear();

	}

	
	return 0;
}
