windows:
	gcc -Wall --std=c99 src/main.c -L./libs/windows -I./src/extern -mwindows -lopengl32 -lgdi32 -lraylib -lwinmm 

## FOR HOT RELOAD ON WINDOWS ##
timestamp := $(shell date +%s)
module := $(module)
windows_hr:
	rm -rf ${module}*.dll ${logging}.o
	gcc -c ./src/modules/${module}.c -Dmodule_${module}_build_dll -o ${module}.o
	gcc -shared ${module}.o -o ${module}${timestamp}.dll
