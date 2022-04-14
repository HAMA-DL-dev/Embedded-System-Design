/* A simple SocketCAN example */
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <signal.h>
#include <unistd.h>

int soc;
int read_can_port;
int dev_pid=0;
struct can_frame frame_rx;

int open_port(const char *port)
{
    struct ifreq ifr;
    struct sockaddr_can addr;
    /* open socket */
    soc = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if(soc < 0)
    {
        return (-1);
    }
    addr.can_family = AF_CAN;
    strcpy(ifr.ifr_name, port);
    if (ioctl(soc, SIOCGIFINDEX, &ifr) < 0)
    {
        return (-1);
    }
    addr.can_ifindex = ifr.ifr_ifindex;
    fcntl(soc, F_SETFL, O_NONBLOCK);
    if (bind(soc, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        return (-1);
    }
    return 0;
}
int send_port(struct can_frame *frame)
{
    int retval;
    retval = write(soc, frame, sizeof(struct can_frame));
    if (retval != sizeof(struct can_frame))
    {
        return (-1);
    }
    else
    {
        return (0);
    }
}
/* this is just an example, run in a thread */
void read_port()
{
    int recvbytes = 0;
    read_can_port = 1;
    while(read_can_port)
    {
        struct timeval timeout = {1, 0};
        fd_set readSet;
        FD_ZERO(&readSet);
        FD_SET(soc, &readSet);
        if (select((soc + 1), &readSet, NULL, NULL, &timeout) >= 0)
        {
            if (!read_can_port)
            {
                break;
            }
            if (FD_ISSET(soc, &readSet))
            {
                recvbytes = read(soc, &frame_rx, sizeof(struct can_frame));
                if(recvbytes)
                {
                    printf("dlc = %d, id = 0x%x, data[0] = 0x%x\n", frame_rx.can_dlc, frame_rx.can_id, frame_rx.data[0]);
                    //send_port(&frame_rx);
                }
            }
        }
    }
}
int close_port()
{
    close(soc);
    return 0;
}
int main(void)
{
     struct can_frame frame_tx;
     
     open_port("can0");
     
     frame_tx.can_id=1;
     frame_tx.data[0]=0x12;
     frame_tx.data[1]=0x34;
     frame_tx.can_dlc=8;
    
     send_port(&frame_tx);
     while(1){
          read_port();
     }
          
     return 0;
}
