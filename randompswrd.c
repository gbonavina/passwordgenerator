#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char charset[75] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                        '0','1','2','3','4','5','6','7','8','9','!','@','#','$','&','*','(',')','-','_','+','='};
    int c, n;
    int index;

    printf("Digite o numero de caracteres da senha (enter the amount of characters): ");
    scanf("%d", &c);
    printf("Digite quantas senhas devem ser geradas (enter the amount of passwords): ");
    scanf("%d", &n);

    char pwrd[n][c + 1];

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < c; j++)
        {
            index = rand() % 75;
            pwrd[i][j] = charset[index];
        }

        pwrd[i][c] = '\0';
        printf("Senha %d (Password %d): %s\n", i + 1, i + 1, pwrd[i]);
    }

    return 0;
}
