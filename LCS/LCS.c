#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Find_LCS(int m, int n, char A[], char B[], int C[m + 1][n + 1], int Sy[m + 1][n + 1]);

void print_LCS(int i, int j, int Sy[i + 1][j + 1], char A[]);

void print_Matrix(int m, int n, char A[], char B[], int C[m + 1][n + 1], int Sy[m + 1][n + 1]);

void main()
{
    char A[100], B[100], S[100];

    system("cls");
    printf("\t\t\t\tLongest Common Subsequence\n");
    printf("\t\t\t--------------------------------------\n\n");

    printf("Enter First String : ");
    scanf("%s", &A);

    printf("Enter Secong String : ");
    scanf("%s", &B);

    printf("\n\n");

    int m = strlen(A);
    int n = strlen(B);

    int C[m + 1][n + 1];
    int Sy[m + 1][n + 1];

    Find_LCS(m, n, A, B, C, Sy);

    print_LCS(m, n, Sy, A);
    printf("\n\n");

    int flag;
    printf("Press 1 to Print Matrix or Any key to Exit : ");
    scanf("%d",&flag);
    printf("\n\n");
    if(flag == 1)
    {
        print_Matrix(m, n, A, B, C, Sy);
    }
    else
    {
        exit(0);
    }

}

void Find_LCS(int m, int n, char A[], char B[], int C[m + 1][n + 1], int Sy[m + 1][n + 1])
{

    int i, j, k;

    for (i = 0; i <= m; i++)
    {
        C[i][0] = 0;
        Sy[i][0] = 0;
    }

    for (j = 0; j <= n; j++)
    {
        C[0][j] = 0;
        Sy[0][j] = 0;
    }

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                C[i][j] = C[i - 1][j - 1] + 1; // "\"
                Sy[i][j] = 92;
            }
            else if (C[i - 1][j] >= C[i][j - 1])
            {
                C[i][j] = C[i - 1][j]; // "^"
                Sy[i][j] = 94;
            }
            else
            {
                C[i][j] = C[i][j - 1];
                Sy[i][j] = 60; // "<"
            }
        }
    }
}

void print_LCS(int i, int j, int Sy[i + 1][j + 1], char A[])
{
    char s[50];
    int k = 0, l;
    while (i > 0 && j > 0)
    {
        if (Sy[i][j] == 92)
        {
            s[k++] = A[i - 1];
            i--;
            j--;
        }

        else if (Sy[i][j] == 94)
            i--;
        else
            j--;
    }
    s[k--] = '\0';

    if(k==-1)
    {
        printf("No Common Subsequence found");
        return;
    }
    printf("Longest Common Subsequence : ");
    for (l = k; l >= 0; l--)
    {
        printf("%c", s[l]);
    }
}
void print_Matrix(int m, int n, char A[], char B[], int C[m + 1][n + 1], int Sy[m + 1][n + 1])
{
    int i, j, k;
    for (i = 0; i <= m; i++)
    {
        if (i == 0)
        {
            printf("         ");
            for (k = 0; k <= n; k++)
            {

                printf("%c     ", B[k]);
            }
            printf("\n");
        }

        for (j = 0; j <= n; j++)
        {
            if (j == 0 && i != 0)
            {
                printf("%c ", A[i - 1]);
            }
            if (i == 0)
            {
                printf("   ");
                printf("%d  ", C[i][j]);
            }
            else
            {
                printf("%c %d   ", Sy[i][j], C[i][j]);
            }
        }
        printf("\n");
    }
}

// ABCDBACDF
// CBAF