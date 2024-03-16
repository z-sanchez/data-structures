CFLAGS=-g


linkedList: linkedListOutput
	./linkedListOutput

linkedListOutput: linkedList.c
	gcc $(CFLAGS) linkedList.c -o linkedListOutput
