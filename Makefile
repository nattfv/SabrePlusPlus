CC=g++
FLAGS=-Wall -pedantic -pthread -std=c++11
CFLAGS=$(FLAGS) -c
VARS=-DBOARD_PATH="\"./board/board.dat\"" -DTILEBAG_PATH="\"./tilebag/bag.dat\"" -DDICT_PATH="\"./dict/dict.dat\""
SRCDIR=src
OBJECTS=Board.o Field.o Player.o SabreController.o SabreTerminalView.o SabreView.o Dictionary.o Move.o TileBag.o Tile.o SabreException.o

all: Sabre++

Sabre++: $(OBJECTS)
	$(CC) $(FLAGS) $(VARS) -o Sabre++ $(SRCDIR)/Sabre++.cpp $(OBJECTS)
	cp *.o Sabre++ bin/
	rm *.o Sabre++

Board.o:
	$(CC) $(CFLAGS) $(SRCDIR)/Board.cpp

Field.o:
	$(CC) $(CFLAGS) $(SRCDIR)/Field.cpp

Player.o:
	$(CC) $(CFLAGS) $(SRCDIR)/Player.cpp

SabreController.o:
	$(CC) $(CFLAGS) $(SRCDIR)/SabreController.cpp

SabreTerminalView.o:
	$(CC) $(CFLAGS) $(SRCDIR)/SabreTerminalView.cpp

SabreView.o:
	$(CC) $(CFLAGS) $(SRCDIR)/SabreView.cpp

Dictionary.o:
	$(CC) $(CFLAGS) $(SRCDIR)/Dictionary.cpp

Move.o:
	$(CC) $(CFLAGS) $(SRCDIR)/Move.cpp

TileBag.o:
	$(CC) $(CFLAGS) $(SRCDIR)/TileBag.cpp

Tile.o:
	$(CC) $(CFLAGS) $(SRCDIR)/Tile.cpp

SabreException.o:
	$(CC) $(CFLAGS) $(SRCDIR)/SabreException.cpp

.PHONY clean:
	rm bin/*.o bin/Sabre++
