#include <iostream>

using namespace std;

int main(){
	int rows,cols,t,aux;

	cin >> t;

	while(t > 0){
		cin >> rows >> cols;

		rows -= 2;
		cols -= 2;

		int xRows = rows / 3;
		aux = xRows * 3;
		if(aux < rows){
			xRows += 1;	
		}

		int xCols = cols / 3;
		aux = xCols * 3;
		if(aux < cols){
			xCols += 1;	
		}

		int mini = xRows * xCols;//minimum Xs
		cout << mini << endl;
		t--;
	}

	return 0;
}
