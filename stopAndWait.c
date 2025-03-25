#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#define TOTAL_PACK 5
#define TIMEOUT 3

int stimulate_ack()
{
    return rand()%10<7;
}
int main()
{
    srand(time(0));
    int packet=1;
    int ack_recieved;
    while(packet<=TOTAL_PACK)
    {
        printf("sender sending packet %d\n",packet);
        sleep(1);
        ack_recieved=stimulate_ack();
        if(ack_recieved)
        {
            printf("receiver recieved packet %d\n",packet);
            packet++;
            
        }
        else
        {
            printf("packet %d lost and retransmitted\n",packet);
            sleep(TIMEOUT);
        }
    }
    printf("all packet sent succesfully");
}