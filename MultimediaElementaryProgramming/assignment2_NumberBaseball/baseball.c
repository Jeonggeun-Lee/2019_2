#include "baseball.h"

int main() {
    char selection;
    while(selection = select_game_menu()) {
        if (selection == '1') {
            int answer[3] = {0, 0, 0};
            generate_number(answer);
            play_with(answer);
        }
    }
    printf("Good bye~ \n");
    return 0;
}