NAME    = PhoneBook
CFLAG   = c++ -Wall -Werror -Wextra -std=c++98 #are this flags enough
RM      = rm -rf
OBJDIR  = obj
SOURCES = *.cpp #is this correct?
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

%.o: %.cpp
	@$(C+) $(CFLAG) -c $< -o $@
	@echo "✅ Objects compiled"

$(NAME): $(OBJECTS)
	@$(C+) $(OBJECTS) -o $(NAME)
	@echo "\033[0;32m☎️ Project compiled -> ./PhoneBook"

clean : 
	@$(RM) -r $(OBJDIR)  > /dev/null 2>&1

fclean : clean
	@$(RM) -r $(OBJDIR)  > /dev/null 2>&1
	@$(RM) $(NAME)

all : $(NAME)

re: fclean all

.PHONY: clean all re fclean