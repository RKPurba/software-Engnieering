#include <bits/stdc++.h>
using namespace std;

char str[20];

char plaintext[20];

int key[10];
int key_len;
int arr[20];
int arr1[20];
int arr2[20];


void decrypt();
void get_key();
void permute(int,int,int);
void swap(int,int);

int main()
{
    //char str[50];
    int i, j, k,div[5],p=0;

    // Read a string from user
    printf("Enter a string: ");
    scanf("%s", str);
    int t = strlen(str);

    cout<<"Length:"<<t<<endl;

    printf("The divisors of %d are: ", t);
    for (i = 2; i < t; i++)
    {
        if (t % i == 0)
        {
            //printf("%d ", i);
            div[p++]=i;
        }
    }

    cout<<div[0]<<div[1]<<endl;

    int ROWS = div[0];
    int COLS = div[1];


    /* Store the string in a row and column-wise matrix
    char matrix[ROWS][COLS];
    k = 0;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (k < strlen(str))
                matrix[i][j] = str[k++];
            else
                matrix[i][j] = ' ';
        }
    }*/

    get_key();

    //decrypt();


    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int arr[], int start, int end)
{
    if (start == end)
    {
        // Print the permutation
        goto s1;
        //cout<<"returned from goto:"<<endl;

        printf("\n");
    }
    else
    {
        // Recursive permutation of subarray
        for (int i = start; i <= end; i++)
        {
            swap(&arr[start], &arr[i]);
            permute(arr, start + 1, end);
            swap(&arr[start], &arr[i]);
        }
    }

s1:
    //cout<<"goto:"<<endl;
    int text_len = strlen(str);
    int row_len = 5;
    int num_rows = 2;

    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < row_len; j++)
        {
            int index = i + j * num_rows;
            if (index < text_len)
            {
                plaintext[i * row_len + arr[j] - 1] = str[index];
            }
        }
    }

    plaintext[text_len] = '\0';
             printf("Plaintext: %s", plaintext);
             printf("\n");

    return;
}

void get_key()
{
    char input[10];
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    permute(arr1, 0, n - 1);

    int n1 = sizeof(arr2) / sizeof(arr2[0]);
    permute(arr2, 0, n1 - 1);

    //cout<<"end here"<<endl;

    //printf("Enter the key for the transposition cipher: ");
    //scanf("%s", input);


}
