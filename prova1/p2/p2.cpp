#include <bits/stdc++.h>

using namespace std;

int main(){
	map<vector<int>,int > froshs;
	int n, course, f=0;

	while(cin >> n, n != 0){
		for(int i=0;i<n;i++){
			vector<int> temp;
			for(int j=0;j<5;j++){
				cin >> course;
				temp.push_back(course);
			}
			sort(temp.begin(), temp.end());
			froshs[temp] += 1;
			temp.clear();
		}
		cout << max_element(froshs.begin(), froshs.end())->second << endl;

	}
	return 0;
}
