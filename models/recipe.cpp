#include <bits/stdc++.h>
#include "ingredient.cpp"


using namespace std;

class Recipe {
  map<Ingredient*, int> requiredIngredients;
public:
  Recipe() {
    requiredIngredients.clear();
  }
  Recipe(map<Ingredient*, int> ingredientList) {
    this->requiredIngredients = ingredientList;
  }
  map<Ingredient*, int> getRequiredIngredients() {
    return requiredIngredients;
  }
  // add ingredient
  void addIngredient(Ingredient* ingredient, int qty) {
    requiredIngredients[ingredient] = qty;
  }
};
