#include <iostream>
#include <sstream>
#include <time.h>

using namespace std;

class Player {
    public:
    Player(int x, int y){
        health = MAX_HEALTH;
        hunger = MAX_HUNGER;
        thirst = MAX_THIRST;
        
        this->x = x;
        this->y = y;
        this->score = 0;
    }
    
    int getScore() const {
        return score;
    }
    
    void takeDamage(int val){
        this->health -= val;
        if(this->health < 0) this->health = 0;
    }
    
    void takeTurn(){
        this->thirst--;
        this->hunger--;
        
        if(this->thirst <= 0){
            this->health--;
            this->thirst = 0;
        }
        
        if(this->hunger <= 0){
            this->health--;
            this->hunger = 0;
        }
        
        this->score++;
    }
    
    string getStats() const {
        stringstream ss;
        ss  << "============\n"
            << "Health: " << this->health << "\n" 
            << "Hunger: " << this->hunger << "\n" 
            << "Thirst: " << this->thirst << "\n"
            << "============\n";
        return ss.str();
    }
    
    bool isAlive() const {
        return this->health > 0;
    }
    
    void increaseThrist(int val){
        this->thirst = this->thirst + val;
        if(this->thirst > MAX_THIRST) this->thirst = MAX_THIRST;
    }
    
    void increaseHunger(int val){
        this->hunger += val;
        if(this->hunger > MAX_HUNGER) this->hunger = MAX_HUNGER;
    }
    
    void increaseHealth(int val){
        this->health += val;
        if(this->health > MAX_HEALTH) this->health = MAX_HEALTH;
    }
    
    int x, y;
    private:
    int health, hunger, thirst, score;
    const int MAX_HEALTH = 3;
    const int MAX_HUNGER = 5;
    const int MAX_THIRST = 3;
};

class Land {
    public:
    virtual string getDescription() = 0;
    virtual string visit(Player& player) = 0;
};

class Forest : public Land {
    public:
    string getDescription(){
        return "a densely wooded forest.";
    }
    
    string visit(Player& player){
        int randomNum = rand() % 100;
        
        if(randomNum > 74){
            player.takeDamage(1);
            return "You are attacked by a bear while foraging for berries.";
        } else {
            player.increaseHunger(1);
            return "You forage for berries in the woods and eat a few.";
        }
    }
};

class Lake : public Land {
    public:
    string getDescription(){
        return "a clear sparkling lake.";
    }
    
    string visit(Player& player){
        player.increaseThrist(2);
        return "You visit the lake and drink its clean water";
    }
};

class Desert : public Land {
    public:
    string getDescription(){
        return "a dry sandy wasteland";
    }
    
    string visit(Player& player){
        int randomNum = rand() % 100;
        
        if(randomNum >= 95){
            player.increaseThrist(1);
            return "You find an oasis and drink its water";
        }
        
        else if(randomNum > 95 && randomNum < 60){
            player.takeDamage(1);
            return "There is a dust storm and you breath in lots of sand";
        }
        
        else if(randomNum >= 60){
            player.increaseHunger(1); 
            return "You hunt some wildlife to cook and eat";
        } 
    }
};

class Ocean : public Land {
  public: 
  string getDescription(){
      return "a vast body of water";
  }
  
  string visit(Player& player){
      int randomNum = rand() % 100;
      
      if(randomNum > 95){
          player.takeDamage(3);
          return "You notice the water pulling back and a giant wave forms...";
      }
      if(randomNum <= 95 && randomNum >= 5){
          player.increaseHunger(1);
          return "You caught a fish and decided to cook and eat it";
      }
      if(randomNum < 5){
          player.takeDamage(1);
          return "While fishing you caught a shark and it bit you";
      }
  }
};

class Village : public Land {
  public: 
  string getDescription(){
      return "a civilization";
  }
  
  string visit(Player& player){
      int randomNum = rand() % 100;
      
      if(randomNum > 69){
          player.takeDamage(3);
          return "You find out that the villagers don't like outsiders";
      }
      if(randomNum <= 69 && randomNum >= 20){
          player.increaseHunger(2);
          player.increaseThrist(1);
          return "The villagers take you in and give you a meal";
      }
      if(randomNum < 20){
          player.increaseHealth(1);
          return "One of the villagers is a doctor and tends to your health";
      }
  }
};

const int MAP_SIZE = 10;
Land* map[MAP_SIZE][MAP_SIZE];

void populateMap(){
    for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
            int randomNum = rand() % 5;
            switch(randomNum){
                case 0:
                    map[i][j] = new Forest;
                    break;
                case 1:
                    map[i][j] = new Lake;
                    break;
                case 2:
                    map[i][j] = new Desert;
                    break;
                case 3:
                    map[i][j] = new Ocean;
                    break;
                case 4:
                    map[i][j] = new Village;
                    break;
                default:
                    cout << "Invalid land type selected" << endl;
                    break;
            }
        }
    }
}

int main(){
    srand(time(0));
    
    populateMap();
    
    Player player(MAP_SIZE/2, MAP_SIZE/2);
    
    cout << "You wake up and find yourself lost in the middle of a strange wilderness." << endl;
    
    // TODO: Handle boundary conditions (e.g., if index out of bounds north, you index the south-most location)
    
    while(player.isAlive()){
        cout << "To the north you see " << map[player.x][player.y - 1]->getDescription() << endl;
        cout << "To the east you see " << map[player.x + 1][player.y]->getDescription() << endl;
        cout << "To the south you see " << map[player.x][player.y + 1]->getDescription() << endl;
        cout << "To the west you see " << map[player.x - 1][player.y]->getDescription() << endl;
        
        cout << "Which way will you go? Enter N, E, S, or W:" << endl;
        char userInput;
        cin >> userInput;
        
        switch(userInput){
            case 'N':
                player.y = player.y - 1;
                break;
            case 'E':
                player.x = player.x + 1;
                break;
            case 'S':
                player.y = player.y + 1;
                break;
            case 'W':
                player.x = player.x - 1;
                break;
            default:
                break;
        }
        if(player.y > 9){
            player.y = player.y - 10;
        }
        
        if(player.y < 0){
            player.y = player.y + 10;
        }
        
        if(player.x > 9){
            player.x = player.x - 10;
        }
        
        if(player.x < 0){
            player.x = player.x + 10;
        }
        
        cout << map[player.x][player.y]->visit(player) << endl;
        
        cout << player.getStats() << endl;
        player.takeTurn();
    }
    
    cout << "You died." << endl;
    cout << player.getScore() << endl;
    
    return 0;
}