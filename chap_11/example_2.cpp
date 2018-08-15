// Structures

// Example of creating and updating structures, by making copies
// (refer to pointers to improve performance rather than copying structs)

# import <iostream>

using namespace std;

// Defining our new strucure, EnemySpaceShip
struct EnemySpaceShip {
    int x_coordinate;
    int y_coordinate;
    int weapon_power;
};

// Function to generate new structure of EnemySpaceShip
EnemySpaceShip getNewEnemy() {
    EnemySpaceShip ship;
    ship.x_coordinate = 0;
    ship.y_coordinate = 0;
    ship.weapon_power = 20;
    return ship;
}

// Function to upgrade weapon_power, changing a structure
EnemySpaceShip upgradeWeapons(EnemySpaceShip ship) {
    ship.weapon_power += 10;
    return ship;
}

// Our main function to execute:
int main() {
    EnemySpaceShip enemy = getNewEnemy();
    // Since the upgrade function only creates a copy
    // of the passed in "enemy", the changes aren't 
    // automatically saved!
    // Hence we need to pass the copy as the new "enemy"
    enemy = upgradeWeapons(enemy);

    cout << enemy.weapon_power << endl;
}