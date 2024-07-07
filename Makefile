#######################################################
# VARS     	 										  #
#######################################################
NAME = philosophers

CC = cc

#CFLAGS = -Wall -Wextra -Werror

#######################################################
# MANDATORY     									  #
#######################################################
SOURCES = philosophers.c philosophers_utils_1.c philosophers_utils_2.c

OBJECTS = $(SOURCES:.c=.o)

#######################################################
# OPERATIONS 										  #
#######################################################
$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all