#include <stdio.h>

int X[1000];
char message1[] = "Enter array size: ";
char error_msg[] = "Size should be a positive integer, please input again!";
char message2[] = "Enter array: ";
char message3[] = "Max element of the array: ";
char message4[] = "Enter m: ";
char message5[] = "Enter M: ";
char message6[] = "Number of element in range (m , M): ";

int main(){
    int size;
    printf("%s", message1);
    scanf("%d", &size);
    while(size < 0){
        printf("%s\n%s", error_msg, message1);
        scanf("%d", &size);
    }
    printf("%s", message2);
    for(int i = 0; i < size; i++){
        scanf("%d", &X[i]);
    }
    int max = X[0];
    for(int i = 1; i < size; i++){
        if(X[i] > max) max = X[i]; 
    }
    printf("%s%d\n", message3, max);
    int m, M;
    printf("%s", message4);
    scanf("%d", &m);
    printf("%s", message5);
    scanf("%d", &M);
    int count = 0;
    for(int i = 0; i < size; i++){
        if(X[i] > m && X[i] < M) count++;
    }
    printf("%s%d", message6, count);
    return 0;
}