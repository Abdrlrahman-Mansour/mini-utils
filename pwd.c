#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define COUNT 100

int main(int argc, char* argv[])
{
	char buf[COUNT];
	
	if(argc != 1)
	{
		printf("usage %s file-name\n",argv[0]);
		exit(-1);
	}
	getcwd(buf,COUNT);
	printf("%s\n",buf);
	
	return 0 ;

}

