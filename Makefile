SRCDIRS = src
TEST_SRCDIRS = test
INCDIRS = include
BUILDDIR = build

CC = gcc
AR = ar
FLAGS = -Wall -Wextra -Werror $(foreach D, $(INCDIRS), -I$(D))

SRCS = $(foreach D, $(SRCDIRS), $(wildcard $(D)/*.c))
OBJS = $(patsubst %.c, %.o, $(SRCS))

TEST_SRCS = $(foreach D, $(TEST_SRCDIRS), $(wildcard $(D)/*.c))
TEST_OBJS = $(patsubst %.c, %.o, $(TEST_SRCS))

NAME = hashtable
LIB = $(BUILDDIR)/lib$(NAME).a

all: $(LIB)

$(LIB): $(OBJS) | $(BUILDDIR)
	$(AR) rcs $@ $^

$(BUILDDIR):
	mkdir -p $@

test: $(LIB) $(TEST_OBJS) | $(BUILDDIR)
	$(CC) $^ -L. -L$(BUILDDIR) -l$(NAME) -lcriterion -o $(BUILDDIR)/test

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(LIB)
	rm -rf $(BUILDDIR)/test

.PHONY: all test clean fclean
