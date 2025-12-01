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

int number_of_zero_left(int dial, int subtrahend, int *dial_zero_count)
{
    for (int i = 0; i < subtrahend; i++) {
        dial -= 1;
        if (dial == -1) {
            dial = 99;
        }
        if (dial == 0) {
            *dial_zero_count += 1;
        }
    }
    return dial;
}

int number_of_zero_right(int dial, int addend, int *dial_zero_count)
{
    for (int i = 0; i < addend; i++) {
        dial += 1;
        if (dial == 100) {
            dial = 0;
        }
        if (dial == 0) {
            *dial_zero_count += 1;
        }
    }
    return dial;
}
int get_code(char **combinations)
{
    int dial_zero_count = 0;
    int dial = 50;
    char direction = 'N';
    int tmp = 0;

    for (int i = 0; combinations[i] != NULL; ++i) {
        direction = combinations[i][0];
        if (direction == 'L') {
            dial = number_of_zero_left(dial, atoi(&combinations[i][1]), &dial_zero_count);
        } else if (direction == 'R') {
            dial = number_of_zero_right(dial, atoi(&combinations[i][1]), &dial_zero_count);
        } else
            return -1;
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
