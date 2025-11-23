#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Move Class
class Move
{
public:
    string moveName;
    int movePower;

    Move(string n = "", int p = 0)
    {
        moveName = n;
        movePower = p;
    }
};

// Base Pokemon Class
class Pokemon
{
protected:
    string pokemonName, pokemonType;
    int health, attackPower, defensePower;

public:
    Move moveOne, moveTwo;

    Pokemon(string name, string type, int hp, int atk, int def, Move m1, Move m2)
    {
        pokemonName = name;
        pokemonType = type;
        health = hp;
        attackPower = atk;
        defensePower = def;
        moveOne = m1;
        moveTwo = m2;
    }

    // Type Advantage
    double typeMultiplier(string attackerType, string defenderType)
    {

        if (attackerType == "electric" && defenderType == "water")
            return 2.0;
        if (attackerType == "fire" && defenderType == "grass")
            return 2.0;
        if (attackerType == "grass" && defenderType == "water")
            return 2.0;
        if (attackerType == "water" && defenderType == "fire")
            return 2.0;

        if (attackerType == "grass" && defenderType == "fire")
            return 0.5;
        if (attackerType == "water" && defenderType == "grass")
            return 0.5;
        if (attackerType == "fire" && defenderType == "water")
            return 0.5;
        if (attackerType == "water" && defenderType == "electric")
            return 0.5;

        return 1.0;
    }

    // Damage Calculation
    void useMove(Pokemon &opponent, Move chosenMove)
    {
        double effectiveness = typeMultiplier(pokemonType, opponent.pokemonType);

        int damage = chosenMove.movePower + attackPower - opponent.defensePower;

        damage += rand() % 6 - 3;

        if (damage < 1)
            damage = 1;

        damage *= effectiveness;
        opponent.health -= damage;

        if (opponent.health < 0)
            opponent.health = 0;

        cout << pokemonName << " used " << chosenMove.moveName << " and dealt " << damage;

        if (effectiveness > 1)
            cout << " (super effective)";
        else if (effectiveness < 1)
            cout << " (not very effective)";

        cout << "\n";
    }

    bool isAlive() { return health > 0; }
    int getHP() { return health; }
    string getName() { return pokemonName; }
};

// Pokémon Classes
class Pikachu : public Pokemon
{
public:
    Pikachu() : Pokemon("Pikachu", "electric", 100, 22, 12,
                        Move("Thunder Shock", 18), Move("Quick Attack", 15)) {}
};

class Charmander : public Pokemon
{
public:
    Charmander() : Pokemon("Charmander", "fire", 110, 20, 14,
                           Move("Flamethrower", 20), Move("Scratch", 14)) {}
};

class Bulbasaur : public Pokemon
{
public:
    Bulbasaur() : Pokemon("Bulbasaur", "grass", 120, 18, 18,
                          Move("Vine Whip", 17), Move("Tackle", 13)) {}
};

Pokemon *selectPokemon()
{
    cout << "\nChoose Pokémon:\n";
    cout << "1. Pikachu\n";
    cout << "2. Charmander\n";
    cout << "3. Bulbasaur\n";

    int choice;
    cin >> choice;

    while (choice < 1 || choice > 3)
    {
        cout << "Invalid choice, enter 1-3: ";
        cin >> choice;
    }

    if (choice == 1)
        return new Pikachu();
    if (choice == 2)
        return new Charmander();
    return new Bulbasaur();
}

void battle(Pokemon &p1, Pokemon &p2, bool isCPUOpponent)
{
    cout << "\nBattle Starts: " << p1.getName() << " vs " << p2.getName() << "\n";

    while (p1.isAlive() && p2.isAlive())
    {

        //Player 1 Turn
        cout << "\n"
             << p1.getName() << " HP: " << p1.getHP() << "\n";
        cout << p2.getName() << " HP: " << p2.getHP() << "\n";

        cout << "\n"
             << p1.getName() << " choose move:\n";
        cout << "1. " << p1.moveOne.moveName << "\n";
        cout << "2. " << p1.moveTwo.moveName << "\n";

        int playerMove;
        cin >> playerMove;

        while (playerMove != 1 && playerMove != 2)
        {
            cout << "Enter 1 or 2: ";
            cin >> playerMove;
        }

        if (playerMove == 1)
            p1.useMove(p2, p1.moveOne);
        else
            p1.useMove(p2, p1.moveTwo);

        if (!p2.isAlive())
            break;

        //Plyer 2 Turn
        if (isCPUOpponent)
        {
            cout << "\nCPU turn:\n";
            int randomMove = rand() % 2;
            if (randomMove == 0)
                p2.useMove(p1, p2.moveOne);
            else
                p2.useMove(p1, p2.moveTwo);
        }
        else
        {
            cout << "\n"
                 << p2.getName() << " choose move:\n";
            cout << "1. " << p2.moveOne.moveName << "\n";
            cout << "2. " << p2.moveTwo.moveName << "\n";

            int player2Move;
            cin >> player2Move;

            while (player2Move != 1 && player2Move != 2)
            {
                cout << "Enter 1 or 2: ";
                cin >> player2Move;
            }

            if (player2Move == 1)
                p2.useMove(p1, p2.moveOne);
            else
                p2.useMove(p1, p2.moveTwo);
        }
    }

    cout << "\nWinner: ";
    if (p1.isAlive())
        cout << p1.getName();
    else
        cout << p2.getName();
    cout << "\n";
}

int main()
{
    srand(time(0));

    cout << "Mini Pokémon Battle Game\n";
    cout << "Choose Mode:\n";
    cout << "1. Player vs CPU\n";
    cout << "2. Player vs Player\n";

    int gameMode;
    cin >> gameMode;

    while (gameMode != 1 && gameMode != 2)
    {
        cout << "Enter 1 or 2: ";
        cin >> gameMode;
    }

    Pokemon *player1Pokemon = selectPokemon();
    Pokemon *player2Pokemon;

    if (gameMode == 1)
    {
        Pokemon *options[3] = {new Pikachu(), new Charmander(), new Bulbasaur()};
        player2Pokemon = options[rand() % 3];
        cout << "CPU chose " << player2Pokemon->getName() << "\n";
    }
    else
    {
        cout << "\nPlayer 2 choose:\n";
        player2Pokemon = selectPokemon();
    }

    battle(*player1Pokemon, *player2Pokemon, gameMode == 1);

    return 0;
}
