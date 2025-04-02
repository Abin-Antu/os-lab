#include<stdio.h>
int main(void)
{
int fork(void),value;
value=fork();
printf("main:value =%d\n",value);
return 0;
}