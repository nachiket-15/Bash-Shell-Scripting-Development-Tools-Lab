#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int top;
    int size;
    char*array;
};

struct stack*createnode(int size){
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->top=-1;
    sp->size=size;
    sp->array=(char*)malloc(sizeof(char)*size);
}

void push(struct stack*ptr,char ch){
    if(ptr->top==ptr->size-1){
        printf("Stack overflow!\n");
    }
    else{
        ptr->top++;
        ptr->array[ptr->top]=ch;
    }
}

char pop(struct stack*ptr){
    if(ptr->top==-1){
        printf("Stack underflow\n");
    }
    else{
        char value=ptr->array[ptr->top];
        ptr->top--;
        return value;
    }
}

void reverse(char ch[]){
    int n=strlen(ch);
    struct stack*sp=createnode(n);

    for(int i=0;i<n;i++){
        push(sp,ch[i]);
    }

    for(int i=0;i<n;i++){
        ch[i]=pop(sp);
    }

}

int main() {
    printf("Enter a string :\n");//INPUT A STRING FROM USER
    char ch[25];//INPUT STRING WILL BE STORED INTO CHARACTER ARRAY

    char store[25];//THIS CHAR ARRAY WILL STORE INPUT VALUE
    scanf("%s",ch);

    strcpy(store,ch);//STRCPY(DESTINATION,SOURCE) ->COPIES SOURCE STRING INTO DESTINATION

    reverse(ch);//PUTS STRING INTO STACK AND AGAIN POPS IT FROM STACK THEN STORES INTO CHAR ARRAY
    printf("Reversed string is: %s\n",ch);
    
    int result=strcmp(store,ch);//STRCMP(STR1,STR2)->COMPARES 2 STRINGS ->RETURN 0 IF TWO STRINGS ARE EQUAL
    
    if(result==0){
        printf("Given string is a palindrome\n");
    }
    else{
        printf("Given string is not a palindrome\n");
    }
    return 0;
}
