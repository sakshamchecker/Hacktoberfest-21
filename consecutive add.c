#include<stdio.h>
main()
{
    int i, first, second,sum=0,choice;
    printf("Enter two numbers\n");
    scanf("%d%d",&first,&second);
    sum+=first*second;
    first=second;
    printf("%d",sum);
    
    /*for(i=1;i<=12;i++)
    {
        printf("Enter the next number\n");
        scanf("%d",&second);
        pro=first*second;
        sum+=pro;
        second=first;
    }*/
    printf("Do you want to continue?\n1:Yes\nOther:No\n");
    scanf("%d",&choice);
    while(choice==1)
    {
    	printf("Enter the next number\n");
        scanf("%d",&second);
        sum+=first*second;
        first=second;
        printf("%d",sum);
        printf("Do you want to continue?\n1:Yes\nOther:No\n");
    	scanf("%d",&choice);
	}
    printf("Sum of the numbers: %d",sum);

}
