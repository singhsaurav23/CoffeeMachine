#include <bits/stdc++.h>

using namespace std;

class Ingredient {
  string name;
  int cost;
public:
  Ingredient(string name, int cost) {
    this->name = name;
    this->cost = cost;
  }
  int getCost() {
    return cost;
  }
  void setCost(int cost) {
    this->cost = cost;
  }
  string getName() {
    return name;
  }
  void setName(string name) {
    this->name = name;
  }
};
