#include <stdio.h>
 
int main()
{
    int a = 5;
    int* ptr = &a;
    int** d_ptr = &ptr;
 	int*** t_ptr = &d_ptr;
 	
  	printf("Value of var = %d\n", a);
    printf("Address of var using single pointer = %p\n", ptr);
    printf("Address of var using double pointer = %p\n", *d_ptr);
    printf("Address of var using triple pointer = %p\n", **t_ptr);
    
	//Coba lakukan penjumlahan terhadap variable a dengan nilai 7
	//lakukan dengan cara mengakses variable dengan triple pointer
    
    (***t_ptr) += 7;
    
    //mengecek isi dari variable a
    printf("a variable after addition = %d\n", a);
    
    return 0;
}
