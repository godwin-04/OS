#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 20

int main() {
    int pages[MAX_PAGES]; // Array to hold page references
    int frames[MAX_FRAMES]; // Array to hold page frames
    int pageFaults = 0; // Counter for page faults
    int numPages, numFrames; // Number of pages and frames

    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    printf("Enter the page references: ");
    for (int i = 0; i < numPages; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    // Initialize all frames to -1 (indicating an empty frame)
    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;
    }

    // Iterate through each page reference
    for (int i = 0; i < numPages; i++) {
        int page = pages[i];
        int pageFound = 0; // Flag to check if page is already in a frame

        // Check if the page is already in a frame
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == page) {
                pageFound = 1;
                break;
            }
        }

        // If the page is not found in any frame, replace the optimal page
        if (!pageFound) {
            int optimalIndex = -1; // Index of the optimal page to replace
            int farthestPage = i + 1; // Initialize farthest page to be replaced

            // Iterate through each frame to find the optimal page to replace
            for (int j = 0; j < numFrames; j++) {
                int k;

                // Iterate through remaining pages to find the farthest occurrence
                for (k = i + 1; k < numPages; k++) {
                    if (frames[j] == pages[k]) {
                        if (k > farthestPage) {
                            farthestPage = k;
                            optimalIndex = j;
                        }
                        break;
                    }
                }

                // If the page is not referenced in the future, replace it
                if (k == numPages) {
                    optimalIndex = j;
                    break;
                }
            }

            // Replace the optimal page with the new page
            frames[optimalIndex] = page;
            pageFaults++;
        }

        // Print the current page frames
        printf("Page Frames: ");
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == -1) {
                printf(" -");
            } else {
                printf(" %d", frames[j]);
            }
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}


