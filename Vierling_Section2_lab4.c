//C calculator
//Matthew Vierling
//9/17/2015
//Lab #4
//section 2

#include<stdio.h>

/********************************
function prototypes
*********************************/

float addTwoNumbers(float, float);
float subtractTwoNumbers(float, float);
float multiplyTwoNumbers(float, float);
float divideTwoNumbers(float, float);
int modulusTwoNumbers(int, int);
int testForPrime (int);
int factorsOfANumber(int);
float power(float, int);
int showPrimesInInterval (int, int);

//********************************

main(){
	
	int iSelection = -1;
	
	printf("Welcome to Matt's C Calculator");
	
	do{
		
	float fn1=0.0;
	float fn2=0.0;
	int in1=0;
	int in2=0;
		
	printf("\n\nCalculator Menu:");
	printf("\n 1. Add\n 2. Subtract\n 3. Multiply\n");
	printf(" 4. Divide\n 5. Modulus (Integers Only)\n 6. Test for prime number (Positive Integers Only)\n");
	printf(" 7. Factors of a number (Integers Only)\n 8. Power \n 9. Show all primes for an interval\n\n");
	printf(" Enter your selection here: "); 
	scanf("%d", &iSelection);//end of menu options
	
	switch (iSelection){
		
		case 1:
			printf("\n Enter the first number here: ");
			scanf("%f", &fn1);
			printf("\n Enter the number you want to add to %.2f here: ", fn1);
			scanf("%f", &fn2);
			printf("\nThe sum is %.2f\n\n", addTwoNumbers(fn1, fn2));
			break;
			
		case 2:
			
			printf("\n Enter the first number here: ");
			scanf("%f", &fn1);
			printf("\n Enter the number you want to subtract from %.2f here:  ", fn1);
			scanf("%f", &fn2);
			printf("\n The difference is %.2f\n\n", subtractTwoNumbers(fn1, fn2));
			break;
			
		case 3:
			
			printf("\n Enter the first number here: ");
			scanf("%f", &fn1);
			printf("\n Enter the number you want to multiply %.2f by here:  ", fn1);
			scanf("%f", &fn2);
			printf("\n The product is %.\n\n", multiplyTwoNumbers(fn1, fn2));
			break;
			
		case 4:
			
			printf("\n Enter the first number here: ");
			scanf("%f", &fn1);
			printf("\n Enter the number you want to divide %.2f by here:  ", fn1);
			scanf("%f", &fn2);
			printf("\n The quotent is ");
			divideTwoNumbers(fn1, fn2);
			break;
			
		case 5:
			
			printf("\n Enter the first number here: ");
			scanf("%d", &in1);
			printf("\n Enter the second number here: ");
			scanf("%d", &in2);
			modulusTwoNumbers (in1, in2);
			break;
			
		case 6:
			
			printf("\nEnter the number you would like to check for prime: ");
			scanf("%d", &in1);
			testForPrime(in1);
			break;
			
		case 7:
			
			printf("\n Enter the number you want to factor here: ");
			scanf("%d", &in1);
			factorsOfANumber(in1);
			break;
			
		case 8:
			
			printf("\n Enter the Base of the problem here: ");
			scanf("%f", &fn1);
			printf("\n Enter the power you want to raise %.2f to: ", fn1);
			scanf("%d", &in1);
			printf("\n The answer is %.2f\n\n", power(fn1, in1));
			
			break;
			
		case 9:
			
			printf("\n Enter the fist number of the interval here: ");
			scanf("%d", &in1);
			printf("\n Enter the second number of the interval here: ");
			scanf("%d", &in2);
			
			if (in1<in2){
				showPrimesInInterval (in1, in2);
				break;
			}
				
			else {
				printf("\n The first number in the interval must be smaller than the second number.");
				printf("\n Please try again.");
				break;
			}
			
		case 0:
			
			printf("\n\n Gooddbye!\n\n\n");
			break;
			
		default:
			
			break;
			
	}//end switch
	
	
	system("pause");

	
}while (iSelection !=0);

return 0;

}//main

/********************************************
Function Definitions
*********************************************/

float addTwoNumbers (float n1, float n2){ 
	
	return n1+n2;
	
}//add two numbers 1

float subtractTwoNumbers (float n1, float n2){
	
	return n1-n2;
	
}//subtract two numbers 2

float multiplyTwoNumbers (float n1, float n2){
	
	return n1*n2;
	
}//multiply two numbers 3

float divideTwoNumbers(float n1, float n2){
	
	if (n2==0){
		printf("Undefined.\n\n");
	}
	else{
		printf("%.3f", n1/n2);
	} 
	
}//divide two numbers 4

int modulusTwoNumbers (int n1, int n2){
	
	if (n2==0){
		printf("\nYou cannot find the modulus of a %d and 0\n\n", n1);
		
	}
	else{
		printf("\nThe answer is %d\n\n", n1%n2);
	}

}//modulus 5

int testForPrime (int n1){
	
	int x=2;
	int isPrime=0;
	
	while (x<n1){
		if (n1%x==0){
			
			isPrime=1;
			break;
		}
		else
		
		x++;
		 
	}

	x=2;
	
	if (isPrime==1){

		printf("\n%d is not prime.\n\n", n1);
		printf("Factors are:\n\n");
		
		while (x<n1){

			if (n1%x==0)
				printf("%d\n", x);
				
			x++;
		}//end of factors for nonPrime
		
	}//end if is prime
	else{
	
		printf("\n%d is prime.\n\n", n1);
		
	}
	
	printf("\n\n");
		
}//check for prime 6

int factorsOfANumber (int n1){
	
	int x=1;
	
	printf("\nFactors of %d are\n", n1);
	
	while (x<=n1){
		
		if(n1%x==0)
		
			printf("\n %d", x);
			
		x++;
		
	}//while
	
	printf("\n\n\n");
		
}//factor of a number 7

float power (float n1, int n2){
	
int x=1;
double fx=1;

while (x<=n2){
	
	fx*=n1;
	x++;
}

return fx;

}//power 8

int showPrimesInInterval (int n1, int n2){
	
	
	int notPrime=0;
	int numberOfPrimes=0;
	int x=n1;
	int y=2;
	
	while (x<=n2){
		
		while (y<x){
			if (x%y==0){
				notPrime=1;
				break;
			}
		
			y++;
			
		}//end while
		
		if (notPrime==0){
				numberOfPrimes++;
		}
		
		notPrime=0;
		y=2;
		x++;
		
	}//end loop for number of primes
	
	int primeArray [numberOfPrimes];
	
	printf("\nThere are %d prime(s) in interval [%d, %d]. They are:\n\n", numberOfPrimes, n1, n2);
	
	x=n1;//redefining variable x
	int z=0;
	
	while (x<=n2){
		
		while (y<x){
			if (x%y==0){
				notPrime=1;
				break;
			}
			
			y++;
			
		}
		
		if (notPrime==0){
			primeArray[z]=x;
			z++;
		}//assigning prime numbers to primeArray
		
		notPrime=0;
		y=2;
		x++;
	}
	
	z=0;
	
	while (z<numberOfPrimes){
		printf("%d\n", primeArray[z]);
		z++;
	}//printing all primes in primeArry
	
}//primes of an interval 9





