CXX = g++
CXXFLAGS = -Wall -pedantic
OBJECTS = Main.o Board.o Move.o Humanplayer.o KI.o Grafik.o Graphicobserver.o TournamentPlayer.o IPv4TCPSocket.o Position.o
#OBJECTS = Main.o Observer.o Board.o Move.o Humanplayer.o KI.o Grafik.o Graphicobserver.o TournamentPlayer.o IPv4TCPSocket.o Position.o
UNIXBINARY = Main.out
WINBINARY = Main.exe

SRCS = Main.cpp Board.cpp Move.cpp Humanplayer.cpp KI.cpp Graphicobserver.cpp TournamentPlayer.cpp IPv4TCPSocket.cpp Position.cpp
#SRCS = Main.cpp Observer.cpp Board.cpp Move.cpp  Humanplayer.cpp KI.cpp Grafik.cpp Graphicobserver.cpp TournamentPlayer.cpp IPv4TCPSocket.cpp Positon.cpp
CFLAGS = -O -DHACK -I../foobar -xyz

all: unixprogram

win: winprogram

unixprogram: $(OBJECTS) Makefile
	$(CXX) $(CXXFLAGS) -o $(UNIXBINARY) $(OBJECTS) -lSDL -lSDL_image

winprogram: $(OBJECTS) Makefile
	$(CXX) $(CXXFLAGS) -o $(WINBINARY) $(OBJECTS) -lSDL -lSDL_image

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

depend:
	makedepend -- $(CFLAGS) -- $(SRCS)

doc:
	doxygen

.PHONY: clean
clean:
	-rm –f $(OBJECTS) $(BINARY)
	-rm –f *~ *.bak
	-rm -r ./html/
# Minus sorgt dafür, dass auch bei einem Fehler
# (z.B. File not found) nicht abgebrochen wird# DO NOT DELETE

# DO NOT DELETE THIS LINE -- make depend depends on it.

Main.o: Move.hh Board.hh Player.hh Humanplayer.hh KI.hh Grafik.hh Graphicobserver.hh TournamentPlayer.hh
Board.o: Board.hh Move.hh Position.hh
Move.o: Move.hh
Humanplayer.o: Humanplayer.hh Player.hh Move.hh Board.hh
KI.o: KI.hh Player.hh Move.hh Board.hh
randKI.o: randKI.hh Player.hh Move.hh Board.hh
