#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define max(a, b) ((a > b) ? a : b)

int* longestCommonSubsequence(int a_size, int* a, int b_size, int* b, int *result_size)
{
    // Complete this function
    int i, j, k;

    int **m = calloc((a_size + 1), sizeof(int*));
    for (i = 0; i <= a_size; i++)
        m[i] = calloc((b_size + 1), sizeof(int));

    for (i = 1; i <= a_size; i++) {
        for (j = 1; j <= b_size; j++) {
            if(a[i - 1] == b[j - 1])
                m[i][j] = 1 + m[i - 1][j - 1];
            else
                m[i][j] = max(m[i - 1][j], m[i][j - 1]);
        }
    }

    *result_size = m[a_size][b_size];
    int *result = calloc(*result_size, sizeof(int));

    i = a_size;
    j = b_size;
    k = 0;

    while (i >= 1 && j >= 1) {
        if (a[i - 1] == b[j - 1]) {
            result[*result_size - 1 - k++] = a[i - 1];
            i--;
            j--;
        }
        else if (m[i - 1][j] > m[i][j - 1])
            i--;
        else
            j--;
    }

    return result;
}

int main()
{
    int n;
    int m;
    scanf("%i %i", &n, &m);
    int *a = malloc(sizeof(int) * n);
    for (int a_i = 0; a_i < n; a_i++) {
        scanf("%i", &a[a_i]);
    }
    int *b = malloc(sizeof(int) * m);
    for (int b_i = 0; b_i < m; b_i++) {
        scanf("%i", &b[b_i]);
    }
    int result_size;
    int* result = longestCommonSubsequence(n, a, m, b, &result_size);
    for(int result_i = 0; result_i < result_size; result_i++) {
        if(result_i) {
            printf(" ");
        }
        printf("%d", result[result_i]);
    }
    puts("");


    return 0;
}
