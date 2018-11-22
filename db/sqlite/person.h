#ifndef PERSON_H
#define PERSON_H

#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"

#define CREATE_TABLE_PERSON \
	"CREATE TABLE IF NOT EXISTS person (\n" \
	"  id   INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT\n" \
	", name TEXT    NOT NULL\n" \
	", age  INTEGER NOT NULL\n" \
	");"

typedef struct Person Person;

struct Person {
	int id;
	char name[60];
	int age;
	Person *next;
};

void new_person (Person **list, int id, const char* name, int age) {
	Person *person = malloc(sizeof(Person));
	person->id = id;
	strcpy(person->name, name);
	person->age = age;
	person->next = *list;
	*list = person;
}

int set_persons (sqlite3 *db, Person *list) {
	char insert[100];
	if (list != NULL) {
		set_persons(db, list->next);
		sprintf(insert, "INSERT INTO person (name, age) VALUES('%s', %d);", list->name, list->age);
		if (sqlite3_exec(db, insert, NULL, NULL, NULL) != SQLITE_OK) {
			fprintf(stderr, "Error table person: %s\n", sqlite3_errmsg(db));
			exit(sqlite3_errcode(db));	
		}
	}
}
//int callback(void (*italo)(int, char**,int), int a, char **b, char **c) {
int callback(void* ptr, int a, char **b, char **c) {
	int id;
	char **name;
	int age;
	for (int i = 0; i < a; ++i) {
		printf("%s:\t%s\n", c[i], b[i]);
	
	}
	//italo(id, name, age);
	return 0;
}

void italo (int id, char** name, int age) {
	puts("oi");
}

void get_persons (sqlite3 *db, Person** list) {
	sqlite3_exec(db, "SELECT * FROM person;", callback, italo, NULL);
}

void show_persons (Person *list) {
	if (list != NULL) {
		show_persons(list->next);
		printf("Person id:   %d\n", list->id);
		printf("Person name: %s\n", list->name);
		printf("Person age:  %d\n", list->age);
		puts("---------------");
	}
}

#endif
