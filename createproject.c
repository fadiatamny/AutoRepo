
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <string.h>
#include <errno.h>
#include <sys/wait.h>


int main(int argc,char* argv[])
{
    char buff[256] = {0};
    char ogDist[256] = "/home/";
    char dist[256] = "";
    char* params[] = {"cd", "~/"};

    strcat(ogDist,getlogin());
    strcat(ogDist,"/Documents/");
    strcpy(dist,ogDist);
    strcat(dist,"Github/");
    strcpy(buff,argv[1]);

    if(chdir(dist)==-1)
    {
        chdir(ogDist);
        if(mkdir("Github", 0700) == -1)
        {
            printf(strerror(errno));
            return -1;
        }   
        chdir(dist);
    }

    struct stat st = {0};

    if (stat(buff, &st) == -1) 
    {
        if(mkdir(buff, 0700) == -1)
        {
            printf(strerror(errno));
            return -1;
        }
        
        strcat(dist,buff);
        chdir(dist);
        open(".gitignore",O_RDWR|O_CREAT,0700);
        
        int status = 0;
        pid_t wpid;

        pid_t id = fork();

        if(id)
        {
            while ((wpid = wait(&status)) > 0);
            
            char* paramsCode[] = {"code-oss", ".", NULL};
            if (execvp("code-oss",paramsCode))
            {
                printf(strerror(errno));
            }
        }
        else
        {
            char* params1[] = {"git", "init", NULL};
            if (execvp("git",params1))
            {
                printf(strerror(errno));
                strcpy(dist,ogDist);
                strcat(dist,"Github/");
                chdir(dist);
                char* params2[] = {"rm", "-r",buff, NULL};
                if(execvp("rm",params2))
                    printf(strerror(errno));
            }
        }
    }
    else
    {
        printf("File already exists");
    }
    
    return 0;
}