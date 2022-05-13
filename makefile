
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -MMD
FILEFLAG = -I src

MAIN = src/main/main.cpp
CHESSVIZ = src/lib/chessviz.cpp
PARSER = src/lib/parser.cpp

COMPILE = obj/src/main/main.o obj/src/lib/chessviz.o obj/src/lib/parser.o

master: $(COMPILE)
	g++ $(COMPILE) -o $@ 
obj/src/main/main.o: $(MAIN)
	g++ -c $(FILEFLAG) $(CFLAGS) $(CPPFLAGS) -o $@ $(MAIN) 
obj/src/lib/chessviz.o: $(CHESSVIZ)
	g++ -c $(FILEFLAG) $(CFLAGS) $(CPPFLAGS) -o $@ $(CHESSVIZ) 
obj/src/lib/parser.o: $(PARSER)
	g++ -c $(FILEFLAG) $(CFLAGS) $(CPPFLAGS) -o $@ $(PARSER)

-include parser.d chessviz.d main.d

MAIN_TEST = test/main_test.cpp
CHESSVIZ_TEST = test/chessviz_test.cpp src/lib/chessviz.cpp
PARSER_TEST = test/parser_test.cpp src/lib/parser.cpp
FILEFLAG_TEST = -I ./

COMPILE_TEST = obj/test/main/main_test.o 

utest: obj/test/main_test.o obj/test/chessviz_test.o obj/src/lib/chessviz.o
	g++ obj/test/main_test.o obj/test/chessviz_test.o obj/src/lib/chessviz.o -o $@ 
obj/test/main_test.o:
	g++ -c $(FILEFLAG_TEST) $(CFLAGS) $(CPPFLAGS) -o $@ test/main_test.cpp
obj/test/chessviz_test.o:
	g++ -c $(FILEFLAG_TEST) $(CFLAGS) $(CPPFLAGS) -o $@ test/chessviz_test.cpp