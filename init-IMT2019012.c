// Your semaphores can have any keys in the range 7770-7779.
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include "mysemops-IMT2019012.h"
# define SEM_KEY_VAL 7770

int main(int argc, char * argv[])
{
	int semid1 = create_new_sem(SEM_KEY_VAL); // creates and locks SEM_KEY_VAL
    free_up(semid1);						  // frees SEM_KEY_VAL
    return 0;
}