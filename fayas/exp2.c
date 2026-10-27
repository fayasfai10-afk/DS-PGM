#include <stdio.h>
int main(){
	int arr[7];
	int target;
	int i;

	printf("enter the sorted number:\n");
	for(i=0;i<7;i++){
		scanf("%d",&arr[i]);
	}
	
	printf("enter target number:\n");
	scanf("%d",&target);	
	
	int l=0;
	int r=6;
	
	while(l<=r){
		int mid = (l+r)/2;
		
		if(arr[mid] == target){
			printf("found at position %d\n",mid);
			return 0;
			
		}
		
		if (arr[mid]<target){
			l=mid+1;
		}else {
			r=mid-1;
		}		
	}
	printf("not found");
	return 0;
}		
	
