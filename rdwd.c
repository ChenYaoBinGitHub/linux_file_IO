#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int fd;
	char buff[30] = {0};

	sprintf( (char *)buff, "/home/c/C/File/%s", argv[1]);
   	fd = open(buff,O_CREAT | O_RDWR, 0777 );	

	if(fd == -1)
	{
 		fprintf(stderr, "file fail\n");
		return -1;
	}
	printf("file %s_%d is successfully ! \n", argv[1], fd);

	int wt_cnt = 0;

	wt_cnt = write(fd, buff, strlen(buff));
	printf("writed num:%d\n", wt_cnt);

	lseek(fd, 0, SEEK_SET);

	int rd_cnt = 0;
	char c;
	
	memset(buff, 0, sizeof(buff) );
	while(read(fd, &c, 1)>0 )
	{
		printf("%c", c);
	}
	printf("read:ok\n");

	close(fd);

	return 0;
}


