#include <stdio.h>
#include <stdlib.h>
void print_matrix(int **matrix,int rows, int cols); //print_matrix 함수 선언
int free_matrix(int **matrix, int rows, int cols); //free_matrix 함수 선언
int addition_matrix(int **a, int **b, int rows_A, int cols_A, int rows_B, int cols_B); //addition_matrix 함수 선언
int subtraction_matrix(int **a, int **b, int rows_A, int cols_A, int rows_B, int cols_B);//subtraction_matrix 함수 선언
int multiply_matrix(int **a, int **b, int rows_A, int cols_A, int rows_B, int cols_B);//multiply_matrix 함수 선언
void transpose_matrix(int **a, int rows, int cols); //tranpose_matrix 함수 선언
int main()
{

    int rows_A, cols_A, rows_B, cols_B; //행렬 a,b의 행과 열을 각각 변수 선언

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
    //A행렬을 전치시킨 행렬의 동적 메모리 할당
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
    //B행렬을 전치시킨 행렬의 동적 메모리 할당
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

    addition_matrix(A,B,rows_A,cols_A,rows_B,cols_B); //addition_matrix 함수 출력
    subtraction_matrix(A,B,rows_A,cols_A,rows_B,cols_B); //substraction_matrix 함수 출력
    multiply_matrix(A,B,rows_A,cols_A,rows_B,cols_B); //multiply_matrix 함수 출력
    transpose_matrix(A,rows_A,cols_A);//transpose_matrix A로 함수 출력
    transpose_matrix(B,rows_B,cols_B);//transpose_matrix B로 함수 출력
    free_matrix(A,rows_A,cols_A); //A행렬 동적메모리 할당 해제
    free_matrix(B,rows_B,cols_B); //B행렬 동적메모리 할당 해제
  
   
    return 0;
}
void print_matrix(int **matrix,int rows, int cols){ //int형 이중포인터 변수 matrix와 int형 변수 rows, cols를 매개변수로 갖는 void형 함수
    printf("------------------------------\n");
    printf("The matrix is:\n");
        for(int i=0; i<rows; i++){ //행렬의 행만큼 반복
        for(int j=0; j<cols; j++){ //행렬의 열만큼 반복
            printf("%3d",matrix[i][j]); //행렬 출력
            
        }
        printf("\n");
    }
}    
int free_matrix(int **matrix, int rows, int cols) //int형 이중포인터 변수 matrix와 int형 변수 rows, cols를 매개변수로 갖는 free_matrix 함수
{
        
    for (int i = 0; i < rows; i++) { //행렬의 행만큼 반복
        free(matrix[i]);//행렬의 행들 메모리 해제
    }
    free(matrix);//행렬의 열들 메모리 해제
    

}
int addition_matrix(int **a, int **b, int rows_A, int cols_A, int rows_B, int cols_B){//이중포인터 변수 a,b와 행렬A,B의 행과 열을 각각 매개변수로 받는 함수
    int **matrixadd;
    matrixadd = (int**) malloc(rows_A * sizeof(int*)); // 행렬 A와B의 합을 저장할 행렬의 행만큼 동적 할당
        for(int i=0; i<rows_A; i++)
        {
            matrixadd[i] = (int*) malloc(cols_A * sizeof(int)*rows_A); // 열만큼 동적 할당
        }
    if((rows_A==rows_B)&&(cols_A==cols_B)) //행렬A,B의 행과 열이 모두 동일할 때
    {
    
            for(int i=0; i<rows_A; i++){
                for(int j=0; j<cols_A; j++){
                matrixadd[i][j]=a[i][j]+b[i][j]; //행렬의 합 구하기
                }
                               
            }
            
        
        printf("\n");
        print_matrix(matrixadd,rows_A,cols_A); //행렬의 합 출력
        free_matrix(matrixadd,rows_A,cols_A); //행렬의 합을 저장한 행렬의 동적 메모리 해제
    }
    else
    printf("Cannot calculate the sum of these two matrices \n"); //행렬의 합을 구할 수 없다고 출력

   

}
int subtraction_matrix(int **a, int **b, int rows_A, int cols_A, int rows_B, int cols_B){//이중포인터 변수 a,b와 행렬A,B의 행과 열을 각각 매개변수로 받는 함수
    int **matrixminus;
        matrixminus=(int**)malloc(rows_A*sizeof(int*)); //행렬 A와B의 차을 저장할 행렬의 행만큼 동적 할당
        for(int i=0; i<rows_A; i++){
            matrixminus[i]=(int*) malloc(cols_A*sizeof(int)); //행렬 A와B의 차를 저장할 행렬의 열만큼 동적 할당
        }
    if((rows_A==rows_B)&&(cols_A==cols_B)) //행렬A와B의 행과 열이 각각 같을 때만 출력
    {
        
            for(int i=0; i<rows_A; i++){//행렬A의 행 만큼 반복
                for(int j=0; j<cols_A; j++){ //행렬A의 열만큼 반복
                matrixminus[i][j]=a[i][j]-b[i][j]; //행렬의 차 구하기
                
                }
            }
            printf("\n");
            
        
        printf("\n");
        print_matrix(matrixminus,rows_A,cols_A); //matrixminus 출력
        free_matrix(matrixminus,rows_A, cols_A); //matrtixminus 메모리 해제

        
    }
    else
    printf("Cannot calculate the difference between these two matrices \n"); //두 행렬의 차를 계산할 수 없음

    
}

int multiply_matrix(int **a, int **b, int rows_A, int cols_A, int rows_B, int cols_B) //
{
    int i,j=0; //int형 변수 i,j 선언
    int **matrixmulti; //행렬의 곱을 저장할 matrixmulti 선언
        matrixmulti = (int**) malloc(rows_A * sizeof(int*)); //행렬A의 행만큼 동적 할당
        for(int i=0; i<rows_A; i++){
            matrixmulti[i] = (int*) malloc(cols_B * sizeof(int)); //행렬 B의 열만큼 동적 할당
        }
    if(cols_A==rows_B){ //행렬의 곱은 행렬A의 열과 행렬B의 행이 같을 때 실행
        
            for(int i=0; i<rows_A; i++){//행렬A의 열만큼 반복
                for(int j=0; j<rows_A; j++)//행렬A의 열만큼 반복
                {
                    int temp=0; //int형 변수 temp선언
                    for(int k = 0; k < cols_B; k++){//행렬B의 행만큼 반복
                        
                    temp += a[i][k] * b[k][j]; //temp = temp + a[i][k]*b[k][j]
                    matrixmulti[i][j]=temp;//matrixmulti에 temp값 할당
                    
                    }
                }
               printf("\n");
                
            }
            printf("\n");
        
        printf("\n");
        print_matrix(matrixmulti,rows_B,cols_A); //matrixmulti 출력
        free_matrix(matrixmulti,rows_B,cols_A); //matrixmulti 동적 메모리 해제
        
    }
    else
    printf("Cannot calculate the multiplication of these two matrices");//행렬A의 열과 행렬B의 행이 다를 시 계산할 수 없다고 출력
    
   
}
void transpose_matrix(int **a,  int rows, int cols)//int형 이중포인터 변수, 행, 열을 매개변수로 받는 함수 tarnspose_matrix
{
    int **b; //전치행렬을 저장할 b선언
    b = (int **) malloc(cols* sizeof(int *)); //b의 열만큼 동적메모리 할당
    for (int i = 0; i < cols; i++) {
        b[i] = (int *) malloc(rows * sizeof(int));//b의 행만큼 동적메모리 할당
    }
    for (int i = 0; i < cols; i++) { //열만큼 반복
        for ( int j = 0; j < rows; j++) {//행만큼 반복
            b[i][j]=a[j][i]; //전치행렬 구하기
            
        }
        printf("\n");
        
    }
    print_matrix(b,cols,rows);//전치행렬 출력
    free_matrix(b,rows,cols);


    
}
