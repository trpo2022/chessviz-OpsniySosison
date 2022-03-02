
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -MMD

MAIN = src/main/main.cpp
CHESSVIZ = src/lib/chessviz.cpp
PARSER = src/lib/parser.cpp

COMPILE = main.o chessviz.o parser.o

master: $(COMPILE)
	g++ $(COMPILE) -o $@ 
main.o: $(MAIN)
	g++ -c $(CFLAGS) $(CPPFLAGS) -o $@ $(MAIN)
chessviz.o: $(CHESSVIZ)
	g++ -c $(CFLAGS) $(CPPFLAGS) -o $@ $(CHESSVIZ)
parser.o: $(PARSER)
	g++ -c $(CFLAGS) $(CPPFLAGS) -o $@ $(PARSER)

-include parser.d chessviz.d main.d