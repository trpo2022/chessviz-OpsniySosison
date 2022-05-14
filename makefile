
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

FILEFLAG_TEST = -I ./

COMPILE_TEST = obj/test/main/main_test.o obj/test/lib/chessviz_test.o obj/src/lib/chessviz.o obj/test/lib/parser_test.o obj/src/lib/parser.o
MAIN_TEST = test/main_test.cpp
CHESSVIZ_TEST = test/chessviz_test.cpp
PARSER_TEST = test/parser_test.cpp

utest: $(COMPILE_TEST)
	g++ $(COMPILE_TEST) -o $@ 
obj/test/main/main_test.o: $(MAIN_TEST)
	g++ -c $(FILEFLAG_TEST) $(CFLAGS) $(CPPFLAGS) -o $@ $(MAIN_TEST)
obj/test/lib/chessviz_test.o: $(CHESSVIZ_TEST)
	g++ -c $(FILEFLAG_TEST) $(CFLAGS) $(CPPFLAGS) -o $@ $(CHESSVIZ_TEST)
obj/test/lib/parser_test.o: $(PARSER_TEST)
	g++ -c $(FILEFLAG_TEST) $(CFLAGS) $(CPPFLAGS) -o $@ $(PARSER_TEST)

-include chessviz_test.d parser_test.d main_test.d