#include <iostream>



int M[10][100];
int rows,cols;
int sol[100];

inline int fix(int x){
	if(x<0)    return rows-1;
	if(x>rows) return 0;
	return x;
}

int f(int pr,int pc,int v){
	if(pc < cols){
		int value = M[pr][pc]+v;
		sol[pc] = value;
		//std::cout << pr << "-" << pc << std::endl;
		f(fix(pr-1),pc+1,value);		
		f(pr,pc+1,value);		
		f(fix(pr+1),pc+1,value);		
	}
	else{
		for(int i=0;i<cols;i++)
			std::cout << sol[i] << " ";
		std::cout << std::endl;
		//std::cout << pr << " ";
		//std::cout << v << std::endl;
	}
}

int min_path(){	
	int path[cols];
	//sp start point	
	for(int sp=0;sp<rows;sp++){
		
	}

}

void read_matrix(int M[][100],int r, int c){
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			std::cin >> M[i][j];
}

void print_matrix(int M[][100],int r, int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			std::cout << M[i][j] << " ";
		std::cout << std::endl;
	}
}

int main(){

	while(std::cin >> rows >> cols){
		read_matrix(M,rows,cols);
		f(0,0,0);
		//	print_matrix(M,n_rows,n_cols);	
	}

	return 0;
}
