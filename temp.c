#include <stdio.h>

int main(void)
{
   int arr[5], i = 0, sum = 0;
   do
   {
    printf("Enter a number:\n");
    scanf("%i", &arr[i]);
    i++;
   } 
   while (i<5);
 
   for (i = 0; i < 5; i++)
   {
       sum += arr[i];
   }
   printf("sum:%i\naverage:%i\n", sum, sum/i);
}

// int arr[4] = {1, 2, 3, 4};

//     for (int i = 0; i < 4; i++)
//     {
//         printf("%i ", &arr[0]); //*(arr + i)
//     }
//     printf("\n");
    // float n, m;
    // scanf("%f", &n);
    // scanf("%5f", &m);
    // printf("%f %f\n", n, m);





    //int n = 35;
    //printf("in decimal %d\nin octal %o\nin hex %x\n", n, n, n);    
    //printf("%10.2f\n",(float)n);

// for (int i = 1; i <= 500; i++)
//     {
//         if (i % 5 == 0) 
//         {
//             continue;
//         }
//         printf("%i ", i);
//     }
//     printf("\n");

    // for (int i = 1; i <=2; i++)
    // //{
    //     for (int j = 2; j < 5; j++)
    //     //{
    //         printf("%i %i\n", i, j);
    //         if (j % 2 == 0)
    //         {
    //             break;
    //         }
    //     //}
    // //}