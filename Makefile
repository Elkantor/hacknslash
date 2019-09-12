windows:
	gcc -Wall src/main.c -L./libs/windows -I./src/extern -lraylib -lopengl32 -lgdi32 -lwinmm

