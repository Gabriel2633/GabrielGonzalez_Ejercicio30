all: datos.dat CINCO.gif

%.gif: %.dat CINCO.gif 
	python3 ya.py

%.dat: a.out
	./a.out

a.out: vacas.cpp
	g++ vacas.cpp 

clean:
	rm -rf *.x *.dat *.png
