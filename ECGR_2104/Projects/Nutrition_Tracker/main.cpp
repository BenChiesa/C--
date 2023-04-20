#include <iostream>
#include <vector>
#include <stdlib.h>
#include "nutrition.h"

using namespace std;

void output(FoodItem foodTotal, FoodItem foodAverage);

int main(){
    vector<FoodItem> food;
    int input;
    
    FoodItem food1("Apple", 95, 0.3, 19, 0.5, 0.002);
    FoodItem food2("Pizza", 285, 10, 3.8, 12, 0.64);
    FoodItem food3("Fried Chicken", 320, 16, 0, 40, 0.1);
    FoodItem food4("French Fries", 365, 17, 0.4, 4, 0.246);
    FoodItem food5("Eggs", 78, 5, 0.6, 6, 0.062);
    FoodItem food6("Spaghetti", 221, 1.3, 0.8, 8, 0.001);
    FoodItem food7("Steak", 679, 48, 0, 62, 0.146);
    FoodItem food8("Grapes", 62, 0.3, 15, 0.6, 0.002);
    FoodItem food9("Chocolate", 155, 9, 14, 1.4, 0.007);
    FoodItem food10("Taco", 156, 9, 0.6, 6, 0.274);
    FoodItem foodTotal("Total", 0, 0, 0, 0, 0);
    FoodItem foodAverage("Daily Average Intake", 2500, 97, 37.5, 60, 3.4);
    
    food.push_back(food1);
    food.push_back(food2);
    food.push_back(food3);
    food.push_back(food4);
    food.push_back(food5);
    food.push_back(food6);
    food.push_back(food7);
    food.push_back(food8);
    food.push_back(food9);
    food.push_back(food10);
    food.push_back(foodTotal);
    food.push_back(foodAverage);
    
    cout << "This program calculates the nutritional value of multiple foods that have been inputted." << endl;
    cout << "All information is based off of a single serving of the food item." << endl;
    
    do{
        cout << "Select a food item by typing its corresponding number" << endl;
        for(int i = 0; i < 10; i++){
            cout << i + 1 << ". " << food.at(i).getName() << endl;
        }
        cout << "11. to exit program" << endl;
        cin >> input;
        switch(input){
            case 1:
                foodTotal += food1;
            break;
            
            case 2:
                foodTotal += food2;
            break;
            
            case 3:
                foodTotal += food3;
            break;
            
            case 4:
                foodTotal += food4;
            break;
            
            case 5:
                foodTotal += food5;
            break;
            
            case 6:
                foodTotal += food6;
            break;
            
            case 7:
                foodTotal += food7;
            break;
            
            case 8:
                foodTotal += food8;
            break;
            
            case 9:
                foodTotal += food9;
            break;  
            
            case 10:
                foodTotal += food10;
            break;
            
            case 11:
                output(foodTotal, foodAverage);
                exit(0);
            break;
            
            default:
                cout << "Invalid Input" << endl;
                cout << "Select a food item by typing its corresponding number" << endl;
                for(int i = 0; i < food.size(); i++){
                    cout << i + 1 << ". " << food.at(i).getName() << endl;
                }
                cout << "11. to exit program" << endl;
                cin >> input;
                break;
        }
    }while(input != 11);
    
    return 0;
}

void output(FoodItem foodTotal, FoodItem foodAverage){
    cout << "\n" << endl;
                
                cout << "The total amount of calories you consumed was " << foodTotal.getCalories() << "." << endl;
                cout << "The total amount of fat you consumed was " << foodTotal.getFat() << "g." << endl;
                cout << "The total amount of sugar you consumed was " << foodTotal.getSugar() << "g." << endl;
                cout << "The total amount of protein you consumed was " << foodTotal.getProtein() << "g." << endl;
                cout << "The total amount of sodium you consumed was " << foodTotal.getSodium() << "g." << endl;
                
                cout << "\n" << endl;
                
                cout << "The average amount of calories consumed by a person is " << foodAverage.getCalories() << "." << endl;
                cout << "The average amount of fat consumed by a person is " << foodAverage.getFat() << "g." << endl;
                cout << "The average amount of sugar consumed by a person is " << foodAverage.getSugar() << "g." << endl;
                cout << "The average amount of protein consumed by a person is " << foodAverage.getProtein() << "g." << endl;
                cout << "The average amount of sodium consumed by a person is " << foodAverage.getSodium() << "g." << endl;
                
                cout << "\n" << endl;
                
                if(foodTotal.getCalories() > foodAverage.getCalories()){
                    cout << "You consumed" << foodTotal.getCalories() - foodAverage.getCalories() << " over the recommended amount of calories" << endl;
                } 
                else if(foodTotal.getCalories() < foodAverage.getCalories()){
                    cout << "You consumed " << (foodTotal.getCalories() - foodAverage.getCalories()) * -1 << " under the recommended amount of calories" << endl;
                }
                else{
                    cout << "You consumed the recommended amount of calories." << endl;
                }
                
                if(foodTotal.getFat() > foodAverage.getFat()){
                    cout << "You consumed" << foodTotal.getFat() - foodAverage.getFat() << " over the recommended amount of fats" << endl;
                } 
                else if(foodTotal.getFat() < foodAverage.getFat()){
                    cout << "You consumed " << (foodTotal.getFat() - foodAverage.getFat()) * -1 << " under the recommended amount of fats" << endl;
                }
                else{
                    cout << "You consumed the recommended amount of fats." << endl;
                }
                
                if(foodTotal.getSugar() > foodAverage.getSugar()){
                    cout << "You consumed" << foodTotal.getSugar() - foodAverage.getSugar() << " over the recommended amount of sugar" << endl;
                } 
                else if(foodTotal.getSugar() < foodAverage.getSugar()){
                    cout << "You consumed " << (foodTotal.getSugar() - foodAverage.getSugar()) * -1 << " under the recommended amount of sugar" << endl;
                }
                else{
                    cout << "You consumed the recommended amount of sugar." << endl;
                }
                
                if(foodTotal.getProtein() > foodAverage.getProtein()){
                    cout << "You consumed" << foodTotal.getProtein() - foodAverage.getProtein() << " over the recommended amount of protein" << endl;
                } 
                else if(foodTotal.getProtein() < foodAverage.getProtein()){
                    cout << "You consumed " << (foodTotal.getProtein() - foodAverage.getProtein()) * -1 << " under the recommended amount of protein" << endl;
                }
                else{
                    cout << "You consumed the recommended amount of protein." << endl;
                }
                
                if(foodTotal.getSodium() > foodAverage.getSodium()){
                    cout << "You consumed" << foodTotal.getSodium() - foodAverage.getSodium() << " over the recommended amount of sodium" << endl;
                } 
                else if(foodTotal.getSodium() < foodAverage.getSodium()){
                    cout << "You consumed " << (foodTotal.getSodium() - foodAverage.getSodium()) * -1 << " under the recommended amount of sodium" << endl;
                }
                else{
                    cout << "You consumed the recommended amount of sodium." << endl;
                }
}