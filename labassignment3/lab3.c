//Katie Davenportd
//davenport.k@northeastern.edu
//To perform insertion sort of integers stored in a file and display the output and store it in another file.
#include <stdio.h>
#include<stdlib.h>

int main()
{   //create text file of integers 
    FILE *fp, *fp1;
    int arr[10],temp;
    int count=0,i,j;/*count will have the total number of elements in the array*/
    
    /*read the file*/
    fp=fopen("Input.txt","r"); 
    if(fp==NULL){
    
    //if file returns NULL then can't open the file
    printf("\n Cannot open the file \n");
    exit(0);
    }
    
    //add the integers to an array and print out 
    printf("The contents of the file are:\n");
    while(fscanf(fp,"%d",&arr[count])==1){
        printf("%d\n",arr[count]);
        count++;
    }

    //helper function to swap integers
    void swap(int* a, int* b){
	temp = *a;
	*a = *b;
	*b = temp;
    }
	    
    //Insertion Sort
    for (i=1; i<10; i++) {	
	for (j=i-1; j>=0; j--){
	if (arr[j+1] <= arr[j]){
		swap(&arr[j+1], &arr[j]);
		}
	}	
    }

    // Display the ouput 
    printf("The contents of the sorted array are:\n");
	for (i=0; i<10; i++){
	printf("%d\n",arr[i]);
	} 	
	
    //Put the contents of the sorted array into a file    
    printf("The output is:\n");
    fp1=fopen("sorted.txt","w");
    for(i=0; i<count; i++){
	fprintf(fp1,"%d\n",arr[i]);
    }  

fclose(fp);
fclose(fp1);
return 0;
}
