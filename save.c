#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int age,pirm,acced,assu;
bool c1,c2,c3;
char *situ;
int main()
{
    printf("Entrez l'age:\n");
    scanf("%d",&age);
    printf("Entrez le nombre d'années de permis:");
    scanf("%d",&pirm);
    printf("Entrez le nombre d'accidents: ");
    scanf("%d",&acced);
    printf("Entrez le nombre d'années d'assurance:");
    scanf("%d",&assu);
    c1=age>=25;
    c2=pirm>=2;
    c3=assu>5;
    if (!c1 && !c2)
    {
        if(acced == 0)
        {
            situ = "Rouge";
        }
        else
        {
            situ = "Refuse";
        }
    }
    else if ((!c1 && c2) || (c1 && !c2))
    {
        if (acced == 0)
        {
            situ = "Orange";
        }
        else if (acced == 1)
        {
            situ = "Rouge";
        }
        else
        {
            situ = "Refuse";
        }
    }
    else 
    {
        if (acced == 0)
        {
            situ = "Vert";
        }
        else if (acced == 1)
        {
            situ = "Orange";
        }
        else if (acced == 2)
        {
            situ = "Rouge";
        }
        else
        {
            situ = "Refuse";
        }
    }
    printf("%s",situ);
}