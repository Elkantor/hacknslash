####################################### INFO ###########################################
## Use the raylib 2.6 version, at the ae2452d280a07952529ea82bcc2288d73bc3ccdf commit ##
## To get this raylib version, clone the raylib projet (github.com/raysan5/raylib)    ##
## and rebase onto the commit with this command: 									  ##
## git reabse --onto ae2452d280a07952529ea82bcc2288d73bc3ccdf						  ##
## Then build raylib with its makefile and don't forget to enable PNG format support  ##
## which can be enable by decommented the line inside the config.h file in raylib/src ##
## After that, place the libraylib.a inside the libs/'youros' folder, and enjoy!	  ##
########################################################################################

windows:
	gcc -Wall -std=c99 src/main.c -L./libs/windows -I./src/extern -I./src -mwindows -lopengl32 -lgdi32 -lraylib -lwinmm
