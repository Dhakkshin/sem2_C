#include <stdio.h>

int main() {
    FILE* file;
    int num;
    int count = 0;
    int sum = 0;
    float average;

    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    while (fscanf(file, "%d", &num) != EOF) {
        sum += num;
        count++;
    }

    fclose(file);

    if (count > 0) {
        average = (float)sum / count;
        printf("Average: %.2f\n", average);
    } else {
        printf("No numbers found in the file.\n");
    }

    return 0;
}
