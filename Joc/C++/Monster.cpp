#include "..\Headers\Monster.h"

Monster::Monster()
    :Name("Dummy"), maxHealth(5), Health(5), Shield(0), maxMana(0), Mana(0), Level(0)
{}

Monster::Monster(string Name)
        :Name(Name), maxHealth(100), Health(100), Shield(1), maxMana(100), Mana(100), Level(1)
{}

void Monster::DisplayStats() {
    cout << "Monster Name:   " << Name << endl;
    cout << "Monster HP:     " << Health << " out of: " << maxHealth << endl;
    cout << "Monster Mana:   " << Mana << " out of: " << maxMana << endl;
    cout << "Monster Shield: " << Shield << endl;
    cout << "Monster Level:  " << Level << endl;
}

void Monster::DisplayArmor() {
    cout << "Info regarding the armor that the monster's wearing: " << endl;
    for (const auto& pair : Armor) {
        cout << pair.first << " - ";
        for (const auto& subPair : pair.second)
        {
            for (const auto& sub : InventoryQuality)
                    if(sub.first == subPair.first)
                        cout << subPair.first << " gives " << subPair.second << " armor. It has a " << sub.second << " quality.";
            if(subPair.first == "None")
                cout << subPair.first;
            cout << endl;
        }
    }
}

void Monster::DisplayStatusEffects() {
    cout << "Info regarding the status effects that are active: " << endl;
    for (const auto& pair : StatusEffects) {
        if (pair.first == "No effects")
            cout << pair.first << endl;
        else
            for (const auto& sub : TurnsStatusEffects)
                if(sub.first == pair.first)
                    cout << pair.first << " that deals " << pair.second << " damage every round. This effect lasts for " << sub.second << " round(s)" << endl;
    }
}

void Monster::Describe(const string object) {
    bool ok = false;
    for (const auto& pair : DescriptionMonster)
        if(object == pair.first)
            cout << pair.second << endl, ok = true;
    if (ok == false)
        cout << "I think u might have got the wrong game. We ain't got that here. Check yo spelling maybe, idk..." << endl;
}

void Hero::Heal() {
    string input;
    int ok = 0;
    cout << endl;
    while(ok != 1) {
        getline(cin, input);
        if(input == "e" or input == "exit" or input == " e") {
                cout << "Ya fat fingered it didn't ya? Be honest..." << endl;
                break;
        }
        for (const auto& pair : Inventory) {
            if(pair.first == "Healing")
                for (const auto& subPair : pair.second)
                    if(input == subPair.first)
                        for (auto& sub : InventoryQuantity)
                            if(sub.first == input)
                                if(sub.second > 0)
                                    if(Health + subPair.second > maxHealth)
                                        cout << "You kinda overspilled but it's aight" << endl, sub.second--, Health = maxHealth, ok = 1;
                                    else
                                        cout << "You good now" << endl, Health += subPair.second, sub.second--, ok = 1;
                                else
                                    cout << "I don't think u have the facilities for that big man" << endl, ok = 2;
            if(pair.first == "Regeneration")
                for (const auto& subPair : pair.second)
                    if(input == subPair.first)
                        for (auto& sub : InventoryQuantity)
                            if(sub.first == input)
                                if(sub.second > 0)
                                    if(Health + subPair.second > maxHealth){
                                        cout << "You kinda overspilled but it's aight" << endl, sub.second--, Health = maxHealth, ok = 1;
                                        if(StatusEffects[pair.first] == 0)
                                            StatusEffects[pair.first] = subPair.second, TurnsStatusEffects[pair.first] = 2;
                                        else
                                            StatusEffects[pair.first] += subPair.second, TurnsStatusEffects[pair.first] += 2;
                                    }
                                    else {
                                        cout << "You good now" << endl, Health += subPair.second, sub.second--, ok = 1;
                                        if(StatusEffects[pair.first] == 0)
                                            StatusEffects[pair.first] = subPair.second, TurnsStatusEffects[pair.first] = 2;
                                        else
                                            StatusEffects[pair.first] += subPair.second, TurnsStatusEffects[pair.first] += 2;
                                    }
                                else
                                    cout << "I don't think u have the facilities for that big man" << endl, ok = 2;

        }
        if (ok == 0)
            cout << "That's not a healing item silly. Maybe try again?" << endl;
    }
    cout << endl;
}

