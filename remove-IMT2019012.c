#include <stdio.h>
#include "mysemops-IMT2019012.h"
#include <stdbool.h>
#include <unistd.h>
# define SEM_KEY_VAL 7770

int main()
{
    int semid = get_existing_sem(SEM_KEY_VAL);
    remove_sem(semid);
    return 0;
}