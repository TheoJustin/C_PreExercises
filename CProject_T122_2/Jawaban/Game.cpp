#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>


struct bullet {
    int x, y;
    int go;
    int active;
};

struct enemy {
    int x, y;
    int go;
    int active;
    int hp;
};


#define MAX_BULLETS 10
struct bullet bullets[MAX_BULLETS];
struct enemy enemies[100];

clock_t enemyTimer = clock() + 4000;

struct scoreboard{
	int score;
	char name[256];
};

void cls(){
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void hideCursor(){
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

struct scoreboard data[100];

char map[9][64] = {};
int px = 31, py = 1, score = 0, sc = 0;
int hp = 1;
int logic = 0, logicShooting = 0;
int bulletx = -1, bullety = -1, bullet = 0, go = 0;
int es = 0;


void enemySpawn(){
	for(int i = 0; i<100; i++){
		if(enemies[i].active == 0){
			enemies[i].active = 1;
			enemies[i].go = rand()%2;
			if(enemies[i].go == 1){
				enemies[i].x = 62;
			}else{
				enemies[i].x = 1;
			}
			enemies[i].y = rand()%7+1;
			break;
		}
	}
}

void board(){
	for(int y = 0; y<9; y++){
		for(int x = 0; x<64; x++){
			if(y == 0 || x == 0 || y == 8 || x == 63){
				map[y][x] = '#'; 
			}else if(y > 0 && y<8 && (x == 30 || x == 33)){
				map[y][x] = 'G';
			}else if(y > 0 && y < 9 &&  (x < 30 || x > 33)){
				map[y][x] = '.';
			}else if(y == py && x == px){
				map[y][x] = 'P';
			}else{
				map[y][x] = ' ';
			}
		}		
	}
}

void printBoard(){
    for(int y = 0; y<9; y++){
        for(int x = 0; x<64; x++){
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

void printScore(){
	printf("Score : %d\n", score);
}

void move(){
    if(kbhit()){
        switch(getch()){
            case 'w': // 72
                logic = 1;
                break;
            case 'a': // 75
                logic = 2;
                break;
            case 's': // 80
                logic = 3;
                break;
            case 'd': // 77
                logic = 4;
                break;
            case ' ':
                logic = -1;
                logicShooting = 1;
                break;
        }
        
        if(logic == 1 && map[py-1][px] == ' '){
            py--;
        }else if(logic == 2 && map[py][px-1] == ' '){
            px--;
        }else if(logic == 3 && map[py+1][px] == ' '){
            py++;
        }else if(logic == 4 && map[py][px+1] == ' '){
            px++;
        }   
    }
    if(logicShooting == 1){
	    for(int i = 0; i < MAX_BULLETS; i++){
	        if(bullets[i].active == 0){
	            if(map[py][px - 1] == 'G'){
	                bullets[i].x = px - 2;
	                bullets[i].y = py;
	                bullets[i].go = 0;
	                bullets[i].active = 1;
	            }else if(map[py][px + 1] == 'G'){
	                bullets[i].x = px + 2;
	                bullets[i].y = py;
	                bullets[i].go = 1;
	                bullets[i].active = 1;
	            }
	            break;
	        }
	    }
	    logicShooting = 0;
	}
	
	

		for(int i = 0; i < 100; i++){
	        if(enemies[i].active && enemies[i].hp > 0 && enemies[i].x >= 0 && enemies[i].x < 64 && map[enemies[i].y][enemies[i].x] == '.'){
	            map[enemies[i].y][enemies[i].x] = '.';
	            if (enemies[i].go == 0 && enemies[i].x < 62){
	                enemies[i].x++;
	            }else if(enemies[i].go == 1 && enemies[i].x > 1){
	                enemies[i].x--;
	            }else{
	                enemies[i].active = 0;
	            }
	            if(enemies[i].active && enemies[i].x >= 0 && enemies[i].x < 64 && map[enemies[i].y][enemies[i].x] == 'O'){
	                enemies[i].hp--;
	            }else if(enemies[i].active && enemies[i].x >= 0 && enemies[i].x < 64 && map[enemies[i].y][enemies[i].x] == 'G'){
	            	hp = 0;
				}else if(enemies[i].active && enemies[i].x >= 0 && enemies[i].x < 64 && map[enemies[i].y][enemies[i].x] == '.'){
	                map[enemies[i].y][enemies[i].x] = 'E';
	            }
	        }
	    }


		for(int i = 0; i < MAX_BULLETS; i++){
		    if(bullets[i].active && bullets[i].x >= 0 && bullets[i].x < 64 && map[bullets[i].y][bullets[i].x] == '.'){
		        map[bullets[i].y][bullets[i].x] = 'O';
		        if (bullets[i].go == 0){
		            bullets[i].x--;
		        }else if (bullets[i].go == 1){
		            bullets[i].x++;
		        }
		    }else{
		        bullets[i].active = 0;
		    }
		}

	
	for (int i = 0; i < 100; i++) {
    if (enemies[i].active) {
        for (int j = 0; j < MAX_BULLETS; j++) {
            if (bullets[j].active && bullets[j].x == enemies[i].x && bullets[j].y == enemies[i].y) {
                enemies[i].hp--;
                bullets[j].active = 0;
                map[bullets[j].y][bullets[j].x] = '.';

                if (enemies[i].hp <= 0) {
                    enemies[i].active = 0;
                    map[enemies[i].y][enemies[i].x] = '.';
                    score+=10;
                }
                break;
            }
        }
    }
}
}


void floodFill(int x, int y){
    if(map[y][x] == 'P' || map[y][x] == ' '){
        map[y][x] = '.';
        cls();
        printScore();
        printBoard();
        Sleep(200);
        floodFill(x+1, y);
        floodFill(x, y+1);
        floodFill(x-1, y);
        floodFill(x, y-1);
    }
}

int main(){
	srand(time(NULL));
	
	cls();
	hideCursor();
	
	FILE *fptr;
	printf("RUN N GUN\n\n");
	printf("Play\nHow To Play\nScoreboards\nExit\n");
	int menu;
	scanf("%d", &menu);
	getchar();
	while(menu != 4){
		switch(menu){
			case 1:
				score = 0;
				hp = 1;
				system("cls");	
				for (int i = 0; i < MAX_BULLETS; i++) {
					bullets[i].active = 0;
				}
				for (int i = 0; i < 100; i++) {
					enemies[i].active = 0;
					enemies[i].hp = 3;
				}
				while(hp != 0){
					cls();
					hideCursor();
					board();
					move();
					
					clock_t spawn = clock();
					if(score<50){
						if(spawn > enemyTimer){
							enemySpawn();
							enemyTimer = spawn + 4000;
						}
					}else{
						if(spawn > enemyTimer){
							enemySpawn();
							enemyTimer = spawn + 3000;
						}
					}
					
					printScore();
					printBoard();
					Sleep(100);
				}
				floodFill(px, py);
				cls();
				printScore();
				printBoard();
				printf("You LOSE!\n");
				
				printf("Input Your Name >> ");
				char name[200];
				scanf("%[^\n]", &name);
				getchar();
				fptr = fopen("scoreboard.txt", "a");
				fprintf(fptr, "%s#%d\n", name, score);
				fclose(fptr);
				break;
			case 2:
				printf("How To Play\n");
				printf("How to Play\nRun n Gun is a shooting game. Enemy is trying to destroy our base.\nOur purpose is defend our base from enemy in the water.\n\nWe have guns to defend. We need to Run n Gun!! Kill all enemy and save our base!\n\nSymbols\nP : Player\nG : Gun\n. : Water\nE : Enemy\n# : Wall\n\nControls\nArrow Key Down : Move Down\nArrow Key Up : Move Up\nArrow Key Left : Move Left\nArrow Key Right: Move Right\nSpace : Shoot Using Nearest Gun\nPress enter to contiue!!");		
				getchar();
				system("cls");
				break;
			case 3:
				printf("Scoreboards\n");
				fptr = fopen("scoreboard.txt", "r");
				while(!feof(fptr)){
					fscanf(fptr, "%[^#]#%d\n", &data[sc].name, &data[sc].score);
					sc++;
				}
				fclose(fptr);
				system("cls");
				printf("NAME | SCORE\n");
				for(int i = 0; i<sc; i++){
					printf("%-8s %d\n", data[i].name, data[i].score);
				}
				printf("Press Enter to continue\n");
				getchar();
				sc = 0;
				break;
			case 4:
				printf("Thanks for playing\n");
				break;
		}
		system("cls");
		printf("RUN N GUN\n\n");
		printf("Play\nHow To Play\nScoreboards\nExit\n");
		scanf("%d", &menu);
		getchar();
	}
	
	return 0;
}

