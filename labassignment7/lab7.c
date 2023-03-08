/* Katie Davenport */
/* davenport.k@northeastern.edu*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    char name[20];
    int age;
    char address[100];
    int reg;
    int priority;
    struct node *next;
}node_t;

/* Inserting patients in the queue based on priority*/
node_t *insert(struct node *front)
{
    node_t *p,*temp;
    //char name[20],address[100];
    temp=(node_t*)malloc(sizeof(node_t));
    printf("Enter patient Name:");
    //fgets(temp->name, strlen(temp->name), stdin); // Use to allow for white spaces
    scanf("%s", temp->name);
    printf("Enter the patient's age:");
    scanf("%d",&(temp->age));
    printf("Enter the address:");
    //fgets(temp->address, strlen(temp->address), stdin); // Use to allow for white spaces
    scanf("%s",temp->address);
    printf("Enter the reg no:");
    scanf("%d",&(temp->reg));
    printf("Enter the priority:");
    scanf("%d",&(temp->priority));
    int pri=temp->priority;

 // Case: queue is empty or new priority is highest
 // Add temp to the front
 if(front == NULL || pri > front->priority){
	temp->next = front; 
	front = temp;
	return front; 
} 
 // Else: Loop through the queue so long as the priority of the next node is greater than 
 // the priority of the temp and we have not reached the end of the queue
 
  p = front; 
  while(p->next != NULL && p->next->priority >= pri){
	p = p->next;
	}
 	
	temp->next = p->next;
 	p->next = temp; 
 	return front; 

}
 
/* Function to free the nodes*/
void freenode(node_t *temp)
{
     if(temp!=NULL){
     freenode(temp->next);
     free(temp);
     }
}


/* Delete the node which is present at the front*/
node_t *delete(struct node *front)
{
node_t *temp = front; 

if(front == NULL) {
	return front;
} if (front->next == NULL){
	free(front);
	front = NULL;  
	return front; 
} else { 	
	temp = front->next;
	front->next = NULL;
	free(front);
	front = temp;
	return front;            
}

}

/* To display the patients records */
void display(node_t *front)
{
    node_t *temp=front;
    if(front==NULL)
    printf("\nTHERE IS NO PATIENT");
    else
    {
        printf("\nPriority wise appointments are:\n");
        while(temp!=NULL)
        {
        printf("The name of patient is:%s\n",temp->name);
        printf("The age of patient is:%d\n",temp->age);
        printf("The address of patient is : %s\n",temp->address);
        printf("---------------------------------------------------\n");
        temp=temp->next;
        }
    }
    return;
}


/*-----------------Main program---------------------------*/
int main()
{
    node_t *front=NULL;
    int option;
    do{
        printf("\t\t\t Hospital emergency room system\n");
        printf("\t\t\t1.ADD A PATIENT\n");
        printf("\t\t\t2.DELETE A RECORD\n");
        printf("\t\t\t3.PATIENTS WAITING IN THE QUEUE\n");
        printf("\t\t\tEnter your choice:");
        scanf("%d",&option);
            switch(option)
            {
            /*Select 1 to insert elements in the priority queue*/
            case 1:
            front= insert(front);
            break;
             /* Select 2 to delete the elements at the front of priority queue*/
            case 2:
            front= delete(front);
            break;
            /* Select 3 To display the elements present in the priority queue*/
            case 3:
            display(front);
            break;
            /* Select 4 to terminate*/
            case 4:
            printf("The program is being terminated\n");
            break;
            }
    }
    while(option!=4);
        freenode(front);
return 0;
}
