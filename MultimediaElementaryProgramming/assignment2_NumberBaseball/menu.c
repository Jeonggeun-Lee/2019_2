#include "baseball.h"

char select_game_menu() {
    char input = '\0';
    while(input!='1'&&input!='2'){
        printf("*** Game Menu ***\n");
        printf("1.play\n");
        printf("2.quit\n");
        printf(">");
        input = getchar();
        getchar();
        if(input!='1'&&input!='2'){
            printf("Wrong selection\n");
        }
    }
    if(input=='2') input = '\0';
    return input;
}