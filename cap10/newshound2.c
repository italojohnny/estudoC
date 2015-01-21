#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void error (char *msg)
{
    fprintf(stderr, "Erro: %s\n", msg);
    exit(1);
}

int main (int argc, char *argv[])
{
    char *phrase = argv[1];
    char *vars[] = {"RSS_FEED=http://feeds.bbci.co.uk/news/rss.xml", NULL};
    FILE *f = fopen("stories.txt", "w");
    
    if (!f) error("Can't open stories.txt");
    pid_t pid = fork();
    if (pid == -1) error("Can't fork process");
    
    if (!pid) {
        puts("entrou na condicao principal");
        if (dup2(fileno(f), 1) == -1) 
            error("Can't redirect Standard Output");
        if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars) == -1)
            error("Can't run script");
    }
    puts("chegou no fim");
    return 0;
}
