#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include "mysemops.h"
# define SEM_KEY_VAL 7890
# define SEM_PROG_END 7891

int main(int argc, char * argv[])
{
	int semid1 = get_existing_sem(SEM_KEY_VAL);
	int semid2= get_existing_sem(SEM_PROG_END);
	// removing the semaphores from the system
	remove_sem(semid1);
	remove_sem(semid2);
    return 0;
}