#include <stdio.h>

int main(){
	int p, e;
	
	scanf("%d", &p);
	getchar();
	scanf("%d", &e);
	getchar();
	
	int testcase;
	
	scanf("%d", &testcase);
	getchar();
	
	char inp[101];
	for(int i = 0; i<testcase; i++){
		scanf("%c", &inp[i]);
		getchar();
	}
	
	
	int check = 1;
	for(int i = 0; i<testcase; i++){
		if(inp[i] == 'e'){
			p-=2;
		}else if(inp[i] == 'E'){
			p-=5;
		}else if(inp[i] == 'o'){
			e-=2;
		}else if(inp[i] == 'O'){
			e-=5;
		}
		
		if(p<=0){
			printf("Enemy Win\n");
			check = 0;
			break;
		}
		if(e<=0){
			printf("Player Win\n");
			check = 0;
			break;			
		}
	}
	
	if(check == 1){
		printf("Draw\n");
	}
	
	return 0;
}
