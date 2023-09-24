#include <stdio.h>

char map[105][105] = {};
int check = 0;
int testcase;

void floodFill(int py, int px){
	if(map[py][px+1] == ' ' && (px+1 < testcase)){
		map[py][px+1] = 'P';
		floodFill(py, px+1);
	}else if(map[py][px-1] == ' ' && (px-1 > -1)){
		map[py][px-1] = 'P';
		floodFill(py, px-1);
	}else if(map[py+1][px] == ' ' && (py+1 < testcase)){
		map[py+1][px] = 'P';
		floodFill(py+1, px);
	}else if(map[py-1][px] == ' ' && (py-1 > -1)){
		map[py-1][px] = 'P';
		floodFill(py-1, px);
	}
	
	if(map[py][px+1] == 'X'){
		check = 1;
	}else if(map[py][px-1] == 'X'){
		check = 1;	
	}else if(map[py+1][px] == 'X'){
		check = 1;		
	}else if(map[py-1][px] == 'X'){
		check = 1;	
	}
	
	
}

int main(){
	int px, py;
	scanf("%d", &testcase);
	getchar();
	for(int i = 0; i<testcase; i++){
		for(int j = 0; j<testcase; j++){
			scanf("%c", &map[i][j]);
			if(map[i][j] == 'P'){
				px = j;
				py = i;
			}
		}
		getchar();
	}
	
	floodFill(py, px);
	
	if(check == 1){
		printf("True\n");
	}else{
		printf("False\n");		
	}
	
	return 0;
}
