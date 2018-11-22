#include <stdio.h>
#include <string.h>
#include "sqlite3.h"
#include "person.h"

int main (void) {
	sqlite3 *db = NULL;
	const char *database_file = "/tmp/database.db";

	// cria banco de dados
	if (sqlite3_open(database_file, &db) != SQLITE_OK) {
		fprintf(stderr, "Error database: %s\n", sqlite3_errmsg(db));
		exit(sqlite3_errcode(db));
	}

	// cria se necessario tabela persona
	if (sqlite3_exec(db, CREATE_TABLE_PERSON, NULL, NULL, NULL) != SQLITE_OK) {
		fprintf(stderr, "Error table person: %s\n", sqlite3_errmsg(db));
		exit(sqlite3_errcode(db));
	}

	// INSERT PERSONS
	/*
	Person *list_person = NULL;
	new_person(&list_person, 0, "italo", 29);
	new_person(&list_person, 0, "pedro", 25);
	new_person(&list_person, 0, "hiago", 22);
	set_persons(db, list_person);
	*/


	// SELECT PERSONS
	Person *list_people = NULL;
	get_persons(db, &list_people);
	show_persons(list_people);


	sqlite3_close(db);
	return 0;
}
