#include<stdio.h>
#include<string.h>

int main()
{    
     char name1[10];
     char name2[10];
     
     printf(" enter name1 :");
     gets(name1);
      printf(" enter name2 :");
     gets(name2);


    printf(" %s",name1);
    printf(" %s",name2);
         
   int i = 0;
   while( name1[i] != '\0' && name2[i] != '\0')
    { if( name1[i] != name2[i])
       {
       break;
       }
    }

    return 0;
}