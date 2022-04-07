#include <stdbool.h>

struct doctor
{
    int count;
    int time_completed_in_shift;
    int shift_number;
    int arrival_time;
    bool available;
    bool accepting_more_patient;
};

int main(int argc, char * argv[])
{
    printf("%d %s %s\n",argc,argv[0],argv[1]);
    return 0;
}