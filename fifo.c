#include <stdio.h>

int main() {
    int pages[50], frames[50];
    int n, f, i, j, k = 0, found, page_fault = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page numbers: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &f);

    // Initialize all frames to -1
    for(i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++) {
        found = 0;

        // Check if the page is already in the frame
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            // Page fault: replace using FIFO
            frames[k] = pages[i];
            k = (k + 1) % f;
            page_fault++;

            // Print current frames
            printf("%d\t", pages[i]);
            for(j = 0; j < f; j++) {
                if(frames[j] != -1)
                    printf("%d ", frames[j]);
                else
                    printf("_ ");
            }
            printf("\n");
        } else {
            // Page hit
            printf("%d\tHit\n", pages[i]);
        }
    }

    printf("\nTotal Page Faults: %d\n", page_fault);
    return 0;
}
