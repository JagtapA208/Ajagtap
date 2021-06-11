#include<stdio.h>
#include<stdlib.h>

void AcceptMatrix(int *m,int row,int col)
{
  int i,j;
  printf("\n********Enter data : ********");

  for(i=0; i<row; i++)
  {
    for(j=0; j<col; j++)
    {
      printf("\nEnter data for cell[%d][%d] : ",i+1,j+1);
      scanf("%d",(m + (i*col) + j));
    }
  }
}

void DisplayMatrix(int *m,int row,int col)
{
  int i,j;

  for(i=0; i<row; i++)
  {
    printf("\n");
    for(j=0; j<col; j++)
     printf("%d ",*(m + i*col + j));
  }
  printf("\n");
}

void Multiplication(int *m1,int *m2,int *m3,int row,int col)
{
   int i,j,k,ans;

   for(i=0; i<row; i++)
   {
     for(j=0; j<col; j++)
     {  ans = 0;
       for(k=0; k<col; k++)
         ans =ans + ((*(m1 + i*col + k)) * (*(m2 + k*col + j)));
        *(m3 + i*col + j) = ans; 
     }
   }
}



int main()
{
  int m1,n1,m2,n2,*mat1,*mat2,*mat3;

  printf("\nEnter number of rows for matrix1 : ");
  scanf("%d",&m1);

  printf("\nEnter number of columns for matrix1 : ");
  scanf("%d",&n1);

  printf("\nEnter number of rows for matrix2 : ");
  scanf("%d",&m2);

  printf("\nEnter number of columns for matrix2 : ");
  scanf("%d",&n2);

  if(n1 != m2)
    printf("\nMultiplication is not possible.\nColumns of 1st matrix and rows of 2nd matrix should be equal\n");
  else
  {
     
     mat1 = (int *)malloc((m1*n1)*sizeof(int));
     mat2 = (int *)malloc((m2*n2)*sizeof(int));
     mat3 = (int *)malloc((m1*n2)*sizeof(int));

    AcceptMatrix(mat1, m1, n1);
    AcceptMatrix(mat2, m2, n2);

    Multiplication(mat1,mat2,mat3,m1,n2);
    
    printf("\nMatrix Multiplication : ");
    DisplayMatrix(mat3, m1, n2);
  }
  return 1;
}