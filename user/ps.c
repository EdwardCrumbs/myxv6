#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/pstat.h"
#include "user/user.h"

int main(int argc, char **argv)
{
    struct pstat uproc[NPROC];
    int nprocs;
    int i;
    char *state;
    static char *states[] = {
        [SLEEPING_C] "sleeping",
        [RUNNABLE_C] "runnable",
        [RUNNING_C] "running ",
        [ZOMBIE_C] "zombie  "};
    
    nprocs = getprocs(uproc);
    if (nprocs < 0)
        exit(-1);
	

    int startUptime = uptime();
        
    printf("pid\tstate\t\tsize\tppid\tname\n");
    for (i = 0; i < nprocs; i++)
    {
        state = states[uproc[i].state];
        printf("%d\t%s\t%l\t%d\t%s\n", uproc[i].pid, state,
               uproc[i].size, uproc[i].ppid, uproc[i].name);
	int totalAge = 0;
	if(uproc[i].state == RUNNABLE_C){
		totalAge = startUpTime - uproc[i].readyTime;
	}
    }

    exit(0);
}
