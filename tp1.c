#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


void main(int argc, char** argv)
{ 
    char datas[] = "bonjour\n";
    int sockfd,newsockfd,clilen,chilpid,ok,nleft,nb; 
    char c;
    struct sockaddr_in cli_addr, serv_addr;
    if (argc!=2) 
        {
        printf ("usage: socket_srv port_number\n");
        exit(0);
        } 
    printf ("server starting...\n");             /* ouvertture du socket */
    sockfd = socket (AF_INET,SOCK_STREAM,0);
    if (sockfd<0)
         {
        printf ("impossible d’ouvrir le socket\n") ;
        exit(0);
         }   /* initialisation des parametres */
    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;

    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));
    /* effecture le bind */
    if (bind(sockfd, (struct sockaddr*)&serv_addr,sizeof(serv_addr))<0) 
        {
        printf ("impossible de faire le bind\n");
        exit(0);
        }
    /* petit initialisation */
    listen (sockfd, 1);
    /* attend la connection d’un client */
    clilen = sizeof (cli_addr);
    newsockfd = accept (sockfd, (struct sockaddr*) &cli_addr, &clilen); 
    if (newsockfd<0) 
        {
        printf ("accept error\n");
         exit(0);
        }
    printf ("connection accepted\n"); 
    nb = read(newsockfd,&c,1);
    printf("j'ai lu %i caracteres : %c",nb,c);

close(newsockfd);
}
