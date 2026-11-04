#include <stdio.h>

int main() {
    int n, i, j, t, last = 0;
    int s[20], f[20];

    printf("Enter number of activities: ");
    scanf("%d", &n);
    printf("Enter start and finish time of each activity:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &s[i], &f[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (f[j] < f[i]) {
                t = f[i]; f[i] = f[j]; f[j] = t;
                t = s[i]; s[i] = s[j]; s[j] = t;
            }
        }
    }

    printf("Selected activities:\n");
    for (i = 0; i < n; i++) {
        if (s[i] >= last) {
            printf("(%d, %d)\n", s[i], f[i]);
            last = f[i];
        }
    }
    return 0;
}
