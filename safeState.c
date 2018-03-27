#include<stdio.h>
#include<stdlib.h>

//data structure used
int no_of_pro,no_of_res;
int *inst,*avail_inst,**alloc,**max,**need,*work;
int *finish;

//fxn to allot memory to all datastructre.
void allot()
{
int i=0;
printf("Enter the number of process\n");
scanf("%d",&no_of_pro);
printf("Enter the number of resource\n");
scanf("%d",&no_of_res);
inst=(int *)calloc(no_of_res,sizeof(int));	
avail_inst=(int *)calloc(no_of_res,sizeof(int));
alloc=(int **)calloc(no_of_pro,sizeof(int *));
max=(int **)calloc(no_of_pro,sizeof(int *));
need=(int **)calloc(no_of_pro,sizeof(int *));
finish=(int *)calloc(no_of_pro,sizeof(int));
work=(int *)calloc(no_of_res,sizeof(int));
for(i=0;i<no_of_pro;i++)
{
	alloc[i]=(int *)calloc(no_of_res,sizeof(int));
	max[i]=(int *)calloc(no_of_res,sizeof(int));
	need[i]=(int *)calloc(no_of_res,sizeof(int));
}
return;
}

//fxn to intialize all data structures.
void initialize()
{
	int i,j;
	for(i=0;i<no_of_pro;i++)
	{
		finish[i]=0;
	}
	printf("Enter the total number of instances of resources in format A B C ..\n");
	for(i=0;i<no_of_res;i++)
	{
		scanf("%d",&inst[i]);
	}
	printf("Enter the number of available instances of resource in format A B C ..\n");
	for(i=0;i<no_of_res;i++)
	{
		scanf("%d",&avail_inst[i]);
		work[i]=avail_inst[i];
	}
	for(i=0;i<no_of_pro;i++)
	{	
	printf("Enter the number of instances of resource already allocated to Process %d in format A B C ..\n",i);
	for(j=0;j<no_of_res;j++)
		{
		scanf("%d",&alloc[i][j]);
		}
	}
	for(i=0;i<no_of_pro;i++)
	{	
	printf("Enter the maximum number of instances of resource required by Process %d in format A B C ..\n",i);	
	for(j=0;j<no_of_res;j++)
		{
		scanf("%d",&max[i][j]);
		if(max[i][j]>inst[j])
				{
					printf("Process is asking for invalid number of resources. Error.\n");
					exit(0);
				}
		need[i][j]=max[i][j]-alloc[i][j];
		}
	}
}

//fxn to display all datastructures values.
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
{	printf("\n%d\t",i);
	for(j=0;j<no_of_res;j++)
	{
		printf("%c->%d\t",j+65,alloc[i][j]);		
	}
}
printf("\nProcess\tMaximum Resource");
for(i=0;i<no_of_pro;i++)
{	printf("\n%d\t",i);
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
{	printf("\n");
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
	allot();
	initialize();
	display();
	check();
}
