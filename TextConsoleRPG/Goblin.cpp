//// Goblin.cpp
//
//#include "Goblin.h"
//#include <iostream>
//#include <cstdlib>
//
//using namespace std;
//
//Goblin::Goblin()
//    : Monster("Goblin", 70, 8) {
//}
//
//int Goblin::attack() {
//    int damage = atk;
//
//    cout << "[Goblin] Quick Strike! "
//        << damage << " damage!" << endl;
//
//    return damage;
//}
//
//int Goblin::useSkill() {
//    int roll = rand() % 100;
//
//    if (roll < 25) {
//        int damage = atk + 5;
//
//        cout << "[Goblin] Stab Attack! "
//            << damage << " damage!" << endl;
//
//        return damage;
//    }
//
//    return -1;
//}