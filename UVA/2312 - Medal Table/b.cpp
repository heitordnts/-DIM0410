#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct ranks{
	string pais;
	int ouro,prata,bronze;

};

bool compare(ranks a, ranks b){
	int pa = 4*(a.ouro > b.ouro) + 2*(a.prata > b.prata) + (a.bronze > b.bronze);
	int pb = 4*(a.ouro < b.ouro) + 2*(a.prata < b.prata) + (a.bronze < b.bronze);
	return pa > pb;

}

int main(){
	int n;

	cin >> n;

	vector<ranks> medals(n);
	for(int i=0;i<n;i++){
		cin >> medals[i].pais >> medals[i].ouro>> medals[i].prata>> medals[i].bronze;


	}
	sort(medals.begin(),medals.end(),compare);

	for(int i = 0; i<n ; i++){

		cout << medals[i].pais <<" " << medals[i].ouro<< " " << medals[i].prata << " " << medals[i].bronze << endl;
		
	}

	return 0;
}

