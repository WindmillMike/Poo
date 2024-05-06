#pragma once
#include <bits/stdc++.h>
using namespace std;

class Monster {
private:
    string Name;
    int maxHealth;
    int Health;
    int Shield;
    int maxMana;
    int Mana;
    int Level;
    map<string, map<string, int>> Skills;
    map<string, string> SkillsStatusEffects;
    map<string, int> Cooldown;
    map<string, string> SkillsQuality;
    map<string, map<string, int>> Armor;
    map<string, string> InventoryQuality;
    map<string, int> StatusEffects;
    map<string, int> TurnsStatusEffects;
    map<string, string> DescriptionMonster;
public:
    Monster();
    Monster(string Name);
    Monster(string Name, int maxHealth, int Health, int Shield, int maxMana, int Mana,
         int Level, map<string, map<string, int>> Skills,
         map<string, string> SkillsStatusEffects, map<string, int> Cooldown,
         map<string, string> SkillsQuality,
         map<string, map<string, int>> Armor, map<string, string> InventoryQuality,
         map<string, int> StatusEffects,
         map<string, int> TurnsStatusEffects, map<string, string> DescriptionMonster);
    void DisplayStats();
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
    void Equip(string Category, string Name, int Armor2);

    friend ostream &operator <<(ostream &os,const Hero &hero);
};

