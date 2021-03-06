/******************************************************************************
* Container.h
* CS 281-0798, Fall 2020
*
* Container pure abstract class declaration
*******************************************************************************
*/
#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
#include <vector>

#include "Treasure.h"
#include "Weapon.h"
#include "Bogey.h"

constexpr int ROOM_CONTAINER    = 'R';
constexpr int PLAYER_CONTAINER  = 'P';
constexpr int GENERIC_CONTAINER = 'C';

class Container : public Element
{
protected:
    std::vector<Treasure*> m_pTreasureV;  // accumulated Treasure
    std::vector<Weapon*> m_pWeaponV;      // accumulated Weapons
    std::vector<Bogey*> m_pBogeyV;        // accumulated Bogeys

public:
    Container();
    // Container instances will persist for app lifetime
    // so destructor not needed
    //~Container();

    // copy constructor
    Container(const Container& rhsC);

    // Treasure management
    int addTreasure(Treasure* pT);
    Treasure* removeTreasure();
    Treasure* selectTreasure(const std::string& tName);
    int getTreasureCount() const;
    int getTreasureInfo(std::vector<Treasure*>& pTV);
    void removeAllTreasure();

    // Weapon management
    int addWeapon(Weapon* pT);
    Weapon* removeWeapon();
    Weapon* selectWeapon(const std::string& wName);
    int getWeaponCount() const;
    int getWeaponInfo(std::vector<Weapon*>& pWV);
    void removeAllWeapon();

    // Bogey management
    int addBogey(Bogey* pB);
    Bogey* removeBogey();
    Bogey* selectBogey(const std::string& bName);
    int getBogeyCount() const;
    int getBogeyInfo(std::vector<Bogey*>& pBV);
    void removeAllBogey();

    // overload comparison operator ==
    bool operator== (const Container& rhsC);

private:
    template <class I>
    int getItemInfo(std::vector<I*>& pDstIV,
                    std::vector<I*>& pSrcIV);

    template <class I>
    int addItem(I* pItem, std::vector<I*>& pIV);

    template <class I>
    I* removeItem(std::vector<I*>& pIV);

    template <class I>
    I* selectItem(const std::string& iName, std::vector<I*>& pIV);

};

#endif
