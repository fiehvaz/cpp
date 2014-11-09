#Makefile by AtsushiSakai
OOP : OOP.o Person.o Dog.o
				g++ -o OOP OOP.o Person.o Dog.o

OOP.o : OOP.c
				g++ -Wall -c ./OOP.c

Person.o : Person.c Person.h
				g++ -c Person.c

Dog.o : Dog.c Dog.h
				g++ -c Dog.c

clean :
				rm OOP.o Person.o OOP
