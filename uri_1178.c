#include <stdio.h>

int main() {

    /**
     * Escreva a sua solu��o aqui
     * Code your solution here
     * Escriba su soluci�n aqu�
     */
     double n;
     scanf("%lf", &n);
     int i;
     for(i=0; i<100; i++){
         if(i==0){
             printf("N[0] = %.4lf\n", n);
         }
         else{
             n /= 2.0;
             printf("N[%d] = %.4lf\n", i, n);
         }
     }

    return 0;
}
