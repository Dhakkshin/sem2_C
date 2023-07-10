/*Write a program in C to encrypt the contents of a file using a simple encryption algorithm.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

int main() 
{
    FILE* inputFile;
    FILE* outputFile;
    int shift = 3; 
    char ch;

    inputFile = fopen("q12input.txt", "r");
    if (inputFile == NULL) 
    {
        printf("Failed to open the input file.\n");
        return 1;
    }

    outputFile = fopen("q12output.txt", "w");
    if (outputFile == NULL) 
    {
        printf("Failed to create the output file.\n");
        return 1;
    }

    while ((ch = fgetc(inputFile)) != EOF) 
    {
        if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + shift) % 26) + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + shift) % 26) + 'A';
        }
        
        fputc(ch, outputFile);
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
