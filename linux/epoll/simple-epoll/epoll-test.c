
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <unistd.h>

#define MAX_EVENTS 64


int main(int argc, char* argv[])
{
    
    struct epoll_event *events;
    int nr_events, i, epfd;
    events = malloc(sizeof(struct epoll_event) * MAX_EVENTS);
    if(!events)
    {
        perror("malloc");
        exit(-1);
    }

    nr_events = epoll_wait(epfd, events, MAX_EVENTS, -1);
    if(nr_events < 0)
    {
        perror("epoll_wait");
        free(events);
        exit(-1);
    }

    for(i = 0; i < nr_events; ++i)
    {
        /**
         * @brief now, we can, per events[i].events, operate on
         * events[i].data.fd without blocking.
         */
        printf("event = %d on fd = %d\n",
            events[i].events, events[i].data.fd);
    }
    free(events);



    return 0;
}