#include <stdio.h>

int main(){
	int testcase;
	scanf("%d", &testcase);
	getchar();
	
	int x = 1;
	int t;
	int s = testcase-1;
	char abc[30] = "abcdefghijklmnopqrstuvwxyz";
	for(int i = 0; i<testcase; i++){
		for(int k = 0; k<s; k++){
			printf(" ");
		}
		s--;
		for(int j = 0; j<x; j++){
			t = j%26;	
			printf("%c", abc[t]);
		}
		printf("\n");
		x+=2;
	}
	
	return 0;
}
