#include <stdio.h>
#include <string.h>

int main(){
	int testcase;
	scanf("%d", &testcase);
	getchar();
	
	int c, l, n, s, len, sum;
	
//	char num[256] = "1234567890";
//	char low[256] = "abcdefghijklmnopqrstuvwxyz";
//	char cap[256] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//	char sym[256] = "!@#$%^&*()";
	
	char str[256];
	for(int i = 0; i<testcase; i++){
		scanf("%s", &str);
		getchar();
		
		len = strlen(str);
		
		c = l = n = s = sum = 0;
		for(int j = 0; j<len; j++){
			if(str[j] >= 65 && str[j]<=90){
				c = 1;
			}else if(str[j] >= 33 && str[j] <= 47){
				s = 1;
			}else if(str[j] >= 48 && str[j] <= 57){
				n = 1;
			}else if(str[j] >= 97 && str[j] <= 122){
				l = 1;
			}
		}
		
		sum += (c+s+n+l);
		if(sum == 1){
			printf("None\n");
		}else if(sum == 2){
			printf("Weak\n");
		}else if(sum == 3){
			printf("Medium\n");
		}else if(sum == 4){
			printf("Strong\n");
		}
	

	}
	
	return 0;
}
