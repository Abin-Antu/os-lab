#include <stdio.h>

int p[30], bt[30], wt[30], tat[30], n;

void sort() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                int temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }
}

void WT_TAT(int *tot_tat, int *tot_wt) {
    *tot_tat = *tot_wt = 0;
    tat[0] = bt[0];
    *tot_tat += tat[0];
    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        tat[i] = tat[i - 1] + bt[i];
        wt[i] = wt[i - 1] + bt[i - 1];
        *tot_tat += tat[i];
        *tot_wt += wt[i];
    }
}

int main() {
    int tot_tat, tot_wt;
    float avg_tat, avg_wt;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        p[i] = i;  // Process IDs
    }

    sort();
    WT_TAT(&tot_tat, &tot_wt);

    avg_tat = (float)tot_tat / n;
    avg_wt = (float)tot_wt / n;

    printf("\nPROCESS\tBURST TIME\tTURNAROUND TIME\tWAITING TIME\n");
    for (int i = 0; i < n; i++) {
        printf("Process[%d]\t%d\t%d\t%d\n", p[i] + 1, bt[i], tat[i], wt[i]);
    }

    printf("\nTotal Turnaround Time: %d", tot_tat);
    printf("\nAverage Turnaround Time: %.2f", avg_tat);
    printf("\nTotal Waiting Time: %d", tot_wt);
    printf("\nAverage Waiting Time: %.2f", avg_wt);

    return 0;
}
