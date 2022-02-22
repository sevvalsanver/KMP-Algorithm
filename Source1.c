#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void KMPSearch(char* A,char* B, int size_A, int size_B)
{
    //size_A= size of [A], size_B= size of [B]
    
    // *next stores the index of the next best match
    int* next = malloc((size_B+1)*sizeof(int));
    int count = 0;

    for (int i = 0; i < size_B + 1; i++) {
        next[i] = 0;
    }

    for (int i = 1; i < size_B; i++)
    {
        int j = next[i + 1];

        while (j > 0 && B[j] != B[i]) {
            j = next[j];
        }

        if (j > 0 || B[j] == B[i]) {
            next[i + 1] = j + 1;
        }
    }
    // index starts 0
    printf("B metninin bulundugu konumlar: ");
    for (int i = 0, j = 0; i < size_A; i++)
    {
        if (*(A + i) == *(B + j))
        {
            
            if (++j == size_B) {
                count++;
                printf("%d ", i - j + 1);
            }
        }
        else if (j > 0)
        {
            j = next[j];
            i--;    
        }
    }
    if (count == 0)
    {
        printf("\n\nB pattern'i A dizisinde bulunamadi.\n", count);
    }
    else
    {
        printf("\n\nEslestirme Sonucu: %d farkli eslestirme gerceklesti.\n", count);
    }
    
}
// convertString() converts the int array to char array
char* convertString(int array[], int size) {
    int i;
    char* output = (char*)malloc(1024);
    char* point = output;
    
    for (i = 0; i != size; ++i)
        point = point + sprintf(point,"%d",array[i]);

    return output;
}
// sizeControl() controls the size of arrays to string search
void sizeControl(int size_A, int size_B)
{
    int i, num;
    int A[1024];
    int B[1024];

    for (i = 0; i < size_A; i++)
    {
        num = rand() % 2; //generate a random value between 0 and 1
        A[i] = num;
    }
    for (i = 0; i < size_B; i++)
    {
        num = rand() % 2; //generate a random value between 0 and 1
        B[i] = num;
    }
    printf("\nRastgele bir sekilde %d ve %d elemanli iki farkli dizi olusturuldu:\n",size_A,size_B);
    printf("\nA = ");
    for (i = 0; i < size_A; i++)
    {
        printf("%d", A[i]);

    }
    printf("\n\n");
    printf("B = ");
    for (i = 0; i < size_B; i++)
    {
        printf("%d", B[i]);
    }
    printf("\n\n");
    if (size_A <= 0 || size_B <= 0)
    {
    printf("\nString aramasi yapilabilmesi icin A ve B dizilerinin eleman sayisi 0'dan buyuk olmalidir.\n");
    }
    // [A] 's length is less than [B]'s
    else if (size_B > size_A) 
    {
        printf("\nB pattern'i A dizisinde bulunamadi.\nString aramasi yapilabilmesi icin A dizisinin eleman sayisi B dizisinden buyuk olmalidir.\n");
    }
    
    // [A]'s length is more than [B]'s & size of [A] and size of [B] is not equal 0
    else if (size_A > size_B && size_A != 0 && size_B != 0)
    {
        char* x = convertString(A, size_A); // char array of [A]
        char* y = convertString(B, size_B); // char array of [B]
        size_t sizeA = strlen(x); //calculate the size of char *x
        size_t sizeB = strlen(y); //calculate the size of char *y

        KMPSearch(x, y, sizeA, sizeB);
        printf("\n");
    }
}
int main()
{
    //[A] is text array, [B] is pattern
    // n size of [A], m size of [B]
    int n, m; 
    printf("A dizisinin boyutunu giriniz:\n");
    scanf("%d",&n);

    printf("B dizisinin boyutunu giriniz:\n");
    scanf("%d",&m);
    
    sizeControl(n, m);
    return 0;
}