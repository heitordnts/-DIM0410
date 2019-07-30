#include <stdio.h>
#include <stdlib.h>

int main(){
	long int a,b;
	int n;

	scanf("%d",&n);

	for(int i=0;i<n;i++){
		scanf("%ld %ld",&a,&b);
		
		if(a>b){
			printf(">\n");
		}
		else if(a<b){
			printf("<\n");
		}
		else{
			printf("=\n");
		}
	}
	return 0;
}
