CFLAGS=-g

clean: 
	rm newLinkedListOutput

linkedList: linkedListOutput
	./linkedListOutput

linkedListOutput: linkedList.c
	gcc $(CFLAGS) linkedList.c -o linkedListOutput


newLinkedList: newLinkedListOutput
	./newLinkedListOutput

newLinkedListOutput:
	gcc $(CFLAGS) newLinkedList.c -o newLinkedListOutput

reverseLinkedList:
	gcc reverseLinkedList.c -o build/reverseLinkedList && ./build/reverseLinkedList