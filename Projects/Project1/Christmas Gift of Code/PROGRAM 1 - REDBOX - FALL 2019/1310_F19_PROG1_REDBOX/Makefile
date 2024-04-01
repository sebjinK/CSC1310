#this is a comment

all				:	RedBox

RedBox			:	RedBox.o Movie.o MovieLibrary.o Text.o
					g++ -o RedBox.exe RedBox.o Movie.o MovieLibrary.o Text.o

RedBox.o		:	RedBox.cpp
					g++ -I ./ -c RedBox.cpp
				
Movie.o			:	Movie.cpp
					g++ -I ./ -c Movie.cpp
			
MovieLibrary.o	:	MovieLibrary.cpp
					g++ -I ./ -c MovieLibrary.cpp
			
Text.o			:	Text.cpp
					g++ -I ./ -c Text.cpp

clean			:	RedBox.exe
					del *.o 
					del RedBox.exe