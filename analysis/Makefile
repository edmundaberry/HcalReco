COMP=g++
FLAGS = -g
ROOTINC= -I`root-config --incdir`
ROOTLIBS=  `root-config --glibs --cflags | sed 's/-pthread//g'` -lMinuit 
INC= -I./include 
LIBS= ${ROOTLIBS} 
SRC= ./src
OBJECTS=$(SRC)/analysisClass.o $(SRC)/baseClass.o $(SRC)/Cell.o $(SRC)/fitResults.o
TREES=$(SRC)/HcalNoiseTree.o 

default: main

main: $(SRC)/main.o $(OBJECTS) $(TREES)
	$(COMP) $(INC) $(ROOTINC) $(LIBS) $(FLAGS) $(CFLAGS) -o $@ $(OBJECTS) $(TREES) $(SRC)/$@.o

.cc.o:
	$(COMP) -c $(INC) $(ROOTINC) $(FLAGS) $(CFLAGS) -o $@ $<

.C.o:
	$(COMP) -c $(INC) $(ROOTINC) $(FLAGS) $(CFLAGS) -o $@ $<

clean:
	rm -rf main
	rm -rf $(SRC)/*.o

