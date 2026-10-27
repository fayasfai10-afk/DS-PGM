#include <stdio.h>
int main()
{
int p1[10],p2[10],sum[10];
int degree1,degree2,maxdegree,i;
printf("enter the 1st polynomial:\n");
scanf("%d",&degree1);
printf("enter the coefficient of 1st polynomial:\n");

for(i=degree1;i>=0;i--){

	printf("coefficients of x^%d:",i); 
	scanf("%d",&p1[i]);
	}
printf("enter the 2st polynomial:\n");
scanf("%d",&degree2);
printf("enter the coefficient of 2nd polynomial:\n");
for(i=degree2;i>=0;i--)
	{
	printf("coefficient of x^%d:",i);
	scanf("%d",&p2[i]);
	}
	if(degree1>degree2)
	{
	maxdegree = degree1;
	}else{
	maxdegree = degree2;
	}
	
	for(i=0;i<=maxdegree;i++)
	{
	sum[i] = p1[i]+p2[i];
	}
	printf("sum of the two polynomials is :\n");
	for(i=maxdegree;i>=0;i--)
	{
		if(sum[i]!=0)
		{
			printf("%d^%d",sum[i],i);
			if(i!=0)
			printf("+");
			}
		}
return 0;
}			
	


