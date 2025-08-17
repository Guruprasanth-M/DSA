#include<stdio.h>

int foo(){
	 int i ;
	i++;
	return i;
}

int main(){
     int i ;
	for (int i = 0; i<10;i++){
		printf("foo(): %d\n",foo()); 
}
  printf("%d\n",i);
}