CPPFLAGS= -ansi -pedantic -Wall -std=c++11 -g

analog : Analog.o LectureLog.o Noeud.o Graph.o
	@echo "edl de Analog"
	g++ -o $@ $^

%.o : %.cpp %.h
	@echo "compil de $<"
	g++ -c $< $(CPPFLAGS)


clean : 
	clear
	clear
	@echo "suppresion des fichiers compilés existants"
	touch t.o
	rm *.o
	make