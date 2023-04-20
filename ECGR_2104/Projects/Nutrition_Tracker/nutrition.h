#ifndef NUTRITION_H
#define NUTRITION_H

#include <iostream>

using namespace std;

class FoodItem {
    public:
        FoodItem(string n, int c, double f, double s, double p, double Na){
            setName(n);
            setCalorie(c);
            setFat(f);
            setSugar(s);
            setProtein(p);
            setSodium(Na);
        }
    
    void setName(string n){
        name = n;
    }
    
    string getName(){
        return name;
    }
    
    void setCalorie(int c){
        calories = c;
    }
    
    int getCalories(){
        return calories;
    }
    
    void setFat(double f){
        totalFat = f;
    }
    
    double getFat(){
        return totalFat;
    }
    
    void setSugar(double s){
        totalSugars = s;
    }
    
    double getSugar(){
        return totalSugars;
    }
    
    void setProtein(double p){
        protein = p;
    }
    
    double getProtein(){
        return protein;
    }
    
    void setSodium(double Na){
        sodium = Na;
    }
    
    double getSodium(){
        return sodium;
    }
    
    FoodItem operator+=(const FoodItem& item){
        FoodItem result("Result", 0, 0, 0, 0, 0);
        result.calories += item.calories;
        result.totalFat += item.totalFat;
        result.totalSugars += item.totalSugars;
        result.protein += item.protein;
        result.sodium += item.sodium;
        return result;
    }
    
    private:
        string name;
        int calories;
        double totalFat, totalSugars, protein, sodium;
};

#endif