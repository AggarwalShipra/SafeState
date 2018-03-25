#include<stdio.h>
int main()
{
int no_of_pro,no_of_res,i,j;
int inst[no_of_res],avail_inst[no_of_res];
int alloc[no_of_pro][no_of_res],max[no_of_pro][no_of_res],need[no_of_pro][no_of_res];
printf("Enter the number of process\n");
scanf("%d",&no_of_pro);
printf("Enter the number of resource\n");
scanf("%d",&no_of_res);
for(i=0;i<no_of_res;i++)
{
	printf("Enter the total number of instances of resource %c\n",i+65);
	scanf("%d",&inst[i]);
}
for(i=0;i<no_of_res;i++)
{
	printf("Enter the number of available instances of resource %c\n",i+65);
	scanf("%d",&avail_inst[i]);
}
for(i=0;i<no_of_pro;i++)
{
	for(j=0;j<no_of_res;j++)
	{
		printf("Enter the number of instances of resource %c already allocated to Process %d \n",j+65,i+1);
		scanf("%d",&alloc[i][j]);
	}
}
for(i=0;i<no_of_pro;i++)
{
	for(j=0;j<no_of_res;j++)
	{
		printf("Enter the maximum number of instances of resource %c required by Process %d \n",j+65,i+1);
		scanf("%d",&max[i][j]);
		need[i][j]=max[i][j]-alloc[i][j];
	}
}
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
{	printf("\n%d\t",i);
	for(j=0;j<no_of_res;j++)
	{
		printf("%c->%d\t",j+65,need[i][j]);		
	}
}
}
