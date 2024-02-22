#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *ptr=NULL;
    char string[34]="wtf!!!";
    ptr=fopen("myfile.txt","w");
    fprintf(ptr,"%s",string);
    


return 0;
}