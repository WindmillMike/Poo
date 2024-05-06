#pragma once
#include <bits/stdc++.h>
using namespace std;

class Hero {
private:
    string Name;
    int maxHealth;
    int Health;
    int Shield;
    int maxMana;
    int Mana;
    int Wallet;
    int Level;
    map<string, map<string, int>> Skills;
    map<string, string> SkillsStatusEffects;
    map<string, int> Cooldown;
    map<string, string> SkillsQuality;
    map<string, map<string, int>> Inventory;
    map<string, string> InventoryQuality;
    map<string, int> InventoryQuantity;
    map<string, map<string, int>> Armor;
    map<string, int> StatusEffects;
    map<string, int> TurnsStatusEffects;
    map<string, string> DescriptionHero;
public:
    Hero();
    Hero(string Name);
    Hero(string Name, int maxHealth, int Health, int Shield, int maxMana, int Mana,
         int Wallet, int Level, map<string, map<string, int>> Skills,
         map<string, string> SkillsStatusEffects, map<string, int> Cooldown,
         map<string, string> SkillsQuality, map<string, map<string, int>> Inventory,
         map<string, string> InventoryQuality, map<string, int> InventoryQuantity,
         map<string, map<string, int>> Armor, map<string, int> StatusEffects,
         map<string, int> TurnsStatusEffects, map<string, string> DescriptionHero);
    void DisplayStats();
    void DisplayInventory();
    void DisplaySkills();
    void DisplayArmor();
    void DisplayStatusEffects();
    void Describe(const string object);
    void Heal();
    void regenFromStatuses();
    int ManaRecharge();
    int calculateShield();
    void LevelUP();
    int isDamaged(int damageTaken, string effectsApplied, int damageStatus, int effectsRoundsLeft);
    void takeDamageFromStatuses();
    void Equip(string Category, string Name2, int Armor2, string Quality);

    friend ostream &operator <<(ostream &os,const Hero &hero);
};
