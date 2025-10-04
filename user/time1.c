#include  "kernel/types.h"
#include "kernel/stat.h"
#include "user.h" 

int time1(int argc, char ** argv){
	int numOfTicks = uptime();
	int pid;
	int totalTime_elapsed;
	int endOfTicks;
	int theCpu;
	int totalPercent;
	int status;
	struct rusage ru;

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
		//put the arguments to pass to exec if child process is created 
		exec(argv[1], argv + 1);
		printf("Execution returned error");
		exit(1);
	}else{
		
		wait2(&status, &ru);
		endOfTicks = uptime();
		totalTime_elapsed = endOfTicks - numOfTicks;
		theCpu = ru.cpuTime;
		totalPercent = 0;

		if(totalTime_elapsed > 0){
			totalPercent = (theCpu * 100)/totalTime_elapsed;
		}

		printf("elapsed time: %d ticks, cpu time: %d ticks, %d%% CPU", totalTime_elapsed, theCpu, totalPercent);
		exit(0);
	}
	
}
