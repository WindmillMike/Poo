#include "..\Headers\Hero.h"

Hero::Hero()
    :Name("Dummy"), maxHealth(5), Health(5), Shield(0), maxMana(0), Mana(0), Wallet(0), Level(0)
{}

Hero::Hero(string Name)
    :Name(Name), maxHealth(100), Health(100), Shield(1), maxMana(100), Mana(100), Wallet(10), Level(1)
{Skills["Neutral"]["Basic Attack"] = 15;
Cooldown["Basic Attack"] = 0;
SkillsQuality["Basic Attack"] = "Common";
SkillsStatusEffects["Basic Attack"] = "No effects";
Cooldown["Basic Attack"] = 0;

Inventory["Primary"]["Wooden Sword"] = 15;
Inventory["Accessories"]["Iron Ring"] = 1;
Inventory["Armor"]["None"] = 0;
Inventory["Healing"]["Small Healing Potion"] = 10;

InventoryQuality["Basic Attack"] = "Common";
InventoryQuality["Wooden Sword"] = "Common";
InventoryQuality["Iron Ring"] = "Common";
InventoryQuality["Small Healing Potion"] = "Common";

InventoryQuantity["Small Healing Potion"] = 2;
InventoryQuantity["Wooden Sword"] = 1;
InventoryQuantity["Iron Ring"] = 1;

Armor["Helmet"]["None"] = 0;
Armor["Chestplate"]["None"] = 0;
Armor["Gloves"]["None"] = 0;
Armor["Leggings"]["None"] = 0;
Armor["Boots"]["None"] = 0;
Armor["Accessory"]["Iron Ring"] = 1;

StatusEffects["No effects"] = 0;
TurnsStatusEffects["No effects"] = 0;

DescriptionHero["Basic Attack"]         = "You basically attack with your sword";
DescriptionHero["Wooden Sword"]         = "The starting sword of every adventurer";
DescriptionHero["Iron Ring"]            = "The starting accessory of every adventurer. At least I think so...";
DescriptionHero["Small Healing Potion"] = "The basic healing kit of every adventurer";
}

Hero::Hero(string Name, int maxHealth, int Health, int Shield, int maxMana, int Mana,
         int Wallet, int Level, map<string, map<string, int>> Skills,
         map<string, string> SkillsStatusEffects, map<string, int> Cooldown,
         map<string, string> SkillsQuality, map<string, map<string, int>> Inventory,
         map<string, string> InventoryQuality, map<string, int> InventoryQuantity,
         map<string, map<string, int>> Armor, map<string, int> StatusEffects,
         map<string, int> TurnsStatusEffects, map<string, string> DescriptionHero)
    :Name(Name), maxHealth(maxHealth), Health(Health), Shield(Shield), maxMana(maxMana), Mana(Mana),
    Wallet(Wallet), Level(Level), Skills(Skills), SkillsStatusEffects(SkillsStatusEffects),
    Cooldown(Cooldown), SkillsQuality(SkillsQuality),
    Inventory(Inventory), InventoryQuality(InventoryQuality), InventoryQuantity(InventoryQuantity),
    Armor(Armor), StatusEffects(StatusEffects), TurnsStatusEffects(TurnsStatusEffects),
    DescriptionHero(DescriptionHero)
{}

void Hero::DisplayStats() {
    cout << "Hero Name:   " << Name << endl;
    cout << "Hero HP:     " << Health << " out of: " << maxHealth << endl;
    cout << "Hero Mana:   " << Mana << " out of: " << maxMana << endl;
    cout << "Hero Shield: " << Shield << endl;
    if(Wallet < 5)
    {
        cout << "A fly mocks you while it flies away from your wallet" << endl;
        cout << "You once again realize that you're a Brokie" << endl << endl;
    }
    else
        cout << "Wallet:      " << Wallet << endl;
    cout << "Hero Level:  " << Level << endl;
}

void Hero::DisplayInventory() {
    cout << "Your inventory contains: " << endl;
    for (const auto& pair : Inventory) {
        cout << pair.first << " - ";
        for (const auto& subPair : pair.second)
        {
            if(pair.first == "Accessories" or pair.first == "Armor" and subPair.first != "None")
                for (const auto& sub : InventoryQuantity)
                    for (const auto& sub2 : InventoryQuality)
                        if(sub.first == subPair.first and subPair.first == sub2.first)
                            cout << subPair.first << " gives " << subPair.second << " armor. It has a " << sub2.second << " quality. You have " << sub.second;
            if(pair.first == "Healing" and subPair.first != "None")
                for (const auto& sub : InventoryQuantity)
                    for (const auto& sub2 : InventoryQuality)
                        if(sub.first == subPair.first and subPair.first == sub2.first)
                            cout << subPair.first << " gives " << subPair.second << " HP. It has a " << sub2.second << " quality. You have " << sub.second;
            if(pair.first == "Primary" and subPair.first != "None")
                for (const auto& sub : InventoryQuantity)
                    for (const auto& sub2 : InventoryQuality)
                        if(sub.first == subPair.first and subPair.first == sub2.first)
                            cout << subPair.first << " deals " << subPair.second << " damage. It has a " << sub2.second << " quality. You have " << sub.second;
            if(subPair.first == "None")
                cout << subPair.first;
            cout << endl;
        }
    }
}

void Hero::DisplaySkills() {
    cout << "Your skills are: " << endl;
    for (const auto& pair : Skills) {
        cout << pair.first << " - ";
        for (const auto& subPair : pair.second) {
            for (const auto& sub : SkillsStatusEffects)
                for (const auto& sub2 : Cooldown)
                    for (const auto& sub3 : SkillsQuality)
                        if(sub.first == subPair.first and subPair.first == sub2.first and sub2.first == sub3.first)
                            cout << subPair.first << " deals " << subPair.second << " ,applies: " << sub.second << " ,has a " << sub2.second << " turns cooldown and is of " << sub3.second << " quality" << endl;
        }
    }
}

void Hero::DisplayArmor() {
    cout << "Info regarding the armor that you have on you: " << endl;
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

void Hero::DisplayStatusEffects() {
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

void Hero::Describe(const string object) {
    bool ok = false;
    for (const auto& pair : DescriptionHero)
        if(object == pair.first)
            cout << pair.second << endl, ok = true;
    if (ok == false)
        cout << "I think u might have got the wrong game. We ain't got that here. Check yo spelling maybe, idk..." << endl;
}

void Hero::Heal() {
    string input;
    int ok = 0;
    cout << "Which item would you like to use to heal? If you want to exit type the letter: e" << endl;
    cout << "By the way, you have " << Health << " health out of " << maxHealth << endl << endl;
    DisplayInventory();
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

int Hero::ManaRecharge() {
    string input;
    cout << "You sure chief? Cuz if u ain't u can type: e as in exit" << endl;
    cout << "You've got " << Mana << " mana left" << endl;
    while(true) {
        getline(cin, input);
        if(input == "e" or input == "exit" or input == " e") {
                cout << "U ain't really sure what u want are ye" << endl;
                return 0;
        }
        if(Mana + maxMana / 2 > maxMana){
            Mana = maxMana;
            cout << "Mana restoration complete" << endl;
            return 1;
        }
        else {
            Mana += maxMana;
            cout << "Mana restoration complete" << endl;
            return 1;
        }
    }
    cout << endl;
    return 0;
}

void Hero::LevelUP() {
    maxHealth += 20;
    Health = maxHealth;
    maxMana += 10;
    Mana = maxMana;
    Wallet = Level * 8;
    Level++;
}

int Hero::isDamaged(int damageTaken, string effectsApplied, int damageStatus, int effectsRoundsLeft) {
    Health -= damageTaken;
    if (Health <= 0)
        return 1;
    if (effectsApplied != "No effects") {
        StatusEffects[effectsApplied] = damageStatus, TurnsStatusEffects[effectsApplied] = effectsRoundsLeft;
        cout << "You've been hit with " << effectsApplied << " which deals " << damageStatus << " damage for " << effectsRoundsLeft << " rounds" << endl;}
    return 0;
}

void Hero::takeDamageFromStatuses() {
    for (auto& pair : StatusEffects)
        for (auto& sub : TurnsStatusEffects)
            if(pair.first == sub.first)
                if(pair.second != 0 and pair.first != "Regeneration"){
                    cout << "You've been damaged by " << pair.first << " for " << pair.second << " damage that lasts " << --sub.second << " rounds left" << endl;
                    Health -= pair.second;
                    if(sub.second == 0 and pair.first != "No effects")
                        StatusEffects.erase(pair.first), TurnsStatusEffects.erase(sub.first), cout << pair.first << " status effect expired" << endl;
                }
}

void Hero::regenFromStatuses() {
    for (auto& pair : StatusEffects)
        for (auto& sub : TurnsStatusEffects)
            if(pair.first == sub.first)
                if(pair.second != 0 and pair.first == "Regeneration"){
                    cout << "You've regened " << pair.second << " HP. " << --sub.second << " rounds left" << endl;
                    Health += pair.second;
                    if(sub.second == 0 and pair.first != "No effects")
                        StatusEffects.erase(pair.first), TurnsStatusEffects.erase(sub.first), cout << pair.first << " status effect expired" << endl;
                }
}

int Hero::calculateShield() {
    int aux = 0;
    for (const auto& pair : Armor)
        for (const auto& sub : pair.second)
            aux += sub.second;
    return aux;
}

void Hero::Equip(string Category, string Name2, int Armor2, string Quality) {
    for (const auto& pair : Armor)
        for (auto& sub : pair.second)
            if(pair.first == Category) {
                Armor[pair.first][Name2] = Armor2, InventoryQuality[Name2] = Quality;
                Armor[pair.first].erase(sub.first);
                break;
            }
}

ostream &operator <<(ostream &os,const Hero &hero) {
    os << "Hero Name:   " << hero.Name << endl;
    os << "Hero HP:     " << hero.Health << " out of: " << hero.maxHealth << endl;
    os << "Hero Mana:   " << hero.Mana << " out of: " << hero.maxMana << endl;
    os << "Hero Shield: " << hero.Shield << endl;
    if(hero.Wallet < 5)
    {
        os << "A fly mocks you while it flies away from your wallet" << endl;
        os << "You once again realize that you're a Brokie" << endl << endl;
    }
    else
        os << "Wallet:      " << hero.Wallet << endl;
    os << "Hero Level:  " << hero.Shield << endl << endl;
    //Skill display
    os << "Your skills are: " << endl;
    for (const auto& pair : hero.Skills) {
        os << pair.first << " - ";
        for (const auto& subPair : pair.second) {
            for (const auto& sub : hero.SkillsStatusEffects)
                for (const auto& sub2 : hero.Cooldown)
                    for (const auto& sub3 : hero.SkillsQuality)
                        if(sub.first == subPair.first and subPair.first == sub2.first and sub2.first == sub3.first)
                            os << subPair.first << " deals " << subPair.second << " ,applies: " << sub.second << " ,has a " << sub2.second << " turns cooldown and is of " << sub3.second << " quality" << endl;
        }
    }
    //Inventory display
    os << endl;
    os << "Your inventory contains: " << endl;
    for (const auto& pair : hero.Inventory) {
        os << pair.first << " - ";
        for (const auto& subPair : pair.second)
        {
            if(pair.first == "Accessories" or pair.first == "Armor" and subPair.first != "None")
                for (const auto& sub : hero.InventoryQuantity)
                    for (const auto& sub2 : hero.InventoryQuality)
                        if(sub.first == subPair.first and subPair.first == sub2.first)
                            os << subPair.first << " gives " << subPair.second << " armor. It has a " << sub2.second << " quality. You have " << sub.second;
            if(pair.first == "Healing" and subPair.first != "None")
                for (const auto& sub : hero.InventoryQuantity)
                    for (const auto& sub2 : hero.InventoryQuality)
                        if(sub.first == subPair.first and subPair.first == sub2.first)
                            os << subPair.first << " gives " << subPair.second << " HP. It has a " << sub2.second << " quality. You have " << sub.second;
            if(pair.first == "Primary" and subPair.first != "None")
                for (const auto& sub : hero.InventoryQuantity)
                    for (const auto& sub2 : hero.InventoryQuality)
                        if(sub.first == subPair.first and subPair.first == sub2.first)
                            os << subPair.first << " deals " << subPair.second << " damage. It has a " << sub2.second << " quality. You have " << sub.second;
            if(subPair.first == "None")
                os << subPair.first;
            os << endl;
        }
    }
    //The armor you have equiped
    os << endl;
    os << "Info regarding the armor that you have on you: " << endl;
    for (const auto& pair : hero.Armor) {
        os << pair.first << " - ";
        for (const auto& subPair : pair.second)
        {
            for (const auto& sub : hero.InventoryQuality)
                    if(sub.first == subPair.first)
                        os << subPair.first << " gives " << subPair.second << " armor. It has a " << sub.second << " quality.";
            if(subPair.first == "None")
                os << subPair.first;
            os << endl;
        }
    }
    //Status Effects display
    os << endl;
    os << "Info regarding the status effects that are active: " << endl;
    for (const auto& pair : hero.StatusEffects) {
        if (pair.first == "No effects")
            os << pair.first << endl;
        else
            for (const auto& sub : hero.TurnsStatusEffects)
                if(sub.first == pair.first)
                    os << pair.first << " that deals " << pair.second << " damage every round. This effect lasts for " << sub.second << " round(s)" << endl;
    }
    return os;
}
