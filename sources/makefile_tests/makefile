CC = cc
# compiler
RM = rm -rf
# used to delete files permanetly
CFILES = main.c hello.c bye.c
# resource c files to use
CFLAGS = -Wall -Werror -Wextra
# FLAGS used to compile
OFILES = $(CFILES:.c=.o)
# variable OFILES corresponds to the variable CFILES with the suffix of its files changed to .o
NAME = project
# the name of the final executable

all: $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)
# the target all relies on the prerequisite OFILES
# once the object files are made they are linked into the final executable
# the CFLAGS are used during compilation
# -o specifies the output file name

%.o: %.c
	$(CC) -c $<
# a pattern rule for making the OFILES
# every .c file is made into a corresponding .o file
# are compiled with cc
# -c tells the compiler to compile each .c file into an object file without linking
# $< is an automaitc variable that is a placeholder for the different CFILES

clean:
	$(RM) $(OFILES)
# uses the RM variable to delete all object files permanetly

fclean: clean
	$(RM) $(NAME)
# is dependent on the clean rule
# once it has been executed it deletes the final exectuable

re: fclean
	$(MAKE) all
# is dependent on fclean
# once fclean has been executed it makes all