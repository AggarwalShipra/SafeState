#include<stdio.h>
#include<stdlib.h>
//fxn to display all datastructures values.
int no_of_pro,no_of_res;
int inst[5],avail_inst[3];
int alloc[5][3],max[5][3],need[5][3],work[3],finish[5];
void display()
{
	int i,j;
	printf("Number of process are %d \n",no_of_pro);
	printf("Number of resources are %d \n",no_of_res);
	printf("\nTotal Instances\n");
	for(i=0;i<no_of_res;i++)
	{
		printf("%c --> %d ",i+65,inst[i]);
	}
	printf("\nAvailable Instances\n");
	for(i=0;i<no_of_res;i++)
	{
		printf("%c --> %d ",i+65,avail_inst[i]);
	}
	printf("\nProcess\tAllocated Resource");
	for(i=0;i<no_of_pro;i++)
	{	
		printf("\n%d\t",i);
		for(j=0;j<no_of_res;j++)
		{
			printf("%c->%d\t",j+65,alloc[i][j]);		
		}
	}
	printf("\nProcess\tMaximum Resource");
	for(i=0;i<no_of_pro;i++)
	{	
		printf("\n%d\t",i);
		for(j=0;j<no_of_res;j++)
		{
			printf("%c->%d\t",j+65,max[i][j]);		
		}
	}
	printf("\nProcess\tNeed");
	for(i=0;i<no_of_pro;i++)
	{	
		printf("\n%d\t",i);
		for(j=0;j<no_of_res;j++)
		{
			printf("%c->%d\t",j+65,need[i][j]);		
		}
	}	
}
void check()
{	
	printf("\n");
	int i,j,count;
	for(i=0;i<no_of_pro;i++)
	{
		count=0;
		if(finish[i]==0)
		{
			for(j=0;j<no_of_res;j++)
			{
				if(need[i][j]<=work[j])
				count++;
			}
			if(count==no_of_res)
			{
				printf(" P%d \t",i);
				finish[i]=1;
				for(j=0;j<no_of_res;j++)
				{	
					work[j]=work[j]+alloc[i][j];
				}
				i=-1;
			}
		}
	}
	count=0;
	for(i=0;i<no_of_pro;i++)
	{
		if(finish[i]==1)
		{
			count++;
		}
	}
	if(count==no_of_pro)
	{
		printf("\nSafe State\n");
	}
	else
	printf("\nUnsafe state\n");
}
int main()
{	
int i,j;
no_of_pro=5;
no_of_res=3;
inst[0]=10;inst[1]=5;inst[2]=7;
avail_inst[0]=3;avail_inst[1]=3;avail_inst[2]=2;
alloc[0][0]=0;alloc[0][1]=1;alloc[0][2]=0;
alloc[1][0]=2;alloc[1][1]=0;alloc[1][2]=0;
alloc[2][0]=3;alloc[2][1]=0;alloc[2][2]=2;
alloc[3][0]=2;alloc[3][1]=1;alloc[3][2]=1;
alloc[4][0]=0;alloc[4][1]=0;alloc[4][2]=2;
max[0][0]=7;max[0][1]=5;max[0][2]=3;
max[1][0]=3;max[1][1]=2;max[1][2]=2;
max[2][0]=9;max[2][1]=0;max[2][2]=2;
max[3][0]=2;max[3][1]=2;max[3][2]=2;
max[4][0]=4;max[4][1]=3;max[4][2]=3;
for(i=0;i<no_of_pro;i++)
	{	
	finish[i]=0;
	for(j=0;j<no_of_res;j++)
		{
		work[j]=avail_inst[j];
		if(max[i][j]>inst[j])
				{
					printf("Process is asking for invalid number of resources. Error.\n");
					exit(0);
				}
		need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	display();
	check();
}
