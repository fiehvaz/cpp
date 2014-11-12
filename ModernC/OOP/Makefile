#Makefile by AtsushiSakai
OOP : OOP.o Person.o Dog.o Teacher.o
				g++ -o OOP OOP.o Person.o Dog.o Teacher.o

OOP.o : OOP.c
				g++ -c ./OOP.c

Person.o : Person.c Person.h
				g++ -c Person.c

Dog.o : Dog.c Dog.h
				g++ -c Dog.c

Teacher.o : Teacher.c Teacher.h
				g++ -c Teacher.c

clean :
				rm OOP.o Person.o OOP
