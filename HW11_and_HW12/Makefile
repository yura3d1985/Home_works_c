all: temp_prog 

temp_prog: temp_main.o temp_api.o 
	gcc -o temp_prog temp_main.o temp_api.o 

temp_main.o: temp_main.c temp_api.h 
	gcc -c -o temp_main.o temp_main.c 

temp_api.o: temp_api.c 
	gcc -c -o temp_api.o temp_api.c 

clean:
	del -rf *.o 
	del -rf temp_prog.exe