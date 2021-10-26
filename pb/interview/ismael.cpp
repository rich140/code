// You're a chef who wants to know which recipes you can make 
// in a given day given a list of raw ingredients.
// Each recipe has a list of raw ingredients and intermediate ingredients.
// You have a cookbook that contains all your recipes.
// Return the set of recipes that you can make.
//
// Examples
// Ham and Cheese Sandwich 
//      Raw Ingredients: Ham, Cheese 
//      Intermediate Ingredients: Bread
// Bread
//      Raw Ingredients: Flour, Yeast
//      Intermediate Ingredients: None

// Followup: What if we tracked quantity?

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Recipe {
    public:
        string getName() {
            return name;
        } 
        vector<string> get_raw_ingredients() {
            return raw_ingredients;
        }
        vector<Recipe> get_intermediate_ingredients() {
            return intermediate_ingredients;
        }
    private:
        string name;
        vector<string> raw_ingredients;
        vector<Recipe> intermediate_ingredients;
};


void canMakeRecipe(Recipe recipe, unordered_set<string>& available_raw_ingredients,
        unordered_set<Recipe>& possible_recipes) {
    for (string ingredient : recipe.get_raw_ingredients()) {
        if (available_raw_ingredients.count(ingredient) == 0) {
            return;
        }
    }    
    for (Recipe ingredient : recipe.get_intermediate_ingredients()) {
        // Optimize by caching so you don't check the same ingredient twice
        if (possible_recipes.count(ingredient) == 0) {
            canMakeRecipe(ingredient, available_raw_ingredients, possible_recipes);        
        }
    }
    possible_recipes.insert(recipe);
}

int main() {
    vector<Recipe> all_recipes;
    unordered_set<string> available_raw_ingredients;
    unordered_set<Recipe> possible_recipes;
    for (auto recipe : all_recipes) {
        canMakeRecipe(recipe, available_raw_ingredients, possible_recipes);
    }
    return 0;
}
