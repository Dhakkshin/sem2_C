#include <stdio.h>

enum ErrorCode
{
    on,
    off
};

int main(void)
{
    enum ErrorCode e = off;
    printf("%i\n", e);
    switch(e)
    {
        case on:
        {
            printf("On\n");
            break;
        }

        case off:
        {
            printf("off");
            break;
        }

        default:
        printf("Default text\n");
        break;
    }
}