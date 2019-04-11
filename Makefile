f = -lSDL -lSDL_image -lSDL_mixer 

prog: fonctions.o Menu.o
	gcc fonctions.o Menu.c -o prog $(f)
Menu.o: Menu.c fonctions.h
	gcc -c Menu.c fonctions.h $(f)
fonctions.o:fonctions.c fonctions.h
	gcc -c fonctions.c fonctions.h $(f)


clean:
	rm *.o *.h.gch prog
