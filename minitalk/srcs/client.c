#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int main()
{
	int pid = getpid();
	printf("%d\n", pid);
	sleep(100);

	return 0;
}
