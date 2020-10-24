#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define STACK_CAPACITY 2 

struct Stack { 
    int top; 
    unsigned capacity; 
    int* array; 
}; 

struct Stack* createStack() 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = STACK_CAPACITY; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 

void *reAlloc(void *p, size_t size)
{
    void *newp;
    if(!p){
        newp=malloc(size); 
        if(!newp){
            return NULL;
    }
    }
    else{
        if(sizeof(p) < size){
            newp = malloc(size);
            memcpy(newp, p, sizeof(p));
            free(p);
            }
        else {
            newp = p;
        }
    }
    return newp;
}

void halfResize(struct Stack* stack)
{
    stack->capacity/=2;
    stack->array=(int*)reAlloc(stack->array, stack->capacity * sizeof(int));
    printf("stack reallocated, new length: %d\n", stack->capacity);
}

void checkSize(struct Stack* stack)
{
    if((stack->capacity) /4 >=stack->top)
    halfResize(stack);
}


// deallocates the dynamic memory to prevent memory leak
void deallocStack(struct Stack* stack)
{
    free(stack->array);
    free(stack);
    printf("deallocated\n");
}

int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void resize(struct Stack* stack)
{
    stack->capacity *= 2;
    stack->array = (int*)reAlloc(stack->array,stack->capacity * sizeof(int));
    printf("stack reallocated, new length: %d\n",stack->capacity);
}

void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        resize(stack);
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    checkSize(stack);
    return stack->array[stack->top--]; 
} 
  
int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
} 
  
int main() 
{ 
    struct Stack* stack = createStack(); 
  
    push(stack, 10); 
    push(stack, 20); 
    push(stack, 30);
    push(stack, 40);
    push(stack, 40);
    push(stack, 40);
    push(stack, 40);
    push(stack, 40);
    push(stack, 40);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    checkSize(stack);

    printf("%d popped from stack\n", pop(stack)); 

    deallocStack(stack);
    return 0; 
} 




