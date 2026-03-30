//// Slime.cpp
//
//#include "Slime.h"
//#include <iostream>
//#include <cstdlib>
//
//using namespace std;
//
//Slime::Slime()
//    : Monster("Slime", 40, 5) {
//}
//
//int Slime::attack() {
//    int damage = atk;
//
//    cout << "[Slime] Body Slam "
//        << damage << " Damage!" << endl;
//
//    return damage;
//}
//
//int Slime::useSkill() {
//    int roll = rand() % 100;
//
//    if (roll < 20) {
//        int damage = atk + 3;
//
//        cout << "[Slime] spraying mucus! "
//            << damage << " Damage!" << endl;
//
//        return damage;
//    }
//
//    return -1;
//}