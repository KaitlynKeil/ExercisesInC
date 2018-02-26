#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include "util.h"

/* variables we might want to configure */
extern int max_ttl;
extern int nprobes;

/* other global variables */

extern int seq;

extern char recvbuf[];
extern char sendbuf[];
extern Rec *rec;

extern int sendfd, recvfd;
extern int pipefd[];              /* the pipe for the alarm handler */

extern Sockaddr *sasend;    /* socket addresses for various purposes */
extern Sockaddr *sarecv;
extern Sockaddr *salast;
extern Sockaddr *sabind;

extern socklen_t salen;                    /* length of a socket address */
extern int datalen;         /* length of the data in a datagram */

extern u_short sport;                      /* source UDP port # */
extern u_short dport;        /* destination port -- hopefully unused */
                                    /* 668 = the neighbor of the beast */
extern Timeval sendtv[];
extern Timeval recvtv[];
extern Timeval difftv[];
