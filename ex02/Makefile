# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 12:16:36 by mlaporte          #+#    #+#              #
#    Updated: 2025/05/02 12:16:36 by mlaporte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe
SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
INC = PmergeMe.hpp

all: $(NAME)

$(NAME): $(OBJS) $(INC)	$(SRCS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp %.hpp
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean	
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
