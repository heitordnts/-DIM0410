#include <bits/stdc++.h>
using namespace std;


bool has_ascend(vector<int> &v){
	int less_until_i = v[0];
	int i = 1;
	int n = v.size();
	
	while(i<n){
		if(less_until_i < v[i]) 
			return true;
		less_until_i = min(v[i], less_until_i);
		i++;
	}
	return false;
}
void print(vector<int> v){
	for(int i=0;i<v.size();i++){
		printf("%d ",v[i]);
	}
	putchar('\n');
}
int main(){
	int n,l;
	vector<vector<int> > non_increase_seqs;
	scanf("%d",&n);

	for(int i=0;i<n;i++){
		scanf("%d",&l);
		vector<int> aux;
		aux.resize(l);
		for(int j=0;j<l;j++){
			scanf("%d",&aux[j]);
		}
		if(!has_ascend(aux)){
			non_increase_seqs.push_back(aux);
		}
	}//end input

	long long int p = 0;
	//combine the non_incresing and count how many has ascends	
	for(int i=0;i<non_increase_seqs.size();i++){
		for(int j=0;j<non_increase_seqs.size();j++){
			vector<int> s;
			s.resize(non_increase_seqs[i].size()+non_increase_seqs[j].size());
			//fill s
			for(int k=0,ii=0,jj=0;k<s.size();k++){
				if(k<non_increase_seqs[i].size()){
					s[k] = non_increase_seqs[i][ii++];	
				}
				else{
					s[k] = non_increase_seqs[j][jj++];	
				}
			}
			p += !has_ascend(s);
		}
	}

	printf("%lld\n",n*n - p);

	return 0;
}
