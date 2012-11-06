#include<stdio.h>

char** func1_Str();
char** func2_Str();

int main(void)
{
    char **ptr1 = NULL;
    char **ptr2 = NULL;

    ptr1 = func1_Str();
    printf("\n [%s] \n",*ptr1);

    ptr2 = func2_Str();
    printf("\n [%s] \n",*ptr2);

    printf("\n [%s] \n",*ptr1);

    return 0;
}

char** func1_Str()
{
    char *p = "Linux";
    return &p;
}

char** func2_Str()
{
    char *p = "Windows";
    return &p;
}
