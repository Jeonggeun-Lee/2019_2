#include <stdio.h>
int main(int argc, char* argv[]){
    int i,j;
    FILE *source, *result;
    char source_arr[512][512];
    char result_arr[512][512];

    source = fopen(argv[1],"rb+");

    for(i=0; i<512; i++){
        for(j=0; j<512; j++){
            source_arr[i][j] = fgetc(source);
        }
    }

    source_arr[396][511-4] = 20;
    source_arr[396][511-3] = 17;
    source_arr[396][511-2] = 11;
    source_arr[396][511-1] = 35;
    source_arr[396][511-0] = 47;

    fseek(source, 0, 0);

    for(i=0; i<512; i++){
        for(j=0; j<512; j++){
            fprintf(source, "%c", source_arr[i][j]);
        }
    }
    fclose(source);

    source = fopen(argv[1],"rb");
    result = fopen(argv[2],"wb");

    for(i=0; i<512; i++){
        for(j=0; j<512; j++){
            source_arr[i][j] = fgetc(source);
        }
    }
    
    for(i=0; i<512; i++){
        for(j=0; j<512; j++){
            result_arr[511-j][511-i] = source_arr[i][j];
        }
    }

    for(i=0; i<512; i++){
        for(j=0; j<512; j++){
            fprintf(result, "%c", result_arr[i][j]);
        }
    }

    fclose(result);
    fclose(source);

    return 0;
}