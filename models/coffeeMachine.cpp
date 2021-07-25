#include <bits/stdc++.h>
#include "ingredient.cpp"
#include "drink.cpp"

using namespace std;

class CoffeeMachine {
  private:
    map<Ingredient*, int> maxLimit;
    map<Ingredient*, int> stock;
    vector<Drink*> menu;

    bool isAvailable(Drink* drink) {
      map<Ingredient*, int> requiredIngredient = drink->getRecipe()->getRequiredIngredients();
      for (map<Ingredient*, int>::iterator it = requiredIngredient.begin(); it != requiredIngredient.end(); ++it) {
        Ingredient* current_ingredient = it->first;
        // qty available with us in the stock is more
        if (stock[current_ingredient] >= requiredIngredient[current_ingredient]) {
          continue;
        } else {
          cout << "The ingredient " << current_ingredient->getName() << " is not in stock!\n";
          return false;
        }
      }
      // all the ingredients are in the stock
      return true;
    }

    // assuming that it is in stock
    void consumeIngredients(Drink* drink) {
      map<Ingredient*, int> requiredIngredient = drink->getRecipe()->getRequiredIngredients();
      for (map<Ingredient*, int>::iterator it = requiredIngredient.begin(); it != requiredIngredient.end(); ++it) {
        Ingredient* current_ingredient = it->first;
        // subtract the required amount that we are consuming
        stock[current_ingredient] -= requiredIngredient[current_ingredient];
      }
    }

  public:
    CoffeeMachine(map<Ingredient*, int> maxLimit, vector<Drink*> menu) {
      this->stock = maxLimit; // initially machine full with stock
      this->maxLimit = maxLimit;
      this->menu = menu;
    }

    void printMenuList() {
      vector<string> res;
      for (vector<Drink*>::iterator it = menu.begin(); it != menu.end(); ++it) {
        res.push_back((**it).getName());
      }
      cout << "The menu contains:\n";
      for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
      }
      cout << endl;re
    }

    void printStock() {
      map<string, int> res;
      for (map<Ingredient*, int>::iterator it = stock.begin(); it != stock.end(); ++it) {
        res[it->first->getName()] = it->second;
      }
      cout << "The stock contains\n";
      for (map<string, int>::iterator it = res.begin(); it != res.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
      }
      cout << endl;
    }

    void processDrink(Drink* drink) {
      // check availability
      if (!isAvailable(drink)) {
        cout << "Drink cannot be made due to lack of ingredients in the stock\n";
        return;
      }
      // create the drink and consume the ingredients
      consumeIngredients(drink);
    }

    void refillStock() {
      // reffill all the ingredients completely
      this->stock = this->maxLimit;
    }
};
