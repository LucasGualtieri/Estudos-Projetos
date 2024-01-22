// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

int CompareToListaDupla(CelulaDupla* cel1, CelulaDupla* pivot, Log* log) {

	log->comparacoes++;

	Jogador jog1 = cel1->jogador, pivotJog = pivot->jogador;

	int strComp = strcmp(jog1.estadoNascimento, pivotJog.estadoNascimento);

	if (strComp == 0) {
		log->comparacoes++;
		strComp = strcmp(jog1.nome, pivotJog.nome);
	}

	return strComp;
}

void InserirInicioListaDupla(Jogador jogador, Queue* lista) {

	CelulaDupla* new = newCelulaDupla(jogador, NULL, NULL);

	if (lista->primeiro == NULL)
		lista->primeiro = lista->ultimo = new;

	else {
		new->dir		= lista->primeiro;
		lista->primeiro = lista->primeiro->esq = new;
	}

	lista->size++;
}

void InserirFimListaDupla(Jogador jogador, Queue* lista) {

	CelulaDupla* new = newCelulaDupla(jogador, NULL, NULL);

	if (lista->ultimo == NULL)
		lista->ultimo = lista->primeiro = new;

	else {
		new->esq	  = lista->ultimo;
		lista->ultimo = lista->ultimo->dir = new;
	}

	lista->size++;
}

void MostrarListaDupla(Queue lista) {
	if (lista.size == 0) {
		errx(1, "Erro ao mostrar: Lista Dupla vazia.\n");
	}

	for (CelulaDupla* i = lista.primeiro; i != NULL; i = i->dir) {
		printf("[%d ## ", i->jogador.id);
		printf("%s ## ", i->jogador.nome);
		printf("%d ## ", i->jogador.altura);
		printf("%d ## ", i->jogador.peso);
		printf("%d ## ", i->jogador.anoNascimento);
		printf("%s ## ", i->jogador.universidade);
		printf("%s ## ", i->jogador.cidadeNascimento);
		printf("%s]\n", i->jogador.estadoNascimento);
	}
}

void CloseListaDupla(Queue* lista) {

	CelulaDupla* i = lista->primeiro;
	while (i != NULL) {
		CelulaDupla* tmp = i;
		i				 = i->dir;
		tmp->Close(tmp);
	}

	lista->size = 0;
}

Queue newListaDupla() {

	Queue lista;

	lista.size	   = 0;
	lista.primeiro = lista.ultimo = NULL;

	lista.CompareTo = CompareToListaDupla;

	lista.InserirInicio = InserirInicioListaDupla;
	lista.InserirFim	= InserirFimListaDupla;

	lista.Mostrar = MostrarListaDupla;
	lista.Close	  = CloseListaDupla;

	return lista;
}