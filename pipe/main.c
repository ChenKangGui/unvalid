#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/time.h>


int main()
{
	struct timeval tv, tv1={0};
    
	int ret, pipefd[2], timefd[2], status;

	ret = pipe(pipefd);
	if(ret < 0)
	{
		perror("pipe fail\n");
		return -1;
	}
	

	ret = pipe(timefd);
	if(ret < 0)
	{
		perror("timefd fail\n");
		return -1;
	}
	

	pid_t pid = fork();
	if(pid >= 1)
	{
//		printf("pid = %d\n", getpid());

		char buf[1024];
		int size, ret;		

		FILE *fd = fopen("1.png", "r");
		if(fd == NULL)
		{
			perror("open fail\n");
			return -1;
		}
		
		gettimeofday(&tv, NULL);
		write(timefd[1], &tv, sizeof(struct timeval));
	//	printf("%lds:%ldms\n", tv.tv_sec, tv.tv_usec/1000);
		while(1)
		{
			memset(buf, 0, sizeof(buf));
			size = fread(&buf[1], 1, 1023, fd);
			if(feof(fd))
			{
				buf[0] = 'F';
				ret = write(pipefd[1], buf, size+1);
				break;				
			}
			else
			{
				buf[0] = 'C';				
				ret = write(pipefd[1], buf, size+1);
			}

			if(ret != size+1)
			{
				write(pipefd[1], "E", 1);
				perror("write fail\n");
				fclose(fd);
				exit(-1);
			}

		}
		fclose(fd);
//		printf("fd read success\n");
		exit(0);

	}
	else
	{
//		printf("pid1 = %d\n", getpid());		


		char buf[1024];
		int size, ret;



		FILE *fd = fopen("2.png", "w");
		if(fd == NULL)
		{
			perror("open fail\n");
			return -1;
		}

		while(1)
		{
			memset(buf, 0, sizeof(buf));
			
			size = read(pipefd[0], buf, 1024);
//			printf("size = %d\n", size);
			if(buf[0] == 'F')
			{
				gettimeofday(&tv1, NULL);
				fwrite(&buf[1], 1, size-1, fd);				
				//printf("11 :%lds:%ldms\n", tv1.tv_sec, tv1.tv_usec/1000);
				//printf("read finish\n");
				read(timefd[0], &tv, sizeof(struct timeval));
				//printf("%lds:%ldms\n", tv.tv_sec, tv.tv_usec/1000);
				printf("cost time: %ld.%ldms\n", tv1.tv_sec-tv.tv_sec, tv1.tv_usec/1000-tv.tv_usec/1000);
				break;
			}
			else if(buf[0] == 'E')
			{
				break;
			}
			else if(buf[0] == 'C')
			{
				ret = fwrite(&buf[1], 1, size-1, fd);
				if(ret < 0)
				{
					perror("fwrite fail\n");
				}
			}
			else
			{
				perror("read fd fail\n");
				break;
			}
		}
		fclose(fd);
		close(pipefd[0]);
		close(pipefd[1]);
		close(timefd[0]);
		close(timefd[1]);
		wait(&status);

	}

	return -1;
}











		
