CC := gcc

.PHONY: clean

eliza: data.h eliza.c
	$(CC) -o eliza eliza.c

clean:
	rm eliza