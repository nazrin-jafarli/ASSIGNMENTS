#include <stdio.h>
#include <string.h>
#define MAX 100

struct stack{
    int top;
    char stk[MAX];
}s;

void init(){
    s.top = -1; //stack is empty
}

int isEmpty(){   //check whether stack is empty or not
    if(s.top == -1){ 
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){   //check whether stack is full or not
    if(s.top == MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(char item){
    if(isFull()){
            printf("Stack is full");
    }
    else{
        s.top++;              
        s.stk[s.top] = item;        //push the char and increment top
    }
}

void pop(){
    if(isEmpty()){
        printf("Stack is empty");
    }
    else{
        s.top--;      //pop the char and decrement top
    }
}

int match(char opening,char closing)
{
	if(opening == '(' && closing == ')') return 1;
	else if(opening == '{' && closing == '}') return 1;
	else if(opening == '[' && closing == ']') return 1;
	return 0;
}

int main()
{
    char exp[MAX];
    int i;
    int j;

    init();

    printf("Enter an expression:");
    fgets(exp, sizeof(exp), stdin);

    for(i=0;i<strlen(exp);i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
                push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(isEmpty() || !match(s.stk[s.top], exp[i])){
                printf("\nNO unbalanced");
                return 0;
            }
            else{
                pop();
            }
        }
    }

    if(isEmpty()){  
        printf("\nNO unbalanced");
    }else{
        printf("\nYES balanced!");
    }
}
