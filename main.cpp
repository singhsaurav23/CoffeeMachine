#include <bits/stdc++.h>
#include "models/coffeeMachine.cpp"
using namespace std;

int main () {
  // dummy data
  Ingredient sugar("sugar", 25);
  Ingredient milk("milk", 50);
  Ingredient coffee("coffee", 30);

  map<Ingredient*, int> coffeeRecipeIngredients;
  coffeeRecipeIngredients[&sugar] = 1;
  coffeeRecipeIngredients[&milk] = 1;
  coffeeRecipeIngredients[&coffee] = 3;

  Recipe coffeeRecipe(coffeeRecipeIngredients);

  Drink coffeeBeverage("normal coffee", &coffeeRecipe);

  map<Ingredient*, int> machineStock;
  machineStock[&sugar] = 0;
  machineStock[&milk] = 50;
  machineStock[&coffee] = 1000;

  vector<Drink*> menu = {&coffeeBeverage};

  CoffeeMachine coffeeMachine(machineStock, menu);

  // play here

  coffeeMachine.printMenuList();
  coffeeMachine.printStock();

  coffeeMachine.processDrink(&coffeeBeverage);
  coffeeMachine.printStock();
}