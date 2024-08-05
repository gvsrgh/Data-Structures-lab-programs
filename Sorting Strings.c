/*A program in which we take strings as input and print them in sorted order*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

void bubbleSort(char *names[], int n)
{
    char *temp;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(strcmp(names[i], names[j]) > 0)
            {
                temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of names: ");
    scanf("%d", &n);
    
    char* names[n];
    printf("Please input the names\n");
    for(int i = 0; i < n; i++)
    {
        names[i] = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
        if (names[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        printf("Enter the name %d: ", i + 1);
        scanf("%s", names[i]);
    }
    
    printf("Names in before Sorting:\n");
    for(int i = 0; i < n; i++)
        printf("%s ", names[i]);
    
    bubbleSort(names, n);
    
    printf("\nNames in after Sorting:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%s ", names[i]);
        free(names[i]);  
    }

    return 0;
}
