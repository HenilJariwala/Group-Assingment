#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_RECIPES 100
#define MAX_RECIPE_NAME 50
#define MAX_RECIPE_LENGTH 1000
#define MAX_FILENAME 50
#define MAIN_FILE "mainfile.txt"

typedef struct Recipe {
	int recipe_number;
	char recipe_name[MAX_RECIPE_NAME];
	char filename[MAX_FILENAME];
	char recipe[MAX_RECIPE_LENGTH];
}RECIPE;

void add_Recipe(RECIPE*,int);
void display_Recipe(RECIPE*);
int display_recipe_list(RECIPE* r);
void delete_Recipe();
void update_Recipe();
void search_Recipe();