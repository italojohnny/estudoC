encrypt.o: encrypt.c encrypt.h
	gcc -c encrypt.c -o encrypt.o #isso cria o arquivo objeto forte encrypt.c

checksum.o: checksum.c checksum.h
	gcc -c checksum.c -o checksum.o #isso cria o objeto do arquivo fonte checksum.c

#voce nao pode construir o deposito libhfsecurity.a ate criar encrypt.o e checksum.o
libhfsecurity.a: checksum.o encrypt.o
	ar -rcs libhfsecurity.a encrypt.o checksum.o #isso vai criar o deposito libfsecurity.a

#voce precisa de -lhfsecurity, porque o deposito se chama libhfsecurity.a
bank_vault.o: bank_vault.c encrypt.h checksum.h
	gcc -c bank_vault.c -I. -o bank_vault.o
#o codigo-fonte do programa precisa ser listado antes do codigo da biblioteca
#voce precisa de -I., porque os arquivos heard estao no diretorio "." (atual)
#voce precisa do -L., porque o deposito esta no diretorio atual

bank_vault: bank_vault.o libhfsecurity.a
		gcc bank_vault.o -I. -L. -lhfsecurity -o bank_vault
clean:
	-rm -f *.o bank_vault 

FONTES=$(wildcard *.c)
OBJETOS=$(FONTES:.c=.o)
lista: listaFontes listaObjetos
listaFontes: $(FONTES)
	@echo "os arquivos fontes sao" $(FONTES)
listaObjetos: $(OBJETOS)
	@echo "os arquivos objetos sao" $(OBJETOS)

