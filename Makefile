CC = g++
CPPFLAGS = -Wall -Werror -pedantic
DIST = ./bin
PROG_NAME = ./tntwizard

LIBS = -L/usr/lib
LIBS += -I/usr/include 

OBJECTS = \
./src/tntwizard.o \
./src/CrontollerCreator.o \
./src/ViewCreator.o \


all: dist
	##################### dist #######################


dist: $(PROG_NAME)
	############################## Start ##############################
	if [ ! -d $(DIST) ]; then mkdir $(DIST) ; fi
	mv ./$(PROG_NAME) $(DIST)
	cp ./GPLv3.txt $(DIST)
	cp ./README.md $(DIST)


$(PROG_NAME): $(OBJECTS)
	LANG=C LC_ALL=C $(CC) $(CPPFLAGS) -o $(PROG_NAME) $(OBJECTS) $(LIBS)	

clean:
	rm  $(OBJECTS)
	rm -Rvf $(DIST)

.PHONY: dist clean