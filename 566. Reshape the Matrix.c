

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsSize, int* numsColSize, int r, int c, int* returnSize, int** returnColumnSizes){
    if(!nums || numsSize*(*numsColSize) != r*c){
        // Return copy of the input array
        r=numsSize;
        c=*numsColSize;
    }
    
    // Define 2D matrix output
    *returnSize = r;
    int** res = (int**)malloc(r*sizeof(int*));
    *returnColumnSizes = (int*) malloc(r * sizeof(int));
    for(int i=0; i<r; i++){
        res[i] = (int*)malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }
    
    // --- Solution 1 --- //
    // Reshape matrix
    // Access input nums[i][j] with size numsSize and numsColSize limits
    // Only need to take care of the res arguments correctly
    /*
    int count = 0;
    for(int i=0; i<numsSize; i++){
        for(int j=0; j<*numsColSize; j++){
            res[count/c][count%c] = nums[i][j];
            count++;
        }
    }
    */
    
    // --- Solution 2 --- //
    int row = 0;
    int col = 0;
    for(int i=0; i<numsSize; i++){
        for(int j=0; j<*numsColSize; j++){
            res[row][col] = nums[i][j];
            col++;
            if(col==c){
                row++;
                col=0;
            }
        }
    }
    
    return res;
}

