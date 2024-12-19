#ifndef WHICH_H
#define WHICH_H

/*
 * File: which.h
 * Description: Header file that contains prototypes functions.
 * This header ensures that the functions can be used in other files by
 * declaring it here, so other source files can include this header
 * and call it.
 */


/**
 * struct list_s - singly linked list
 * @str: string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
char *str;
struct list_s *next;
} list_t;

list_t *chopper(char *string, char *separator);

list_t *add_node_end(list_t **head, const char *str);


#endif
