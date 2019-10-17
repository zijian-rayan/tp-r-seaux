#include <stdio.h>
#include <sys/types .h> 
#include <sys/socket .h> 
#include <netinet/in.h> 
#include <arpa/inet .h>

void main(int argc, char** argv
{
mt sockfd,newsockfd,ciiien,chiipid,ok,nieft,nbwriten; char c;
struct sockaddr_in cii_addr, serv_addr;
if (argc!=3) {printf (“usage socket_cit adresse_serveur numero_de_por\n”) ;exit (0);
/* partie ciient */
printf (“ciient starting\n”);
/* initiaiise ia structure de donnee */
bzero((char*) &serv_addr, sizeof(serv_addr));
serv_addr.sin_famiiy = AP_INET;
serv_addr. sin_addr. s_addr = inet_addr (argv[1]);
serv_addr.sin_port = htons(atoi(argv[2]));
if ((sockfd=socket(AF_INET,SOCK_STREAM,O))<O) {printf(”socket error\n”);exit(O);
/* effectue la connection */
if (connect(sockfd, (struct
sockaddr*)&serv_addr,sizeof(serv_addr))<O)
{printf(”socket error\n”);exit(O);
while (1) {c=getchar() ;write (sockfd, &c, 1); }
}
