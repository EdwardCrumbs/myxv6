#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"



#define MB(1024*1024)
#define PAGE_SIZE 4096


int main(int argc, char *argv[]){

	printf("Lazy allocation tests");


//Case1: 
	char *case1 = malloc(0x15 * MB);
	printf("malloc is returned %p", case1);
	free(case1);


//Case2:
	char *case2 = malloc(0x1F * MB);

	int i;
	for(i = 0; i < 0x1F * MB; i += PAGE_SIZE){
		case2[i] = 1;
	}
	printf("Touchded pages in range of 31 MB");
	free(case2);

//Case3:
	char *case3 = malloc(0x47 * MB);

	int y;
	for(y = 0; y < 0x47 * MB; y += PAGE_SIZE * 16){
		case3[y] = 1;
	}
	printf("Touched a sixteenth of the pages in 71 MB");
	free(case3);


	exit(0);
	

}
