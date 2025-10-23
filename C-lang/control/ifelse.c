#include<stdio.h>

int main(){
	
	int age = 0;	
	printf("Enter a number: ");
	scanf("%d", &age); // to take input from users

	if(age == 15) {
		printf("You can apply for SCC");
	}
	else if(age == 18) {
		printf("You can apply for HSC");
	} 
	else if(age == 20) {
		printf("You can apply for Degree");
	}
	else if(age == 22) {
		printf("You can apply for Masters");
	}
	else {
		printf("You can apply in Fortune cloud");
	}
	
}
