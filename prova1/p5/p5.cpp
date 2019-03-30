#include <bits/stdc++.h>

using namespace std;

void tolowerCase(string &s){
	std::locale loc;
	for(int i=0; i< s.length();i++){
		s[i] = tolower(s[i], loc);
	}

}

struct comp {
  bool operator() (string a, string b) const{
		return lexicographical_compare(a.begin(),a.end(),b.begin(),b.end());
	}
};

int main(){

	string s;
	map<string, pair<int,string>> anagrams_number;

	while(getline(cin, s), s!="#"){
		//transforma em lista de strings
		vector<string> splitted;
		char* cstr = const_cast<char*>(s.c_str());
		char* curr;

		curr = strtok(cstr, " ");
		while(curr!=NULL){
			splitted.push_back(curr);
			curr = strtok(NULL, " ");
		}
		//ordena as palavras
		vector<string> sorted(splitted);	
		for(int i=0;i<sorted.size();i++){
			tolowerCase(sorted[i]);	
			sort(sorted[i].begin(), sorted[i].end());	
			if(anagrams_number.find(sorted[i]) != anagrams_number.end())
				anagrams_number[sorted[i]].first += 1;
			else{
				auto p = make_pair(1, splitted[i]);
				anagrams_number[sorted[i]] = p;
			}
		}

	}

		vector<string> ananagrams;
		for(auto it=anagrams_number.begin();it!=anagrams_number.end(); it++){	
			if(it->second.first == 1) 
				//cout << it->second.second << endl; 
				ananagrams.push_back(it->second.second);	
		}
		sort(ananagrams.begin(), ananagrams.end());
		for(auto anng:ananagrams){	
			cout << anng << endl; 
		}

	return 0;
}
