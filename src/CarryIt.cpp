/******************************************************************************
* CarryIt.cpp
* CS 281-0798, Fall 2020
*
* CarryIt base class definition
*******************************************************************************
*/
#include <string>
#include <cstdlib>

#include "CarryIt.h"

// default carryable element characteristics
constexpr int MAX_POWER = 5;
constexpr int MIN_POWER = 3;

//***********************************************************
// CarryIt()
//
// constructor
//***********************************************************
CarryIt::CarryIt()
{
    m_id = GENERIC_CARRYIT;
    m_name = "carry me";

    m_power = rand() % MAX_POWER + MIN_POWER;
    m_roomInfo = 0;
    m_playerInfo = 0;
}

//***********************************************************
// setPower()
//***********************************************************
void CarryIt::setPower(int power)
{
    m_power = power;
}

//***********************************************************
// getPower()
//***********************************************************
int CarryIt::getPower() const
{
    return m_power;
}

//***********************************************************
// addPower()
//
// returns updated power setting
//***********************************************************
int CarryIt::addPower(int morePower)
{
    return m_power += morePower;
}

//***********************************************************
// overload insertion operator << 
//***********************************************************
std::ostream& operator<< (std::ostream& os, const CarryIt& item)
{
    std::string str;
    os << item.getName(str);
    
    // Treasure power means nothing so don't display it 
    if (item.getId() != TREASURE_CARRYIT)
        os << " [" << item.getPower() << "]";
        
    os << " (" << item.getPoints() << ")\n";

    return os;
}

