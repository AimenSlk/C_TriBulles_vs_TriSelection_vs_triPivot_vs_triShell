usage:
	@echo
	@echo taper \"make all\" pour compiler tous les tris
	@echo ou
	@echo taper \"make triBulles\" pour compiler le tri a bulles
	@echo taper \"make triPivot\" pour compiler le tri rapide
	@echo taper \"make triShell\" pour compiler le tri Shell
	@echo taper \"make triselection\" pour compiler le tri selection
	@echo

all: triBulles triPivot triShell triselection

triBulles: triBulles.o tableau.o
	g++ -g -o triBulles triBulles.o tableau.o -lTPC+2

triBulles.o: triBulles.C tableau.h
	g++ -c -g triBulles.C

triPivot: triPivot.o tableau.o
	g++ -g -o triPivot triPivot.o tableau.o -lTPC+2

triPivot.o: triPivot.C tableau.h
	g++ -c -g triPivot.C

triShell: triShell.o tableau.o
	g++ -g -o triShell triShell.o tableau.o -lTPC+2

triShell.o: triShell.C tableau.h
	g++ -c -g triShell.C

tableau.o: tableau.C tableau.h
	g++ -c -g tableau.C

triselection.o: triselection.C tableau.h
	g++ -c -g triselection.C

clean:
	rm -f *.o triBulles triPivot triShell

