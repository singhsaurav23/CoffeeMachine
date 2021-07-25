#include <bits/stdc++.h>
#include "ingredient.cpp"
#include "recipe.cpp"

using namespace std;

class Drink {
  int cost;
  string name;
  Recipe* recipe;

  int calculatCost() {
    int cost = 0; // local variable
    map<Ingredient*, int> ingredientsList = recipe->getRequiredIngredients();
    // add cost for each of the ingredient in the recipe
    map<Ingredient*, int>:: iterator it;
    for (it = ingredientsList.begin(); it != ingredientsList.end(); ++it) {
      Ingredient* ingredient = it->first;
      int qty = it->second;
      cost += (ingredient->getCost() * qty);
    }
    return cost;
  }
public:
  Drink(string name, Recipe* recipe) {
    this->name = name;
    this->recipe = recipe;
    // cost is computed based on the recipe
    this->cost = calculatCost();
  }

  Recipe* getRecipe() {
    return recipe;
  }

  string getName() {
    return name;
  }
};
