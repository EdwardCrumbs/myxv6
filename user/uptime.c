#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"


int main(int argc, char ** argv){
	int numOfTicks = uptime();

	printf("The number of timcks ,%d ", numOfTicks);

	exit(1);


}
