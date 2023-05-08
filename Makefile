prog: main.o enigme.o image.o buttons.o son.o sonbref.o ennemi.o 
	gcc main.o enigme.o image.o buttons.o son.o sonbref.o ennemi.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g 
main.o:main.c	
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g 
enigme.o:enigme.c 
	gcc -c enigme.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
image.o:image.c 
	gcc -c image.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
buttons.o:buttons.c 
	gcc -c buttons.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
son.o:son.c 
	gcc -c son.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
sonbref.o:sonbref.c 
	gcc -c sonbref.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
ennemi.o: ennemi.c
	gcc -c ennemi.c -g
