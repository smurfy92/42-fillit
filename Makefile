# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/28 14:03:26 by jtranchi          #+#    #+#              #
#    Updated: 2016/02/04 02:10:57 by jtranchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB = inc/libft/libft.a
SRC =	src/clean.c \
		src/fillit.c \
		src/main.c \
		src/map.c \
		src/read.c
OBJ = $(SRC:.c=.o)
FLAG = -Wall -Werror -Wextra
CG = \033[92m
CY =  \033[93m
CE = \033[0m
CB = \033[34m

all: start $(NAME)

$(NAME): $(OBJ)
	@echo "$(CY)[FILLIT] :$(CE) $(CG)Creating Library$(CE)";
	-@make -C inc/libft nohd
	@echo "$(CY)[FILLIT] :$(CE) $(CG)Compiling fillit ...$(CE)";
	@gcc -o $(NAME) $(FLAG) $(SRC) $(LIB)

start:
	@echo "\n\n"
	@echo "						$(CG)		           ¶¶¶¶¶¶¶¶¶¶¶              $(CE)";
	@echo "						$(CG)		         ¶¶           ¶¶            $(CE)";
	@echo "						$(CG)		       ¶¶               ¶¶          $(CE)";
	@echo "						$(CG)		     ¶¶      $(CY)¶¶$(CE)    $(CY)¶¶$(CE)     $(CG)¶¶        $(CE)";
	@echo "						$(CG)		   ¶¶       $(CY)¶¶$(CE)    $(CY)¶¶$(CE)        $(CG)¶¶      $(CE)";
	@echo "						$(CG)		 ¶¶          $(CY)¶¶$(CE)    $(CY)¶¶$(CE)         $(CG)¶¶    $(CE)";
	@echo "						$(CG)		¶¶                             ¶¶   $(CE)";
	@echo "						$(CG)		¶¶                             ¶¶ $(CE)";
	@echo "						$(CG)		¶¶     $(CY)¶¶$(CE)              $(CY)¶¶$(CE)      $(CG)¶¶ $(CE)";
	@echo "						$(CG)		¶¶      $(CY)¶¶$(CE)            $(CY)¶¶$(CE)       $(CG)¶¶ $(CE)";
	@echo "						$(CG)		¶¶       $(CY)¶¶$(CE)         $(CY)¶¶$(CE)         $(CG)¶¶   $(CE)";
	@echo "						$(CG)		 ¶¶         $(CY)¶¶¶¶¶¶¶$(CE)           $(CG)¶¶    $(CE)";
	@echo "						$(CG)		   ¶¶                        ¶¶     $(CE)";
	@echo "						$(CG)		     ¶¶                    ¶¶       $(CE)";
	@echo "						$(CG)		       ¶¶                ¶¶         $(CE)";
	@echo "						$(CG)		         ¶¶            ¶¶           $(CE)";
	@echo "						$(CG)		           ¶¶¶¶¶¶¶¶¶¶¶¶             $(CE)";
	@echo "\n\n"
	@echo "						$(CY) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -$(CE)";
	@echo "						$(CY)|$(CE)$(CG)     _______ _________ _        _       __________________     $(CE)$(CY)|$(CE)";
	@echo "						$(CY)|$(CE)$(CG)    (  ____ \\__   __/(  \      ( \      \__   __/\__   __/     $(CE)$(CY)|$(CE)";
	@echo "						$(CY)|$(CE)$(CG)    | (    \/   ) (   | (      | (         ) (      ) (        $(CE)$(CY)|$(CE)";
	@echo "						$(CY)|$(CE)$(CG)    | (__       | |   | |      | |         | |      | |        $(CE)$(CY)|$(CE)";
	@echo "						$(CY)|$(CE)$(CG)    |  __)      | |   | |      | |         | |      | |        $(CE)$(CY)|$(CE)";
	@echo "						$(CY)|$(CE)$(CG)    | (         | |   | |      | |         | |      | |        $(CE)$(CY)|$(CE)";
	@echo "						$(CY)|$(CE)$(CG)    | )      ___) (___| (____/\| (____/\___) (___   | |        $(CE)$(CY)|$(CE)";
	@echo "						$(CY)|$(CE)$(CG)    |/       \_______/(_______/(_______/\_______/   )_(        $(CE)$(CY)|$(CE)";
	@echo "						$(CY) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -$(CE)";

%.o: %.c
	@echo "$(CY)[FILLIT] :$(CE) $(CG)Compiling $<$(CE)";
	@gcc $(FLAG) -c $< -o $@

clean: start
	@echo "$(CY)[FILLIT] :$(CE) $(CG)Cleaning Library ...$(CE)";
	-@make -C inc/libft nohdclean
	@echo "$(CY)[FILLIT] :$(CE) $(CG)Cleaning fillit objects$(CE)";
	@/bin/rm -rf $(OBJ)

fclean: clean
	@echo "$(CY)[FILLIT] :$(CE) $(CG)FCleaning Library ...$(CE)";
	-@make -C inc/libft nohdfclean
	@echo "$(CY)[FILLIT] :$(CE) $(CG)Cleaning fillit ...$(CE)";
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
