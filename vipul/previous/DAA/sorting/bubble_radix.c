#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100

void radix_sort(char **, int, int);

int main()
{
	char **input;
	char ch=' ';
	int n, k, i, j;
	srand(time(NULL));
	scanf("%d", &n);
	scanf("%d", &k);
	input = (char **)malloc(n*sizeof(char *));
	for(i = 0;i < n; i++)
	{
		input[i] = (char *)malloc((k+1)*sizeof(char));
		for(j = 0; j < k; j++)
			input[i][j] = (rand()%95)+32;
		input[i][k]='\0';
	}
//INPUT
	printf("INPUT\n");
	for(i=0;i<n;i++)
	{
		printf("%s\n",input[i]);
	}

	radix_sort(input,n,k);
	printf("\nOUTPUT\n");
	for(i=0;i<n;i++)
	{
		printf("%s\n",input[i]);
	}
	return 0;
}

void count_sort(char **input,int n,int i,int k)
{
    int m,p;
    char *temp=(char *)malloc(sizeof(char)*(k+1));
    for(m=1;m<n;m++)
    for(p=0;p<n-m;p++){
            if(input[p][i]>input[p+1][i]){
                    strcpy(temp,input[p]);
                    strcpy(input[p],input[p+1]);
                    strcpy(input[p+1],temp);
            }
    }

}


void radix_sort(char **input, int n, int k)
{
  /* The function sorts the array input using radix sort
     Write the two versions of the radix sort here, one after another.
     To execute one of the version just comment out the other version.
   */
  	int i;
	for(i = k-1; i >= 0; i--) {
		count_sort(input, n, i, k);
	}
}
