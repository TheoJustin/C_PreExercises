#include <stdio.h>
#include <math.h>

int main(){
	long long testcase, inp, check = 0, sum = 1;
	scanf("%d", &testcase);
	getchar();
	
	for(int i = 0; i<testcase; i++){
		scanf("%d", &inp);
		getchar();
		if(sum == inp){
			check = 1;
		}
		while(sum <= inp){
			sum *= 3;
			if(sum == inp){
				check = 1;
			}
		}
		if(check == 1){
			printf("Case #%d: %s\n", i+1, "True");
		}else{
			printf("Case #%d: %s\n", i+1, "False");
		}
		check = 0;
		sum = 1;
	}
	
	return 0;
}
