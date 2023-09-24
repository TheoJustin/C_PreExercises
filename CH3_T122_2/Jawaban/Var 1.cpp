#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int testcase;
char str[35];

int change(char str[], int x){
	for(x; str[x]!='\0' && str[x] != ']'; x++){
		if(str[x] >= 'a' && str[x] <='z'){
			printf("%c", str[x]);
		}else if(str[x] >='0' && str[x] <='9'){
			int number = atoi(str + x);
			while(str[x] != '['){
				x++;	
			}
			for(int k = 0; k<number; k++){
				if(k == number-1){
					x = change(str, x);	
				}
				else{
					change(str,x);	
				}
			}
		}
	}
	return x;
}

int main(){
	scanf("%d", &testcase);getchar();
	for(int i = 0; i<testcase; i++){
		scanf("%[^\n]", str); getchar();
		printf("Case #%d: ", i+1);
		change(str, 0);
		printf("\n");
	}
	return 0;
}
