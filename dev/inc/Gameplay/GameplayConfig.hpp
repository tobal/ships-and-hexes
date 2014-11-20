/*
 * GameplayConfig.hpp
 *
 *  Created on: Nov 20, 2014
 *      Author: tobal
 */

#ifndef GAMEPLAYCONFIG_HPP_
#define GAMEPLAYCONFIG_HPP_

namespace Gameplay
{

struct TurnConfig
{
	int planetBuildSpeed;
	int stationBuildSpeed;
	float basePopIncrese;
};

struct GameplayConfig
{
	TurnConfig turn;
	GameplayConfig()
	{
		turn.basePopIncrese = 0.1f;
		turn.planetBuildSpeed = 25;
		turn.stationBuildSpeed = 25;
	};
};

}

#endif /* GAMEPLAYCONFIG_HPP_ */
