#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void error (char*);
void open_url (char*);

int main (int argc, char *argv[])
{
    char *phrase = argv[1];//recebe o primeiro argumeto passado a este programa
    char *vars[] = {"RSS_FEED=http://feeds.bbci.co.uk/news/rss.xml", NULL};//local onde serao lido as noticias
    int fd[2];//essa array vai armazenar os descritores para o seu pipe;
    
    if (pipe(fd) == -1) error("Can't create the pipe");
    pid_t pid = fork();//cria um processo filho
    if (pid == -1) error("Can't fork process");

    if (!pid) {//verifica se o atual processo ...
        dup2(fd[1], 1);
        close(fd[0]);
        if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", "-u", phrase, NULL, vars) == -1) error("Can't rum script");
    }
    dup2(fd[0], 0);
    close(fd[1]);

    char line[255];
    while (fgets(line, 255, stdin))
        if (line[0] == '\t') open_url(line + 1);

   return 0;
}

void error (char *msg)
{
    fprintf(stderr, "Erro: %s\n", msg);
    exit(1);
}

void open_url (char *url)
{
    /*
    FILE *file = fopen("urls.txt", "w");
    if (!file) error("nao deu pra abrir o arquivo");
    fprintf(file, "%s\n", url);
    fclose(file);
    */
    char launch[255];
    pid_t pid = fork();
    if (pid == -1) error("Can't fork process");
    if (!pid) {
        if (execlp("firefox", "firefox", url, NULL) == -1) error("Can't run navigator");
    }
}
