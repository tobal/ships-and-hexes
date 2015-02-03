
#ifndef ORXMAIN_HPP_
#define ORXMAIN_HPP_

#include "orx.h"
#include "GFX/OrxGFX/OrxTypes.hpp"
#include "GFX/OrxGFX/ObjectRepos.hpp"

#include "GameMap/GameMap.hpp"
#include "GFXI/GameGFXI/GameStateGFXI.hpp"

#include "MapElement/Planet.hpp"
#include "MapElement/Anomaly.hpp"
#include <sstream>
#include <vector>

orxSTATUS orxFASTCALL Init();
orxSTATUS orxFASTCALL Run();
void orxFASTCALL Exit();
int orxMain(int argc, char **argv);

#endif /* ORXMAIN_HPP_ */
