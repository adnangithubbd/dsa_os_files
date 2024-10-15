#include <stdint.h>
#include <stdio.h>

#define MAX_FRAMES 3  

// Check if a page is in the frame
int isPageInFrame(int frames[], int page, int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) {
            return i; // Return the index of the page if found
        }
    }
    return -1; // Return -1 if the page is not found
}

// Print the current frames
void printFrames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1) {
            printf(" - ");
        } else {
            printf(" %d ", frames[i]);
        }
    }
    printf("\n");
}

int main() {
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};  // Page requests
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames[MAX_FRAMES];
    int counters[MAX_FRAMES];

    // Initialize frames and counters
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1; // Mark frames as empty
        counters[i] = 0; // Initialize counters
    }
    
    int page_faults = 0;

    // Process each page request
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int index = isPageInFrame(frames, page, MAX_FRAMES);

        if (index == -1) { // Page fault occurs
            page_faults++;
            int lru_index = 0;

            // Find the least recently used page
            for (int j = 1; j < MAX_FRAMES; j++) {
                if (counters[j] < counters[lru_index]) {
                    lru_index = j; // Update the index of the least recently used page
                }
            }

            // Replace the least recently used page with the new page
            frames[lru_index] = page; // Insert the new page
            counters[lru_index] = i; // Update the counter for the new page
        } else { // Page hit
            counters[index] = i; // Update the counter for the existing page
        }

        // Print the current state of the frames after each request
        printf("Current frames: ");
        printFrames(frames, MAX_FRAMES);
    }

    // Print the total number of page faults
    printf("Total page faults: %d\n", page_faults); // Corrected printf statement for total page faults
    return 0;
}
