#include <stdio.h>

void main()
{
    int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;
    int fragmentation[10];

    for (i = 0; i < 10; i++)
    {
        flags[i] = 0;
        allocation[i] = -1;
        fragmentation[i] = 0;
    }

    printf("Enter the number of blocks: ");
    scanf("%d", &bno);

    printf("Enter the size of each block: ");
    for (i = 0; i < bno; i++)
        scanf("%d", &bsize[i]);

    printf("Enter the number of processes: ");
    scanf("%d", &pno);

    printf("Enter the size of each process: ");
    for (i = 0; i < pno; i++)
        scanf("%d", &psize[i]);

    // First Fit Allocation
    for (i = 0; i < pno; i++)
    {
        for (j = 0; j < bno; j++)
        {
            if (flags[j] == 0 && bsize[j] >= psize[i])
            {
                allocation[j] = i;
                fragmentation[i] = bsize[j] - psize[i];
                flags[j] = 1;
                break;
            }
        }
    }

    // Display allocation details
    printf("\nBlock no.\tSize\t\tProcess no.\t\tSize\t\tFragmentation");
    for (i = 0; i < bno; i++)
    {
        printf("\n%d\t\t%d\t\t", i + 1, bsize[i]);
        if (flags[i] == 1)
            printf("%d\t\t\t%d\t\t\t%d", allocation[i] + 1, psize[allocation[i]], fragmentation[allocation[i]]);
        else
            printf("Not allocated\t\t\t-\t\t\t-");
    }
}
