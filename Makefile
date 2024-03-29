# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 10:10:32 by jprofit           #+#    #+#              #
#    Updated: 2023/01/16 17:58:33 by jprofit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# ARGUMENTS

NAME	=	minitalk

FLAGS	=	-Wall -Wextra -Werror -g

HEADERS	=	minitalk.h

INCLUDES=	$(addprefix includes/, ${HEADERS})

SRCFILE1=	server.c chained_list_op.c	chained_list_op2.c

SRCS1	=	$(addprefix src/, ${SRCFILE1})

OBJS1	=	$(SRCS1:.c=.o)

SRCFILE2=	client.c

SRCS2	=	$(addprefix src/, ${SRCFILE2})

OBJS2	=	$(SRCS2:.c=.o)

LIBDIR	=	libft/

LIB		= 	libft.a

LIBFULL	=	$(addprefix $(LIBDIR), $(LIB))

LIBSHORT=	$(LIB:lib%.a=%)

EXEC1	=	server

EXEC2	=	client

# **************************************************************************** #
# RULES

all: 			${NAME}

libft:
				@$(MAKE) -C $(LIBDIR)

${NAME}:		libft $(EXEC1) $(EXEC2)

$(EXEC1):		$(OBJS1)
				$(CC) ${FLAGS} -L ${LIBDIR} -l${LIBSHORT} ${OBJS1} -o $(EXEC1)

$(EXEC2):		$(OBJS2)
				$(CC) ${FLAGS} -L ${LIBDIR} -l${LIBSHORT} ${OBJS2} -o $(EXEC2)

%.o:			%.c ${INCLUDES} Makefile ${LIBFULL}
				${CC} ${FLAGS} -c $< -o $@

clean:
				$(MAKE) clean -C $(LIBDIR)
				$(RM) ${OBJS1} ${OBJS2}

fclean:			clean
				$(MAKE) fclean -C $(LIBDIR)
				$(RM) ${EXEC1} ${EXEC2}

re:				fclean
				$(MAKE) all

debug:
				echo $(EXEC1) $(OBJS1)
				echo $(EXEC2) $(OBJS2)

.PHONY:			all libft clean fclean re
