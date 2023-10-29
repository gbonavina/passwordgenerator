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
    int password;
    FILE *saved_passwords;

    printf("Digite o numero de caracteres da senha: ");
    scanf("%d", &c);
    printf("Digite quantas senhas devem ser geradas: ");
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
        printf("Senha %d: %s\n", i + 1, pwrd[i]);
    }

    saved_passwords = fopen("passwords.txt", "w");
    if(saved_passwords == NULL) {
        printf("Erro ao abrir arquivo!");
        exit(1);
    }
    
    while (password != 0) {
    printf("Digite qual senha deve ser salva (digite 0 para sair): ");
    scanf("%i", &password);

    if (password >= 1 && password <= n) {
        fprintf(saved_passwords, "%s\n", pwrd[password - 1]);
    }
}

    return 0;
}
