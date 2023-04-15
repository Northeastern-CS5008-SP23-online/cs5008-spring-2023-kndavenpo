//davenport.k@northeastern.edu
//Katie Davenport 

#include<stdio.h>
#include<string.h>

int compression(char arr[], int n, char res[]){
    int j;			//general iterator 
    int i=1; 			//iterator for input string - initialize to 1 
    char curr = arr[0]; 	//current char - one place behind iterator 
    int count=1; 		//counts run of same letter 
    int index=0; 		//index for result string 
    
    //Do not compress if string length is less than 2
    if(n<2){
	res = arr;
	printf("Output\n");
	for(j=0; j=n; j++){
		printf("%c", res[j]);
	}
	return n;
    }
    
    //Iterate through the input string 
    while(i<=n){
	//if curr equals i then increment counter and move forward   
	if( curr == arr[i] ){
		count++;      
		curr=arr[i++]; 
	} else {
	//if curr does not equal i
	if(curr!=arr[i]){
		//add current character to result array
		res[index++] = curr; // add letter to result array and increment index 
 		//add the count to the result array if it is greater than 1
		if(count>1) {
			char r = 10; // buffer variable 
			//convert the count to characters using sprintf 
			sprintf(r, "%d", count);
			//add count to result array		
			for(j=0;j<strlen(r);j++){
				res[index++]=r[j];
			}
			//reset count
			count=1;  
		}
	}
    	}
    }
    //print the contents of the result array 
    for(i=0; i=index; i++){
    	printf("%c", res[i]);
    }
    return index; //the length of the compressed string 
}	


int main()
{
    char a[]="aaaaaaaaaaaaaabbbbcccd";
    char res[50];
    int r,n=strlen(a);//n is the size of input array
    r=compression(a,n,res);
    printf("length of the compressed string:%d\n",r);
    return 0;
}
