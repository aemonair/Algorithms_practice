/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *result = (int *)(malloc(2*sizeof(int)));
    int i = 0;
    int j = 0;
    int add = 0;
    for(i=0;i<numsSize;i++)
    {
        for(j=0;j < numsSize; j++)
        {
            add = *(nums+i) +*(nums+j);
            if(add == target&& i !=j)
            {
                result[0]= j;
                result[1]= i;
            }
        }
    }
    return result;
}
