# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 10:34:37 by mlaporte          #+#    #+#              #
#    Updated: 2025/04/18 10:34:37 by mlaporte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc
SRCS = main.cpp BitcoinExchange.cpp 
OBJS = $(SRCS:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
INC = BitcoinExchange.hpp

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
