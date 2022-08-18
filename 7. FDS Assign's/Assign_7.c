#include<stdio.h>

const int MAX=20;
typedef struct {
    int row, column, value;
} term;

void acceptMatrix(int arr[MAX][MAX], int m, int n){
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            scanf("%d", &arr[i][j]);
        }
    }
}

void display(int a[][MAX], int r1, int c1){
    int i, j;
    printf("\nMatrix\n");
    for( i=0; i<r1; i++){
        for(j=0; j<c1; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int convertToSparse(int m[][MAX], int r, int c, term sparse[]){
    int k=0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(m[i][j] != 0){
                sparse[k].row = i;
                sparse[k].column = j;
                sparse[k].value= m[i][j];
                k++;            
            }
        }
    }
    return k;
}

void displaySparse(term sparse[], int size){
    printf("\nRow\tCol.\tValue");
    for(int i=0; i<size; i++){
        printf("\n");
        printf("%d\t%d\t%d", sparse[i].row, sparse[i].column, sparse[i].value);
    }
}

int AddSparse(term m1[], term m2[], int s1, int s2, term result[]){
    int s3=0;
    int i=0, j=0;
    while(i<s1 && j<s2){
        if((m1[i].row == m2[j].row && m1[i].column < m2[j].column) || m1[i].row < m2[j].row){
            result[s3].row= m1[i].row;
            result[s3].column= m1[i].column;
            result[s3].value= m1[i].value;
            i++;   
        }
        else if(m2[j].row< m1[i].row || (m2[j].row == m1[i].row && m2[j].column < m1[i].column)){
            result[s3].row = m2[i].row;
            result[s3].column = m2[i].column;
            result[s3].value = m2[i].value;
            j++;
        }
        else{
            result[s3].row = m1[i].row;
            result[s3].column = m1[i].column;
            result[s3].value = m1[i].value + m2[j].value;

            i++;
            j++;
        }
        s3++;
    }

    while(i<s1)
    {
        result[s3].row = m1[i].row;
        result[s3].column = m1[i].column;
        result[s3].value = m1[i].value;

        i++;
        s3++;
    }
    while(j<s2){
        result[s3].row = m2[i].row;
        result[s3].column = m2[i].column;
        result[s3].value = m2[i].value;

        j++;
        s3++;
    }
    return s3;
}

int simpleTranspose(term m[], int s, int r, int c, term result[]){
    int s3= 0;
    for(int i=0; i<c; i++){
        for(int j=0; j<s; j++){
            if(m[j].column==i){
                result[s3].row = m[j].column;
                result[s3].column = m[j].row;
                result[s3].value = m[j].value;

                s3++;
            }
        }
    }
    return s3;
}

int fastTranspose(term m[], int s, int r, int c, term result[]){
    int s3=0;
    int rowTerms[c], rowStart[c];

    for(int i=0; i<c; i++){
        rowTerms[i] =0;
        rowStart[i]=0;
    }
    for(int i=0; i<s; i++){
        rowTerms[m[i].column]++;
    }
    for(int i=0; i<c; i++){
        rowStart[i]= rowStart[i-1]+ rowTerms[i-1];
    }
    for(int i=0; i<s; i++){
        int col = m[i].column;
        result[rowStart[col]].value = m[i].value;
        result[rowStart[col]].column = m[i].row;
        result[rowStart[col]].row = col;

        s3++;
        rowStart[col]++;
    }
    return s3;
}

int main(){
    int m1, n1, m2, n2;
    int matrix1[MAX][MAX], matrix2[MAX][MAX];

    term sparse1[MAX];
    term sparse2[MAX];
    term addition[MAX];
    term transpose[MAX];

    int choice = -1, s1, s2, s3, s4;

    do{
        printf("\n\t1. Accept Two Conventional Matrices\n\t2. Display Conventional Matrices\n\t3. Display Sparse Matrices\n\t4. Add Two Sparse Matyrices\n\t5. Simple Transpose\n\t6. Fast Transpose\n\t7. Exit");
        printf("\n\tEnter Your Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter Number of Rows and Columns:");
            scanf("%d%d", &m1, &n1);
            acceptMatrix(matrix1, m1, n1);

            printf("\nEnter Number of Rows and Columns:");
            scanf("%d%d", &m2, &n2);
            acceptMatrix(matrix2, m2, n2);

            break;
        case 2:
            display(matrix1, m1, n1);
            display(matrix2, m1, n1);

            break;
        case 3:
            s1= convertToSparse(matrix1, m1, n1, sparse1);
            s2= convertToSparse(matrix2, m1, n1, sparse2);

            printf("Sparse Matrix(1st)\n");
            displaySparse(sparse1, s1);

            printf("\nSparse Matrix(2nd)\n");
            displaySparse(sparse2, s2);

            printf("\n");
            break;
        case 4:
            if(m1==m2 && n1==n2){
                s3= AddSparse(sparse1, sparse2, s1, s2, addition);
                displaySparse(addition, s3);
            }
            else{
                printf("\nMatrices Cannot be Added! Enter Again!");
            }
            break;
        case 5:
            if(m1==n1){
                s3=convertToSparse(matrix1, m1, n1, sparse1);
                
                s4=simpleTranspose(sparse1, s3, m1, n1, transpose);

                printf("Simple Transpose of Matrix(1st)");
                displaySparse(transpose, s4);
                printf("\n");
            }
            else{
               printf("Transpose cannot be Performed!"); 
            }
            if(m2==m2){
                s3= convertToSparse(matrix2, m2, n2, sparse2);

                s4= simpleTranspose(sparse2, s3, m2, n2, transpose);
                printf("Simple Transpose of matrix(2nd)");
                displaySparse(transpose, s4);
                printf("\n");
            }
            else{
                printf("Transpose cannot be Performed! ");
            }
            break;
        case 6:
            if(m1==n1){
                s3= convertToSparse(matrix1, m1, n1, sparse1);

                s4= fastTranspose(sparse1, s3, m1, n1, transpose);

                printf("Fast Transpose of Matrix(1st)");
                displaySparse(transpose, s4);
                printf("\n");
            }
            else{
                printf("Transpose cannot be Performed! ");
            }
            if(m2==n2){
                s3= convertToSparse(matrix2, m2, n2, sparse2);

                s4= fastTranspose(sparse2, s3, m2, n2, transpose);
                printf("Fast Transpose of Matrix(2nd)");
                displaySparse(transpose, s4);
                printf("\n");
            }
            else{
                printf("Transpose cannot be Performed! ");
            }
            break;
        }
    }while(choice!=7);
    
    return 0;
}