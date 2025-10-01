#include  "kernel/types.h"
#include "kernel/stat.h"
#include "user.h" 


int time1(int argc char ** argv){
	int numOfTicks = uptime();
	int pid;
	int totalTime_elapsed;
	int endOfTicks;

	if(argc < 2){
		printf("Error");
		exit(1);
	}



	pid = fork();
	//checking if process failed
	if(pid < 0){
		printf("Fork was unsuccesfull");
		exit(1);
	}else if (pid == 0){
		//Assemble the arguments to pass to exec if child process is created 
		exec(argv[1], argv + 1);
		printf("Execution returned error");
		exit(1);
	}else{
		
		wait(0);
		endOfTicks = uptime();
		totalTime_elapsed = endOfTicks - numOfTicks;
		printf("Time: %d", totalTime_elapsed);
		exit(0);
	}
	
}
