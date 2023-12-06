#include "Recipe.h"

void add_Recipe(RECIPE* r, int recipeno) {
    

    char recipe_name[MAX_RECIPE_NAME];
    printf("Enter the name of the new recipe: (Dont include space in name)");
    scanf_s("%s", recipe_name,MAX_RECIPE_NAME);
    getchar(); // Consume the newline character

    char filename[MAX_FILENAME];
    sprintf(filename, "%s.txt", recipe_name);

    r[recipeno].recipe_number = recipeno;
    strcpy(r[recipeno].recipe_name , recipe_name);
    strcpy(r[recipeno].filename, filename);
    
    /*int totalRecipes = display_recipe_list(r);
    recipeno = totalRecipes + 1;
    */
    FILE* mainFile = fopen(MAIN_FILE, "w");
    if (mainFile == NULL) {
        printf("File not found\n");
    }
    else {
        
        fprintf(mainFile, "%d \t %s \t %s\n", recipeno, r[recipeno].recipe_name, r[recipeno].filename);
        fclose(mainFile);
    }

    FILE* newFile = fopen(filename, "r");

    int k = 1;
    if (newFile != NULL) {
        printf("\nFile Name already exists!\n");
        fclose(newFile);
    }
    else {

        newFile = fopen(filename, "w");

        if (newFile != NULL) {

            printf("Enter the recipe steps (enter an empty line to finish):\n");

            // Using a loop to read multiple lines of text
            bool finished = false;
            while (!finished) {
                char recipe_steps[MAX_RECIPE_LENGTH];
                printf("Step %d: ", k);
                fgets(recipe_steps, sizeof(recipe_steps), stdin);

                // to check if the line is empty (contains only newline character)
                if (recipe_steps[0] == '\n') {
                    finished = true;
                }
                else {
                    fprintf(newFile, "%s", recipe_steps);
                }
                k++;
            }

            printf("\nRecipe added successfully!\n");
            fclose(newFile);
        }
        else {
            printf("\nError creating the recipe file!\n");
        }
    }
    
}

void display_Recipe(RECIPE* r) {
    FILE* mainFile = fopen(MAIN_FILE, "r");

    char recipe[MAX_RECIPE_LENGTH];
    int k = 1;

    if (mainFile == NULL) {
        printf("File not found\n");
    }
    else {
        // Assuming the file format is: recipe_number recipe_name filename
        while (fscanf(mainFile, "%d %s %s", &r[k].recipe_number, r[k].recipe_name, r[k].filename) != EOF) {
            printf("\n%d %s\n", r[k].recipe_number, r[k].recipe_name);
            FILE* recipefile = fopen(r[k].filename, "r");
            int stepcnt = 1;
            if (recipefile == NULL) {
                printf("File not found\n");
            }
            else {
                while (fgets(recipe, MAX_RECIPE_LENGTH, recipefile) != NULL) {
                    printf("Step%d: %s", stepcnt, recipe);
                    stepcnt++;
                }
                fclose(recipefile);
            }
            k++;
        }

        fclose(mainFile);
    }
}

 
//int display_recipe_list(RECIPE* r) {
//    FILE* mainFile = fopen(MAIN_FILE, "r");
//
//    char recipe[MAX_RECIPES];
//    int k = 1;
//
//    if (mainFile == NULL) {
//        printf("File not found\n");
//    }
//    else {
//        // Assuming the file format is: recipe_number recipe_name filename
//        while (fscanf(mainFile, "%d %s %s", &r[k].recipe_number, r[k].recipe_name, r[k].filename) != EOF) {
//            printf("\n%d %s\n", r[k].recipe_number, r[k].recipe_name);
//        }
//    }
//    fclose(mainFile);
//    return k;
//}

int display_recipe_list(RECIPE* r) {
    FILE* mainFile = fopen(MAIN_FILE, "r");

    char recipe[MAX_RECIPES];
    int k = 1;  // Initialize to 0 to count the recipes

    if (mainFile == NULL) {
        printf("File not found\n");
    }
    else {
        // Assuming the file format is: recipe_number recipe_name filename
        while (fscanf(mainFile, "%d %s %s", &r[k].recipe_number, r[k].recipe_name, r[k].filename) != EOF) {
            printf("\n%d %s\n", r[k].recipe_number, r[k].recipe_name);
            k++;
        }
    }
    fclose(mainFile);
    return k;  // Return the total number of recipes
}


void delete_Recipe(RECIPE* r, int totalrecipe) {
    int delrecipe;
    printf("Enter the Recipe number to delete: ");
    scanf_s("%d", &delrecipe);

    FILE* mainFile = fopen(MAIN_FILE, "r");

    int k = 1;
    int breakat = -1;  // Initialize breakat to an invalid index

    if (mainFile == NULL) {
        printf("File not found\n");
        return;
    }

    // Assuming the file format is: recipe_number recipe_name filename
    while (fscanf(mainFile, "%d %s %s", &r[k].recipe_number, r[k].recipe_name, r[k].filename) != EOF) {
        if (delrecipe == r[k].recipe_number) {
            breakat = k;
            if (remove(r[k].filename) == 0) {
                printf("Recipe file %s deleted successfully.\n", r[k].filename);
            }
            else {
                printf("Error deleting recipe file %s\n", r[k].filename);
            }
        }
        k++;
    }

    fclose(mainFile);

    if (breakat == -1) {
        printf("Recipe not found.\n");
        return;
    }

    mainFile = fopen(MAIN_FILE, "w");
    k = 1;

    if (mainFile == NULL) {
        printf("Error opening main file for writing.\n");
        return;
    }

    // Write back the remaining recipes to the main file
    for (int i = 1; i <= totalrecipe; i++) {
        if (i != breakat) {
            fprintf(mainFile, "%d %s %s\n", r[i].recipe_number, r[i].recipe_name, r[i].filename);
        }
    }

    fclose(mainFile);
    printf("Recipe Deleted successfully.\n");
}

void update_Recipe();

void search_Recipe(RECIPE r) {

}