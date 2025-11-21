#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ---------------------------------------------------------
// Klasa 1: Weapon (Broń)
// Odpowiada za przechowywanie informacji o nazwie broni i jej sile.
// ---------------------------------------------------------
class Weapon {
public:
    string name;
    int damage;
    int range;

    // Konstruktor - ustawia początkowe wartości
    Weapon(string aname, int adamage, int arange) {
        name = aname;
        damage = adamage;
        range = arange;
    }

    // Metoda do wyświetlania statystyk broni
    void displayStats() {
        cout << "[Broń] " << name << " (Obrażenia: " << damage << ")" << endl;
    }
};

// ---------------------------------------------------------
// Klasa 2: Character (Postać)
// Posiada imię, punkty zdrowia i metody do walki.
// ---------------------------------------------------------
class Character {
private:
    // Pola prywatne (dostępne tylko wewnątrz tej klasy)
    string name;
    int health;

public:
    // Konstruktor
    Character(string n, int h) {
        name = n;
        health = h;
    }

    // Metoda: Atakowanie innej postaci
    // Przyjmuje referencję do celu (target) i referencję do broni (weapon)
    void attack(Character &target, Weapon &weapon) {
        cout << endl << name << " atakuje " << target.getName() 
             << " uzywajac " << weapon.name << "!" << endl;
        
        target.takeDamage(weapon.damage);
    }

    // Metoda: Otrzymywanie obrażeń
    void takeDamage(int amount) {
        health -= amount;
        if (health < 0) health = 0;
        
        cout << name << " otrzymuje " << amount << " obrazen." << endl;
        cout << "Pozostale zdrowie " << name << ": " << health << " HP." << endl;
    }

    // Getter (pobieranie imienia, bo pole 'name' jest prywatne)
    string getName() {
        return name;
    }
    
    // Sprawdzenie czy postać żyje
    bool isAlive() {
        return health > 0;
    }
};

// ---------------------------------------------------------
// Główna funkcja programu
// ---------------------------------------------------------
int main() {
    // 1. Tworzenie obiektów klasy Weapon
    Weapon sword("Excalibur", 25, 1);
    Weapon axe("Topór Wikinga", 40, 2);
    Weapon karabin("AK-47", 200, 10);

    // 2. Tworzenie obiektów klasy Character
    Character hero("Wiedzmin", 100);
    Character monster("Ghoul", 60);

    // Wyświetlenie dostępnych broni
    cout << "--- DOSTEPNE BRONIE ---" << endl;
    sword.displayStats();
    axe.displayStats();

    // 3. Symulacja walki (Interakcja między obiektami)
    cout << "\n--- ROZPOCZECIE WALKI ---" << endl;

    // Bohater atakuje potwora mieczem
    hero.attack(monster, sword);

    // Potwór atakuje bohatera (używając innej broni, np. topora lub pazurów jako "broni")
    if (monster.isAlive()) {
        monster.attack(hero, axe);
    }

    // Bohater wykańcza potwora
    hero.attack(monster, sword); // Drugi cios
    hero.attack(monster, sword); // Trzeci cios (jeśli potrzebny)

    if (!monster.isAlive()) {
        cout << "\n--> " << monster.getName() << " zostal pokonany!" << endl;
    }

    return 0;
}