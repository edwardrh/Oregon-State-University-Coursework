WRITEUP=final

all:
	make tex 
	
main.o: main.c
	g++ -c main.c
	
tex:
	latex $(WRITEUP).tex
	dvips $(WRITEUP).dvi
	ps2pdf $(WRITEUP).ps
	cp -f $(WRITEUP).pdf ~/public_html
	chmod a+r ~/public_html/$(WRITEUP).pdf

clean:
	rm -f *.out *.log *.dvi *.aux *.ps *.pdf *.blg *.bbl
	