all: main.c
	gcc -o random_file_generator main.c
run: all
	./random_file_generator