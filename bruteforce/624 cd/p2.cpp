#include <bits/stdc++.h>

using namespace std;


typedef vector<int> veci;

int sum(veci conj,veci tracks, int N, int i, veci &elements){
	static int result = 0;
	int current_sum = accumulate(conj.begin(), conj.end(), 0);
	int tracks_size = tracks.size();	
	int x = tracks[i];	
	if(tracks_size > i){	
		sum(conj,tracks,N,i+1,elements);

		conj.push_back(x);

		sum(conj,tracks,N,i+1,elements);
	}
	if(result < current_sum && current_sum <= N){
		result = current_sum;

		elements.assign(conj.begin(), conj.end());
	}

	return result;

}


int main(){
	int N;
	int	t; 
	int track;	
	while(!cin.eof()){
		vector<int> tracks;
		veci conj, elements;
		cin >> N;

		cin >> t;

		for(int i=0;i<t;i++){
			cin >> track;
			tracks.push_back(track);
		}//fim de entrada
		
		int s = sum(conj, tracks, N, 0,elements);
		for_each(elements.begin(), elements.end(), [&] (int n) { cout << n << " ";});

		cout << "sum: " << s << endl;

		
		tracks.clear();
		conj.clear();
	}

	return 0;
}
