#include <bits/stdc++.h>

using namespace std;

struct numLetter{
	int num;
	char state;
};

struct entry{
	numLetter a[52];
	int size;
};

void convert(entry &states,const char *s){
	int i=0,k=0,qtd=0;
	char c = s[0]; 
	while(s[i] != 0){
		if(s[i] != c){
			states.a[k].state = c;
			states.a[k].num = qtd;
			k++;
			c = s[i];
			qtd = 0;
		}
		i++;
		qtd++;
	}
	states.a[k].state = c;
	states.a[k].num = qtd;
	k++;
	c = s[i];
	qtd = 0;
	states.size = k;

}


void print(entry e){
	for(int i=0;i<e.size;i++){
		cout <<e.a[i].num<< e.a[i].state;

	}	

	cout << endl;
}


bool compare(entry f,entry e){
	int i=0,j=0;

	while(i < e.size){
		if(e.a[i].state == f.a[j].state){
			if(e.a[i].num <= f.a[j].num){
				j++,i++;	
			}
			else{
				return false;
			}
		}
		else{
			j++;
			if(f.a[j].state == 0 && e.a[i].state != 0)
				return false;
		}

	}
	return true;

}
int main(){
	char s[1000000];
	char q[120];
	entry f;	
	int t,k=0,fi=0;
	
	
	cin >> s;
	convert(f,s);
	//print(c[0]);
	cin >> t;
	
	for(int i=0;i<t;i++){
		entry e;
			
		cin >> q;
		convert(e,q);
		cout << compare(f,e)<< endl;
		
	}

	return 0;
}

