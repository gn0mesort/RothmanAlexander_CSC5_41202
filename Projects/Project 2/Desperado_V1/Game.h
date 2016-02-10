/* 
 * File:   Game.h
 * Author: Alexander Rothman
 * Purpose: Define game objects for Desperado
 * Created on February 9, 2016, 10:01 AM
 */

#ifndef GAME_H
#define	GAME_H

/******************************************************************************/
/**************************************Gun*************************************/
/******************************************************************************/
//  Struct representing a gun in the Desperado game
struct Gun{
    unsigned short atk, //The attack power of the gun
                   ammo, //The maximum ammo the gun can hold
                   cAmmo; //The current ammo in the gun
    string name, //The gun's name
           dsc; //The gun's description
};

/******************************************************************************/
/**************************************Charm***********************************/
/******************************************************************************/
//  Struct representing a charm in the Desperado game
struct Charm{
    unsigned short def; //The defense power of the charm
    string name, //The name of the charm
           dsc; //The description of the charm
};

/******************************************************************************/
/**************************************Player**********************************/
/******************************************************************************/
//  Struct representing a player in the Desperado game
struct Player{
    short hp; //The player's current hit points
    unsigned short  level, //The player's current level
                    gold; //The player's current gold
    string name; //The player's name
    Charm eqCharm; //The player's currently equipped charm
    Gun eqGun; //The player's currently equipped gun
};

#endif	/* GAME_H */

