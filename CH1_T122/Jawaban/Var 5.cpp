#include <stdio.h>
#include <string.h>

int main(){
	
	char str[10001];
	scanf("%s", &str);
	getchar();
	
	char arr[100] = "1234567890aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
	
	int len = strlen(str);
	int a[100] = {};
	for(int i = 0; i<len; i++){
		for(int j = 0; j<62; j++){
			if(arr[j] == str[i]){
				a[j]++;
			}
		}
	}
	for(int i = 0; i<62; i++){
		for(int j = 0; j<a[i]; j++){
			printf("%c", arr[i]);
		}
	}
	printf("\n");
	
	return 0;
}
