#include<stdio.h>
void main()
{   
    int A,S,M,D,a,b,c;
    char choice;
    printf("Calculator-");
    
    printf("Enter A for Addition: \n");
    printf("Enter S for subtraction: \n");
    printf("Enter M for Multiplication:\n");
    printf("Enter D for Division: \n");
    printf("Enter %% for Modulo Division: \n");
    printf("Enter your choice:\n");
    scanf("%c",&choice);
    
    

    switch (choice) 
    {
        
        case 'A' :
        printf("Enter two numbers \n");
        scanf("%d %d",&a,&b);
        c=a+b;
        printf("Addition of %d and %d is %d",a,b,c);
        break;
        
        case'S' :
        printf("Enter two numbers \n");
        scanf("%d %d",&a,&b);
        c=a-b;
        printf("Subtraction of %d and %d is %d",a,b,c);
        break;

        case'M' :
        printf("Enter two numbers \n");
        scanf("%d %d",&a,&b);
        c=a*b;
        printf("Multiplication of %d and %d is %d",a,b,c);
        break;

        case'D' :
        printf("Enter two numbers \n");
        scanf("%d %d",&a,&b);
        c=a/b;
        printf("Division of %d and %d is %d",a,b,c);
        break;

        case '%' :
        printf("Enter two numbers");
        scanf("%d %d",&a,&b);
        c=a%b;
        printf("Modulo division of %d and %d is %d",a,b,c);
        break;

        default:
        printf("Invalid choice ");
    }
    
     
}