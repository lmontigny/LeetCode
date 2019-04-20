/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) {
    int i,j;
    *returnSize = *AColSizes;
    *columnSizes = (int*)malloc(sizeof(int)*(*AColSizes));
    for(i =0;i<*AColSizes;i++){
        (*columnSizes)[i] = ARowSize;
        //columnSizes[0][i]=ARowSize;
    }
    
    int** B = (int**)malloc(*AColSizes*sizeof(int*));
    for(i=0; i<*AColSizes; i++){
        B[i]= malloc(ARowSize*sizeof(int));
    }
    
    for(i=0; i<*AColSizes; i++){
            for(j=0; j<ARowSize; j++){
                B[i][j]=A[j][i];
            }
    }
    
    
    return B;
}

