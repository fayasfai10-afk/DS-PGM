#include <stdio.h>
int main()
{
	int arr[5],min;
	int i,j,temp=0;
	for(i=0;i<5;i++)
	{
		printf("enter no:");
		scanf("%d",&arr[i]);
	}
	
	for(i=0;i<5-1;i++){
		min=i;
		for(j=i+1;j<5;j++){
			if(arr[j]<arr[min]){
			min=j;
			}
		}	
			temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
		}

	for(i=0;i<5;i++){
		printf("%d\n",arr[i]);
	}

return 0;
}					
