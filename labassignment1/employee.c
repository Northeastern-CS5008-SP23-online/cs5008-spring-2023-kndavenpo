//Katie Davenport
//davenport.k@northeastern.edu

/*C Program to read and print the n employee details using structure and dynamic memory allocation*/
#include <stdio.h>
#include <stdlib.h>

/*structure to hold the details of an employee*/
typedef struct employee
{
    int empId;
    char Name[100];
    char Designation[100];
    char Dept[10];

}employee_t;

/* Read the employee details using scanf*/
void readData(int n, employee_t* s)
{
  int i;
  for(i=0; i<n, n++){
    printf("Enter empID, Name, Designation, and Dept: \n");   
    scanf("%d %s %s %s", d->empID, s->Name, s->Designation, s->Dept);
}

/* Function to print the employee details*/
void display(int n, employee_t * s)
{
     
}

/*----------Main Program--------*/
int main()

{
int n;// n is the number of employees 
scanf("%d",&n);// to take the user input 

// dynamic memory allocation - in the heap 
employee_t * s = (employee_t*)malloc(n * sizeof(employee_t)); 

// will return generic pointer to heep   

// null pointer means no memory allocated 
  if(s!=NULL) {
    readData(n,s);
    display(n,s);
    free(s);
  }
}
  
  }
  RETURN 0;
}    

}

