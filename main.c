
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    // int fd = 0;
    char *line;
    int i;

    i = 1;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("LINE %d: %s", i++, line);
        free(line);
    }
    close(fd);
    return 0;
}

/* 
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

int main(void)
{
    int fd1 = open("test1.txt", O_RDONLY);
    int fd2 = open("test2.txt", O_RDONLY);
    int fd3 = open("test3.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        perror("open");
        return 1;
    }

    char *line;
    int i = 1;
    while (1)
    {
        line = get_next_line(fd1);
        if (line)
        {
            printf("FD1 LINE %d: %s", i++, line);
            free(line);
        }

        line = get_next_line(fd2);
        if (line)
        {
            printf("FD2 LINE %d: %s", i++, line);
            free(line);
        }

        line = get_next_line(fd3);
        if (line)
        {
            printf("FD3 LINE %d: %s", i++, line);
            free(line);
        }
        if (!line && !get_next_line(fd1) && !get_next_line(fd2) && !get_next_line(fd3))
            break;
    }

    close(fd1);
    close(fd2);
    close(fd3);
    return 0;
} */
/* 
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

int main(void)
{
    int fd1 = open("test1.txt", O_RDONLY);
    int fd2 = open("test2.txt", O_RDONLY);
    int fd3 = open("test3.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        perror("open");
        return 1;
    }

    char *line;
    int i = 1;

    while ((line = get_next_line(fd1)) != NULL)
    {
        printf("FD1 LINE %d: %s", i++, line);
        free(line);
    }


    while ((line = get_next_line(fd2)) != NULL)
    {
        printf("FD2 LINE %d: %s", i++, line);
        free(line);
    }

    while ((line = get_next_line(fd3)) != NULL)
    {
        printf("FD3 LINE %d: %s", i++, line);
        free(line);
    }

    close(fd1);
    close(fd2);
    close(fd3);

    return 0;
} */

