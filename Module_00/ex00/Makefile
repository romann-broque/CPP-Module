###############
#### SHELL ####
###############

SHELL		= /usr/bin/bash

##############
#### SRCS ####
##############

### srcs/

SRCS		+= megaphone.cpp

##############
#### OBJS ####
##############

PATH_OBJS	+= objs/
OBJS		+= $(patsubst %.cpp, $(PATH_OBJS)/%.o, $(SRCS))

#####################
#### COMPILATION ####
#####################

CC			=	g++

CFLAGS		+=	-Wall
CFLAGS		+=	-Wextra
CFLAGS		+=	-std=c++98

ifneq ($(no_error), true)
	CFLAGS		+=	-Werror
endif

ifeq ($(debug), true)
	CFLAGS	+= -fsanitize=undefined,thread
endif

##############
#### NAME ####
##############

NAME		+= megaphone

#################
#### DISPLAY ####
#################

RED='\033[0;31m'
GREEN='\033[1;32m'
ORANGE='\033[0;33m'
YELLOW='\033[1;33m'
BLUE='\033[1;36m'
NC='\033[0m' # No Color

ifndef ECHO
T := $(words $(SRCS))
N := x
C = $(words $N)$(eval N := x $N)

ECHOC = echo -ne "\r\033[2K"
ECHO = $(ECHOC) $(ORANGE) "[`expr $C '*' 100 / $T`%]"
endif

###############

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	$(ECHOC) $(GREEN) "--> $(NAME) COMPILED !"$(NC)"\n\n"

$(OBJS) : $(PATH_OBJS)/%.o: %.cpp Makefile
	$(ECHO) $(ORANGE) "Compiling $<"
	mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

run : all
	$(ECHOC) $(GREEN) "RUNNING $(NAME)"$(NC)"\n\n"
	./$(NAME)

clean	:
	$(RM) -r $(PATH_OBJS)
	$(ECHOC) $(GREEN) "--> .o files deleted !"$(NC)"\n"

fclean	:	clean
	$(ECHOC) $(YELLOW) "Cleaning up $(NAME)..." $(NC)
	$(RM) $(NAME)
	$(ECHOC) $(GREEN) "--> $(NAME) deleted !"$(NC)"\n"

re 		: fclean
	echo -e $(YELLOW) "\nRebuilding..." $(NC)
	$(MAKE) -s

.PHONY	: all run clean fclean re
.SILENT	:
