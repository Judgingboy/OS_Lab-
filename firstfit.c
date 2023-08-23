#include<stdio.h>
int pno,bno,psize[10],bsize[10],allocation[10],i,j,flag[10];
void main()
{
    printf("\nEnter the number of the process:");
    scanf("%d",&pno);
    printf("\nEnter the number of blocks:");
    scanf("%d",&bno);
    for(int i=0;i<pno;i++)
    {
        flag[i]=0;      //oru aavishyom illa ee kopp inte
        allocation[i]=-1;
    }
    printf("\nEnter the Process Sizes:");
    for(int i=0;i<pno;i++)
    {
        scanf("%d",&psize[i]);
    }
    printf("\nEnter the block sizes:");
    for(int i=0;i<bno;i++)
    {
        scanf("%d",&bsize[i]);
    }
    for (int i = 0; i<pno; i++)
    {
        for (int j = 0; j < bno; j++)
        {
            if(bsize[j]>=psize[i])
            {
                allocation[i]=j;
                bsize[j]-=psize[i]; //reducing the block Size
                break;
            }
        }
    }
    printf("\nProcess No\t Process Size \t Block Number\n");
    for(int i=0;i<pno;i++)
    {
        printf("%d\t\t%d\t\t",i+1,psize[i]);
        if(allocation[i]!=-1)
        {
            printf("%d",allocation[i]+1);
        }
        else
        {
            printf("Not Allocated");
        }
        printf("\n");

    }   
}


