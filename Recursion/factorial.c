#include <stdio.h>
#include <stdlib.h>

// iterative method
int factorial(int n){
    int f, i;
    if(n == 0 || n == 1)
        f = 1;
    else{
        f = 1;
        for(i=2;i<=n;i++){
            f = i * f;
        }
    }
    return f;
} 

// recursive method
int recursive(int n){ 
    if(n==0 || n==1){
        return 1;
    }else{
        return n * recursive(n-1);
    }
}


int main(){

    printf("Factorial of %d ==> [ %d ] \n",5,recursive(5));

    return 0;

}