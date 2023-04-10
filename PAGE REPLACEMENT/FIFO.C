#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()  
{  
char str[20];
    printf("Enter  a reference string:");
    gets(str);
    int len=strlen(str);
    int pageFaults = 0;  
    int frames = 3;  
    int m, n, s, pages,i;
    int incomingStream[20];
for(i=0;i<len;i++){
incomingStream[i]=str[i]-48;
}  
    pages = sizeof(incomingStream)/sizeof(incomingStream[0]);  
    printf(" Incoming \t\t Frame 1 \t\t Frame 2 \t\t Frame 3 ");  
    int temp[ frames ];  
    for(m = 0; m < frames; m++)  
    {  
        temp[m] = -1;  
    }  
    for(m = 0; m < pages; m++)  
    {  
        s = 0;  
        for(n = 0; n < frames; n++)  
        {  
            if(incomingStream[m] == temp[n])  
            {  
                s++;  
                pageFaults--;  
            }  
        }  
        pageFaults++;  
        if((pageFaults <= frames) && (s == 0))  
        {  
            temp[m] = incomingStream[m];  
        }  
        else if(s == 0)  
        {  
            temp[(pageFaults - 1) % frames] = incomingStream[m];  
        }  
        printf("\n");  
        printf("%d\t\t\t",incomingStream[m]);  
        for(n = 0; n < frames; n++)  
        {  
            if(temp[n] != -1)  
                printf(" %d\t\t\t", temp[n]);  
            else  
                printf(" - \t\t\t");  
        }  
    }  
    printf("\nTotal Page Faults:\t%d\n", pageFaults);  
    return 0;  
}  








