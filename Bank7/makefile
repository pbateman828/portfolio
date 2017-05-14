CC= g++
CCFLAGS= -g -Wall

exec: main.o Customer.o Manager.o myBank.o Teller.o GodTeller.o BTeller.o makefile
	$(CC) $(CCFLAGS) -o Report main.o Customer.o Manager.o myBank.o Teller.o GodTeller.o BTeller.o

main.o: main.C Customer.h Manager.h Item.h myBank.h Teller.h GodTeller.h BTeller.h
	$(CC) $(CCFLAGS) -c main.C

Customer.o: Customer.C Customer.h
	$(CC) $(CCFLAGS) -c Customer.C

Manager.o: Manager.C Manager.h
	$(CC) $(CCFLAGS) -c Manager.C

myBank.o: myBank.C myBank.h
	$(CC) $(CCFLAGS) -c myBank.C

Teller.o: Teller.C Teller.h
	$(CC) $(CCFLAGS) -c Teller.C

GodTeller.o: GodTeller.C GodTeller.h Teller.h
	$(CC) $(CCFLAGS) -c GodTeller.C

BTeller.o: BTeller.C BTeller.h Teller.h
	$(CC) $(CCFLAGS) -c BTeller.C
clean:
	rm -rf *.o
	rm -rf Report*

