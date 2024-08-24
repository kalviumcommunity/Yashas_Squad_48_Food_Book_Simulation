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
    vector<string> steps; // New member variable for cooking steps

public:
    Recipe(string n, vector<string> ingr, string instr, string ctype, vector<string> stps)
        : name(n), ingredients(ingr), instructions(instr), cuisine_type(ctype), steps(stps) {}

    virtual void display_recipe() {
        cout << "Recipe: " << name << endl;
        cout << "Cuisine Type: " << cuisine_type << endl;
        cout << "Ingredients: ";
        for (auto &ing : ingredients)
            cout << ing << " ";
        cout << endl;
        cout << "Instructions: " << instructions << endl;

        // Display the cooking steps
        cout << "How to Cook:" << endl;
        for (size_t i = 0; i < steps.size(); ++i) {
            cout << i + 1 << ". " << steps[i] << endl;
        }
    }
};

// Derived classes for different regions
class North : public Recipe {
public:
    North(string n, vector<string> ingr, string instr, vector<string> stps)
        : Recipe(n, ingr, instr, "North Indian", stps) {}

    void display_recipe() override {
        Recipe::display_recipe();
    }
};

class South : public Recipe {
public:
    South(string n, vector<string> ingr, string instr, vector<string> stps)
        : Recipe(n, ingr, instr, "South Indian", stps) {}

    void display_recipe() override {
        Recipe::display_recipe();
    }
};

class Northeast : public Recipe {
public:
    Northeast(string n, vector<string> ingr, string instr, vector<string> stps)
        : Recipe(n, ingr, instr, "Northeast Indian", stps) {}

    void display_recipe() override {
        Recipe::display_recipe();
    }
};

class Northwest : public Recipe {
public:
    Northwest(string n, vector<string> ingr, string instr, vector<string> stps)
        : Recipe(n, ingr, instr, "Northwest Indian", stps) {}

    void display_recipe() override {
        Recipe::display_recipe();
    }
};

int main() {
    // Create some recipes with 10 cooking steps each
    vector<string> ingredients1 = {"Rice", "Chicken", "Spices"};
    vector<string> steps1 = {
        "Rinse the rice thoroughly until the water runs clear.",
        "Soak the rice in water for 30 minutes.",
        "Marinate the chicken with yogurt, spices, and lemon juice for 1 hour.",
        "Heat ghee in a large pot and add whole spices.",
        "Add sliced onions and sauté until golden brown.",
        "Add the marinated chicken and cook until browned.",
        "Add water, bring to a boil, and add the soaked rice.",
        "Cover and cook on low heat until the rice is fully cooked.",
        "Let the biryani rest for 10 minutes before serving.",
        "Garnish with fried onions, coriander, and serve hot."
    };
    North biryani("Biryani", ingredients1, "Cook rice, add chicken and spices", steps1);

    vector<string> ingredients2 = {"Coconut", "Rice", "Fish"};
    vector<string> steps2 = {
        "Grate fresh coconut and extract the coconut milk.",
        "Rinse the rice and soak it in water for 30 minutes.",
        "Clean and cut the fish into pieces.",
        "Marinate the fish with turmeric, salt, and chili powder.",
        "Heat oil in a pan and sauté onions, garlic, and ginger.",
        "Add tomatoes and cook until soft and pulpy.",
        "Add the marinated fish and cook until it turns white.",
        "Pour in the coconut milk and bring to a simmer.",
        "Cook the fish in the coconut milk until tender.",
        "Serve the fish curry hot with steamed rice."
    };
    South fishCurry("Fish Curry", ingredients2, "Cook fish with coconut and spices", steps2);

    vector<string> ingredients3 = {"Bamboo Shoots", "Pork", "Spices"};
    vector<string> steps3 = {
        "Clean and chop the bamboo shoots into thin slices.",
        "Boil the bamboo shoots in water to remove bitterness.",
        "Cut the pork into bite-sized pieces.",
        "Marinate the pork with salt, ginger, and garlic paste.",
        "Heat oil in a pot and add whole spices.",
        "Add the marinated pork and cook until browned.",
        "Add the boiled bamboo shoots and stir well.",
        "Pour in water or broth and bring to a boil.",
        "Simmer on low heat until the pork is tender.",
        "Garnish with fresh herbs and serve hot."
    };
    Northeast bambooPork("Bamboo Pork", ingredients3, "Cook pork with bamboo shoots and spices", steps3);

    vector<string> ingredients4 = {"Wheat", "Meat", "Spices"};
    vector<string> steps4 = {
        "Prepare the dough using wheat flour and water.",
        "Knead the dough until smooth and pliable.",
        "Cut the meat into small pieces and marinate with spices.",
        "Shape the marinated meat into kebabs.",
        "Preheat the grill to a medium-high temperature.",
        "Grill the kebabs until they are browned on all sides.",
        "Baste the kebabs with butter or ghee while grilling.",
        "Cook the kebabs until they are fully cooked inside.",
        "Remove the kebabs from the grill and let them rest.",
        "Serve the kebabs hot with mint chutney and naan."
    };
    Northwest kebab("Kebab", ingredients4, "Grill meat with spices", steps4);

    // Loop until user decides to exit
    int choice;
    while (true) {
        cout << "\nChoose a cuisine region by number:" << endl;
        cout << "1. North\n2. South\n3. Northeast\n4. Northwest\n5. Exit" << endl;
        cin >> choice;

        // Depending on the choice, display corresponding recipes
        if (choice == 1) {
            cout << "\nDisplaying North Indian recipes:" << endl;
            biryani.display_recipe();
        } else if (choice == 2) {
            cout << "\nDisplaying South Indian recipes:" << endl;
            fishCurry.display_recipe();
        } else if (choice == 3) {
            cout << "\nDisplaying Northeast Indian recipes:" << endl;
            bambooPork.display_recipe();
        } else if (choice == 4) {
            cout << "\nDisplaying Northwest Indian recipes:" << endl;
            kebab.display_recipe();
        } else if (choice == 5) {
            cout << "Exiting the program." << endl;
            break; // Exit the loop and end the program
        } else {
            cout << "Invalid choice! Please select a valid option." << endl;
        }
    }

    return 0;
}
