//here is a simple implementation of leaky bucket.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int i,packets[10],content=0,newcontent,time,clk,bcktsize,oprate;
	for(i=0;i<5;i++)
	{
		packets[i]=rand()%10;
		if(packets[i]==0) --i;
	}
	printf("\n Enter output rate of the bucket: \n");
	scanf("%d",&oprate);	
	printf("\n Enter Bucketsize\n");
	scanf("%d",&bcktsize);
	for(i=0;i<5;++i)
	{
		if((packets[i]+content)>bcktsize)
		{
			if(packets[i]>bcktsize)
				printf("\n Incoming packet size %d greater than the size of the bucket\n",packets[i]);
			else
			printf("\n bucket size exceeded\n");
		}
		else
		{
			newcontent=packets[i];
			content+=newcontent;
			printf("\n Incoming Packet : %d\n",newcontent);
			printf("\n Transmission left : %d\n",content);
			time=rand()%10;
			printf("\n Next packet will come at %d\n",time);
			for(clk=0;clk<time && content>0;++clk)
			{	
				printf("\n Left time %d",(time-clk));
				sleep(1);
				if(content)
				{
					printf("\n Transmitted\n");
					if(content<oprate)
						content=0;
					else
						content=content-oprate;
					printf("\n Bytes remaining : %d\n",content);
				}
				else
					printf("\n No packets to send\n");
			}
		}	
	}
}

