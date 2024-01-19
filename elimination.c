#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	float a[20][20],x[20],sum=0;
	int n,i, j ,k;
	printf("enter the order of the matrix \n");
	scanf("%d",&n);
	printf("enter the respective elements for the augmented materix \n");
	for(i=0;i<=n;i++)
	{
		for(j=1;j<=n+1;j++)
		{
			scanf("%f",&a[i][j]);
		}
	}
	for(j=1;j<=n-1;j++)
	{
		if(fabs(a[j][j])<=0.005)
		{
			exit(0);
		}
		for(i=j+1;i<=n;i++)
		{
			float temp=a[i][j];
			for(k=1;k<=n+1;k++)
			{
				a[i][k]=a[i][k]-(temp/a[j][j])*a[j][k];
			}
		}
	}
	x[n]=a[n][n+1]/a[n][n];
	for(i=n-1;i>=1;i--)
	{
		for(j=i+1;j<=n;j++)
		{
			sum=sum+a[i][j]*x[j];
		}
		x[i]=(a[i][n+1]-sum)/a[i][i];
	}
	
	for(i=1;i<=n;i++)
	{
		printf("x[%d]=%f \n",i,x[i]);
		
	}
	return 0;
}
