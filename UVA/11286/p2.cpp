#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, course, f=0;

	while(cin >> n, n != 0){
	    map<vector<int>,int > froshs;
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
        int maior = -1;
        for(auto it = froshs.begin();it != froshs.end();it++){
            int most = it->second;
            if(most > maior) maior = most;
        }
        int count = 0;
        for(auto it = froshs.begin();it != froshs.end();it++){
           if(it->second == maior){
                count+=it->second;
           } 
        }
        cout << count << endl; 
        froshs.clear();
	}
	return 0;
}
