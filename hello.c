#include<stdio.h>
#include<unistd.h>
int main() {
    while(1){
        printf("Hello, World!\n");
        sleep(2);
        printf("Goodbye, World!\n");
        sleep(1);
        // return 0;
    }
}