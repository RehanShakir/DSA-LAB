#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 100

//char Expression[SIZE] = {'[', '{', '[', '2', '-', '{', '4', '+', '(', '3', '-', '5', ')', '*', '(', '3', '+', '4', ')',
//                  '*', '3', '}', ']'}; //24
//char Expression[SIZE] = {'[','4','-','{','2','+','(','3','*','5',')','-','6','}',']'};  //17
//char Expression[SIZE] ={'{','2','+','(','3','*','5',')','-','6','}'}; //11
//char Expression[SIZE] ={'{','2','-','(','2','+','4',')','-','5','}','-' }; //12
struct stack{
   char Expression[SIZE];
   int number[SIZE];
   int ExpressionTop = 0,numberTop=0;
}stack,stackPostfix;

struct Exp{
    char Expression[SIZE];
    int counter=0;
}exp,postfixExp;


bool checkingValidity();
bool postFixConversion();
int precedence(char ch);
bool push(char ch,int status);
char pop(int status);
bool isEmpty();
bool isFull();
int number(char ch);
int postfixEvaluation(int counter,char Expression[]);

bool checkingValidity(){

    for(int i=0; i<exp.counter; i++){
         if (exp.Expression[i] == '[' || exp.Expression[i] == '{' || exp.Expression[i] == '('){
             push(exp.Expression[i],1);
             //stack.Expression[stack.ExpressionTop++] = exp.Expression[i];
             continue;
         }
         if (exp.Expression[i] == ']' && /*stack.Expression[--stack.ExpressionTop]*/pop(1) != '['){
             return false;
         }else if (exp.Expression[i] == '}' && /*stack.Expression[--stack.ExpressionTop]*/pop(1) != '{'){
             return false;
         }else if (exp.Expression[i] == ')' && /*stack.Expression[--stack.ExpressionTop]*/pop(1) != '('){
             return false;
         }
         if(exp.Expression[i] == '+' && exp.Expression[i+1] == '+' || exp.Expression[i] == '-' && exp.Expression[i+1] == '-' ||
                 exp.Expression[i] == '*' && exp.Expression[i+1] == '*'){
             return false;
         }
    }
    if(stack.ExpressionTop > 0){
        return false;
    }
    return true;
}
bool postFixConversion(){
   // printf("\nIN POST");
   if (checkingValidity() == false){
       printf("\nGiven Expression is False\n");
       return false;
   }
    for(int i=0; i<exp.counter; i++){
        if(exp.Expression[i] == '(' || exp.Expression[i] == '{' || exp.Expression[i] == '['){
            push(exp.Expression[i],2);
            //stackPostfix.Expression[stackPostfix.numberTop++] = exp.Expression[i];
            continue;
        }
        if(exp.Expression[i] >= '0' && exp.Expression[i] <= '9'){
            postfixExp.Expression[postfixExp.counter++] = exp.Expression[i];
            continue;
        }
        stackPostfix.numberTop = stackPostfix.numberTop - 1;
        if(exp.Expression[i] == ')' || exp.Expression[i] == '}' || exp.Expression[i] == ']'){
            while(stackPostfix.Expression[stackPostfix.numberTop] != '('  && stackPostfix.Expression[stackPostfix.numberTop] != '{' && stackPostfix.Expression[stackPostfix.numberTop] != '['){
                postfixExp.Expression[postfixExp.counter++] = pop(2);
                //postfixExp.Expression[postfixExp.counter++] = stackPostfix.Expression[stackPostfix.numberTop--];
            }
            continue;
        }
        if (exp.Expression[i] == '+' || exp.Expression[i] == '-' || exp.Expression[i] == '*' || exp.Expression[i] == '/'){
            while (precedence(stackPostfix.Expression[stackPostfix.numberTop]) >= precedence(exp.Expression[i])){
                postfixExp.Expression[postfixExp.counter++] = pop(2);
                //postfixExp.Expression[postfixExp.counter++] = stackPostfix.Expression[stackPostfix.numberTop--];
            }
            stackPostfix.numberTop++;
            push(exp.Expression[i],2);
            //stackPostfix.Expression[stackPostfix.numberTop++] = exp.Expression[i];
        }
    }
    return true;

}
int postfixEvaluation(){
    int num1,num2,rst;
    if(postFixConversion() == false){
        printf("\nNot Converted into postfix\n");
        return false;
    }
    for(int i=0; i<postfixExp.counter; i++){
        if(postfixExp.Expression[i] >= '0' && postfixExp.Expression[i] <= '9'){
            push(postfixExp.Expression[i],3);
            //stack.number[stack.numberTop++] = number(postfixExp.Expression[i]);
        }
        else if(postfixExp.Expression[i]>'9'){
            push(postfixExp.Expression[i],4);
        }else{
            num2 = pop(3);// stack.number[--stack.numberTop];
            num1 = pop(3); //stack.number[--stack.numberTop];

            if (postfixExp.Expression[i] == '-'){
                stack.number[stack.numberTop++] = num1 - num2;


            }
            if (postfixExp.Expression[i] == '+'){
                stack.number[stack.numberTop++] = num1 + num2;

            }
            if (postfixExp.Expression[i] == '*'){
                stack.number[stack.numberTop++] = num1 * num2;

            }
            if (postfixExp.Expression[i] == '/'){
                stack.number[stack.numberTop++] = num1 / num2;

            }
        }
    }
    return (pop(3));
}
bool push(char exp,int status){    //Inserting (Pushing) values in Stack
    if(isFull()){
        printf("\nStack is FULL!");
       return false;
    }
    if(status == 1){                    //Expression Stack (For checking Validity of Expression)
        stack.Expression[stack.ExpressionTop++] = exp;
    } else if(status == 2){
        stackPostfix.Expression[stackPostfix.numberTop++] = exp;
    } else if (status == 3){
        stack.number[stack.numberTop++] = number(exp);
    }
    return true;
}
char pop(int status){                   //Deleting (poping) values from stack
    if (!isEmpty()) {
        if (status == 1) {
            return stack.Expression[--stack.ExpressionTop];
        } else if (status == 2) {
            return stackPostfix.Expression[stackPostfix.numberTop--];
        } else if (status == 3){
            return stack.number[--stack.numberTop];
        }

    }
    printf("\nStack is EMPTY!");

}
char convertToChar(int num){
    int i=num;
    for(int j=0; j<num; j++) {
        if (j==num) {
            return 'j';
        }
    }
}
bool isEmpty(){
    if(stack.ExpressionTop <=0 && stackPostfix.numberTop <=0 && stack.numberTop <=0){
        return true;
    }
    return false;
}
bool isFull(){
    if (stack.ExpressionTop > SIZE && stackPostfix.numberTop > SIZE && stack.numberTop >SIZE ){
        return true;
    }
    return false;
}

int precedence(char ch){
    if(ch=='-'){
        return 1;
    } else if(ch=='+'){
        return 2;
    } else if(ch=='*'){
        return 3;
    } else if(ch=='/'){
        return 4;
    }
    return 0;
}

int number(char ch){
    if(ch=='1'){
        return 1;
    } else if(ch=='2'){
        return 2;
    } else if(ch=='3'){
        return 3;
    } else if(ch=='4'){
        return 4;
    } else if(ch=='5'){
        return 5;
    } else if(ch=='6'){
        return 6;
    } else if(ch=='7'){
        return 7;
    } else if(ch=='8'){
        return 8;
    } else if(ch=='9'){
        return 9;
    }
}

int main(){
    char ch;
    printf("Please Enter Expression to Evaluate: ");
    ch = getchar();
    while(ch != '\n'){
        exp.Expression[exp.counter++] = ch;
        ch = getchar();
    }
    printf("\ncount=%d\n",exp.counter);
    printf("\nGiven Expression is ");
    for(int i=0; i<exp.counter; i++){
        printf("%c",exp.Expression[i]);
    }
    int result = postfixEvaluation();

    printf("\nResult of Expression = %d\n",result);



    return 0;
}
