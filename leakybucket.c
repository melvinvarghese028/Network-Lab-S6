#include<stdio.h>
int main()
{
    int i,in,out,n,bsize,bucket=0,ina[20];
    printf("\nEnter the bucket size:");
    scanf("%d",&bsize);
    printf("\nEnter the no. of inputs:");
    scanf("%d",&n);
    printf("\nEnter the outgoing rate:");
    scanf("%d",&out);
    for(i=0;i<n;i++)
    {
       printf("\nEnter the input size of packet%d:",i+1);
        scanf("%d",&ina[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("\n\nAt insertion of packet%d",i+1);
        
        if(ina[i]<=(bsize-bucket))
        {
            bucket=bucket+ina[i];
            printf("\nBucket status after insertion:%d out of %d",bucket,bsize);
            if(ina[i]<out)
            {
                printf("\n%d byte packet transfered",ina[i]);
                bucket-=ina[i];
            }
            else
            {
                printf("\n%d byte packet transfered",out);
                 bucket-=out;
            }
            printf("\nBucket status after transfer:%d out of %d\n",bucket,bsize);
        }
        else
        {
            printf("\n%d byte packet discarded",ina[i]);
            if(bucket<out)
            {
                printf("\n%d byte packet transfered",bucket);
                bucket=0;
            }
            else
            {
                printf("\n%d byte packet transfered",out);
                 bucket-=out;
            }
            printf("\nBucket status after transfer:%d out of %d\n",bucket,bsize);


        }
    }
}