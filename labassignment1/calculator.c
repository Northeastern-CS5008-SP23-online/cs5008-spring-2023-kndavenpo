//Katie Davenport 
//davenport.k@northeastern.edu
#include<stdio.h>

int main()
{
    int num1,num2,answer,choice;
 
    //1 = addition, 2 = subtraction, 3 = mult ... 
   
    printf("Enter your choice\n");
    printf(" 1.addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n");
    scanf("%d",&choice);
    
    printf("Enter num1 and num2 values");
    scanf("%d %d", &num1, &num2);
    
    switch (choice) {
    case 1:
	answer = num1 + num2;
	printf("Addition\nSum= %d\n", answer);
    case 2:
	answer = num1 - num2;
	printf("Subtraction\nDifference = %d\n", answer); 	
    case 3:
	answer = num1 * num2;
	printf("Multiplication\nProduct = %d\n", answer);
    case 4:
	if(num2 == 0) {
	printf("*** You cannot divide by zero ***\n");
	} else { 
	answer = num1 / num2;      // Check no remainder 
	int remainder = num1 % num2; // Check modulo 
	printf("Division\nQuotient = %d\n", answer);
	printf("Remainder = %d:", remainder);
	}
    default:
	printf("Invalid input\n");
	break;
  } 
    return 0;
}
