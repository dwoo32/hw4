#include <stdio.h>
#include <stdlib.h>
void print_matrix(int **matrix,int rows, int cols);
int free_matrix(int **matrix, int rows, int cols);
int addition_matrix(int **a, int **b, int rows_A, int cols_A, int rows_B, int cols_B);
int subtraction_matrix(int **a, int **b, int rows_A, int cols_A, int rows_B, int cols_B);
int multiply_matrix(int **a, int **b, int rows_A, int cols_A, int rows_B, int cols_B);
void transpose_matrix(int **a, int rows, int cols);
int main()
{

    int rows_A, cols_A, rows_B, cols_B;

    // A 행렬의 행과 열 입력 받기
    printf("Enter the number of rows for matrix A: ");
    scanf("%d", &rows_A);
    printf("Enter the number of columns for matrix A: ");
    scanf("%d", &cols_A);

    // B 행렬의 행과 열 입력 받기
    printf("Enter the number of rows for matrix B: ");
    scanf("%d", &rows_B);
    printf("Enter the number of columns for matrix B: ");
    scanf("%d", &cols_B);

    // A 행렬 동적 메모리 할당
    int **A = (int **) malloc(rows_A * sizeof(int *));
    for (int i = 0; i < rows_A; i++) {
        A[i] = (int *) malloc(cols_A * sizeof(int));
    }
    int **A_t = (int **) malloc(rows_A * sizeof(int *));
    for (int i = 0; i < cols_A; i++) {
        A[i] = (int *) malloc(rows_A * sizeof(int));
    }

    // A 행렬 입력 받기
    printf("Enter values for matrix A\n");
    for (int i = 0; i < rows_A; i++){
        for (int j = 0; j < cols_A; j++) {
            printf("Enter element [%d][%d]: \n", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // B 행렬 동적 메모리 할당
    int **B = (int **) malloc(rows_B * sizeof(int *));
    for (int i = 0; i < rows_B; i++) {
        B[i] = (int *) malloc(cols_B * sizeof(int));
    }
    int **B_t = (int **) malloc(rows_B * sizeof(int *));
    for (int i = 0; i < cols_B; i++) {
        B[i] = (int *) malloc(rows_B * sizeof(int));
    }


    // B 행렬 입력 받기
    printf("Enter values for matrix B\n");
    for (int i = 0; i < rows_B; i++) {
        for (int j = 0; j < cols_B; j++) {
            printf("Enter element [%d][%d]: \n", i, j);
            scanf("%d", &B[i][j]);
       }
    }

    // A 행렬 출력하기
    printf("Matrix A:\n");
    print_matrix(A, rows_A, cols_A);

    // B 행렬 출력하기
    printf("Matrix B:\n");
    print_matrix(B, rows_B, cols_B);

    addition_matrix(A,B,rows_A,cols_A,rows_B,cols_B);
    subtraction_matrix(A,B,rows_A,cols_A,rows_B,cols_B);
    multiply_matrix(A,B,rows_A,cols_A,rows_B,cols_B);
    transpose_matrix(A,rows_A,cols_A);
    transpose_matrix(B,rows_B,cols_B);
    free_matrix(A,rows_A,cols_A);
    free_matrix(B,rows_B,cols_B);
  
   
    return 0;
}
void print_matrix(int **matrix,int rows, int cols){
    printf("------------------------------\n");
    printf("The matrix is:\n");
        for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%3d",matrix[i][j]);
            
        }
        printf("\n");
    }
}    
int free_matrix(int **matrix, int rows, int cols)
{
        
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

}
int addition_matrix(int **a, int **b, int rows_A, int cols_A, int rows_B, int cols_B){
    if((rows_A==rows_B)&&(cols_A==cols_B))
    {
    int **matrixadd;
    matrixadd = (int**) malloc(cols_A * sizeof(int*)); // 동적 할당
        for(int i=0; i<cols_A; i++)
        {
            matrixadd[i] = (int*) malloc(rows_A * sizeof(int)); // 동적 할당
            for(int j=0; j<rows_A; j++){
                matrixadd[i][j]=a[i][j]+b[i][j];
                               
            }
            
        }
        printf("\n");
        print_matrix(matrixadd,rows_A,cols_A);
        free_matrix(matrixadd,rows_A,cols_A);
    }
    else
    printf("Cannot calculate the sum of these two matrices \n");

   

}
int subtraction_matrix(int **a, int **b, int rows_A, int cols_A, int rows_B, int cols_B){
    if((rows_A==rows_B)&&(cols_A==cols_B))
    {
        int **matrixminus;
        matrixminus=(int**)malloc(cols_A*sizeof(int*));
        for(int i=0; i<cols_A; i++){
            matrixminus[i]=(int*) malloc(rows_A*sizeof(int));
            for(int j=0; j<rows_A; j++){
                matrixminus[i][j]=a[i][j]-b[i][j];
                
                
            }
            printf("\n");
            
        }
        printf("\n");
        print_matrix(matrixminus,rows_A,cols_A);
        free_matrix(matrixminus,rows_A, cols_A);
        
    }
    else
    printf("Cannot calculate the difference between these two matrices \n");

    
}

int multiply_matrix(int **a, int **b, int rows_A, int cols_A, int rows_B, int cols_B)
{
    if(cols_A==rows_B){
        int **matrixmulti;
        matrixmulti = (int**) malloc(cols_A * sizeof(int*)); // 동적 할당
        for(int i=0; i<cols_A; i++){
            matrixmulti[i] = (int*) malloc(rows_B * sizeof(int)); // 동적 할당
            for(int j=0; j<rows_B; j++){
                matrixmulti[i][j] = 0;
                for(int k = 0; k < rows_B; k++){
                    
				matrixmulti[i][j] += a[i][k] * b[k][j];
                
                
                }
               printf("\n");
                
            }
            printf("\n");
        }
        printf("\n");
        print_matrix(matrixmulti,cols_A,rows_B);
        free_matrix(matrixmulti,cols_A,rows_B); // 할당 해제
        
    }
    else
    printf("Cannot calculate the multiplication of these two matrices");
    
   
}
void transpose_matrix(int **a,  int rows, int cols)
{
    int **b;
    b = (int **) malloc(rows* sizeof(int *));
    for (int i = 0; i < rows; i++) {
        b[i] = (int *) malloc(cols * sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for ( int j = 0; j < cols; j++) {
            b[i][j]=a[j][i];
            
        }
        printf("\n");
        
    }
    print_matrix(b,cols,rows);
    
}
