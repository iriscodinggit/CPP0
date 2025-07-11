NAME    = PhoneBook
CFLAG   = c++ -Wall -Werror -Wextra -std=c++98
RM      = rm -rf
SOURCES = main.cpp Contact.cpp add.cpp search.cpp #are all of them included?
OBJECTS = $(SOURCES:%.cpp=%.o)
PINK = \033[38;5;218m

%.o: %.cpp
	@$(CFLAG) -c $< -o $@

$(NAME): $(OBJECTS)
	@$(CFLAG) $(OBJECTS) -o $(NAME)
	@echo "$(PINK)📞 PhoneBook compiled! Usage -> ./PhoneBook"

clean : 
	@$(RM) $(OBJECTS)
	@echo "$(PINK) Objects removed 🧹"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(PINK) Project cleaned 🧹"

all : $(NAME)

re: fclean all

.PHONY: clean all re fclean