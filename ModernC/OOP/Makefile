#Makefile by AtsushiSakai
OOP : OOP.o Person.o
				g++ -o OOP OOP.o Person.o

OOP.o : OOP.c
				g++ -Wall -c ./OOP.c

Person.o : Person.c Person.h
				g++ -c Person.c

clean :
				rm OOP.o Person.o OOP
