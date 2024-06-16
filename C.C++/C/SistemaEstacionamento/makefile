COMPILER = gcc
FLAGS = #-Wall
SRCDIR = src
UTILSDIR = utils/src
BINDIR = bin

# Lista de arquivos
FILES =							\
	$(BINDIR)/main.o			\
	$(BINDIR)/clientes.o		\
	$(BINDIR)/placas.o			\
	$(BINDIR)/user_input.o		\
	$(BINDIR)/utils.o			\
	$(BINDIR)/lista_dupla.o		\
	$(BINDIR)/celula_dupla.o	\
	$(BINDIR)/date_utils.o		\

SistemaEstacionamento: $(BINDIR)/SistemaEstacionamento

$(BINDIR)/SistemaEstacionamento: $(FILES)
	$(COMPILER) $(FLAGS) $^ -o $@

$(BINDIR)/main.o: $(SRCDIR)/main.c
	$(COMPILER) $(FLAGS) -c $< -o $@

$(BINDIR)/clientes.o: $(SRCDIR)/clientes.c
	$(COMPILER) $(FLAGS) -c $< -o $@

$(BINDIR)/placas.o: $(SRCDIR)/placas.c
	$(COMPILER) $(FLAGS) -c $< -o $@

$(BINDIR)/user_input.o: $(UTILSDIR)/user_input.c
	$(COMPILER) $(FLAGS) -c $< -o $@

$(BINDIR)/utils.o: $(UTILSDIR)/utils.c
	$(COMPILER) $(FLAGS) -c $< -o $@

$(BINDIR)/lista_dupla.o: $(UTILSDIR)/lista_dupla.c
	$(COMPILER) $(FLAGS) -c $< -o $@

$(BINDIR)/celula_dupla.o: $(UTILSDIR)/celula_dupla.c
	$(COMPILER) $(FLAGS) -c $< -o $@

$(BINDIR)/date_utils.o: $(UTILSDIR)/date_utils.c
	$(COMPILER) $(FLAGS) -c $< -o $@


# make clean para remover arquivos gerados durante o processo de compilação
clean:
	rm -f $(BINDIR)/*.o $(BINDIR)/SistemaEstacionamento
