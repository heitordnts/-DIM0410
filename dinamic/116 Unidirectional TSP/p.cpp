#include <iostream>



unsigned int

void read_matrix(int M[][100],int r, int c){
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			std::cin >> M[i][j];
}

int main(){
	int n_rows,n_cols;
	int M[10][100];

	while(std::cin >> n_rows >> n_cols){
		read_matrix(M,n_rows,n_cols);
		



	}


	return 0;
}
