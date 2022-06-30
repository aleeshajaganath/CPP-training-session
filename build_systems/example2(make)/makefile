### reference https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

CC=g++ 
WFLAGS=-Wall 
ODIR=include
INCDIR=src
_DEPS = graph_path_using_dfs1.h #dependency .h files
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ=graph_path_using_dfs1.o #graph_cycles_using_dfs1.o # graph_path_using_dfs1.o 
#only one main function will be taken for creating exec file
Exec: $(OBJ) #creates exec file
	$(CC) -o $@ $^ $(WFLAGS)
# %.o: %.c 
$(ODIR)/%.o: %.c $(DEPS)

	$(CC) -o $@ -c $< $(WFLAGS)
.PHONY: cleanv

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

