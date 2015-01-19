encrypt.o: encrypt.c
	gcc -c encrypt.c -o encrypt.o #isso cria o arquivo objeto forte encrypt.c

checksum.o: checksum.c
	gcc -c checksum.c -o checksum.o #isso cria o objeto do arquivo fonte checksum.c

#voce nao pode construir o deposito libhfsecurity.a ate criar encrypt.o e checksum.o
libhfsecurity.a: encrypt.o checksum.o
	ar -rcs libhfsecurity.a encrypt.o checksum.o #isso vai criar o deposito libfsecurity.a

#voce precisa de -lhfsecurity, porque o deposito se chama libhfsecurity.a
bank_vault: bank_vault.c libhfsecurity.a
	gcc bank_vault.c -I. -L. -lhfsecurity -o bank_vault
#o codigo-fonte do programa precisa ser listado antes do codigo da biblioteca
#voce precisa de -I., porque os arquivos heard estao no diretorio "." (atual)
#voce precisa do -L., porque o deposito esta no diretorio atual

