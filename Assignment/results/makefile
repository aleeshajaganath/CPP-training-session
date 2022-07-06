CC=g++ 
WFLAGS=-Wall 
ODIR=
INCDIR=
_DEPS = symtable.h #dependency .h files
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ= symtable.o main.o#symtable_link.o# testing_symtable.o #graph_cycles_using_dfs1.o # graph_path_using_dfs1.o 
#only one main function will be taken for creating exec file
Exec: $(OBJ) #creates exec file
	$(CC) -o $@ $^ $(WFLAGS)
# %.o: %.c 
$(ODIR)/%.o: %.c $(DEPS)

	$(CC) -o $@ -c $< $(WFLAGS)
.PHONY: cleanv

clean:
	rm -f *.o *~ core *~ 