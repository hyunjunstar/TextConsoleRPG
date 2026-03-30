//// Orc.cpp
//
//#include "Orc.h"
//#include <iostream>
//#include <cstdlib>
//
//using namespace std;
//
//Orc::Orc()
//    : Monster("Orc", 100, 12) {
//}
//
//int Orc::attack() {
//    int damage = atk;
//
//    cout << "[Orc] Heavy Smash! "
//        << damage << " damage!" << endl;
//
//    return damage;
//}
//
//int Orc::useSkill() {
//    int roll = rand() % 100;
//
//    if (roll < 30) {
//        int damage = atk + 8;
//
//        cout << "[Orc] Power Ground Hit! "
//            << damage << " damage!" << endl;
//
//        return damage;
//    }
//
//    return -1;
//}