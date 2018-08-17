// Data Structures: LINKED LISTS:

# include <iostream>

using namespace std;

struct EnemySpaceShip {
    int x_coordinate;
    int y_coordinate;
    int weapon_power;
    // Adding pointer to next struct (linked list feature)
    EnemySpaceShip* p_next_enemy;
};

EnemySpaceShip* getNewEnemy() {
    // Pulling from free memory amount needed for an EnemySpaceShip:
    EnemySpaceShip* p_ship = new EnemySpaceShip;

    // Using the '->' operator to access fields of struct
    // with a pointer:
    p_ship->x_coordinate = 0;
    p_ship->y_coordinate = 0;
    p_ship->weapon_power = 20;
    // Since we are just initializing the pointer to what would be
    // the next ship, we set it to NULL (since there obviously is no
    // other ship to point it to)
    p_ship->p_next_enemy = NULL;
    return p_ship;
}

void upgradeWeapons(EnemySpaceShip* p_ship) {
    // Through the memory of our ship (accessed by pointer p_ship)
    // we can make our update without having to rely on instantiating
    // a copied ship:
    p_ship->weapon_power += 10;
}

int main() {
    EnemySpaceShip* p_enemy = getNewEnemy();
    upgradeWeapons(p_enemy);
    cout << p_enemy->weapon_power << endl;
}