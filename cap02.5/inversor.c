#include <stdio.h>
#include <string.h>

void print_reverse(char *s)
{
    size_t len = strlen(s);//inteiro usado para armazenar o tamanho
    char *t = s + len - 1;
    
    while (t >= s) {
        printf("%c", *t);
        t = t - 1;
    }
    puts ("");
}

int main (void)
{
    char palavra[80];
    printf("Digite uma palavra: ");
    scanf("%79s", palavra);
    print_reverse(palavra);

    return 0;
}
