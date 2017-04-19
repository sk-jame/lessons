#include <stdio.h>

inline void printQuadArray(int** array, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%03i ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

typedef void (TCallback)(int, int, int);

inline void printArrayWithCallback(int **array, int rows, int columns, TCallback callback){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            callback(i,j,array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

static const int arraySize = 9;
void diagonal_callback(int i, int j, int value){
     // главная
//    if (i == j){
//        printf("%03i ",i,j, value);
//    }
//    else{
//        printf("--- ");
//    }

//     // побочная
//    if ( i == (arraySize - 1) - j){
//        printf("i:%i j: %i value:%i \n",i,j, value);
//    }

    if ( i <= j && i <= (arraySize - 1) - j){
        printf("%03i ", value);
    }
    else{
        printf("--- ");
    }

//    if ( i >= j && i >= (arraySize - 1) - j){
//        printf("%03i ", value);
//    }
//    else{
//        printf("--- ");
//    }
}


int main(int argc, char *argv[]){

    if (argc){
        printf("%s\n", argv[0]);
    }

    int **array;
    array = new int*[arraySize];
    for(int i = 0; i < arraySize; i++){
        array[i] = new int[arraySize];
    }

    for(int i = 0; i < arraySize; i++){
        for(int j = 0; j < arraySize; j++){
            array[i][j] = i * arraySize + j + 1;
        }
    }

    printQuadArray(array, arraySize);
    printf("##############\n\n");
    printArrayWithCallback(array, arraySize, arraySize, diagonal_callback);


    return 0;
}
