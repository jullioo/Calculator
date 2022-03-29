#include <stdio.h>
#include <math.h>

char opt;
char oper;
char alph;
char optVar;
char sel;

float a=0;
float b=0;
float c=0;
float d=0;
float e=0;
float num1;
float num2;
float result;
float max;
float chnum;

int count;
int place;
float mem[100];

float bin(float num1, float num2, char oper);
float unary(float num1,char oper);

void eraser();
void memory();
void var();
void adv();
void menu();

int main() {
  
  
  menu();
  
  while(opt!='E' || opt!='e'){

    if (opt=='B' || opt=='b' ){
      printf("Enter the first number: ");
      while(scanf("%f", &num1)==0){
        printf("Invalid input...\nEnter the first number: ");
        scanf("%*s");
      }

      printf("Enter the operation(+, -, *, /, P, X, I): ");
      scanf("%s", &oper);
      while(oper!='+' && oper!='-' && oper!='*' && oper!='/' && oper!='P' && oper!='X' && oper!='I' && oper!='p' && oper!='x' && oper!='i'){
        printf("Invalid input...\nEnter the operation(+, -, *, /, P, X, I): ");
        scanf("%s", &oper);
      }
      
      printf("Enter the second number: ");
      while(scanf("%f", &num2)==0){
        printf("Invalid input...\nEnter the second number: ");
        scanf("%*s");
      }
      printf("%.2f\n",bin(num1,num2,oper));
    }

    if (opt=='U' || opt=='u'){
      printf("Please enter the operation ( S (for square root) , L (for logarithm) , E (for exponential) , C (for ceil) , F (for floor) ):");
      scanf("%s",&oper);
      while(oper!='S' && oper!='L' && oper!='E' && oper!='C' && oper!='F' && oper!='s' && oper!='l' && oper!='e' && oper!='c' && oper!='f'){
        puts("Please enter the operation ( S (for square root) , L (for logarithm) , E (for exponential) , C (for ceil) , F (for floor) ):");
        scanf("%s", &oper);
      }

      printf("Enter the number: ");
      while(scanf("%f", &num1)==0 || num1<0){
        printf("Invalid input...\nEnter the number: ");
        scanf("%*s");
      }
      printf("%.2f\n",unary(num1,oper));
    }

    if (opt=='V' || opt=='v'){
      var();
    }
    
    if (opt=='m' || opt=='M'){
      memory();
    }
    
    if (opt=='r' || opt=='R'){
      eraser();
    }

    if (opt=='A' || opt=='a'){
      adv();
    }

    if (opt=='E' || opt=='e'){
      break;
    }

    printf("Choose from this options (B, U, A, V, M, R, E): ");
    scanf("%s",&opt);
  }
  
  if (opt=='E' || opt=='e'){
    printf("Thanks for using my Simple Calculator. Hope to see you soon again, Goodbye!");
  }
}//////////////////////////////////////////////////main

void menu(){
  printf("Welcome to our Command-Line Calculator (CLC)\n");
  printf("Developer: Julio Costa\n");
  printf("Version: 2, Assignment 2\n");
  printf("Date: Novemebr 2020\n");
  printf("Select one of the following items:\n");
  printf("B) - Binary Mathematical Operations, such as addition and subtraction.\n");
  printf("U) - Unary Mathematical Operations, such as square root, and log.\n");
  printf("A) - Advances Mathematical Operations, using variables, arrays.\n");
  printf("V) - Define variables and assign them values.\n");
  printf("M) - Shows what you have stored in the memory.\n");
  printf("R) - Deletes your memory.\n");
  printf("E) - Exit\n");
  scanf("%s",&opt);
}
float bin(float num1, float num2, char oper){

  if (oper=='+'){
    result=num1+num2;
    mem[count++]=result;
  }
  if (oper=='-'){
    result=num1-num2;
    mem[count++]=result;
  }
  if (oper=='*'){
    result=num1*num2;
    mem[count++]=result;
  }
  if (oper=='/'){
    while(num2==0){
      printf("Invalid input...\nEnter the second number: ");
      scanf("%*s");
    }
    result=num1/num2;
    mem[count++]=result;
  }
  if (oper=='P' || oper=='p'){
    result=pow(num1,num2);
    mem[count++]=result;
  }
  if (oper=='X' || oper=='x'){
    if(num1>num2){
      result=num1;
    }
    else if(num2>num1){
      result=num2;
    }
    else{
      result=num1;
    }
    mem[count++]=result;
  }
  if (oper=='I' || oper=='i'){
    if (num2<num1){
      result=num2;
    }
    else if (num1<num2){
      result=num1;
    }
    else if(num1==num2){
      result=num1;
    }
    mem[count++]=result;
  }
  return result;
}

float unary(float num1,char oper){
  if (oper=='S' || oper=='s'){
    
    result=sqrt(num1);
    mem[count++]=result;
  }
  if (oper=='L' || oper=='l'){
    
    result=log(num1);
    mem[count++]=result;
  }
  if (oper=='E' || oper=='e'){
    
    result=exp(num1);
    mem[count++]=result;
  }
  if (oper=='C' || oper=='c'){
    
    result=ceil(num1);
    mem[count++]=result;
  }
  if (oper=='F' || oper=='f'){
    
    result=floor(num1);
    mem[count++]=result;
  }
  return result;
}

void var(){
  printf("Enter a alphabetic character (a-e): ");
  scanf("%s", &alph);
  while(alph!='a' && alph!='b' && alph!='c' && alph!='d' && alph!='e'){
    printf("Invalid input...\nEnter a alphabetic character (a-e): ");
    scanf("%s",&alph);
  }

  printf("Please enter a number:");
  while(scanf("%f", &chnum)==0){
    printf("Invalid input...\nPlease enter a number:");
    scanf("%*s");
  }

  if(alph=='a' || alph=='A'){
    a=chnum;
    printf("Variable a is set to:\t%.2f\n",a);
  }
  if(alph=='b' || alph=='B'){
    b=chnum;
    printf("Variable b is set to:\t%.2f\n",b);
  }
  if(alph=='c' || alph=='C'){ 
    c=chnum;
    printf("Variable c is set to:\t%.2f\n",c);
  }
  if(alph=='d'|| alph=='D'){
    d=chnum;
    printf("Variable d is set to:\t%.2f\n",d);
  }
  if(alph=='e' || alph=='e'){
    e=chnum;
    printf("Variable e is set to:\t%.2f\n",e);
  }   
}

void adv(){
  printf("Select one of the following:\n");
  printf("B) - Binary Mathematical Operations, such as addition and subtraction.\n");
  printf("U) - Unary Mathematical Operations, such as square root, and log.\n");
  printf("E) - Exit and back to the main menu.\n");
  scanf("%s",&optVar);
  while (optVar!='E' || optVar!='e'){

    if (optVar=='B' || optVar=='b' ){
      printf("Would you like to use a variable (V) or a number (N): ");
      scanf("%s", &sel);
      while(sel!='N' && sel!='V' && sel!='n' && sel!='v'){
        printf("Invalid input...\nWould you like to use a variable (V) or a number (N): ");
        scanf("%s", &sel);
      }
      if (sel=='N' || sel=='n'){
        printf("Enter the first number: ");
        while(scanf("%f", &num1)==0){
          printf("Invalid input...\nEnter the first number: ");
          scanf("%*s");
        }
      }
      if (sel=='V' || sel=='v'){
        printf("Enter the first variable: ");
        scanf("%s",&alph);
        while(alph!='a' && alph!='b' && alph!='c' && alph!='d' && alph!='e'){
          printf("Invalid input...\nEnter a alphabetic character (a-e): ");
          scanf("%s",&alph);
        }
        if(alph=='a'){
          num1=a;
        }
        else if(alph=='b'){
          num1=b;
        }
        else if(alph=='c'){
          num1=c;
        }
        else if(alph=='d'){
          num1=d;
        }
        else if(alph=='e'){
          num1=e;
        }
      }
      
      printf("Enter the operation(+, -, *, /, P, X, I): ");
      scanf("%s", &oper);
      while(oper!='+' && oper!='-' && oper!='*' && oper!='/' && oper!='P' && oper!='X' && oper!='I' && oper!='p' && oper!='x' && oper!='i'){
        printf("Invalid input...\nEnter the operation(+, -, *, /, P, X, I): ");
      scanf("%s", &oper);
      }
      

      printf("Would you like to use a variable (V) or a number (N): ");
      scanf("%s", &sel);
      while(sel!='N' && sel!='V' && sel!='n' && sel!='v'){
        printf("Invalid input...\nWould you like to use a variable (V) or a number (N): ");
        scanf("%s", &sel);
      }
      if (sel=='N' || sel=='n'){
        printf("Enter the second number: ");
        while(scanf("%f", &num2)==0){
          printf("Invalid input...\nEnter the first number: ");
          scanf("%*s");
        }
      }

      if (sel=='V' || sel=='v'){
        printf("Enter the second variable: ");
        scanf("%s",&alph);
        while(alph!='a' && alph!='b' && alph!='c' && alph!='d' && alph!='e'){
          printf("Invalid input...\nEnter a alphabetic character (a-e): ");
          scanf("%s",&alph);
        }
        if(alph=='a'){
          num2=a;
        }
        else if(alph=='b'){
          num2=b;
        }
        else if(alph=='c'){
          num2=c;
        }
        else if(alph=='d'){
          num2=d;
        }
        else if(alph=='e'){
          num2=e;
        }
      }

      printf("%.2f\n",bin(num1,num2,oper));
    }
    
    if (optVar=='U' || optVar=='u'){
      printf("Please enter the operation ( S (for square root) , L (for logarithm) , E (for exponential) , C (for ceil) , F (for floor) ):");
      scanf("%s",&oper);
      while(oper!='S' && oper!='L' && oper!='E' && oper!='C' && oper!='F' && oper!='s' && oper!='l' && oper!='e' && oper!='c' && oper!='f'){
        printf("Invalid input...\nPlease select your option ( B (Binary operation), U (Unary operation) , A (Advanced), V (Variables), E (Exit)): ");
        scanf("%s", &oper);
      }

      printf("Would you like to use a variable (V) or a number (N): ");
      scanf("%s", &sel);
      while(sel!='N' && sel!='V' && sel!='n' && sel!='v'){
        printf("Invalid input...\nWould you like to use a variable (V) or a number (N): ");
        scanf("%s", &sel);
      }
      if (sel=='N' || sel=='n'){
        printf("Enter the first number: ");
        while(scanf("%f", &num1)==0 || num1<0){
          printf("Invalid input...\nEnter the first number: ");
          scanf("%*s");
        }
      }
      if (sel=='V' || sel=='v'){
        printf("Enter the first variable: ");
        scanf("%s",&alph);
        while(alph!='a' && alph!='b' && alph!='c' && alph!='d' && alph!='e'){
          printf("Invalid input...\nEnter a alphabetic character (a-e): ");
          scanf("%s",&alph);
        }
        if(alph=='a'){
          num1=a;
        }
        else if(alph=='b'){
          num1=b;
        }
        else if(alph=='c'){
          num1=c;
        }
        else if(alph=='d'){
          num1=d;
        }
        else if(alph=='e'){
          num1=e;
        }
      }

      printf("%.2f\n",unary(num1,oper));  
    } 
    if (optVar=='E' || optVar=='e'){
      break;
    }
    printf("Select one of the following(B, U, E): ");
    scanf("%s", &optVar);
  }
}

void memory(){
  if(count==0){
    puts("There is nothing stored in memory");
  }

  else{
    printf("There are %d items available\n",count);
    while(oper!='e' || oper!='E'){
      printf("\nChoose what you'd like to see\n0) - The whole list\n1) - An item in the memory\nE) - Exit to the main \n");
      scanf("%s",&oper);

      while(oper!='0' && oper!='1' && oper!='e' && oper!='E'){
        printf("\nInvalid input...\nChoose what you'd like to see(0, 1, E):");
        scanf("%s",&oper);
      }

      if(oper=='0'){
        for(int i=0;i<count;i++){
          printf("%.2f ",mem[i]);
        }
      }

      if(oper=='1'){
        printf("Enter a number between 1 and %d\n",count);
        
        while(scanf("%d",&place)==0 || place>count || place<1){
          printf("Enter a number between 1 and %d\n",count);
          scanf("%*s");
        }
        if(place-1==0){
          printf("%.2f",mem[0]);
        }
        else{
          printf("%.2f",mem[place-1]);
        }
      }

      if(oper=='e' || oper=='E'){
        break;
      }
    }
  }
}

void eraser(){
  for(int i=0;i<count;i++){
    mem[i]=0;
  }
  count=0;
  puts("Memory has been erased");
}