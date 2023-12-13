#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>

char *_strtok(char *str, const char *delim);
void handle_error(int err_value, char *filename);
int _strlen(char *str);
void cc_input_exit(char *i_b, ssize_t b_r);
int loop_for(char *str, char delim);
char **tokenize(char *input_buf);
int is_valid_path(char *command, char **path, char **env);
void sfree_memory(char *mem_address);
void dfree_memory(char **mem_address, int size);

#endif
