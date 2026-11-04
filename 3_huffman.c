#include <stdio.h>

char ch[20];
int freq[40], left[40], right[40], used[40];

void printCodes(int node, char code[], int depth) {
    if (left[node] == -1) {
        code[depth] = '\0';
        printf("%c : %s\n", ch[node], code);
        return;
    }
    code[depth] = '0';
    printCodes(left[node], code, depth + 1);
    code[depth] = '1';
    printCodes(right[node], code, depth + 1);
}

int main() {
    int n, i, k, a, b;
    char code[20];

    printf("Enter number of characters: ");
    scanf("%d", &n);
    printf("Enter each character and its frequency:\n");
    for (i = 0; i < n; i++) {
        scanf(" %c %d", &ch[i], &freq[i]);
        left[i] = -1;
        right[i] = -1;
    }

    if (n == 1) {
        printf("%c : 0\n", ch[0]);
        return 0;
    }

    for (k = n; k < 2 * n - 1; k++) {
        a = -1;
        b = -1;
        for (i = 0; i < k; i++) {
            if (used[i] == 0) {
                if (a == -1 || freq[i] < freq[a]) {
                    b = a;
                    a = i;
                } else if (b == -1 || freq[i] < freq[b]) {
                    b = i;
                }
            }
        }
        freq[k] = freq[a] + freq[b];
        left[k] = a;
        right[k] = b;
        used[a] = 1;
        used[b] = 1;
    }

    printf("Huffman Codes:\n");
    printCodes(2 * n - 2, code, 0);
    return 0;
}
