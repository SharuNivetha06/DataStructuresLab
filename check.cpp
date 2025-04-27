//menu-driven c++ program to check whether a number is a palindrome, armstrong or perfect number
#include<stdio.h>
#include<cstdlib>
#include<math.h>

//function prototype
int palindrome(int *num);
int armstrong(int *num);
int perfect(int *num);
int pow(int *n,int *c);

//main function
int main(){
    int *num;
    num=(int*)malloc(sizeof(int));
    int *choice;
    choice=(int*)malloc(sizeof(int));
    //displaying menu
    printf("The menu is as follows:\n");
    printf("1.Palindrome\n");
    printf("2.Armstrong Number\n");
    printf("3.Perfect Number\n");
    printf("4.Exit\n\n");
    //prompting user to enter choice
    printf("Enter a choice\n");
    scanf("%d",choice);
   
    do{
    //prompting user to enter the number
    printf("\nEnter a number\n");
    scanf("%d",num);
        switch(*choice){
            case 1:{
                printf("\nChecking if the number is Palindrome\n");
                if(palindrome(num)==1)
                printf("The entered number is a Palindrome \n\n");
                else
                printf("The entered number is not a Palindrome\n\n");

                //displaying menu
                printf("The menu is as follows:\n");
                printf("1.Palindrome\n");
                printf("2.Armstrong Number\n");
                printf("3.Perfect Number\n");
                printf("4.Exit\n\n");
                //prompting user to enter choice
                printf("Enter a choice\n");
                scanf("%d",choice);
                break;
            }
            case 2:{
                printf("\nChecking if the number is an Armstrong Number\n");
                if(armstrong(num)==1)
                printf("The entered number is an Armstrong Number\n\n");
                else
                printf("The entered number is not a Armstrong Number\n\n");

                //displaying menu
                printf("The menu is as follows:\n");
                printf("1.Palindrome\n");
                printf("2.Armstrong Number\n");
                printf("3.Perfect Number\n");
                printf("4.Exit\n\n");
                //prompting user to enter choice
                printf("Enter a choice\n");
                scanf("%d",choice);
                break;

            }
            case 3:{
                printf("\nChecking if the number is a Perfect Number\n");
                 if(perfect(num)==1)
                printf("The entered number is an Perfect Number\n\n");
                else
                printf("The entered number is not a Perfect Number\n\n");

                //displaying menu
                printf("The menu is as follows:\n");
                printf("1.Palindrome\n");
                printf("2.Armstrong Number\n");
                printf("3.Perfect Number\n");
                printf("4.Exit\n\n");
                //prompting user to enter choice
                printf("Enter a choice\n");
                scanf("%d",choice);
                break;

                  
            }
            default:{
        
                printf("\nInvalid choice entered\n\n");

                
                break;
            }
        }
    }while(*choice!=4);

    if(*choice==4){
        printf("\nProgram has been exited\n");
        void exit(void);
    }

    free(num);
    free(choice);

}

//function definition to check if the entered number is a palindrome
int palindrome(int *num){
    int *original;
    int *reversed=0;
    original=(int*)malloc(sizeof(int));
    reversed=(int*)malloc(sizeof(int));
    *original=*num;
    while(*original>0){
        *reversed=(*reversed*10)+(*original%10);
        *original/=10;
    }
if(*reversed==*num)
return 1;
else 
return -1;
free(original);
free(reversed);
}

//power function definition
int pow(int *n,int *c){
    int *temp;
    int *i;
    int j=1;
    temp=&j;
    temp=(int*)malloc(sizeof(int));
    i=(int*)malloc(sizeof(int));
    for(i=&j;*i<(*c);(*i)++)
    {
       *temp=(*temp)*(*n);
}
temp=&j;
return j;
free(i);
free(temp);
}

//function definition to check if the entered number is a armstrong number
int armstrong(int *num){
    int *original;
    int *count=0;
    int *temp;
    original=(int*)malloc(sizeof(int));
    count=(int*)malloc(sizeof(int));
    temp=(int*)malloc(sizeof(int));
    *original=*num;
    while(*original!=0){
        *count+=1;
        *original/=10;
    }
    *original=*num;
    while(*original!=0){
        *temp+=pow((*original%10),(*count));
        *original/=10;
    }
    if(*temp==*num)
    return 1;
    else 
    return -1;
 free(original);
 free(count);
 free(temp);
}

//function definition to check if the entered number is a perfect number
int perfect(int *num){
    int *original;
    int *sum;
    int *i;
    original=(int*)malloc(sizeof(int));
    sum=(int*)malloc(sizeof(int));
    i=(int*)malloc(sizeof(int));
    int j=1;
    *original=*num;
    for(i=&j;*i<(*original);(*i)++){
        if((*i)%2==0)
        *sum+=*i;
    }
    if(*sum==*num)
        return 1;
    else 
       return -1;

    free(original);
    free(sum);
    free(i);   
    
}