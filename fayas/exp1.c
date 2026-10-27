#include <stdio.h>
int main(){
	int arr[10],i,n,s=0;
	for(i=0;i<=10;i++)
	{
		printf("enter the number:\n");
		scanf("%d",&arr[i]);
	}
	printf("search.\n");
	scanf("%d",&n);
	for(i=0;i<=10;i++)
	{
		if(arr[i]==n)
		{
			s=1;
			break;
		}
	}
	if(s==1)
	{
		printf("\nfound");
	}	
	else
	{
		printf("\nNot found\n");
	}
return 0;	
}			
