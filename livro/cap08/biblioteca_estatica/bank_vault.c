#include <stdio.h>
#include <encrypt.h>
#include <checksum.h>

int main (void)
{
    char s[] = "Speak friend and enter";
    encrypt(s);
    printf("Encrypted to '%s'\n", s);
    printf("Checksum is %i\n", checksum(s));
    
    encrypt(s);
    printf("Decryoted back to '%s'\n", s);
    printf("Checksum is %i\n", checksum(s));

    return 0;
}
