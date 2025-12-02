#ifndef ADVENT_H
    #define ADVENT_H

char **split_string(char *str, char *delim);

typedef struct ids_range_s {
    long long start;
    long long end;
} ids_range_t;

#endif /* !ADVENT_H */
