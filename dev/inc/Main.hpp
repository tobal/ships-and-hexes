
#ifndef MAIN_HPP_
#define MAIN_HPP_

#include "orx.h"
#include "GameMap/GameMapGenerator.hpp"
#include "MapElement/Planet.hpp"
#include "MapElement/Anomaly.hpp"
//#include "Empire/Effect/MapEffect.hpp"
//#include "Empire/Effect/TwinPlanet.hpp"
//#include "Empire/Effect/ExtraShips.hpp"
#include "Empire/CommonTypes.hpp"
#include "GameConfig/Player.hpp"
#include <sstream>
#include <vector>

orxSTATUS orxFASTCALL Init();
orxSTATUS orxFASTCALL Run();
void orxFASTCALL Exit();
int main(int argc, char **argv);

#endif /* MAIN_HPP_ */
