#include <stdio.h>
#include "mysemops-IMT2019012.h"
#include <stdbool.h>
#include <unistd.h>
# define SEM_KEY_VAL 7770

struct patient
{
    int arrival_time;
};

void print_visitor(int argc, char * argv[])
{
    printf("------VISITOR ");
    for(int i =1;i<argc;i++)
    {
        printf("%s ",argv[i]);
    }
}

int main(int argc, char * argv[])
{
    struct patient pat = {0};
    int semid=get_existing_sem(SEM_KEY_VAL);
    if(semid<0)
    {
        print_visitor(argc,argv);
        printf("\nDOC UNAVAILABLE\n");
        return 0;
    }

    print_visitor(argc,argv);
    printf("WAITS\n");

    lock_down(semid);
    
    print_visitor(argc,argv);
    printf("TALKS\n");
    sleep(2);

    free_up(semid);

    print_visitor(argc,argv);
    printf("LEAVES\n");

    return 0;
}