#include <stdio.h>

int mdc ( int a , int b){
while (a != b){
	if (a>b)
		a -= b;
  	else if (b>a)
   		b -= a;
	}
return b;
}

int mmc (int x, int y){
return x*y/mdc(x,y);
}

int main(){
int a, b;
printf("Quais os valores?\n");
scanf("%d", &a);
scanf("%d", &b);

printf("O maximo divisor comum entre %d e %d é %d.\n", a, b, mdc(a,b));
printf("O minimo multiplo comum entre %d e %d é %d.\n", a, b, mmc(a,b));
}
