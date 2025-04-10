#include <stdio.h>

struct process {
    int ps;     // Process size
    int flag;   // Allocation flag (0 = not allocated, 1 = allocated)
} p[50];

struct sizes {
    int size;   // Block size
    int alloc;  // Allocation status (0 = free, 1 = allocated)
} s[50];

int main() {
    int i, np, n, j;
    printf("Best Fit Memory Allocation\n\n");

    // Input number of memory blocks
    printf("Enter the number of blocks: ");
    scanf("%d", &n);
    printf("Enter the size for %d blocks:\n", n);
    for (i = 0; i < n; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &s[i].size);
        s[i].alloc = 0;
    }

    // Input number of processes
    printf("\nEnter the number of processes: ");
    scanf("%d", &np);
    printf("Enter the size of %d processes:\n", np);
    for (i = 0; i < np; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &p[i].ps);
        p[i].flag = 0;
    }

    // Memory allocation using Best Fit
    printf("\nAllocation of blocks using Best Fit is as follows:\n");
    printf("Process\tProcess Size\tBlock Number\n");

    for (i = 0; i < np; i++) {
        int bestIndex = -1;

        for (j = 0; j < n; j++) {
            if (s[j].alloc == 0 && p[i].ps <= s[j].size) {
                if (bestIndex == -1 || s[j].size < s[bestIndex].size) {
                    bestIndex = j;
                }
            }
        }

        if (bestIndex != -1) {
            s[bestIndex].alloc = 1;
            p[i].flag = 1;
            printf("%d\t%d\t\t%d\n", i + 1, p[i].ps, bestIndex + 1);
        }
    }

    // Processes that couldn't be allocated
    for (i = 0; i < np; i++) {
        if (p[i].flag == 0) {
            printf("Sorry! Process %d must wait as there is no sufficient memory.\n", i + 1);
        }
    }

    return 0;
}
