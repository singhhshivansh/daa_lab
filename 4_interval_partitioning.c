#include <stdio.h>

int main() {
    int n, i, j, t, rooms = 0;
    int s[20], f[20], end[20];

    printf("Enter number of intervals: ");
    scanf("%d", &n);
    printf("Enter start and finish time of each interval:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &s[i], &f[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (s[j] < s[i]) {
                t = s[i]; s[i] = s[j]; s[j] = t;
                t = f[i]; f[i] = f[j]; f[j] = t;
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < rooms; j++) {
            if (end[j] <= s[i]) {
                break;
            }
        }
        if (j == rooms) {
            rooms = rooms + 1;
        }
        end[j] = f[i];
        printf("Interval (%d, %d) -> Room %d\n", s[i], f[i], j + 1);
    }

    printf("Total rooms needed = %d\n", rooms);
    return 0;
}
