#include <stdio.h>

void firstFit(int block[], int m, int process[], int n);
void bestFit(int block[], int m, int process[], int n);
void worstFit(int block[], int m, int process[], int n);

int main()
{
    int m, n;

    // Input number of blocks
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    int blockSize[m];

    printf("Enter size of each block:\n");
    for(int i = 0; i < m; i++)
        scanf("%d", &blockSize[i]);

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int processSize[n];

    printf("Enter size of each process:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &processSize[i]);

    printf("\nFIRST FIT\n");
    int block1[m];
    for(int i = 0; i < m; i++)
        block1[i] = blockSize[i];
    firstFit(block1, m, processSize, n);

    printf("\nBEST FIT\n");
    int block2[m];
    for(int i = 0; i < m; i++)
        block2[i] = blockSize[i];
    bestFit(block2, m, processSize, n);

    printf("\nWORST FIT\n");
    int block3[m];
    for(int i = 0; i < m; i++)
        block3[i] = blockSize[i];
    worstFit(block3, m, processSize, n);

    return 0;
}

void firstFit(int block[], int m, int process[], int n)
{
    int alloc[n];
    for(int i = 0; i < n; i++)
        alloc[i] = -1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(block[j] >= process[i])
            {
                alloc[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }

    printf("Process\tBlock\n");
    for(int i = 0; i < n; i++)
        printf("%d\t%d\n", i + 1, alloc[i] + 1);
}

void bestFit(int block[], int m, int process[], int n)
{
    int alloc[n];
    for(int i = 0; i < n; i++)
        alloc[i] = -1;

    for(int i = 0; i < n; i++)
    {
        int best = -1;
        for(int j = 0; j < m; j++)
        {
            if(block[j] >= process[i])
            {
                if(best == -1 || block[j] < block[best])
                    best = j;
            }
        }
        if(best != -1)
        {
            alloc[i] = best;
            block[best] -= process[i];
        }
    }

    printf("Process\tBlock\n");
    for(int i = 0; i < n; i++)
        printf("%d\t%d\n", i + 1, alloc[i] + 1);
}

void worstFit(int block[], int m, int process[], int n)
{
    int alloc[n];
    for(int i = 0; i < n; i++)
        alloc[i] = -1;

    for(int i = 0; i < n; i++)
    {
        int worst = -1;
        for(int j = 0; j < m; j++)
        {
            if(block[j] >= process[i])
            {
                if(worst == -1 || block[j] > block[worst])
                    worst = j;
            }
        }
        if(worst != -1)
        {
            alloc[i] = worst;
            block[worst] -= process[i];
        }
    }

    printf("Process\tBlock\n");
    for(int i = 0; i < n; i++)
        printf("%d\t%d\n", i + 1, alloc[i] + 1);
}
