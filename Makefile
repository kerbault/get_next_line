# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: kerbault <kerbault@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/22 21:55:44 by kerbault     #+#   ##    ##    #+#        #
#    Updated: 2018/04/24 16:29:00 by kerbault    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

SHELL		:= /bin/bash

#### System configuration section ####

NAME		:= get_next_line
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
AR			:= ar
ARFLAGS		:= rc
RANLIB		:= ranlib
MKDIR		:= mkdir
MKDIRFLAGS	:= -p
RM			:= /bin/rm
RMFLAGS		:= -rf
ECHO		:= echo
QUIET		:= @
NORM		:= norminette

#### Libraries def section ####

LIBFTDIR	:= libft
LIBFT		:= ft

#### Files definition section ####

INCLUDESDIR	:= inc
INCLUDES	:= \
	-I$(INCLUDESDIR)/ \
	-I$(LIBFTDIR)/$(INCLUDESDIR)
SRCDIR		:= src
SRCS		:= \
	maintest.c \
	get_next_line.c
OBJDIR		:= obj
OBJS		:= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

#### Linking configuration section ####

LDIBRARIES	:= -L$(LIBFTDIR)/ -l$(LIBFT)

#### Rules section ####

.PHONY: all clean fclean re norm gpush

all: $(NAME)

$(NAME): $(LIBFTDIR)/libft.a $(OBJDIR) $(OBJS)
	$(QUIET)$(ECHO) "Creating the executable"
	$(QUIET)$(CC) $(CCFLAGS) $(LDIBRARIES) $(OBJS) -o $@
	$(QUIET)$(ECHO) "Done"

$(OBJDIR):
	$(QUIET)$(MKDIR) $(MKDIRFLAGS) $(OBJDIR)

$(LIBFTDIR)/libft.a:
	$(QUIET)$(ECHO) "Creating the lib"
	$(QUIET)$(MAKE) -C $(LIBFTDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(QUIET)$(ECHO) "Compiling $<"
	$(QUIET)$(CC) $(CFLAGS) -I$(INCLUDESDIR) -c $< -o $@

clean:
	$(QUIET)$(ECHO) "Cleaning the objects"
	$(QUIET)$(RM) $(RMFLAGS) $(OBJS)

fclean: clean
	$(QUIET)$(ECHO) "Deleting the library"
	$(QUIET)$(RM) $(RMFLAGS) $(NAME) $(OBJDIR)

re: fclean all

norm:
	$(QUIET)$(ECHO) "Checking norm 101"
	$(QUIET)$(NORM) $(SRCDIR)/$(SRC) $(INCLUDESDIR)/*.h

gpush: fclean
	$(QUIET) git add *
	$(QUIET) git commit -m "quick push"
	$(QUIET) git push
