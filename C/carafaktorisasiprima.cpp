#include <stdio.h>

int main()
{
    
    int number,div;    
    printf("Enter a number to know its prime factor: ");    
    scanf("%d",&number);
    
    printf("\nThe prime factors of %d are: \n\n",number);
    
    div = 2;
    
    while(number!=0){
        if(number%div!=0)
            div = div + 1;
        else {
            number = number / div;
            printf("%d ",div);
            if(number==1)
                break;
        }
    }
    return 0;
}
