#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(void)
{

	int pid = getpid();

	int pri = getPriority(pid);

	setPriority(pid, 20);

	int child = fork();

	if( child === 0){
		exec("ps", 0);
		exit(0);
	}else{
		wait(0);
	
	}

	exit(0);

}
