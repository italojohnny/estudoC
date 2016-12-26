all: hfcal.o elliptical.o libhfcal.a elliptical

hfcal.o: hfcal.c
	gcc -I./includes -c hfcal.c -o hfcal.o

elliptical.o: elliptical.c hfcal.c
	gcc -I./includes -c elliptical.c -o elliptical.o

libhfcal.a: hfcal.o
	ar -rcs libs/libhfcal.a hfcal.o #esse comando nao funciona :(

elliptical: libs/libhfcal.a elliptical.o
	gcc elliptical.o -L./libs -lhfcal -o elliptical
