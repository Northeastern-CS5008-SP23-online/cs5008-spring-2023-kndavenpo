// name: Katie Davenport
// email: davenport.k@northeastern.edu

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LIMIT 200
#define RAND_RANGE 95  // 95 printing characters x20-x7E

// return random character
char randChar() {
  // 0 -> x20 -> ' '
  // 1 -> x21 -> '!'
  // ,,,
  // 94 -> x7E -> '~'
  // see https://ascii.cl
  return ((char)((rand() % RAND_RANGE)+0x20));
}

// return the value of a char unless it is lower case
// in which case return the upper case of the character
char upperChar(char c){
  if ((c<'a') || (c>'z')){
    return(c);
  } else {
    // if you forget the displacement of lower to upper case
    // just let the computer figure it out for you!
    return(c-('a'-'A'));
  }
}

// pick pivot and then sort small and big parts 
void quicky(char* data, int left, int right) {

// declare variables 
int i, j; 	// loop variables for the left and right pivot  
int pivot; 	// pivot point
char temp;	// temp variable used to swap 

// Base case: an array with 1 element -> return original array 

// Recursive case: an array with more than 1 element (left less than right)
if(left < right){

pivot = left; 	// choose a pivot - first element is random since unsorted 
i = left;	// left pointer
j = right; 	// right pointer 

// Partition step
// While left pointer is less than right pointer   
while(i < j){ 
	// While left pointer value <= pivot value move pointer right 
	while(upperChar(data[i]) <= upperChar(data[pivot]) && i < right)
		i++;
	
	// While right pointer value > pivot value decrement right pointer
	while(upperChar(data[j]) > upperChar(data[pivot]))
		j--;
	
	if(i < j){
		temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}
}

// Swap values 
temp = data[pivot];
data[pivot] = data[j];
data[j] = temp; 

// repeat partition step on sub-arrays until base case it reached (sorted)
quicky(data, left, j-1); 	// sub-array of elements less than pivot
quicky(data, j+1, right); 	// sub-array of elements greater than pivot 

}
  return;
}



int main(){

  char source[LIMIT]; // array to hold input data values

  int i;             // loop variable
  int j;             // loop variable


  //seed random numbers
  srand((unsigned)time(NULL));

  //initialize source array with random character
  for (i=0; i<LIMIT; i++) {
    source[i] = randChar();
  }

  //print out source array in rows of 20 elments
  printf("Source array:\n");
  for (i=0; i < ((LIMIT/20)+1); i++) {
    for (j=0; j<20; j++) {
      if (i*20+j < LIMIT) {
	printf("%c ",source[i*20+j]);
      }
    }
    printf("\n");
  }
  printf("\n");

  // do the sorting
  quicky(source, 0, LIMIT-1);

  
  //print out sorted array in rows of 10
  printf("Destination array:\n");
  for (i=0; i < ((LIMIT/10)+1); i++) {
    for (j=0; j<10; j++) {
      if (i*10+j < LIMIT) {
	printf("%c ",source[i*10+j]);
      }
    }
    printf("\n");
  }
  printf("\n");
  
  return 0;
}
