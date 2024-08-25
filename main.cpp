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

    virtual void display_recipe() {
        cout << "Recipe: " << this->name << endl;
        cout << "Cuisine Type: " << this->cuisine_type << endl;
        cout << "Ingredients: ";
        for (auto &ing : this->ingredients)
            cout << ing << " ";
        cout << endl;
        cout << "Instructions: " << this->instructions << endl;
        cout << "How to Cook:" << endl;
        for (size_t i = 0; i < this->steps.size(); ++i) {
            cout << i + 1 << ". " << this->steps[i] << endl;
        }
    }
};

// Derived classes for different regions
class North : public Recipe {
public:
    North(string n, vector<string> ingr, string instr, vector<string> stps)
        : Recipe(n, ingr, instr, "North Indian", stps) {}

    void display_recipe() override {
        this->Recipe::display_recipe();
    }
};

class South : public Recipe {
public:
    South(string n, vector<string> ingr, string instr, vector<string> stps)
        : Recipe(n, ingr, instr, "South Indian", stps) {}

    void display_recipe() override {
        this->Recipe::display_recipe();
    }
};

class Northeast : public Recipe {
public:
    Northeast(string n, vector<string> ingr, string instr, vector<string> stps)
        : Recipe(n, ingr, instr, "Northeast Indian", stps) {}

    void display_recipe() override {
        this->Recipe::display_recipe();
    }
};

class Northwest : public Recipe {
public:
    Northwest(string n, vector<string> ingr, string instr, vector<string> stps)
        : Recipe(n, ingr, instr, "Northwest Indian", stps) {}

    void display_recipe() override {
        this->Recipe::display_recipe();
    }
};

int main() {
    // Recipes with 10 cooking steps
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

    vector<string> ingredients1_2 = {"Paneer", "Tomato", "Cream"};
    vector<string> steps1_2 = {
        "Cut paneer into cubes and set aside.",
        "Make a tomato puree by blending fresh tomatoes.",
        "Heat oil in a pan, add cumin seeds.",
        "Add ginger-garlic paste and sauté.",
        "Pour in the tomato puree and cook until oil separates.",
        "Add spices like turmeric, cumin, and coriander powder.",
        "Add cream and mix well.",
        "Add the paneer cubes and simmer for 5-7 minutes.",
        "Garnish with fresh coriander leaves.",
        "Serve hot with naan or rice."
    };
    North paneerButterMasala("Paneer Butter Masala", ingredients1_2, "Cook paneer with tomato and cream", steps1_2);

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

    vector<string> ingredients2_2 = {"Rice", "Urad Dal", "Fenugreek Seeds"};
    vector<string> steps2_2 = {
        "Soak rice, urad dal, and fenugreek seeds separately overnight.",
        "Grind them separately into a smooth batter.",
        "Mix the batters together and let it ferment overnight.",
        "Heat a tawa and pour a ladle of batter onto it.",
        "Spread the batter evenly to form a thin dosa.",
        "Drizzle oil around the edges.",
        "Cook until the edges start lifting.",
        "Flip the dosa and cook the other side for a few seconds.",
        "Serve hot with coconut chutney and sambar.",
        "Enjoy the dosa!"
    };
    South masalaDosa("Masala Dosa", ingredients2_2, "Make dosa batter and prepare dosa", steps2_2);

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

    vector<string> ingredients3_2 = {"Rice", "Fermented Soybeans", "Ginger"};
    vector<string> steps3_2 = {
        "Rinse the rice and soak it in water for 30 minutes.",
        "Grind the fermented soybeans into a paste.",
        "Heat oil in a pan and sauté ginger until fragrant.",
        "Add the soybean paste and cook for a few minutes.",
        "Mix the paste with cooked rice.",
        "Steam the mixture until fully cooked.",
        "Garnish with fresh herbs.",
        "Serve hot with a side of vegetable curry.",
        "Enjoy the unique flavors of the dish.",
        "Perfect for a traditional Northeast Indian meal."
    };
    Northeast fermentedRice("Fermented Rice", ingredients3_2, "Cook rice with fermented soybeans", steps3_2);

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

    vector<string> ingredients4_2 = {"Flour", "Butter", "Sugar"};
    vector<string> steps4_2 = {
        "Mix flour, sugar, and melted butter to form a dough.",
        "Roll out the dough and cut it into small discs.",
        "Heat oil in a pan.",
        "Deep fry the discs until golden brown.",
        "Let them cool and store in an airtight container.",
        "Serve with tea or coffee.",
        "Perfect for a light snack.",
        "Enjoy the crunchy texture.",
        "Best with a sprinkle of powdered sugar on top.",
        "A traditional Northwest Indian treat."
    };
    Northwest mathri("Mathri", ingredients4_2, "Prepare and deep-fry dough discs", steps4_2);

    int cuisineChoice, dishChoice;
    while (true) {
        cout << "\nChoose a cuisine region by number:" << endl;
        cout << "1. North Indian\n2. South Indian\n3. North East Indian\n4. North West Indian\n5. Exit" << endl;
        cin >> cuisineChoice;

        if (cuisineChoice == 5) {
            cout << "Exiting program." << endl;
            break;
        }

        cout << "Choose a dish from this region by number:" << endl;
        cout << "1. " << (cuisineChoice == 1 ? "Biryani" : cuisineChoice == 2 ? "Fish Curry" : cuisineChoice == 3 ? "Bamboo Pork" : "Kebab") << endl;
        cout << "2. " << (cuisineChoice == 1 ? "Paneer Butter Masala" : cuisineChoice == 2 ? "Masala Dosa" : cuisineChoice == 3 ? "Fermented Rice" : "Mathri") << endl;
        cin >> dishChoice;

        if (cuisineChoice == 1) {
            if (dishChoice == 1) biryani.display_recipe();
            else if (dishChoice == 2) paneerButterMasala.display_recipe();
        } else if (cuisineChoice == 2) {
            if (dishChoice == 1) fishCurry.display_recipe();
            else if (dishChoice == 2) masalaDosa.display_recipe();
        } else if (cuisineChoice == 3) {
            if (dishChoice == 1) bambooPork.display_recipe();
            else if (dishChoice == 2) fermentedRice.display_recipe();
        } else if (cuisineChoice == 4) {
            if (dishChoice == 1) kebab.display_recipe();
            else if (dishChoice == 2) mathri.display_recipe();
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
