#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Base class: Recipe
class Recipe {
protected:
    string name;
    vector<string> ingredients;
    string instructions;
    string cuisine_type;
    vector<string> steps;
public:
    Recipe(string n, vector<string> ingr, string instr, string ctype, vector<string> stps)
        : name(n), ingredients(ingr), instructions(instr), cuisine_type(ctype), steps(stps) {}

    virtual ~Recipe() {} // Virtual destructor to ensure proper cleanup for derived classes

    void display_recipe() {
        cout << "Recipe: " << this->name << endl;
        cout << "Cuisine Type: " << this->cuisine_type << endl;
	@@ -48,6 +50,11 @@ class South : public Recipe {
        : Recipe(n, ingr, instr, "South Indian", stps) {}
};






class Northeast : public Recipe {
public:
    Northeast(string n, vector<string> ingr, string instr, vector<string> stps)
	@@ -61,9 +68,9 @@ class Northwest : public Recipe {
};

int main() {
    // North Indian Recipes (Using dynamic memory allocation)
    vector<Recipe*> northRecipes = {
        new North("Biryani", {"Rice", "Chicken", "Spices"}, "Cook rice, add chicken and spices", {
            "Rinse the rice thoroughly until the water runs clear.",
            "Soak the rice in water for 30 minutes.",
            "Marinate the chicken with yogurt, spices, and lemon juice for 1 hour.",
	@@ -75,7 +82,7 @@ int main() {
            "Let the biryani rest for 10 minutes before serving.",
            "Garnish with fried onions, coriander, and serve hot."
        }),
        new North("Paneer Butter Masala", {"Paneer", "Tomato", "Cream"}, "Cook paneer with tomato and cream", {
            "Cut paneer into cubes and set aside.",
            "Make a tomato puree by blending fresh tomatoes.",
            "Heat oil in a pan, add cumin seeds.",
	@@ -89,9 +96,9 @@ int main() {
        })
    };

    // South Indian Recipes (Using dynamic memory allocation)
    vector<Recipe*> southRecipes = {
        new South("Fish Curry", {"Coconut", "Rice", "Fish"}, "Cook fish with coconut and spices", {
            "Grate fresh coconut and extract the coconut milk.",
            "Rinse the rice and soak it in water for 30 minutes.",
            "Clean and cut the fish into pieces.",
	@@ -103,7 +110,7 @@ int main() {
            "Cook the fish in the coconut milk until tender.",
            "Serve the fish curry hot with steamed rice."
        }),
        new South("Masala Dosa", {"Rice", "Urad Dal", "Fenugreek Seeds"}, "Make dosa batter and prepare dosa", {
            "Soak rice, urad dal, and fenugreek seeds separately overnight.",
            "Grind them separately into a smooth batter.",
            "Mix the batters together and let it ferment overnight.",
	@@ -117,9 +124,9 @@ int main() {
        })
    };

    // Northeast Indian Recipes (Using dynamic memory allocation)
    vector<Recipe*> northeastRecipes = {
        new Northeast("Bamboo Pork", {"Bamboo Shoots", "Pork", "Spices"}, "Cook pork with bamboo shoots and spices", {
            "Clean and chop the bamboo shoots into thin slices.",
            "Boil the bamboo shoots in water to remove bitterness.",
            "Cut the pork into bite-sized pieces.",
	@@ -131,7 +138,7 @@ int main() {
            "Simmer on low heat until the pork is tender.",
            "Garnish with fresh herbs and serve hot."
        }),
        new Northeast("Fermented Rice", {"Rice", "Fermented Soybeans", "Ginger"}, "Cook rice with fermented soybeans", {
            "Rinse the rice and soak it in water for 30 minutes.",
            "Grind the fermented soybeans into a paste.",
            "Heat oil in a pan and sauté ginger until fragrant.",
	@@ -140,14 +147,13 @@ int main() {
            "Steam the mixture until fully cooked.",
            "Garnish with fresh herbs.",
            "Serve hot with a side of vegetable curry.",
            "Enjoy the unique flavors of the dish."
        })
    };

    // Northwest Indian Recipes (Using dynamic memory allocation)
    vector<Recipe*> northwestRecipes = {
        new Northwest("Kebab", {"Wheat", "Meat", "Spices"}, "Grill meat with spices", {
            "Prepare the dough using wheat flour and water.",
            "Knead the dough until smooth and pliable.",
            "Cut the meat into small pieces and marinate with spices.",
	@@ -159,17 +165,15 @@ int main() {
            "Remove the kebabs from the grill and let them rest.",
            "Serve the kebabs hot with mint chutney and naan."
        }),
        new Northwest("Mathri", {"Flour", "Butter", "Sugar"}, "Prepare and deep-fry dough discs", {
            "Mix flour, sugar, and melted butter to form a dough.",
            "Roll out the dough and cut it into small discs.",
            "Heat oil in a pan.",
            "Deep fry the discs until golden brown.",
            "Let them cool and store in an airtight container.",
            "Serve with tea or coffee.",
            "Enjoy the crunchy texture.",
            "Best with a sprinkle of powdered sugar on top."
        })
    };

	@@ -187,16 +191,16 @@ int main() {
        vector<Recipe*> chosenRecipes;
        switch (cuisineChoice) {
            case 1:
                chosenRecipes = northRecipes;
                break;
            case 2:
                chosenRecipes = southRecipes;
                break;
            case 3:
                chosenRecipes = northeastRecipes;
                break;
            case 4:
                chosenRecipes = northwestRecipes;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
	@@ -216,5 +220,11 @@ int main() {
        }
    }

    // Freeing dynamically allocated memory
    for (auto recipe : northRecipes) delete recipe;
    for (auto recipe : southRecipes) delete recipe;
    for (auto recipe : northeastRecipes) delete recipe;
    for (auto recipe : northwestRecipes) delete recipe;

    return 0;
}
