#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <ctype.h>


void leaderboard();
void sellOre();
void shop();
void randomize();
void shop();
void sellOre();
void mine();
void changeName();
void loginInt();
void menu1();
void menu2();
void buyItem();

FILE *fptr;
int inp1 = 0, inp2 = 0, inp3 = 0, inp4 = 0;
char myName[35];
int depth = 1, hunger = 10;
int iron = 0, gold = 0, diamond = 0;
int money = 0;
int i;


struct players{
	int id;
	int money;
	int pxlevel;
	char email[35];
	char password[35];
};

struct players datas[100];

void leaderboard(){
	int x = 0;
	fptr = fopen("data//Players.txt", "r");
	int id, money, pxlevel, validation = 0;
	char email[35], password[35];
	printf("%-5s %-35s  %-5s \n", "No", "Email", "Money");
	while(!feof(fptr)){
		fscanf(fptr, "%d,%[^,],%[^,],%d,%d\n", &id, email, password, &money, &pxlevel);
		datas[x].id = id;
		strcpy(datas[x].email, email);
		strcpy(datas[x].password, password);
		datas[x].money = money;
		datas[x].pxlevel = pxlevel;
		x++;
//		printf("%-5d %-35s  %-5d \n", id, email, money);
	}
	
	struct players temp;
	for(int y = 0; y<x-1; y++){
		for(int z = 0; z<x-y-1; z++){
			if(datas[z].money < datas[z+1].money){
				temp = datas[z+1];
				datas[z+1] = datas[z];
				datas[z] = temp;
			}
		}
	}
	printf("Leaderboard from highest to lowest money\n");
	for(int z = 0; z<x; z++){
		printf("%-5d %-35s  %-5d \n", z+1, datas[z].email, datas[z].money);
	}
	getchar();
	fclose(fptr);
}

void sellOre(){
	system("cls");
	printf("You have :\n");
	printf("x%d iron ore\n", iron);
	printf("x%d gold ore\n", gold);
	printf("x%d diamond ore\n", diamond);
	printf("Your gold : %d\n", money);
	
	int menu5;
	printf("1. Sell iron $20\n2. Sell gold $40\n3. Sell diamond $60\n");
	scanf("%d", &menu5);
	getchar();
	
	if(menu5 == 1){
		printf("How many you want to sell? [0 to cancel]");
		int sell;
		scanf("%d", &sell);
		getchar();
		if(sell > 0){
			iron-=sell;
			money+=(sell*20);
			sellOre();
		}
	}else if(menu5 == 2){
		printf("How many you want to sell? [0 to cancel]");
		int sell;
		scanf("%d", &sell);
		getchar();
		if(sell > 0){
			gold-=sell;
			money+=(sell*40);
			sellOre();
		}
	}else if(menu5 == 3){
		printf("How many you want to sell? [0 to cancel]");
		int sell;
		scanf("%d", &sell);
		getchar();
		if(sell > 0){
			diamond-=sell;
			money+=(sell*60);
			sellOre();
		}
	}
	
}

void buyItem(){
	printf("Your gold : %d\n", money);
	printf("1. Buy Apple - $30\n");
	printf("2. Buy Chicken - $70\n");
	printf("3. Buy Beef - $90\n");
	printf("4. Upgrade pickaxe - 350\n");
	printf("0. Back\n");
	
	int menu6;
	scanf("%d", &menu6);
	getchar();
	
	if(menu6 == 1){
		
	}else if(menu6 == 2){
		
	}else if(menu6 == 3){
		
	}else if(menu6 == 4){
		
	}else if(menu6 == 0){
		
	}
	
}

void shop(){
	system("cls");
	printf("Welcome to shop\n");
	printf("1. Buy Item\n");
	printf("2. Sell ore\n");
	printf("0. Back\n");
	printf(">> ");
	
	int menu4;
	scanf("%d", &menu4);
	getchar();
	switch(menu4){
		case 1:
			buyItem();
			break;
		case 2:
			sellOre();
			break;
	}
	menu2();
}

void randomize(){
	int nothing = 0;
	int randInt = rand() % 100;
	if(randInt < 40){
		printf("successfully dig 1 lever lower\n");
		depth++;
		nothing = 1;	
	}
	
	randInt = rand() % 100;
	if(randInt < 20){		
		printf("getting hungry\n");
		hunger--;
		nothing = 1;	
	}
	
	randInt = rand() % 100;
	if(randInt < 10){
		printf("creeper explodes\n");
		hunger-=3;
		nothing = 1;	
	}
	
	randInt = rand() % 100;
	if(randInt < 60){
		printf("found iron\n");
		iron++;
		nothing = 1;	
		if(randInt < 40 && depth > 5){
			printf("found gold\n");
			gold++;
			if(randInt < 0 && depth > 9){
				printf("found diamond\n");
				diamond++;
			}
		}
	}
	
	if(nothing == 0){
		printf("found nothing\n");
	}
	getchar();
}

struct data{
	int id;
	char inv[20][200];
};

void mine(){
	do{
		system("cls");
	    FILE *fptr;
	    fptr = fopen("data/Backpacks.txt", "r");
	    struct data backp[100];
	    int player = 0;
	    char line[1024];
	    while(fgets(line, sizeof(line), fptr) != NULL){
	        char *token;
	        token = strtok(line, ";");
	        backp[player].id = atoi(token);
	        int invIndex = 0;
	        while((token = strtok(NULL, ";")) != NULL){
	            strcpy(backp[player].inv[invIndex], token);
	            invIndex++;
	        }
	        player++;
	    }
	    fclose(fptr);
	    printf("You have : \n");
	    i = 15; // need to find id of player
	    
	    for (int j = 0; j < 20; j++) {
	        if (strlen(backp[i].inv[j]) > 3) {
	            printf("%d: %s\n", j, backp[i].inv[j]);
	            continue;
	        }
	        printf("%d: \n", j);
	    }
	    printf("\n");
	    printf("\n");
		
	
	printf("You are on depth %d\n", depth);
	printf("Hunger bar : [  |  |  |  |  |  |  |  |  |  |  ] (%d)", hunger);
	printf("What do you want to do?\n");
	printf("1. Go Deeper\n");
	printf("2. Eat food\n");
	printf("3. Go to surface\n");
	printf(">> ");
	
	scanf("%d", &inp3);
	getchar();
	switch(inp3){
		case 1:
			randomize();
			break;
		case 2:
//			eatFood();
			break;
		case 3:
			menu2();
			break;
	}
	}while(hunger > 0);
	
    getchar();
}

void changeName(char name[]){
	for(int i = 0; name[i]!='@'; i++){
		myName[i] = name[i];
	}
}

void menu2(){
	do{
		system("cls");
		printf("Welcome, %s\n", myName);
		printf("1. Go to mine\n2. Go to shop\n3. Check leaderboard\n4. Back\n>> ");
		scanf("%d", &inp2);
		getchar();
		
		switch(inp2){
			case 1:
				mine();
				break;
			case 2:
				shop();
				break;
			case 3:
				leaderboard();
				break;
		}
	}while(inp2 != 4);
	
	menu1();
}

void registerInt(){
	char email[35];
	do{
		printf("Input email [ends with @email.com and unique] : ");
		scanf("%s", email);
		getchar();
	}while(strcmp(email + (strlen(email) - strlen("@email.com")),"@email.com") != 0);

	char password[35];
	int validatePassAlp = 0;
	int validatePassNum = 0;
	int len;
	do{
		validatePassAlp = 0;
		validatePassNum = 0;
		printf("Input Password [contain alphanumeric with length between 8 - 15] : ");
		scanf("%s", password);
		getchar();
		len = strlen(password);
		for(int i = 0; i<len; i++){
			if(isdigit(password[i]) != 0){
				validatePassNum = 1;
				continue;
			}
			if((password[i] >= 97 && password[i] <= 122) || (password[i] >= 65 && password[i] <= 90)){
				validatePassAlp = 1;
				continue;
			}
		}
	}while(validatePassAlp == 0 || validatePassNum == 0 || len<8 || len>15);
	
	
	//not finished
	fptr = fopen("data//Players.txt", "a");
	fprintf(fptr, "%d,%s,%s,%d,%d\n", 17, email, password, 0, 1);
	fclose(fptr);
	
	printf("Account successfully created!");
	getchar();
}

void loginInt(){
	char myPassword[35];
	char myEmail[35];
	printf("Input email [ends with @email.com] : ");
	scanf("%[^\n]", &myEmail);
	getchar();
	printf("Input Password [contain alphanumeric with length between 8 - 15] : ");
	scanf("%s", &myPassword);
	getchar();
	
	fptr = fopen("data//Players.txt", "r");
	int id, money, pxlevel, validation = 0;
	char email[35], password[35];
	while(!feof(fptr)){
		fscanf(fptr, "%d,%[^,],%[^,],%d,%d\n", &id, email, password, &money, &pxlevel);
		if(strcmp(email, myEmail) == 0 && strcmp(myPassword, password) == 0){
			changeName(email);
			validation = 1;
		}
	}
	if(validation == 0){
		printf("Failed to logged in, make sure you have prompt the correct credential\n");
	}else{
		menu2();
	}
	getchar();
	
	fclose(fptr);
}

void menu1(){
	do{
		system("cls");
		printf("MineCrap!#$^&\n");
		printf("1. Login\n");
		printf("2. Register\n");
		printf("3. Exit\n");
		printf(">> ");
		scanf("%d", &inp1);
		getchar();
		
		switch(inp1){
			case 1:
				loginInt();
				break;
			case 2:
				registerInt();
				break;
		}
	}while(inp1 != 3);
}



int main(){
	srand(time(NULL));
	menu1();
	return 0;
}
