#include<stdio.h>
#include<conio.h>
int noofprocess,noofhole;
int holeold[10],holesize[10],processsize[10],holenumber[10];
void oldtonew();
void firstfit(){
int i,j;
printf("\n                                                        First Fit");
 printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
printf("\n   Process   Psize   Allocated hole   Remaining hole size");

for(i=1;i<=noofprocess;i++)
    {
int c=0;
for(j=1;j<=noofhole;j++)
        {
if(processsize[i]<=holesize[j])
            {
printf("\n     P%d       %d          H%d",i,processsize[i],j);
c=1;
holesize[j]-=processsize[i];
printf("              %d KB",holesize[j]);
break;
}
}
if(c==0){
printf("\nP%d\t%d\tNot allocated",i,processsize[i]);
}
}
}
void bestfit(){
int i,j;
int temp;
for(i=1;i<=noofhole;i++)
    {
for(j=i+1;j<=noofhole;j++)
        {
if(holesize[i]>holesize[j])
            {
temp=holesize[i];
holesize[i]=holesize[j];
holesize[j]=temp;
temp=holenumber[i];
holenumber[i]=holenumber[j];
holenumber[j]=temp;
}
}
}
printf("\n                                                         Best Fit");
 printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
printf("\n   Process   Psize   Allocated hole   Remaining hole size");

for(i=1;i<=noofprocess;i++){
int c=0;
for(j=1;j<=noofhole;j++){
if(processsize[i]<=holesize[j]){
printf("\n     P%d       %d          H%d",i,processsize[i],j);
c=1;
holesize[j]-=processsize[i];
printf("              %d KB",holesize[j]);
break;
}
}
if(c==0)
printf("\nP%d\t%d\tNot allocated",i,processsize[i]);
}
}
void worstfit(){
int i,j;
int temp;
for(i=1;i<=noofhole;i++)
    {
for(j=i+1;j<=noofhole;j++)
        {
if(holesize[i]<holesize[j])
            {
temp=holesize[i];
holesize[i]=holesize[j];
holesize[j]=temp;
temp=holenumber[i];
holenumber[i]=holenumber[j];
holenumber[j]=temp;
}
}
}
printf("\n                                                      Worst Fit");
 printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
printf("\n   Process   Psize   Allocated hole   Remaining hole size");

for(i=1;i<=noofprocess;i++){
int c=0;
for(j=1;j<=noofhole;j++){
if(processsize[i]<=holesize[j]){
printf("\n     P%d       %d          H%d",i,processsize[i],j);
c=1;
holesize[j]-=processsize[i];
printf("              %d KB",holesize[j]);
break;
}
}
if(c==0)
printf("\nP%d\t%d\tNot allocated",i,processsize[i]);
}
}
void oldtonew()
{
     for(int i=1;i<=noofhole;i++)
     {    
          holesize[i]=holeold[i];
     }
}
int main(){
int i,j;
int ch;

printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
printf("                                                  CONTIGUOUS MEMORY ALLOCATION");
printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
printf("Enter the number of the memory holes: ");
scanf("%d",&noofhole);
printf("Enter the eack block hole size: \n");
for(i=1;i<=noofhole;i++){
printf(" Size of the Hole %d: ",i);
scanf("%d",&holesize[i]);
holenumber[i]=i;
holeold[i]=holesize[i];
}
printf("\n--------------------------------------------------------------------------------------------------------------------------\n");

printf("Enter the number of process: ");
scanf("%d",&noofprocess);
printf("Enter the size of each process:\n");
for(i=1;i<=noofprocess;i++){
printf("Size of Process %d: ",i);
scanf("%d",&processsize[i]);
}
int n=1;
while(n==1)
    {
   printf("\n--------------------------------------------------------------------------------------------------------------------------\n");

printf("\nMenu for allocation:\n");
printf("\n1.First Fit \n2.Best Fit \n3.Worst Fit");
printf("\nEnter your choice: ");
scanf("%d",&ch);
 printf("\n--------------------------------------------------------------------------------------------------------------------------");
switch(ch)
    {
case 1:
firstfit();
break;
case 2:
             oldtonew();
bestfit();
break;
case 3:
             oldtonew();
             worstfit();
             break;
default:
printf("Wrong choice!!");
}
}

getch();
return 0;
}

