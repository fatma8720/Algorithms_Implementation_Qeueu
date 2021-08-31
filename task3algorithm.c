#include<stdio.h>
#include<stdlib.h>

//we make substance that build datatype that forming it " linkedlist node"
struct linkedlist_node
{
    int data;   // part is the value
    struct linkedlist_node *next;   // part is the address of the following node 
};

//implement Qeueu with linked list 
    //make frist and last nodes point to null instade make the array iteration equal to zero / -1  
struct linkedlist_node *front = NULL;
struct linkedlist_node  *rear = NULL;

//Function check if Qeueu is full 
int isFull(int size , int en){
    return (size == en);  
}

//Function check if Qeueu is empty 
int isEmpty(){
	//check if there still are in start mode 
    return (front == NULL && rear == NULL);
}
 
 //Function get first item "data" in the front node
int getFront(){
    if(isEmpty()){
        return -1;
    }
    else{
        return front->data;
    }   
}
 //Function get last item "data" in the rear node
int getRear(){
    if(isEmpty()){
        return -1;
    }
    else{
        return rear->data;
    }
}

//Function insert item at the end of qeueu
void enqueue(int item)
{
	//make new node
    struct linkedlist_node  *newNode = malloc(sizeof(struct linkedlist_node));
    //put item in its data part
    newNode->data = item;
    //make its next "pointer" point to null
    newNode->next = NULL;
    //check if the qeueu empty , put first mode by the new node insteade of null  
    if(isEmpty())
        front = rear = newNode;
        // else make front stable and rear point to the new node insteade of null and make rear equal to new node 
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

 // Function to remove item
int dequeue()
{
	//make struct temp to point to front and keep it until return its value then make it free
    struct linkedlist_node *temp;
    // check if the qeueu isn`t empty firstly 
    if(isEmpty()){
        return -1;
    }       
    else
    {
        temp = front;
        front = front->next;
        //if front equal null then start mode so , make rear equal null to be at the first node ,also
        if(front == NULL)
            rear = NULL;
        return temp->data;
       //make the first node empty
       free(temp);
    }

}


int main()
{ 
  int first , second , third , size , n, en , de; 
  
  printf("Enter the size of qeueu \n");
    scanf("%d", &size);
    
    printf("Enter number of items ,then the items you want to put them in qeueu in order \n");
     scanf("%d", &en);
    int i;
    for (i=1;i<=en;i++){
    	scanf("%d", &n);
    	enqueue(n);
	}
    printf("\n\nWe made enqeueu for your %d numbers successfuly \n",en);
    
    if (isFull(size,en))
    printf("\nQeueu is full \n");
    else
	printf("\nQeueu still not full there are %d nodes are free\n", (size-en));
	    
	    
    printf("\nFront element : %d \n", getFront());
    printf("Rear element: %d \n", getRear());

    printf("\n\nEnter number of items you want to pop them from qeueu \n");
     scanf("%d", &de);
       
    for (i=1;i<=de;i++){
    	 printf("\n dequeue %d : %d \n",i, dequeue());
    	 en=en-1;
	}
    printf(" \nWe made deqeueu for your %d of your numbers successfuly , NOW check if qeueu is empty or not \n ",de);
    if (isEmpty())
       printf("\nQeueu is empty \n");
    else
	    printf("\nQeueu is not empty there are %d nodes are full \n", en);
	    

    return 0;
}
