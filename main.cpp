#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>

class Observer {
  public:
    virtual void update(double health, double speed, double strength)=0;
};

class Subject {
  public:
    virtual void registerObserver(Observer* o)=0;
    virtual void unregisterObserver(Observer* o)=0;
    virtual void notifyObservers()=0;
};

class Character:public Subject{
    private:
        std::vector<Observer*> observerList;
        double health = 0;
        double speed = 0;
        double strength = 0;

        void notifyObservers(){
        for (int i = 0; i < observerList.size(); i++ ) {
        if (observerList.at(i) != nullptr) {
          observerList.at(i)->update(health,speed,strength);
        }
      }
    }




    public:

        Character(){

        }

        void registerObserver(Observer* o){
           observerList.push_back(o);
       }

        void unregisterObserver(Observer* o){
        for (int i = 0; i < observerList.size(); i++ ) {
            if (observerList.at(i) == o) {
             observerList.erase(observerList.begin()+i);
        }
      }
    }

        void sethealth(double newhealth){
            health = newhealth;
            notifyObservers();
        }

        void setspeed(double newspeed) {
            speed = newspeed;
            notifyObservers();
        }

        void setstrength(double newstrength) {
            strength = newstrength;
            notifyObservers();
        }

};


class CharacterObserver: public Observer{
 private:
        double health;
        double speed;
        double strength;

        


 public:

   void update(double newhealth, double newspeed, double newstrength){
      health  = newhealth;
      speed = newspeed;
      strength = newstrength;

      display();
   }

   void display(){
       std::cout << "Health: "  << health  << "\n";
       std::cout << "Speed: " << speed << "\n";
       std::cout << "Strength: " << strength << "\n";
   }


};




int main() {

    CharacterObserver characterDisplay = CharacterObserver();
    Character character = Character();

    character.registerObserver(&characterDisplay);

    std::cout << "Leveling Up Health\n";
    character.sethealth(127);

    std::cout << "\n";
    std::cout << "Leveling Up Speed\n";
    character.setspeed(150);

    std::cout << "\n";
    std::cout << "Leveling Up Strength\n";
    character.setstrength(183);

    character.unregisterObserver(&characterDisplay);


}
