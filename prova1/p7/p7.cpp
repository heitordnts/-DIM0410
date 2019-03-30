#include <bits/stdc++.h>

using namespace std;

int main(){
	int N,C,w,p;
	string s,term,text;

	cin >> N;

	while(0 < N--){
		map<string, int> fit_count;
		map<string, string> category;

		cin >> C;
		for(int i=0;i<C;i++){
			cin >> s >> w >> p;
			fit_count[s] = p;
			for(int j=0;j<w;j++){
				cin >> term;
				category[term] = s;
			}

		}
		//problem description
		cin.ignore();
		set<string> split_text;
		while(getline(cin, text), text!=""){
			//get a line
			char * cstr = const_cast<char*>(text.c_str());
			char * curr;
			curr =  strtok(cstr, " .");
			while(curr != NULL){
				split_text.insert(curr);
				curr = strtok(NULL, " .");
			}	
		}//list of words done
		
		for(auto w : split_text){
			string cat;
			cat = category[w];
			if(cat != ""){
				fit_count[cat]--;
			}
		}
		for(auto p: fit_count){
			if(p.second <= 0)
				cout <<  p.first << endl;
		}

//		fit_count.clear();
//		category.clear();
//		split_text.clear();

	}//casos teste



	return 0;
}
