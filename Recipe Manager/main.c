#define _CRT_SECURE_NO_WARNINGS

#include "Recipe.h"

int main(void) {

    RECIPE r[MAX_RECIPES] = { 0 };
    int recipe_no = 0;  // Initialize to 0 since arrays are 0-indexed
    bool condition = true;
    int choice;
    do {
        printf("\n::----------  Recipe Manager  ----------::\n\n");
        printf("\t\tMain Menu\n");
        printf("  \t1. add a new recipe\n");
        printf("  \t2. delete an existing recipe\n");
        printf("  \t3. update an existing recipe\n");
        printf("  \t4. display single recipe\n");
        printf("  \t5. display range recipe\n");
        printf("  \t6. display all recipe\n");
        printf("  \t7. search for recipe\n");
        printf("  \t0. Exit\n");
        printf("------------------------------------------\n");

        printf("Enter your Choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            recipe_no++;
            add_Recipe(r, recipe_no);
            //printf("%d \t %s \t %s", r[recipe_no - 1].recipe_number, r[recipe_no - 1].recipe_name, r[recipe_no - 1].filename);
            break;
        case 2:            
            int totalrecipe=display_recipe_list(r);
            delete_Recipe(r, totalrecipe);
            break;
        case 5:
            display_Recipe(r);
            break;
        case 7:
            search_Recipe(r);
            break;  // Add a break statement here to prevent fall-through
        case 0:
            condition = false;
            break;  // Add a break statement here to prevent fall-through
        }
    } while (condition);

    return 0;  // Don't forget to return 0 from main
}
