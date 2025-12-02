#include <fcntl.h>
#include <stddef.h>
#include "advent.h"
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

ids_range_t *parse_ranges(char *buffer)
{
    ids_range_t *ids_range = NULL;
    char **ranges = split_string(buffer, ",-\n");
    int ranges_len = 0;
    int range_index = 0;

    for (int i = 0; ranges[i] != NULL; i++) {
        ranges_len += 1;
    }
    if (ranges_len % 2 != 0)
        return NULL;
    ids_range = malloc(sizeof(ids_range_t) * (ranges_len / 2 + 1));
    for (int i = 0; ranges[i] != NULL; i++) {
        ids_range[range_index].start = atoll(ranges[i]);
        ids_range[range_index].end = atoll(ranges[i + 1]);
        range_index += 1;
        i += 1;
    }
    ids_range[range_index].start = -1;
    ids_range[range_index].end = -1;
    return ids_range;
}

ids_range_t *get_ids_range_from_file(char *filepath)
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
    return parse_ranges(buff);
}


long long get_code(ids_range_t *ids_range)
{
    long long sum = 0;
    char *first_half = 0;
    char *second_half = 0;
    char buffer[200];
    int buffer_len = 0;

    for (int i = 0; ids_range[i].start != -1; i++) {
        for (long j = ids_range[i].start; j <= ids_range[i].end; j++) {
            snprintf(buffer, sizeof(buffer), "%lld", j);
            buffer_len = strlen(buffer);
            if (buffer_len % 2 != 0)
                continue;
            first_half = strndup(buffer, buffer_len / 2);
            second_half = strdup(&buffer[buffer_len / 2]);
            if (strcmp(first_half, second_half) == 0) {
                sum += j;
            }
            free(first_half);
            free(second_half);
        }
    }
    return sum;
}

int main(int argc, char **argv)
{
    ids_range_t *ids_range = NULL;
    long long code = 0;

    if (argc != 2)
        return 1;
    ids_range = get_ids_range_from_file(argv[1]);
    if (ids_range == NULL)
        return 1;
    code = get_code(ids_range);
    printf("Code: %lld\n", code);
    free(ids_range);
    return 0;
}
