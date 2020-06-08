#include <iostream>
#include <iterator>
#include <string>

int main(){
	std::istream_iterator<std::string> eos;
	std::istream_iterator<std::string> it(std::cin);


	while(it !=eos){

		std::cout << *it << " ";

		it++;

	}


}
