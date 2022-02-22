#include <iostream>
using namespace std;

void computeLPSArray(char* pat, int M, int* lps);

// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, char* txt)
{
    int M = 256;
    M = strlen(pat);
    int N = strlen(txt);

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
char* PrintArray(int array[], int n) {
    int i;
    char* output = (char*)malloc(128);
    char* point = output + 1;
    *output = '[';
    for (i = 0; i != n; ++i)
        point += sprintf(point, i + 1 != n ? "%d," : "%d]", array[i]);

    return output;
}
int main()
{
    int n, m, i, num;
    printf("Enter the size of the array A:\n");
    scanf("%d",&n);
    printf("Enter the size of the array B:\n");
    scanf("%d", &m);

    int A[256];
    /*(int*)malloc(n * sizeof(int));
     (int*)malloc(m * sizeof(int));*/
    int B[256];

    for (i = 0; i < n; i++)
    {
        num = rand() % 2;
        A[i] = num;
    }
    for (i = 0; i < m; i++)
    {
        num = rand() % 2;
        B[i] = num;
    }
    printf("\nA = ");
    for (i = 0; i < n; i++)
    {
        printf("%d",A[i]);

    }
    printf("\n\n");
    printf("B = ");
    for (i = 0; i < m; i++)
    {
        printf("%d",B[i]);
    }
    printf("\n");
    char *x=PrintArray(A,n);    
    char *y=PrintArray(B,m);
    printf("A= %d", x);
    printf("\n");
    printf("B= %d", y);
    printf("\n");
    //KMPSearch(A, B);
    return 0;
}