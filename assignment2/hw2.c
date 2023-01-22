// name: Katie Davenport
// email: davenport.k@northeastern.edu

#include <stdio.h>   // stardard input/output library
#include <stdbool.h> // standard boolean library: bool, true, false

#define MAXSIZE 100

int stack[MAXSIZE];

// s is an int array, t is top index
bool isEmpty (int* s, int t) {
  // returns true if t = -1
  if (t < 0) {
  return true;
  } else {
  return false;
  }
}

// s is an int array, t is top index
bool isFull (int* s, int t) {
  // returns true if no more room in the stack
  if (t >= MAXSIZE-1) {
  return true;
  } else {
  return false;
  }
}

// Update top(t) so it is passed by reference
// S is an array so inside the push function you will access with s[i]
// tp is a pointer to int so access it with *tp
void push(int v, int* s, int* tp) {
  // put v onto the top of the stack s unless it is already full
  if (s != NULL) {
  if (!isFull(s,*tp)) {
                (*tp)++;
                s[*tp] = v;}
  else {printf("*** attempt to push %d onto full stack ***\n", v);}
  } else {
  printf("The array is null");
  }
}

// Update top(t) so it is passed by reference
int pop (int* s, int* tp) {
  // return the top entry in the stack unless stack is empty
  // update s and *tp -- requires top to be passed by reference!
  if (s != NULL) {
  int returnval = 0;
  if (!isEmpty(s, *tp)) {
        returnval = s[*tp];
        (*tp)--;
  } else {
        printf("*** attempt to pop empty stack ***\n");
  }
  return returnval;
  } else {
  printf("The array is null");
  return 0;
  }
}

int main () {
  //2 stack arrays and 2 top ints
  int stack1[MAXSIZE]; // array in which stack will live
  int top1 = -1;       // top valid location in stack, -1 == empty
  int stack2[MAXSIZE]; // array in which stack will live
  int top2 = -1;       // top valid location in stack, -1 == empty

  printf("pushing: 1, 2, 3, 4, 5 onto first stack\n");
  printf("pushing: 100, 200, 300, 400, 500 onto second stack\n\n");
  push(1, stack1, &top1);
  push(2, stack1, &top1);
  push(3, stack1, &top1);
  push(4, stack1, &top1);
  push(5, stack1, &top1);
  push(100, stack2, &top2);
  push(200, stack2, &top2);
  push(300, stack2, &top2);
  push(400, stack2, &top2);
  push(500, stack2, &top2);

  printf("popping alternating stacks:\n");
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  return 0;
}
