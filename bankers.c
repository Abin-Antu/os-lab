#include <stdio.h>
#include <stdlib.h>

int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n, r;

void input();
void show();
void cal();

int main() {
    printf("********** Banker's Algorithm ************\n");
    input();
    show();
    cal();
    return 0;
}

void input() {
    int i, j;
    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    printf("Enter the number of Resource Instances: ");
    scanf("%d", &r);

    printf("Enter the Max Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the Allocation Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the Available Resources:\n");
    for (j = 0; j < r; j++) {
        scanf("%d", &avail[j]);
    }
}

void show() {
    int i, j;
    printf("\nProcess\tAllocation\tMax\tAvailable\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t", i + 1);
        for (j = 0; j < r; j++) {
            printf("%d ", alloc[i][j]);
        }
        printf("\t");
        for (j = 0; j < r; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\t");
        if (i == 0) {
            for (j = 0; j < r; j++) {
                printf("%d ", avail[j]);
            }
        }
        printf("\n");
    }
}

void cal() {
    int finish[100] = {0};
    int safe[100], k, c1 = 0, flag = 1;
    int i, j;

    // Calculate the Need matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("\nSafe Sequence: ");
    while (flag) {
        flag = 0;
        for (i = 0; i < n; i++) {
            int c = 0;
            for (j = 0; j < r; j++) {
                if (finish[i] == 0 && need[i][j] <= avail[j]) {
                    c++;
                    if (c == r) {
                        for (k = 0; k < r; k++) {
                            avail[k] += alloc[i][k];
                        }
                        finish[i] = 1;
                        printf("P%d -> ", i + 1);
                        flag = 1;
                        break;
                    }
                }
            }
        }
    }

    // Check for deadlock
    for (i = 0; i < n; i++) {
        if (finish[i] == 1) {
            c1++;
        } else {
            printf("P%d -> ", i + 1);
        }
    }

    if (c1 == n) {
        printf("\nThe system is in a SAFE state.\n");
    } else {
        printf("\nProcesses are in DEADLOCK.\n");
        printf("The system is in an UNSAFE state.\n");
    }
}
