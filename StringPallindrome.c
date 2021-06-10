#include <stdio.h>
#include<string.h>

#include<stdlib.h>

int StringPallindrome(char *s)
{

   for(char *p = s+(strlen(s) -1) ; s < p ; s++,p--)  
   {
     if(*p != *s)
       return 0;
   }
   return 1;
}


int main(void)
 {
  
  int n;
  char *str;

  printf("\nEnter length of string : ");
  scanf("%d",&n);
  
   str = (char *)malloc(n*sizeof(char));

  printf("\nEnter String : ");
  scanf("%s",str);

  if(StringPallindrome(str))
    printf("\nString is pallindrome\n");
  else
    printf("\nString not pallindrome\n");  
  
  return 0;
}