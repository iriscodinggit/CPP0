NAME    = megaphone
C+	    = c++
CFLAG   = -Wall -Werror -Wextra -std=c++98
RM      = rm -rf
SOURCES = megaphone.cpp
OBJECTS = $(SOURCES:%.cpp=%.o)
PINK = \033[38;5;218m

%.o: %.cpp
	@$(C+) $(CFLAG) -c $< -o $@

$(NAME): $(OBJECTS)
	@$(C+) $(CFLAG) $(OBJECTS) -o $(NAME)
	@echo "$(PINK)📣 Megaphone compiled! Usage -> ./megaphone [your text]"

clean : 
	@$(RM) $(OBJECTS)
	@echo "$(PINK) Objects removed 🧹"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(PINK) Project cleaned 🧹"

all : $(NAME)

re: fclean all

.PHONY: clean all re fclean