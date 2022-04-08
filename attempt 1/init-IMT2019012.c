// Your semaphores can have any keys in the range 7770-7779.
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include "mysemops.h"
# define SEM_KEY_VAL 7890
# define SEM_PROG_END 7891
# define SEM_DOC_END 7892

int main(int argc, char * argv[])
{
	int semid1 = create_new_sem(SEM_KEY_VAL); // creates and locks SEM_KEY_VAL
    free_up(semid1);						  // frees SEM_KEY_VAL

	int semid_doc_end = create_new_sem(SEM_DOC_END); // creates and locks SEM_KEY_VAL
    free_up(semid_doc_end);					         // frees SEM_KEY_VAL

	int semid2=create_new_sem(SEM_PROG_END);  // creates and locks SEM_PROG_END
	lock_down(semid2);						  
	// locks SEM_PROG_END again so this 
	// will wait in queue for infinite time
	// This will be executed only when the
	// lock applied during it's creation will be freed.
	// This will be done when the doctor is just about to end.
	free_up(semid2); // freeing up the lock applied above

	// removing the semaphores from the system
	remove_sem(semid1);
	remove_sem(semid2);
	remove_sem(semid_doc_end);

    return 0;
}