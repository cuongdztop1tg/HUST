#include <stdio.h>

char names[100][32];
float marks[100];
char message1[] = "Enter number of students: ";
char message2[] = "Enter list of students: ";
char message3[] = "List of students: ";

int main() {
    int size;
    printf("%s", message1);
    scanf("%d", &size);
    
    printf("%s\n", message2);
    for (int i = 0; i < size; i++) {
        scanf("%s", names[i]);
        scanf("%f", &marks[i]);
    }

    int swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (marks[j] < marks[j + 1]) {
                // Swap marks
                float tempMark = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = tempMark;

                // Swap corresponding names
                char tempName[32];
                strcpy(tempName, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], tempName);

                swapped = 1;
            }
        }
        if (swapped == 0) break;
    }

    printf("%s\n", message3);
    for (int i = 0; i < size; i++) {
        printf("%s %.2f\n", names[i], marks[i]);
    }
    return 0;
}