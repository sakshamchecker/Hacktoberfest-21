//string functions using pointers
#include<stdio.h>
int length(char[20]);//function declaration
void copy(char [20],char [20]);//function declaration
void reverse(char[20],char [20],int );//function declaration
int substring(char[20],char[20],int);
int main()
{
char s[20],cop[20],rev[20],substr[20],b[20],count,compare;
int l,choice;

printf("enter the string:");
scanf(" %s",s);//function call
l=length(s);//function call
   printf("\nlength is :%d",l);
   copy(s,cop);//calls copy function
   printf("%s",cop);
   reverse(s,rev,l);
   printf("%s",rev);
   count=substring(s,substr,l);
   if (count>0)
    printf("\nthe string is present %d times",count);
   else
    printf("\nstring not present");  
}
int length(char *p)//function declaration
{
int i=0;
while(*(p+i)!='\0')//increments l till the end of string
 i++;
 return i;
 }
void copy(char *s1,char *cop)//points to the starting address of given string and copied string
{
 int i;
 for(i=0;*(s1+i)!='\0';i++)
 *(cop+i)=*(s1+i);//assigns value from main string to copy,character by character
 *(cop+i)='\0';
 printf("\ncopied string: ");
}
void reverse(char *s,char *rev,int l)
{
 int i;
 for(i=0;i<l;i++)
  *(rev+l-i-1)=*(s+i) ;//assigns the end of string to the beginning of reverse
  rev[i]='\0';//to indicate the end of reverse string
  printf("\nreversed string: ");
  }
int substring(char *s,char *substr,int l)
{
int i=0,j,count=0,k;
printf("\n enter the other string:");
scanf("%s",substr);//accepts the substring from user
  for (i=0;i<l;i++)
   {
   if (*(s+i)==*substr)//scans entire string for the starting element of substring
   {k=i+1;
    for(j=1;*(substr+j)!='\0';j++)
     {if (*(s+(k++))!=*(substr+j))
      break;
	 }//end of inner for 
	 if(*(substr+j)=='\0')
	  count++;
   }//end of if
  }// end of outer for
return count;
}
