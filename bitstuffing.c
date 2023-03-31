#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[20],b[40],i,j,count,n=0;
	printf("enter the number of bits");
	scanf("%d",&n);
	printf("enter the %d bits\n",n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	i=0;
	count=1;
	j=0;
	while(i<n)
	{
		if(a[i]==1)
		{
			b[j]=b[i];
			for(int k=i+1;a[k]==1 && k<n  && count<5;k++){
				j++;
				b[j]=a[k];
				count++;
				if(count==5){
					j++;
					b[j]=0;
				}
				i=k;
			}
			
		}
		else{
			b[j]=a[i];
			
		}
		j++;
			i++;
	}
	printf("string after bitstuffing is: ");
	for(int i=0;i<j;i++)
		printf("%d ",b[i]);
	printf("\n");
}
