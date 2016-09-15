#include <math.h>
#include <stdio.h>
/*
 * Implementation of operation functions
 */
int main( int argc, char *argv[]){    
    if(argc != 4){
       printf("The input is illegal\n");
       printf("%d\n",argc);
    }
    else {
       switch(argv[2][0]){
          case '+':
            printf("%d\n", add(atoi(argv[1]), atoi(argv[3])));
            break;
          case '-':
            printf("%d\n", sub(atoi(argv[1]), atoi(argv[3])));
            break;
          case 'x':
            printf("%d\n", mul(atoi(argv[1]), atoi(argv[3])));
            break;
          case '/':
            printf("%d\n", div(atoi(argv[1]), atoi(argv[3])));
            break;
          case '%':
            printf("%d\n", mod(atoi(argv[1]), atoi(argv[3])));
            break;
       }  
    }
    return 0;
}
