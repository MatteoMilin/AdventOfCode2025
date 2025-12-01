#include <fcntl.h>
#include <stddef.h>
#include "advent.h"
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char **get_combination_from_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buff;
    int size = 0;
    struct stat s;

    if (fd == -1) {
        return NULL;
    }
    stat(filepath, &s);
    buff = malloc(sizeof(char) * s.st_size + 1);
    size = read(fd, buff, s.st_size);
    close(fd);
    buff[size] = '\0';
    return split_string(buff, "\n");
}

int get_code(char **combinations)
{
    int dial_zero_count = 0;
    int dial = 50;
    char direction = 'N';

    for (int i = 0; combinations[i] != NULL; ++i) {
        direction = combinations[i][0];
        if (direction == 'L')
            dial = (dial - atoi(&combinations[i][1])) % 100;
        else if (direction == 'R')
            dial = (dial + atoi(&combinations[i][1])) % 100;
        else
            return -1;
        if (dial == 0)
            dial_zero_count += 1;
    }
    return dial_zero_count;
}

int main(int argc, char **argv)
{
    char **combinations = NULL;
    int code = 0;

    if (argc != 2)
        return 1;
    combinations = get_combination_from_file(argv[1]);
    if (combinations == NULL)
        return 1;
    code = get_code(combinations);
    printf("Code: %d\n", code);
    return 0;
}
