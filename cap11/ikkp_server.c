#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

int listener_d;

void handle_shutdown (int);
int read_in (int, char*, int);
void error (char*);
int open_listener_socket (void);
void bind_to_port (int, int);
int say (int, char*);



int main (int argc, char *argv[])
{
    puts("ola mundo");
    return 0;
}

void handle_shutdown (int sig)
{
    if (listener_d) close(listener_d);
    fprintf(stderr, "Bye!\n");
    exit(0);
}


int read_in(int socket, char *buf, int len)
{
    char *s = buf;
    int slen = len;
    int c = recv(socket, s, slen, 0);
    while((c > 0) && (s[c-1] != '\n')) {
        s += c;
        slen -= c;
        c = recv(socket, s, slen, 0);
    }
    if (c < 0)
        return c;
    else if (c == 0)
        buf[0] = '\0';
    else
        s[c-1] = '\0';
    return len - slen;
}


void error(char *msg)
{
    fprintf(stderr, "%s - %s\n", msg, strerror(errno));
    exit(1);
}

int open_listener_socket()
{
    int s = socket(PF_INET, SOCK_STREAM, 0);
    if (s == -1) error("Can't open socket");
    return s;
}

void bind_to_port(int socket, int port)
{
    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port = (in_port_t)htons(30000);//port fica aqui
    name.sin_addr.s_addr = htons(INADDR_ANY);
    int reuse = 1;
    if (setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char*)&reuse, sizeof(int))== -1)
        error("Can't set the reuse option on the socket");
    int c = bind(socket, (struct sockaddr*)&name, sizeof(name));
    if (c == -1)
        error("Can't bin to socket'");
}

int say(int socket, char *s)
{
    int result = send(socket, s, strlen(s), 0);
    if (result == -1)
        fprintf(stderr, "%s: %s\n", "Erro talkinh to the client", strerror(errno));
        
    return result;
}

