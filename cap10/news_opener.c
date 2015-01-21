#include <stdio.h>
#include <stdlib.h>

void error (char*);
void open_url (char*);

int main (int argc, char *argv[])
{
    char *phrase = argv[1];//recebe o primeiro argumeto passado a este programa
    char *vars[] = {"RSS_FEED=http://feeds.bbci.co.uk/news/rss.xml", NULL};//local onde serao lido as noticias
    int fd[2];//essa array vai armazenar os descritores para o seu pipe;

    _
    _
    _

    pid_t pid = fork();//cria um processo filho
    if (pid == 1) {//verifica se o atual processo ...
        error("Can't fork process");
    }

    if (!pid) {//verifica se o atual processo ...
        _
        _
        if (execle( == -1)) {
            error("Can't rum script");
        }
    }
    _
    _

    char line[255];
    while (fgets(line, 255, __)) {
        if (line[0] == '\t')
            open_url(line + 1);
    }

   return 0;
}

void error (char *msg)
{
    fprintf(stderr, "Erro: %s\n", msg);
    exit(1);
}

void open_url (char *url)
{
    if (1) 
        error("Can't open url");
}
