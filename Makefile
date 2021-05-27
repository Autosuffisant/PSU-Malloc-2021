##
## EPITECH PROJECT, 2021
## myMalloc
## File description:
## Makefile
##

CC = gcc

CFLAGS = -Wall -Wextra -g -fPIC

LDFLAGS = -shared

RM = rm -f

TARGET_LIB = libmy_malloc.so

SRCS =	alignment.c \
		my_malloc.c \
		my_calloc.c \
		my_realloc.c \
		my_realloc_array.c \
		my_free.c


OBJS = $(SRCS:.c=.o)

all: ${TARGET_LIB}

$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^

$(SRCS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@

clean:
	$(RM)	*.o

fclean: clean
	$(RM)	$(NAME)
	-${RM} ${TARGET_LIB} ${OBJS}

re: fclean all