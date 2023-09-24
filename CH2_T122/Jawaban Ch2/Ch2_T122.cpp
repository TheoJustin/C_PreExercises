#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <math.h>
#include <time.h>

char pMap[10][10];
char eMap[10][10];
char bMap[10][10];
char angle = 'x';
int check1 = 0, check2 = 0, check3 = 0, check4 = 0, check5 = 0;

void blankMap(){
	for(int x = 0; x<10; x++){
		for(int y = 0; y<10; y++){
			pMap[x][y] = '.';
			eMap[x][y] = '.';
			bMap[x][y] = '.';
		}
	}
}

void printMapPlayer(){
	printf("  ");
	for(int i = 0; i<10; i++){
		printf("%d ", i);
	}
	printf("\n");
	for(int x = 0; x<10; x++){
		printf("%d ", x);
		for(int y = 0; y<10; y++){
			printf("%c ", pMap[x][y]);		
		}
		printf("\n");
	}
}

int px, py;

void validateAdd(){
	check1 = 1;
	if(angle == 'h'){
		for(int i = py; i<py+5; i++){
			if(pMap[px][i] != '.' || i > 9){
				check1 = 0;
				break;
			}
		}
	}else if(angle == 'v'){
		for(int i = px; i<px+5; i++){
			if(pMap[i][py] != '.' || i > 9){
				check1 = 0;
				break;
			}
		}
	}
	
	
	if(check1 == 0){
		printf("[ ! ] CANNOT PLACE HERE! TRY AGAIN!\n");
	}
}

void putAddersField(){
	if(angle == 'h'){
		for(int i = py; i<py+5; i++){
			pMap[px][i] = 'A';
		}
	}else if(angle == 'v'){
		for(int i = px; i<px+5; i++){
			pMap[i][py] = 'A';
		}
	}
}

void askPlayerAdd(){
	do{
		printf("Town Name: Addersfield\n");
		printf("Orientation ['v' or 'h']\n");
		
		scanf("%c", &angle);
		getchar();
		
		printf("x and y coordinates [0-9] [0-9]: ");
		scanf("%d", &px);
		getchar();
		scanf("%d", &py);
		getchar();
		
		if(px > 9 || px < 0 || py <0 || py > 9){
			printf("[ ! ] CANNOT PLACE HERE! TRY AGAIN!\n");
		}else{
			validateAdd();
		}
	}while((angle == 'v' || angle == 'h') && check1 == 0);
	
	putAddersField();
	
}

void validateBea(){
	check2 = 1;
	if(angle == 'h'){
		for(int i = py; i<py+4; i++){
			if(pMap[px][i] != '.' || i > 9){
				check2 = 0;
				break;
			}
		}
	}else if(angle == 'v'){
		for(int i = px; i<px+4; i++){
			if(pMap[i][py] != '.' || i > 9){
				check2 = 0;
				break;
			}
		}
	}
	
	
	if(check2 == 0){
		printf("[ ! ] CANNOT PLACE HERE! TRY AGAIN!\n");
	}
}

void putBeachcastle(){
	if(angle == 'h'){
		for(int i = py; i<py+4; i++){
			pMap[px][i] = 'B';
		}
	}else if(angle == 'v'){
		for(int i = px; i<px+4; i++){
			pMap[i][py] = 'B';
		}
	}
}

void askPlayerBea(){
	do{
		printf("Town Name: Beachcastle\n");
		printf("Orientation ['v' or 'h']\n");
		
		scanf("%c", &angle);
		getchar();
		
		printf("x and y coordinates [0-9] [0-9]: ");
		scanf("%d", &px);
		getchar();
		scanf("%d", &py);
		getchar();
		
		if(px > 9 || px < 0 || py <0 || py > 9){
			printf("[ ! ] CANNOT PLACE HERE! TRY AGAIN!\n");
		}else{
			validateBea();
		}
	}while((angle == 'v' || angle == 'h') && check2 == 0);
	
	putBeachcastle();
	
}

void validateDav(){
	check3 = 1;
	if(angle == 'h'){
		for(int i = py; i<py+3; i++){
			if(pMap[px][i] != '.' || i > 9){
				check3 = 0;
				break;
			}
		}
	}else if(angle == 'v'){
		for(int i = px; i<px+3; i++){
			if(pMap[i][py] != '.' || i > 9){
				check3 = 0;
				break;
			}
		}
	}
	
	
	if(check3 == 0){
		printf("[ ! ] CANNOT PLACE HERE! TRY AGAIN!\n");
	}
}

void putDavenport(){
	if(angle == 'h'){
		for(int i = py; i<py+3; i++){
			pMap[px][i] = 'D';
		}
	}else if(angle == 'v'){
		for(int i = px; i<px+3; i++){
			pMap[i][py] = 'D';
		}
	}
}

void askPlayerDav(){
	do{
		printf("Town Name: Davenport\n");
		printf("Orientation ['v' or 'h']\n");
		
		scanf("%c", &angle);
		getchar();
		
		printf("x and y coordinates [0-9] [0-9]: ");
		scanf("%d", &px);
		getchar();
		scanf("%d", &py);
		getchar();
		
		if(px > 9 || px < 0 || py <0 || py > 9){
			printf("[ ! ] CANNOT PLACE HERE! TRY AGAIN!\n");
		}else{
			validateDav();
		}
	}while((angle == 'v' || angle == 'h') && check3 == 0);
	
	putDavenport();
	
}

void validateChe(){
	check4 = 1;
	if(angle == 'h'){
		for(int i = py; i<py+2; i++){
			if(pMap[px][i] != '.' || i > 9){
				check4 = 0;
				break;
			}
		}
	}else if(angle == 'v'){
		for(int i = px; i<px+2; i++){
			if(pMap[i][py] != '.' || i > 9){
				check4 = 0;
				break;
			}
		}
	}
	
	
	if(check4 == 0){
		printf("[ ! ] CANNOT PLACE HERE! TRY AGAIN!\n");
	}
}

void putChe(){
	if(angle == 'h'){
		for(int i = py; i<py+2; i++){
			pMap[px][i] = 'C';
		}
	}else if(angle == 'v'){
		for(int i = px; i<px+2; i++){
			pMap[i][py] = 'C';
		}
	}
}

void askPlayerChe(){
	do{
		printf("Town Name: Davenport\n");
		printf("Orientation ['v' or 'h']\n");
		
		scanf("%c", &angle);
		getchar();
		
		printf("x and y coordinates [0-9] [0-9]: ");
		scanf("%d", &px);
		getchar();
		scanf("%d", &py);
		getchar();
		
		if(px > 9 || px < 0 || py <0 || py > 9){
			printf("[ ! ] CANNOT PLACE HERE! TRY AGAIN!\n");
		}else{
			validateChe();
		}
	}while((angle == 'v' || angle == 'h') && check4 == 0);
	
	putChe();
}


int valid;
int vh, ex, ey;

void enemyAdd(){
	valid = 0;
	
	while(!valid){
		vh = rand() % 2;
	    ex = rand() % 10;
	    ey = rand() % 10;
	    valid = 1;
	    
	    if(vh == 1){
	        for(int i = ey; i < ey + 5; i++){
	            if(i >= 10 || eMap[ex][i] != '.'){
	                valid = 0;
	                break;
	            }
	        }
	    }else{
	        for(int i = ex; i < ex + 5; i++){
	            if(i >= 10 || eMap[i][ey] != '.'){
	                valid = 0;
	                break;
	            }
	        }
	    }
	    
	}
	if(vh == 1){
	    for(int i = ey; i < ey + 5; i++){
	        eMap[ex][i] = 'A';
	    }
	}else{
	    for(int i = ex; i < ex + 5; i++){
	        eMap[i][ey] = 'A';
	    }
	}	
}

void enemyBea(){
	valid = 0;
	
	while(!valid){
		vh = rand() % 2;
	    ex = rand() % 10;
	    ey = rand() % 10;
	    valid = 1;
	    
	    if(vh == 1){
	        for(int i = ey; i < ey + 4; i++){
	            if(i >= 10 || eMap[ex][i] != '.'){
	                valid = 0;
	                break;
	            }
	        }
	    }else{
	        for(int i = ex; i < ex + 4; i++){
	            if(i >= 10 || eMap[i][ey] != '.'){
	                valid = 0;
	                break;
	            }
	        }
	    }
	    
	}
	if(vh == 1){
	    for(int i = ey; i < ey + 4; i++){
	        eMap[ex][i] = 'B';
	    }
	}else{
	    for(int i = ex; i < ex + 4; i++){
	        eMap[i][ey] = 'B';
	    }
	}	
}

void enemyDav(){
	valid = 0;
	
	while(!valid){
		vh = rand() % 2;
	    ex = rand() % 10;
	    ey = rand() % 10;
	    valid = 1;
	    
	    if(vh == 1){
	        for(int i = ey; i < ey + 3; i++){
	            if(i >= 10 || eMap[ex][i] != '.'){
	                valid = 0;
	                break;
	            }
	        }
	    }else{
	        for(int i = ex; i < ex + 3; i++){
	            if(i >= 10 || eMap[i][ey] != '.'){
	                valid = 0;
	                break;
	            }
	        }
	    }
	    
	}
	if(vh == 1){
	    for(int i = ey; i < ey + 3; i++){
	        eMap[ex][i] = 'D';
	    }
	}else{
	    for(int i = ex; i < ex + 3; i++){
	        eMap[i][ey] = 'D';
	    }
	}	
}

void enemyChe(){
	valid = 0;
	
	while(!valid){
		vh = rand() % 2;
	    ex = rand() % 10;
	    ey = rand() % 10;
	    valid = 1;
	    
	    if(vh == 1){
	        for(int i = ey; i < ey + 2; i++){
	            if(i >= 10 || eMap[ex][i] != '.'){
	                valid = 0;
	                break;
	            }
	        }
	    }else{
	        for(int i = ex; i < ex + 2; i++){
	            if(i >= 10 || eMap[i][ey] != '.'){
	                valid = 0;
	                break;
	            }
	        }
	    }
	    
	}
	if(vh == 1){
	    for(int i = ey; i < ey + 2; i++){
	        eMap[ex][i] = 'C';
	    }
	}else{
	    for(int i = ex; i < ex + 2; i++){
	        eMap[i][ey] = 'C';
	    }
	}	
}

void printeMap(){
	printf("  ");
	for(int i = 0; i<10; i++){
		printf("%d ", i);
	}
	printf("\n");
	for(int x = 0; x<10; x++){
		printf("%d ", x);
		for(int y = 0; y<10; y++){
			printf("%c ", eMap[x][y]);		
		}
		printf("\n");
	}
}

void printbMap(){
	printf("  ");
	for(int i = 0; i<10; i++){
		printf("%d ", i);
	}
	printf("\n");
	for(int x = 0; x<10; x++){
		printf("%d ", x);
		for(int y = 0; y<10; y++){
			printf("%c ", bMap[x][y]);		
		}
		printf("\n");
	}
}


int ehp = 14;
int myhp = 14;

void enemyTurn(){
	int randx = rand()%10;
	int randy = rand()%10;
	
	if(pMap[randx][randy] == '*' || pMap[randx][randy] == 'X'){
		enemyTurn();
	}else if(pMap[randx][randy] == 'A' || pMap[randx][randy] == 'B' || pMap[randx][randy] == 'C' || pMap[randx][randy] == 'D'){
		myhp--;
		pMap[randx][randy] = 'X';
		enemyTurn();
		printf("Enemy is attacking your territorial at %d, %d\n", randx, randy);
		printf("Enemy hit your boat!\n");
	}else{
		pMap[randx][randy] = '*';
		printf("Enemy is attacking your territorial at %d, %d\n", randx, randy);
	}
	Sleep(1000);
}

void myTurn(){
	int randx = rand()%10;
	int randy = rand()%10;
	
	printf("Enter x, y: ");
	scanf("%d", &randx);
	getchar();
	scanf("%d", &randy);
	getchar();
	
	if(eMap[randx][randy] == '*' || eMap[randx][randy] == 'X'){
		myTurn();
	}else if(eMap[randx][randy] == 'A' || eMap[randx][randy] == 'B' || eMap[randx][randy] == 'C' || eMap[randx][randy] == 'D'){
		ehp--;
		eMap[randx][randy] = 'X';
		bMap[randx][randy] = 'X';
		
		myTurn();
	}else{
		eMap[randx][randy] = '*';
		bMap[randx][randy] = '*';
	}
}
void checkLose(){
	if(myhp == 0){
		printf("You lose!\n");
		printf("press enter to exit\n");
		check5 = 1;
		getchar();
	}else if(ehp == 0){
		printf("You win!\n");
		printf("press enter to exit\n");
		check5 = 1;
		getchar();		
	}
}


int main(){
	printf("battLeKtown\n");
	printf("Welcome to battLeKtow\n");
	Sleep(1500);
	system("cls");
	int menu = -1;
	while(menu != 3){
		srand(time(NULL));
		system("cls");
		printf("1. Play Game\n2. Game Rules\n3. Exit\n");
		printf(">>");
		scanf("%d", &menu);
		getchar();
		switch(menu){
			case 1:
				blankMap();
				
				printMapPlayer();
				askPlayerAdd();
				system("cls");
				printMapPlayer();
				askPlayerBea();
				system("cls");
				printMapPlayer();
				askPlayerDav();
				system("cls");
				printMapPlayer();
				askPlayerChe();
				system("cls");
				enemyAdd();
				enemyBea();
				enemyDav();
				enemyChe();
				
				while(check5 == 0){
					system("cls");
					printbMap();
					printf("\n\n");
					printMapPlayer();
					myTurn();
					enemyTurn();
					checkLose();
				}
//				printeMap();
				
				getchar();
				break;
			case 2:
				printf("1. You have to destroy your opponent's town before he destroys yours.\n");
				printf("2. The battlefield is of 10x10 grid size in which you place your towns\n");
				printf("3. You can place your towns by entering its orientation, i.e horizontal or vertical.\n");
				printf("  For horizontal orientation, type 'h' in the orientation option and type 'v' for vertical\n");
				printf("  and its x y coordinates (both separated by a space) where x is the row number and y is the column number\n");
				printf("4. You have a fleet of 4 towns:\n");
				printf("   -- Addersfield (5 units long)\n");
				printf("   -- Beachcastle (4 units long)\n");
				printf("   -- Davenport (3 units long)\n");
				printf("   -- Cherrytown (2 units long)\n");
				printf("5. After placing your towns, you can attack the enemy area.\n");
				printf("   To attack a area, enter its x y coordinate (separated by a space)\n");
				printf("6. Attack hit to the enemy town is denoted by a 'H' and you get an extra turn\n");
				printf("7. Attack miss is denoted by a '*' and your turn ends\n");
				printf("\n");
				printf("\n");
				printf("Press Enter To Continue\n");
				getchar();
				break;
		}
	}
	return 0;
}
