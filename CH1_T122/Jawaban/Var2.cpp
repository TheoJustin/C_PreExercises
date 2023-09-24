#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct data{
	char name[35];
};

struct data2{
	char name[35];
};

int main(){
	
	struct data nama[101];
	struct data2 nama2[101];
	
	int testcase;
	int x, len, check;
	char n1, n2;
	
	scanf("%d", &testcase);
	getchar();
	
	for(int i = 0; i<testcase; i++){
		scanf("%[^\n]", &nama[i].name);
		getchar();
		
		len = strlen(nama[i].name);		
		x = 0;
		check = 1;
		for(int j = len-1; j>=0; j--){
			n1 = tolower(nama[i].name[x]);
			n2 = tolower(nama[i].name[j]);
			if(n1 != n2){
				check = 0;
				break;
			}
			x++;
		}
		
		if(check == 1){
			printf("Palindrome\n");
		}else if(check == 0){
			printf("Not Palindrome\n");
		}
	}
	return 0;
}
