windows:
	gcc -Wall --std=c99 src/main.c -L./libs/windows -I./src/extern -mwindows -lopengl32 -lgdi32 -lraylib -lwinmm 
