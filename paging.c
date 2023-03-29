
#include<stdio.h>
#include<conio.h>
int l[16] ,p[10];
 int n, page;
 void binary(int n);
 void phyadd(int n);
void logadd(int key)
{
   
     for(int i=0;i<16;i++)
     {
             if(key==l[i])
             {
                  n=i;    
                  printf("index %d\n",n);      
             }            
             
     }
      phyadd(n);
 }
 void phyadd(int n)
 {
      int off,pageno,temp,add;
      off=n%page;
        printf("offset value %d\n",off);    
      pageno=n/page;
        printf("page number %d\n",pageno);    
      for(int i=0;i<page;i++)
      {
         if(pageno==i)
         {
                 temp=p[i];  
                  printf("temp %d",temp);    
         }      
      }
      add=(temp*page)+off;
      printf("\n%d",add);
  }
int main()
{
    int key;
    printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                         Paging technique of memory management\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Enter value of logical  address for each frame\n");
    for(int i=1;i<=16;i++)
    {
       printf("frame %d:",i);
       scanf("%d",&l[i]);  
    }
    printf("\nEnter page size for each page\n");
    scanf("%d",&page);
    for(int i=1;i<=page;i++)
    {
       printf("page size %d:",i);
       scanf("%d",&p[i]);  
    }
    printf("\nEnter value to find it's physical address\n");
    scanf("%d",&key);
    logadd(key);
    getch();
}

