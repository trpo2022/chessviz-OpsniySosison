
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -MMD
FILEFLAG = -I src

MAIN = src/main/main.cpp
CHESSVIZ = src/lib/chessviz.cpp
PARSER = src/lib/parser.cpp

COMPILE = obj/main/main.o obj/lib/chessviz.o obj/lib/parser.o

master: $(COMPILE)
	g++ $(COMPILE) -o $@ 
obj/main/main.o: $(MAIN)
	g++ -c $(FILEFLAG) $(CFLAGS) $(CPPFLAGS) -o $@ $(MAIN) 
obj/lib/chessviz.o: $(CHESSVIZ)
	g++ -c $(FILEFLAG) $(CFLAGS) $(CPPFLAGS) -o $@ $(CHESSVIZ) 
obj/lib/parser.o: $(PARSER)
	g++ -c $(FILEFLAG) $(CFLAGS) $(CPPFLAGS) -o $@ $(PARSER)

-include parser.d chessviz.d main.d