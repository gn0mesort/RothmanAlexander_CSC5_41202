/* 
 * File:   Game.h
 * Author: Alexander Rothman
 * Purpose: Define game objects for Desperado
 * Created on February 9, 2016, 10:01 AM
 */

#ifndef GAME_H
#define	GAME_H

struct Gun{
    unsigned short atk,
                   ammo,
                   cAmmo;
    string name,
           dsc;
};

struct Charm{
    unsigned short def;
    string name,
           dsc;
};

struct Player{
    short hp; 
    unsigned short  level;
    unsigned short gold;
    string name;
    Charm eqCharm;
    Gun eqGun;
};

#endif	/* GAME_H */

