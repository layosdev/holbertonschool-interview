#ifndef SLIDELINE_H
#define SLIDELINE_H

#include <stdlib.h>
#include <stdio.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);
void to_left(int *line, size_t size);
void to_right(int *line, size_t size);

#endif /* LISTS_H */