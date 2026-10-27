#include <stdio.h>
int main()
{
	int arr[5];
	int i,j,temp=0;
	for(i=0;i<5;i++)
	{
		printf("enter no:");
		scanf("%d",&arr[i]);
	}
	
	for(i=0;i<5;i++){
		for(j=0;j<5-1-i;j++){
			if(arr[j]>arr[j+1]){
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		}
	}
}

	for(i=0;i<5;i++){
		printf("%d\n",arr[i]);
	}

return 0;
}					
