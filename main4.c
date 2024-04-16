
#include <stdio.h>

typedef struct {
    int type;
    char *str_value;
    int int_value;
}IntOrString;

void *teste(IntOrString values[]){

}

IntOrString newNumber(int num){
    IntOrString value = {.type = 2, .int_value = 30};
    return value;
}


int main(){
    
    teste((IntOrString[]){
        newNumber(10),
        newNumber(30)
    });

}