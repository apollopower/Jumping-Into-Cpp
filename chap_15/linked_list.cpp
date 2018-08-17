# include <iostream>

using namespace std;

struct EnemySpaceShip {
    int x_coordinate;
    int y_coordinate;
    int weapon_power;
    // Pointer to next enemy
    EnemySpaceShip* p_next_enemy;
};

EnemySpaceShip* addNewEnemyToList(EnemySpaceShip* p_enemies) {
    EnemySpaceShip* p_ship = new EnemySpaceShip;
    // Using arrow syntax to access struct attributes 
    p_ship->x_coordinate = 0;
    p_ship->y_coordinate = 0;
    p_ship->weapon_power = 20;
    p_ship->p_next_enemy = p_enemies;
    return p_ship;
}

void upgradeWeapons(EnemySpaceShip* p_ship) {
    p_ship->weapon_power += 10;
}

int main() {
    EnemySpaceShip* p_enemies = NULL;

    // Adding 3 enemies to p_enemies:
    for (int i = 0; i < 3; i++) {
        p_enemies = addNewEnemyToList(p_enemies);
    }

    cout << "3 enemies added!\n";
    cout << "Upgrading their weapons...\n";

    // Traversing linked list and calling upgradeWeapons
    // Setting a pointer to first enemy in linked list
    EnemySpaceShip* p_current = p_enemies;

    while (p_current != NULL) {
        upgradeWeapons(p_current);
        cout << "Enemy weapons set to power "
             << p_current->weapon_power << endl;
        p_current = p_current->p_next_enemy;
    }
    
    // Returning memory:
    delete p_current;
    delete p_enemies;

    // End of main() call
    return 0;
}

