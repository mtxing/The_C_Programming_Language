#include<stdio.h>
/*二分查找*/
int binsearch(int x, int vec[], int n){
	int low, high, mid;
	low = 0;
	high = n-1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if(vec[mid] > x){
			high = mid - 1;
		} 
		else if(vec[mid] < x){
			low = mid + 1;
		}
		else{
			return mid;
		}
	}
	return -1;
}

int main()
{
	int vec_1[] = {1,2,3,4,5,6,7,8,9};
	int x1 = 10, x2 = 5, idx1=-1, idx2=-1;
	idx1 = binsearch(x1, vec_1, 9);
	idx2 = binsearch(x2, vec_1, 9);
	
	printf("binsearch %d in vec , idx is %d !\n", x1, idx1);
	printf("binsearch %d in vec , idx is %d !\n", x2, idx2);
	return 0;
}