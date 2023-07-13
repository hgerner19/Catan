
# include<stdio.h>




int f(int x)
{
   printf("x is %d\n", x);
   return x;
}

int main()
{
    if ( f(1) || f(0) ) {
       printf("Got it!\n");
    } else {
       printf("Done!\n");
    }
}

