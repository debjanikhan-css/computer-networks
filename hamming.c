#include <stdio.h>

int main() {
    int h[8] = {0};
    int errorPos;

    printf("Enter 4 data bits: ");
    scanf("%d %d %d %d", &h[3], &h[5], &h[6], &h[7]);
    h[1] = h[3] ^ h[5] ^ h[7];
    h[2] = h[3] ^ h[6] ^ h[7];
    h[4] = h[5] ^ h[6] ^ h[7];

    printf("\nHamming Code: ");
    for (int i = 1; i <= 7; i++) {
        printf("%d", h[i]);
    }
    printf("\n\nEnter error position (1-7), or 0 for no error: ");
    scanf("%d", &errorPos);

    if (errorPos >= 1 && errorPos <= 7) {
        h[errorPos] ^= 1;
    }

    printf("Received Code: ");
    for (int i = 1; i <= 7; i++) {
        printf("%d", h[i]);
    }
    int p1 = h[1] ^ h[3] ^ h[5] ^ h[7];
    int p2 = h[2] ^ h[3] ^ h[6] ^ h[7];
    int p4 = h[4] ^ h[5] ^ h[6] ^ h[7];

    int error = p1 + (p2 * 2) + (p4 * 4);

    if (error == 0) {
        printf("\nNo error detected.\n");
    } else {
        printf("\nError detected at position %d.", error);
        h[error] ^= 1;

        printf("\nCorrected Hamming Code: ");
        for (int i = 1; i <= 7; i++) {
            printf("%d", h[i]);
        }
        printf("\n");
    }
    printf("Data bits: %d%d%d%d\n",
           h[3], h[5], h[6], h[7]);

    return 0;
}
