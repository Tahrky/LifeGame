
CPP_FLAGS := -std=c++11 -Wall
LD_FLAGS := -lsfml-graphics -lsfml-window -lsfml-system

TestSFML : TestSFML.o Fenetre.o Tamagotchi.o SceneNode.o Possesseur.o Jauge.o Session.o 
	g++ $^ -o $@ ${LD_FLAGS}

-include $(shell find . -name "*.d")

%.o : %.cpp
	g++ $< -MM -MF $(patsubst %.cpp,%.d,$<) -MT $@
	g++ $< -c ${CPP_FLAGS}

run.% : %
	./$<

clean :
	rm -f *.o
	rm -f *.d

cleanAll :
	rm -f *.o
	rm -f *.d
	rm -f TestSFML

