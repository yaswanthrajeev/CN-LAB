#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int tf, tt, N, i = 1;

void transmission()
{
    while (i <= tf)
    {
        int z = 0; // Reset z for each window
        int k;

        // Send all frames in the current window
        for (k = i; k < i + N && k <= tf; k++)
        {
            printf("frame %d sent\n", k);
            tt++;
        }

        // Process acknowledgments for the sent frames
        for (k = i; k < i + N && k <= tf; k++)
        {
            int f = rand() % 2; // Randomly determine success or failure
            if (!f)
            {
                printf("ack received for frame %d\n", k);
                z++;
            }
            else
            {
                printf("Timeout!! Frame Number: %d Not Received\n", k);
                printf("Retransmitting Window...\n");
                break; // Exit the acknowledgment loop to retransmit the window
            }
        }

        printf("\n");

        // Update the starting frame index for the next window
        i = i + z;
    }
}

int main()
{
    srand(time(NULL));

    printf("Enter the Total number of frames: ");
    scanf("%d", &tf);

    printf("Enter the Window Size: ");
    scanf("%d", &N);

    transmission();

    printf("Total number of frames which were sent and resent: %d\n", tt);

    return 0;
}
