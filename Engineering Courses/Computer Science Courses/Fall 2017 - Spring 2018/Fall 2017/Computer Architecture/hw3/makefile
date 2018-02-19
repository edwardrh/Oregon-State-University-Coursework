WRITEUP=hw3

all:
	make tex main.exe
	
main.exe: main.o
	g++ main.o -o main.exe
main.o: main.c
	g++ -c main.c
	
tex:
	latex $(WRITEUP).tex
	dvips $(WRITEUP).dvi
	ps2pdf $(WRITEUP).ps
	cp -f $(WRITEUP).pdf ~/public_html
	chmod a+r ~/public_html/$(WRITEUP).pdf

clean:
	rm -f *.out *.log *.dvi *.aux *.ps *.pdf *.o *.blg *.bbl *.exe
	