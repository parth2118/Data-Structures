#include <stdio.h>

void move(int n,char source,char dest,char spare)
{
    if(n==1)
    {
        printf("\nMove disk 1 from rod %c to rod %c.",source,dest);
    }
    else
    {
        move(n-1,source,spare,dest);
        move(1,source,dest,spare);
        move(n-1,spare,dest,source);
    }
}

int main()
{
    int n;
    printf("\n Enter the number of rings: ");
    scanf("%d", &n);
    move(n,'A', 'C', 'B');
    return 0;
}
