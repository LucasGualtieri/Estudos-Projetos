# Sistema de Controle de Estacionamento

## Descrição
Este projeto implementa um sistema de controle de clientes e carros para um estacionamento utilizando C.
O sistema permite o cadastro, exclusão e geração de relatórios de clientes e suas respectivas placas de veículos.

## Estrutura de Dados Utilizada
- **Clientes:** Lista duplamente encadeada com inserção pelo fim da lista.
- **Placas:** Lista simplesmente encadeada com inserção pelo início da lista.

## Funcionalidades
1. Cadastro de clientes
2. Cadastro de placas de veículos
3. Exclusão de clientes e suas placas
4. Exclusão de placas de veículos
5. Geração de relatórios detalhados

## Como Compilar
Utilize o comando abaixo para compilar o projeto:
```bash
make
```
## Como Compilar
Como Executar
Após a compilação, execute o binário gerado:

```bash
Copy code
./bin/ControleEstacionamento
```

## Estrutura de Diretórios
- /bin: Contém os arquivos binários compilados.
- /docs: Contém a documentação do projeto.
- /include: Contém os arquivos de cabeçalho.
- /src: Contém o código-fonte do projeto.
- /tests: Contém os testes unitários e de integração.
- Makefile: Script para build do projeto.

## Contribuidores
- Lucas Gualtieri