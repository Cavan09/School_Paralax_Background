//
//  GameConstants.cpp
//  GameDevFramework
//
//  Created by Bradley Flood on 12-08-30.
//  Copyright (c) 2012 Algonquin College. All rights reserved.
//

#include "GameConstants.h"


const float GAME_GRAVITY_X = 0.0f;
const float GAME_GRAVITY_Y = -10.0f;

const char* GAME_PHYSICS_EDITOR_FILENAME = "shapedefs.plist";
const float GAME_PHYSICS_PIXELS_TO_METERS_RATIO = 16;
const bool GAME_PHYSICS_CONTINUOUS_SIMULATION = true;
const int GAME_PHYSICS_VELOCITY_ITERATIONS = 4;
const int GAME_PHYSICS_POSITION_ITERATIONS = 1;

const int SEGMENT_COUNT = 5;

const char* CLOUDS_LAYER[] = {"images/Clouds1", "images/Clouds2","images/Clouds3","images/Clouds4","images/Clouds5"};
const char* STAR_LAYER[] = {"images/Stars1", "images/Stars2","images/Stars3","images/Stars4","images/Stars5"};
const char* MOUNTAIN_LAYER[] = {"images/Mountains1", "images/Mountains2","images/Mountains3","images/Mountains4","images/Mountains5"};
const char* GROUND_LAYER[] = {"images/Ground1", "images/Ground2","images/Ground3","images/Ground4","images/Ground5"};
const char* PATH_LAYER[] = {"images/Path1", "images/Path2","images/Path3","images/Path4","images/Path5"};