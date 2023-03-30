#include<stdio.h>
void main()
{
int memsize=32;
int pagesize,nofpage;
int p[100];
int frameno,offset;
int logadd,phyadd;
int i;
int choice=0;
printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
printf("                                         Paging technique of memory management\n");
printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
printf("\n** memory size = %d **",memsize);
printf("\nEnter page size:");
scanf("%d",&pagesize);

nofpage=memsize/pagesize;

for(i=0;i<nofpage;i++)
{
printf("\nEnter the frame of page%d:",i+1);
scanf("%d",&p[i]);
}

do
{
printf("\nEnter a logical address:");
scanf("%d",&logadd);
frameno=logadd/pagesize;
offset=logadd%pagesize;
phyadd=(p[frameno]*pagesize)+offset;
printf("\n offset value: %d",offset);
printf("\nPhysical address is:%d",phyadd);
printf("\nDo you want to continue(1/0)?:");
scanf("%d",&choice);
}while(choice==1);
}
