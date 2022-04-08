#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "mysemops-IMT2019012.h"
# define SEM_KEY_VAL 7770

struct doctor
{
    long long unsigned int arrival;
    int shift_number;
    bool available;
    bool accepting_more_patient;
};

int main(int argc, char * argv[])
{
    struct doctor doc = {0,0,true,true};
    printf("DOC AVAILABLE\n");
    int semid=get_existing_sem(SEM_KEY_VAL);
    free_up(semid);						  // frees SEM_KEY_VAL from init

    struct timeval tv;
    struct timezone tz;
    gettimeofday(&tv,&tz);
    doc.arrival = tv.tv_sec;

    for(int i=0;i<3;i++)
    {
        sleep(10);
        printf("DOC TIRED\n");

        while(get_val_sem(semid)<1)
        {
        }

        lock_down(semid);
        
        gettimeofday(&tv,&tz);
        doc.available = false;
        printf("DOC UNAVAILABLE\n");
        printf("DOC RESTS, worked %lld\n",tv.tv_sec - doc.arrival);

        if(doc.shift_number !=2) // 3rd shift is going on this should not be executed
        {
            int wait_sec = (rand() % (10 - 5 + 1)) + 5;
            sleep(wait_sec);
            gettimeofday(&tv,&tz);
            doc.arrival = tv.tv_sec;
        }

        free_up(semid);

        doc.available = true;
        doc.shift_number += 1;
                
        if(doc.shift_number <3)
            printf("DOC AVAILABLE\n");
        else
        {
            doc.available = false;
            printf("----- OUTPUT ENDS ---\n");
        }
    }
    remove_sem(semid);
    return 0;
}