#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include<sys/msg.h>
#include<sys/ipc.h>


#define PATH_SHM "/home/"

typedef struct msgbuf 
{
long mtype; /*数据类型必须大于0, must be > 0 */
char buf[1024]; 
}Data;


int main()
{  
	int id = 0, status, timefd[2];
	struct timeval tv, tv1;
	
	key_t key = ftok("/",66);
	id = msgget(key,IPC_CREAT | 0666);
	if(id == -1)
	{
		printf("create msg error \n");
		return 0;
	}

	int ret = pipe(timefd);
	if(ret < 0)
	{
		perror("timefd fail\n");
		return -1;
	}


	pid_t pid = fork();
	if(pid >= 1)
	{
		Data data;
		Data time;
		int size, ret;
		
		FILE *fd = fopen("1.png", "r");
		if(fd == NULL)
		{
			perror("open fail\n");
			return -1;
		}
		
		gettimeofday(&tv, NULL);
		write(timefd[1], &tv, sizeof(struct timeval));
		
		while(1)
		{
			memset(&data, 0, sizeof(data));
			
			data.mtype = 1;
			size = fread(&data.buf[1], 1, 1023, fd);
			if(feof(fd))
			{
				data.buf[0] = 'F';
				ret = msgsnd(id,(void *)&data,size+1,0);
//				ret = msgsnd(timeID,(void *)&time, sizeof(struct timeval),0);
				break;				
			}
			else
			{
				data.buf[0] = 'C';				
				ret = msgsnd(id,(void *)&data,size+1,0);
			}

			if(ret != 0)
			{
				msgsnd(id, "E", 1, 0);
				perror("write fail\n");
				fclose(fd);
				exit(-1);
			}
			
		}
		fclose(fd);
		exit(0);
	}
	else
	{
		Data data;
		int size=0, ret;

		FILE *fd = fopen("2.png", "w");
		if(fd == NULL)
		{
			perror("open fail\n");
			return -1;
		}

		while(1)
		{
			memset(&data, 0, sizeof(data));
			
			size = msgrcv(id,(void *)&data,1024,1,0);
//			printf("size = %d\n", size);
			if(data.buf[0] == 'F')
			{
				gettimeofday(&tv1, NULL);
				fwrite(&data.buf[1], 1, size-1, fd);				
				
				//printf("read finish\n");
				read(timefd[0], &tv, sizeof(struct timeval));
				//msgrcv(timeID,(void *)&tv,sizeof(struct timeval),1,0);
				printf("11 :%lds:%ldms\n", tv1.tv_sec, tv1.tv_usec/1000);
				printf("%lds:%ldms\n", tv.tv_sec, tv.tv_usec/1000);
				printf("cost time: %ld.%ldms\n", tv1.tv_sec-tv.tv_sec, tv1.tv_usec/1000-tv.tv_usec/1000);
				break;
			}
			else if(data.buf[0] == 'E')
			{
				break;
			}
			else if(data.buf[0] == 'C')
			{
				ret = fwrite(&data.buf[1], 1, size-1, fd);
				if(ret < 0)
				{
					perror("fwrite fail\n");
				}
			}
			else
			{
				printf("%c\n", data.buf[0]);
				perror("read fd fail\n");
				break;
			}
		
		}
		fclose(fd);
		msgctl(id,IPC_RMID,NULL);
		wait(&status);
	}



	exit(0);



}
