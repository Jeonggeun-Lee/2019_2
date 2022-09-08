#include "baseball.h"
#include <stdlib.h>
#include <time.h>

void generate_number(int answer[]) {
    srand(time(NULL));
    answer[0] = rand()%9+1;
    while( (answer[1] = rand()%9+1) == answer[0] );
    while( (answer[2] = rand()%9+1) == answer[0] || answer[2] == answer[1] );
}

void play_with(int answer[]) {
    int input[3];
    int is_invalid;
    int num_of_try;
    int computer_win = 1;
    int num_of_strike;
    int num_of_ball;

    for(num_of_try=0; num_of_try<9; num_of_try++){
        is_invalid = 1;
        num_of_strike = 0;
        num_of_ball = 0;
        while(is_invalid){
            scanf("%d %d %d", &input[0], &input[1], &input[2]);
            getchar();
            is_invalid = 0;
            
            if(input[0]==0 || input[1]==0 || input[2]==0) is_invalid = 1;
            else if(input[0]>9 || input[1]>9 || input[2]>9) is_invalid = 1;
            else if(input[1] == input[0]) is_invalid = 1;
            else if(input[2] == input[0] || input[2] == input[1]) is_invalid =1;
            
            if(is_invalid==1) printf("Invalid numbers\n");
        }
        if(input[0]==answer[0]) ++num_of_strike;
        if(input[0]==answer[1]||input[0]==answer[2]) ++num_of_ball;
        if(input[1]==answer[1]) ++num_of_strike;
        if(input[1]==answer[0]||input[1]==answer[2]) ++num_of_ball;
        if(input[2]==answer[2]) ++num_of_strike;
        if(input[2]==answer[0]||input[2]==answer[1]) ++num_of_ball;
        
        printf("%d strike\n",num_of_strike);
        printf("%d ball\n",num_of_ball);
        
        if(num_of_strike==3){
            computer_win = 0;
            break;
        }
    }
    if(computer_win==0) printf("user wins\n");
    else printf("computer wins\n");
}