#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evaluate();
int parse_number();

char str[300000];
int position = 0;

int parse_number(){
    int number = 0;
    if(str[position] == '('){
        position++;
        number = evaluate();

        if (str[position] == ')'){
            position++;
            return number;
        }
    }else{
        while('0' <= str[position] && str[position] <= '9'){
            number = number * 10 + (str[position] - '0');
            position++;
        }
    }
    return number;
}

int evaluate(){
    int first_operand, second_operand;
    while(str[position] == ' '){
        position++;
    }
    first_operand = parse_number();

    while (str[position] != '\0'){
        while(str[position] == ' '){
            position++;
        }
        if (str[position] == '+'){
            position++;
            while(str[position] == ' '){
                position++;
            }
            second_operand = parse_number();
            first_operand += second_operand;
        }else if(str[position] == '-'){
            position++;
            while(str[position] == ' '){
                position++;
            }
            if(str[position] == '-'){
                position++;
                while(str[position] == ' '){
                    position++;
                }
                second_operand = parse_number();
                first_operand += second_operand;
            }else{
                second_operand = parse_number();
                first_operand -= second_operand;
            }
        }else{
            return first_operand;
        }
    }
    return first_operand;
}

int main() {
    scanf("%[^\n]", str);
    getchar();
    printf("%d", evaluate());

    return 0;
}

