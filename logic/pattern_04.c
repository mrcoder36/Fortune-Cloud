#include<stdio.h>
int main(){
    int count = 1;
	int r,c;
	for(r=1;r<4;r++){
		for(c=1;c<4;c++){
			printf("%d ",count);
            count++;
		}
		printf("\n");	
	}
}