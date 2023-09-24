#include <stdio.h>

int x, y, inp;

int recur(int inp){
	if(inp == 0){
		return x;
	}else if(inp == 1){
		return y;
	}else{
		return recur(inp-1) + recur(inp-2);
	}
}


int main(){
	int testcase;
	scanf("%d", &testcase);
	getchar();
	
	for(int i = 0; i<testcase; i++){
		scanf("%d", &inp);
		getchar();
		scanf("%d", &x);
		getchar();
		scanf("%d", &y);
		getchar();
		int sum = recur(inp);
		printf("Case #%d: %d\n", i+1, sum);
	}
	
	return 0;
}
