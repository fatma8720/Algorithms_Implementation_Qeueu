#include <stdio.h>
#include <malloc.h>
int stack[100], qeueu[100];
int top_stack = -1, top_qeueu = -1;
int count = 0;
const int MAX_SIZE = 6;
int front = 0;
int rear = 5;


int peek(int stack[])
{
  if(top_stack == -1){
    return -1;
      }
    else
    return (stack[top_stack]);
    
}
int isFull(){
    return ( count == MAX_SIZE);  
}
 
int isEmpty(){
    return ( count== 0);
}
 
int getFront(){
    if(isEmpty()){
        return -1;
    }
    else{
        return qeueu[front];
    }   
}
 
int getRear(){
    if(isEmpty()){
        return -1;
    }
    else{
        return peek (stack);
    }
}
  
//Function to push the element on to the stack
void push_stack(int data)
{
    stack[++top_stack] = data;
}
 
//Function to pop the element from the stack
int pop_stack()
{
    return(stack[top_stack--]);
}
 
//Function to push an element on to pre_qeueu
void push_qeueu(int data)
{
   qeueu[++top_qeueu] = data;
}
 
//Function to pop an element on to pre_qeueu
 
int pop_qeueu()
{
    return(qeueu[top_qeueu--]);
}
 
//Function to add an element into the queue using stack
void enqueue(int item)
{
    push_stack(item);
    count++;
}
 
//Function to delete an element from the queue using stack
 
void dequeue()
{
    int i;
 
    for (i = 0;i <= count;i++)
    {
        push_qeueu(pop_stack());
    }
    pop_qeueu();
    count--;
    for (i = 0;i <= count;i++)
    {
        push_stack(pop_qeueu());
    }
}
 
//Function to display the elements in the stack
 
void display()
{
    int i;
 
    for (i = 0;i <= top_stack;i++)
    {
        printf("Deqeueu %d :  %d \n", i ,  stack[i]);
    }
}
int main()
{
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(7);
    display();
    dequeue();
    dequeue();
    dequeue();


    printf("\nFront element is  %d \n", getFront());
    printf("Rear element is %d \n", getRear());
}
