#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // for usleep

using namespace std;

class Animal {
private:
    string name;
    double energy;
    double happiness;

public:
    Animal(const string& petName, double initialEnergy = 100, double initialHappiness = 50)
        : name(petName), energy(initialEnergy), happiness(initialHappiness) {}

    double getEnergy() const { return energy; }
    double getHappiness() const { return happiness; }
    string getName() const { return name; }

    void play() {
        energy += 20;
        happiness += 10;
    }

    void idle() {
        energy -= 10;
        happiness -= 5;
    }

    bool isTired() const {
        return energy <= 0;
    }

    virtual void displayInfo() const = 0;
};

class Bird : public Animal {
public:
    Bird(const string& name) : Animal(name) {}
    void displayInfo() const override {
        cout << "Bird Name: " << getName() << endl << "Energy: " << getEnergy() << endl << "Happiness: " << getHappiness() << endl;
        cout << "-------------------------------------" << endl;
    }
};

class Hamster : public Animal {
public:
    Hamster(const string& name) : Animal(name) {}
    void displayInfo() const override {
        cout << "Hamster Name: " << getName() << endl << "Energy: " << getEnergy() << endl << "Happiness: " << getHappiness() << endl;
        cout << "-------------------------------------" << endl;
    }
};

class Turtle : public Animal {
public:
    Turtle(const string& name) : Animal(name) {}
    void displayInfo() const override {
        cout << "Turtle Name: " << getName() << endl << "Energy: " << getEnergy() << endl << "Happiness: " << getHappiness() << endl;
        cout << "-------------------------------------" << endl;
    }
};

class Dog : public Animal {
public:
    Dog(const string& name) : Animal(name) {}
    void displayInfo() const override {
        cout << "Dog Name: " << getName() << endl << "Energy: " << getEnergy() << endl << "Happiness: " << getHappiness() << endl;
        cout << "-------------------------------------" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(const string& name) : Animal(name) {}
    void displayInfo() const override {
        cout << "Cat Name: " << getName() << endl << "Energy: " << getEnergy() << endl << "Happiness: " << getHappiness() << endl;
        cout << "-------------------------------------" << endl;
    }
};

class Fish : public Animal {
public:
    Fish(const string& name) : Animal(name) {}
    void displayInfo() const override {
        cout << "Fish Name: " << getName() << endl << "Energy: " << getEnergy() << endl << "Happiness: " << getHappiness() << endl;
        cout << "-------------------------------------" << endl;
    }
};

class PetActivity {
public:
    void sleep() {
        int timeInMinutes;
        cout << "Welcome To The Bedroom " << endl;
        cout << "Here Your Pet Can Sleep And Rest" << endl;
        cout << "Enter Time in Minutes For The Pet to Sleep: ";
        cin >> timeInMinutes;
        cout << "Pet Sleeping For " << timeInMinutes << " minutes" << endl;
    }

    void feed() {
        cout << "Feeding Pet" << endl;
    }

    void cleanCage() {
        cout << "Cleaning Pet's Cage" << endl;
    }

    void giveBath() {
        cout << "Giving Pet a Bath" << endl;
    }

    void train(Animal* pet) {
        cout << "Choose a training for your pet:" << endl;
        cout << "1. Agility" << endl;
        cout << "2. Strength" << endl;
        cout <<"3. Intelligence" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << pet->getName() << " is training agility!" << endl;
                break;
            case 2:
                cout << pet->getName() << " is training strength!" << endl;
                break;
            case 3:
            cout << pet->getName() << "is training intelligence!" << endl;
            break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    
    void participateInRandomEvent(Animal* pet) {
        cout << "Choose a random event for your pet:" << endl;
        cout << "1. Race" << endl;
        cout << "2. Jump" << endl;
        cout << "3. Show love" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << pet->getName() << " is participating in a race!" << endl;
                break;
            case 2:
                cout << pet->getName() << " is participating in a jump event!" << endl;
                break;
            case 3:
                cout << "You are showing love to " << pet->getName() << "!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    void playMiniGame(Animal* pet) {
        cout << "Choose a mini-game for your pet:" << endl;
        cout << "1. Puzzle" << endl;
        cout << "2. Golf" << endl;
        cout << "3. Ball game" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Playing puzzle with " << pet->getName() << "!" << endl;
                break;
            case 2:
                cout << "Playing golf with " << pet->getName() << "!" << endl;
                break;
            case 3:
                cout << "Playing ball game with " << pet->getName() << "!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
};

class Game {
private:
    int coins;
    int level;
    int happinessLevel;

public:
    Game(int initialCoins = 10, int initialLevel = 1, int initialHappiness = 40)
        : coins(initialCoins), level(initialLevel), happinessLevel(initialHappiness) {}

    void showStats() const {
        cout << "Level: " << level << endl;
        cout << "Coins available: " << coins << endl;
        cout << "To Level Up You Need To Have 2 Coins And A Happiness Level OF 40" << endl;
        cout << "Happiness Level = " << happinessLevel << endl;
        usleep(2500000);
    }

    void feed() {
        char choice;

        do {
            cout << "Feeding Pet" << endl;
            coins += 3;
            cout << "Coin Gained" << endl;
            cout << "Number of Coins: " << coins << endl;
            cout << "Happiness Level Has Increased" << endl;
            happinessLevel += 10;
            cout << "New Happiness Level: " << happinessLevel << endl;
            cout << "Do You Want To Continue Feeding(Y/N): ";
            cin >> choice;
        } while (choice != 'n' && choice != 'N');
        cout << "Done Feeding The Pet" << endl;
        usleep(2000000);
    }

    void levelUp() {
        if (coins >= 2 && happinessLevel >= 40) {
            level++;
            coins -= 2;
            cout << "Level Increased!! ---- Congratulations ----" << endl;
        } else {
            cout << "You Don't Have Enough Coins To Level Up" << endl;
        }
        cout << "Current Level: " << level << endl;
        usleep(2500000);
    }

    void embarkOnQuest(Animal* pet) {
        // Quest logic here...
        cout << "Embarking on a quest with " << pet->getName() << "!" << endl;
    }
};

int main() {
    string petName;
    char choice;

    do {
        cout << "\t\t ----- Welcome To Pet Adoption Center ----- " << endl;
        cout << "Choose a pet to adopt:" << endl;
        cout << "1. Bird" << endl;
        cout << "2. Hamster" << endl;
        cout << "3. Turtle" << endl;
        cout << "4. Dog" << endl;
        cout << "5. Cat" << endl;
        cout << "6. Fish" << endl;
        cout << "Enter your choice (1-6): ";
        int petChoice;
        cin >> petChoice;

        switch (petChoice) {
            case 1:
                cout << "Bird Has Been Adopted" << endl;
                cout << "Please Give Your Bird A Name: ";
                cin >> petName;
                break;
            case 2:
                cout << "Hamster Has Been Adopted" << endl;
                cout << "Please Give Your Hamster A Name: ";
                cin >> petName;
                break;
            case 3:
                cout << "Turtle Has Been Adopted" << endl;
                cout << "Please Give Your Turtle A Name: ";
                cin >> petName;
                break;
            case 4:
                cout << "Dog Has Been Adopted" << endl;
                cout << "Please Give Your Dog A Name: ";
                cin >> petName;
                break;
            case 5:
                cout << "Cat Has Been Adopted" << endl;
                cout << "Please Give Your Cat A Name: ";
                cin >> petName;
                break;
            case 6:
                cout << "Fish Has Been Adopted" << endl;
                cout << "Please Give Your Fish A Name: ";
                cin >> petName;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

        if (!petName.empty()) {
//            Animal* pet = nullptr;

            switch (petChoice) {
                case 1:
                    pet = new Bird(petName);
                    break;
                case 2:
                    pet = new Hamster(petName);
                    break;
                case 3:
                    pet = new Turtle(petName);
                    break;
                case 4:
                    pet = new Dog(petName);
                    break;
                case 5:
                    pet = new Cat(petName);
                    break;
                case 6:
                    pet = new Fish(petName);
                    break;
            }

            if (pet) {
                PetActivity activity;
                Game game;
                int choice;

                do {
                    cout << "\t\t ----- Choose an activity for your pet ----- " << endl;
                    cout << "1. Sleep" << endl;
                    cout << "2. Feed" << endl;
                    cout << "3. Clean Cage" << endl;
                    cout << "4. Give Bath" << endl;
                    cout << "5. Train" << endl;
                    cout << "6. Participate in Random Event" << endl;
                    cout << "7. Play Mini Game" << endl;
                    cout << "8. Level up" << endl;
                    cout << "9. Embark on a Quest" << endl;
                    cout << "10. Quit " << endl;
                    cout << "Enter your choice (1-10): ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            activity.sleep();
                            break;
                        case 2:
                            activity.feed();
                            break;
                        case 3:
                            activity.cleanCage();
                            break;
                        case 4:
                            activity.giveBath();
                            break;
                        case 5:
                            activity.train(pet);
                            break;
                        case 6:
                            activity.participateInRandomEvent(pet);
                            break;
                        case 7:
                            activity.playMiniGame(pet);
                            break;
                        case 8:
                            game.levelUp();
                            break;
                        case 9:
                            game.embarkOnQuest(pet);
                            break;
                        case 10:
                            cout << "Leaving " << pet->getName() << " in the Pet Adoption Center " << endl << endl;
                            break;
                        default:
                            cout << "Invalid choice! Please try again." << endl;
                    }
                } while (choice != 10);

                delete pet;
            }
        }

        cout << "Do You want To Adopt Another Pet (Y/N): " << endl;
        cin >> choice;
    } while (choice != 'N' && choice != 'n');

    cout << "\t\t ----- SUSCCESSFULLY EXITED PET ADOPTION CENTER -----" << endl;

    return 0;
}
