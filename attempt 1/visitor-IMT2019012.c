#include <stdio.h>
#include "mysemops.h"
#include <stdbool.h>
#include <unistd.h>
# define MAX_PATIENT 10000

struct patient
{
	int index;
    int arrival_time;
    bool attended;
};

struct patient patients_array[MAX_PATIENT];

int lock_patient(struct patient * patient_obj, int semid)
{
    lock_down(semid);
    patient_obj->attended = true;
	sleep(2);
	free_up(semid);
    return 0;
}

int main(int argc, char * argv[])
{
    printf("%d %s %s\n",argc,argv[0],argv[1]);
    return 0;
}