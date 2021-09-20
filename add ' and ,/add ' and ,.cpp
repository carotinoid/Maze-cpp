#include <iostream>

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    int a;
    char c;
    scanf("%d", &a);
    scanf("%c", &c);
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<a;j++)
        {
            scanf("%c", &c);
            printf("'%c',", c);
        }
        scanf("%c", &c);
    }
}
