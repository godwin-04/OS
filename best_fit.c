#include<stdio.h>

#define MAX_BLOCKS 10
#define MAX_PROCESSES 10

int main()
{
    int i, j, nb, np, allocation[MAX_PROCESSES];
    int blocks[MAX_BLOCKS], processes[MAX_PROCESSES], flag[MAX_PROCESSES];
    int processFragmentation[MAX_PROCESSES] = {0};
    int totalFragmentation = 0;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter the size of memory blocks: ");
    for(i = 0; i < nb; i++)
        scanf("%d", &blocks[i]);

    printf("Enter the number of processes: ");
    scanf("%d", &np);

    printf("Enter the size of processes: ");
    for(i = 0; i < np; i++)
        scanf("%d", &processes[i]);

    for(i = 0; i < np; i++)
    {
        allocation[i] = -1;
        flag[i] = 0;
    }

    for(i = 0; i < np; i++)
    {
        int best_fit = -1;
        for(j = 0; j < nb; j++)
        {
            if(blocks[j] >= processes[i])
            {
                if(best_fit == -1 || blocks[j] < blocks[best_fit])
                    best_fit = j;
            }
        }

        if(best_fit != -1)
        {
            allocation[i] = best_fit;
            flag[best_fit] = 1;
            processFragmentation[i] = blocks[best_fit] - processes[i];
            blocks[best_fit] -= processes[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\tFragmentation\n");
    for(i = 0; i < np; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if(allocation[i] != -1)
            printf("%d\t\t%d\n", allocation[i] + 1, processFragmentation[i]);
        else
            printf("Not Allocated\t-\n");
    }

    return 0;
}
