/*
 * O Postgresql e um banco de dados extremamente eficiente, que nao deixa a
 * desejar se comparado com os grande bancos de dados comerciais.
 *
 * Neste artigo iremos ver, ainda que de forma bem simplificada, uma das muitas
 * formas de interacao com este banco de dados, que e usando a linguagem C,
 * atraves de uma interface de programacao disponibilizada pelo PostgreSQL.
 *
 * sudo pacman -Su postgresql-libs
 * sudo apt-get install libpq-dev
 *
 * postgresql.conf
 * 		listen_addresses = '*'
 *
 * pg_hba.conf
 * 		host all all 0.0.0.0/0 md5
 *
 * Primeiro voce vai precisaar descobrir onde se encontra o arquivo libpq-fe.h
 * (se voce utilizar o comando "whereis libpq-fe.h", voce vai conseguir
 * descobrir onde se encontra este arquivo), depois, ao compilador o programa,
 * passamos o diretorio acima dentro da opcao -I do gcc:
 *
 * gcc -o programa -I/usr/include/pgsql programa.c -lpq
 * gcc -o porgrama -I/usr/include/postgresql programa.c -lpq
 *
 * Isso supondo que a sua biblioteca esta em /usr/include/pgsql. Altere o
 * diretorio onde se encontra a sua. Talvez seja necessario ultilizar a opcao
 * -L e o diretorio, ao inves da opcao -I.
 *
 * ROTINAS PARA CONEXAO
 * O metodo mais usado para conexao com PostgreSQL e o comando PQconnectdb
 * (existem outras rotinas, mas focaremos apenas nesta), que tem a forma:
 *
 * PGconn *PQconnectdb(const char *conninfo);
 *
 * Esta funcao abre uma nova conexao usando os parametros passados na string
 * conninfo. Esses parametros sao passados separados por espaco, e podem ser:
 *
 * 		* host: O nome do host que queremos nos conectar, neste exemplo,
 * 		usaremos localhost;
 *
 * 		* port: Porta de conexao com o PostgreSQL, como usaremos a porta padrao,
 * 		podemos omitir este parametro;
 *
 * 		* dbname: O nome do banco de dados que iremos nos conectar. Se deixado
 * 		em branco, sera usado o banco de nome igual ao usuario logado no Linux;
 *
 * 		* user: O nome do usuario a realizar a conexao. Se omitido, o padrao e o
 * 		mesmo usuario logado no Linux;
 *
 * 		* password: A senha para o usuario a ser usado.
 * Cada um dos parametros acima e seguido de um sinal de igual ('=') e depois
 * pelo valor que ele deve assumir. Parametros omitidos usarao o valor padrao.
 *
 * Vejamos agora um exemplo para conexao com o nosso banco de dados TESTE criado
 * anteriormente:
 *
 * 		PGconn *conn = NULL;
 * 		conn = PQconnectdb("host=localhost dbname=TESTE");
 *
 * Primeiro declaramos uma variavel *conn, do tipo PGconn com o valor inicial
 * NULL, em seguida, chamamos a funcao PQconnectdb passando como parametros o
 * host, que sera o localhost e o banco sera o TESTE, que ciramos acima.
 *
 * A funcao PQconnectdb ira retornar NULL somente se houver falha na alocacao de
 * memoria para o objeto de conexao. Mesmo que o retorno seja nao-NULL,
 * precisamos verificar se a conexao foi bem sucedida. Podemos fazer isso com a
 * funcao PQstatus, que tem o prototipo:
 *
 * 		ConnStatusType PQstatus(PGconn *conn);
 *
 * Esta funcao recebe como parametro um objeto PGconn e retorna um tipo
 * enumerado, que pode ter dois valores: CONNECTION_OK ou CONNECTION_BAS (os
 * significados sao bem obvios).
 *
 * 		void PQfinish(PGconn *conn);
 *
 * Esta funcao encerra a conexao com o banco de dados e tabmem libera a memoria
 * usada pelo objeto de conexao, e deve ser chamada mesmo que a conexao nao
 * nao tenha ocorrido com sucesso. Vale dizer que uma vez chamada esta funcao,
 * nao se deve tentar usar o objeto conn novamente.
 *
 * Alem de saber que a nossa conexao falhou, podemos quere saber qual foi a
 * mensagem de erro retornada pelo PostgreSQL, podemo fazer isso com a funcao
 * PQerrorMessage, que tem o seguinte prototipo:
 *
 * 		char *PQerrorMessage(PGconn *conn);
 *
 * Esta funcao retorna um ponteiro char, e recebe como parametro um objeto de
 * conexao.
 *
 * CRUD
 * A manipulacao de dados no PostgreSQL e extremamente simples. Apenas a chamada
 * a uma funcao para executar o comando e algumas outras para verificar os
 * resultados sao o suficiente.
 *
 * A funcao a ser chamada para executar o comando e o PQexec, que tem o seguinte
 * prototipo:
 *
 * 		PQresult *PQexec(PGconn *conn, const char *sql_string);
 *
 * Esta funcao recee como parametro um objeto de conexao e uma string contendo o
 * comando SQL a ser executado. O resultado pode ser um NULL em casos
 * execpcionais, do contrario, receberemos um ponteiro que pode ser verificado
 * chamando a funcao PQresultStatus, que recebera como parametro o ponteiro
 * retornado por PQexec e ira retornar um enum do tipo ExecStatusType. A funcao
 * PQresultStatus tem o seguinte prototipo:
 *
 * 		ExecStatusType *PQresultStatus(PGresult *result);
 *
 * Os valore da enum retornada por esta funcao sao:
 * 		+ PGRES_EMPTY_QUERY - Nada foi feito
 * 		+ PGRES_COMMAND_OK - O comando foi bem sucedido, mas sem dados retornados.
 * 		+ PGRES_TUPLES_OK - O comando foi bem sucedido e dados podem ter retornado.
 * 		+ PGRES_COPY_OUT - Uma copia para um arquivo externo estava em andamento.
 * 		+ PGRES_COPY_IN - Uma copia de um arguivo externo estava em andamento.
 * 		+ PGRES_BAD_RESPONSE - Erro inesperado.
 * 		+ PGRES_NONFATAL_ERROR - Erro nao fatal.
 * 		+ PGRES_FATAL_ERROR - Erro fatal.
 *
 * Algumas observacoes quanto aos valores acima: PGRES_TUPLES_OK significa que
 * um comando SELECT foi bem sucedido, mas nao necessariamente que dados foram
 * retornados. Os valores PGRES_COPY_IN e PGRES_COPY_OUT estao relacionados com
 * o banco de dados que esta sendo carregado ou sendo feito o backup.
 *
 * O valor de retorno da funcao PQresultStatus nos mostra apenas a acao
 * ocorrida, se quisermos mais detalhes quanto ao resultado, podemos chamar uma
 * outra funcao, PQresultErrorMessage, que tem o seguinte prototipo:
 *
 * 		const char *PQresultErrorMessage(PGresult *result);
 *
 * Esta funcao recebe o mesmo parametro que a funcao PQresultStatus, porem o
 * retorno e uma string contendo a mensagem retornada pelo banco.
 *
 * Uma outra funcao que pode ter alguma utilidade e a funcao PQcmdTuples, que
 * retorna o numero de linha afetadas por comandos INSERT, DELETE E UPDATE
 * (para descobrir a quantidade de linhas retornadas por um SELECT existe uma
 * outra funcao). A funcao PQcmdTuples tem o seguinte prototipo:
 *
 * 		const char *PQcmdTuples(PGresult *result);
 *
 * O parametro de entrada desta funcao e o mesmo das funcoes acima, o ponteiro
 * retornado por PQexec, e o retorno, uma string terminada com NULL contendo
 * digitos em forma de caracteres (atencao a isto, pois a funcao nao retorna um
 * inteiro, como seria mais obvio).
 *
 * Para finalizar esta secao, precisamos saber como liberar o objeto de
 * resultado que obtivemos com a funcao PQexec. Para isso, usamo a funcao
 * PQclear, que tem o seguinte prototipo:
 *
 * 		void PQclear(PGresult *result);
 *
 * RECUPERANDO DADOS
 * Chegamos na parte mais usada, e tambem a mais complexa da libpq, que e a
 * recuperacao de dados.
 *
 * O que torna essa parte da API mais complexa e o fato de nao sabermos sempre
 * quantas linhas o nosso comando ira retornar, ou mesmo a quantidade de campos.
 * Porem, podemo fazer chamadas adicionais a funcoes da API que ajudam a
 * contornar este problema. Para executar um comando SELECT continuamos a usar a
 * funcao PQexec exatamente como antes.
 *
 * Primeiro, vamos descobrir quantas linhas o nosso comando retorna. Para isso,
 * usamos a funcao PQntuples, que tem o seguinte prototipo:
 *
 * 		int PQntuples(PGresult *result);
 *
 * Onde result e o retorno da chamada a funcao PQexec.
 *
 * Tudo bem, isso na verdade nao ajuda muito, pois o que queremos e ver o temos
 * dentro da tabela. Para isso, vamos usar uma maneira rapida e simples da libpq
 * que gera a saida em um arquivo. Esta funcao e a PQprint, que tem o prototipo:
 *
 * 		void PQprint(FILE *stream, PGresult *result, PQprintOpt *options);
 *
 * Esta funcao vai receber como parametros um ponteiro para o nosso arquivo, um
 * ponteiro de resultado retornado pela funcao PQexec e uma estrutura de opcoes.
 * Esta estrutura vai definir algumas opcoes para gerar o arquivo, como por
 * exemplo o caractere que vai delimitar os dados.
 *
 *
 * typedef struct PQprintOpt {
		pqbool header; // imprime o cabecalho
		pqbool align; // alinha e preenche os campos
		pqbool standard; // formato antigo nao mais utilizado
		pqbool html3; // gera saida das tabelas em html
		pqbool expanded; // expande tabelas
		pqbool pager; // usa o paginador para saida caso necessario
		char *fieldSep; // caractere que sera o separador de campos
		char *tableOpt; // insercao na <table ...> html
		char *legenda; // legenda html
		char **fieldname; //array terminado com null contendo o nome de campo para substituicao
	}
 *
 * Perceba que apesar de ser relativamente simples de usar, esta solucao esta
 * longe de ser a melhor solucao para recuperar dados. Quando temos um volume
 * pequeno de dados esta solucao e aceitavel, mas que torna-se inutilizavel
 * quando temos tabelas maiores. Para piorar, e muito complicado se quisermos
 * manipular os valores retornados.
 *
 * Existe uma outra alternativa muito mais eficiente para retornamos dados que e
 * o uso de cursosres. Este assunto porem e material suficiente para um novo
 * artigo, devido ao tamanho e complexidade envolvida.
 */

#include <libpq-fe.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	PGconn *conn = NULL;
	PGresult *result;
	FILE *output_stream;
	PQprintOpt print_options;

	conn = PQconnectdb("host=192.168.1.104 port=5432 dbname=bancodedados user=admteste password=yma2578k");
	if (PQstatus(conn) == CONNECTION_OK)
		printf("ola mundo %d\n", conn);

	else {
		printf("Falha na conexao.\nErro: %s\n", PQerrorMessage(conn));
		PQfinish(conn);
		return -1;
	}

	//INSERT, UPDATE e DELET
	//result = PQexec(conn, "insert into tabela1 (nome) values ('anjos')");
	result = PQexec(conn, "select * from tabela1");
	if (!result) {
		printf("Erro executando comando\n");
	} else {
		switch (PQresultStatus(result)) {
			case PGRES_EMPTY_QUERY: printf("Nada aconteceu\n"); break;
			case PGRES_FATAL_ERROR: printf("Erro: %s\n", PQresultErrorMessage(result)); break;
			case PGRES_COMMAND_OK: printf("%s linhas afetadas\n", PQcmdTuples(result)); break;
			default: printf("Algum outro resultado ocorreu\nCodigo:%d\n", PQresultStatus(result));
		}
		//SELECT
		output_stream = fopen("saida.txt", "w");
		if (output_stream == NULL)
			printf("erro abrindo o arquivo\n");
		else {
			memset(&print_options, '\0', sizeof(print_options));
			print_options.header = 1;
			print_options.align = 1;
			print_options.html3 = 0;
			print_options.fieldSep = "|";
			print_options.fieldName = NULL;

			PQprint(output_stream, result, &print_options);
		}

		PQclear(result);
	}

	if (conn != NULL) PQfinish(conn);
	return 0;
}
