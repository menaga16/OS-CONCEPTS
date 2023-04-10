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
        printf("off %d\n",off);    
      pageno=n/page;
        printf("pageno %d\n",pageno);    
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
    printf("enter value of logical  address\n");
    for(int i=0;i<16;i++)
    {
       printf(" logical address %d: ",i);
       scanf("%d",&l[i]);  
    }
    printf("\nenter pagesize\n");
    scanf("%d",&page);
    for(int i=0;i<page;i++)
    {
       printf("size of page %d: ",i);
       scanf("%d",&p[i]);  
    }
    printf("\nenter value to find physical address\n");
    scanf("%d",&key);
    logadd(key);
    getch();
}
