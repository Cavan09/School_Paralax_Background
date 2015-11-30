//
//  Game.cpp
//  GameDevFramework
//
//  Created by Bradley Flood on 12-08-30.
//  Copyright (c) 2012 Algonquin College. All rights reserved.
//

#include "Game.h"
#include "GameObject.h"
#include "DeviceUtils.h"
#include "MathUtils.h"
#include "PhysicsEditorWrapper.h"
#include <sstream>
#include <string.h>


Game* Game::m_Instance = NULL;

Game* Game::getInstance()
{
    //Singleton design pattern ensures that there is only 1 instance of the game
    if(m_Instance == NULL)
    {
        m_Instance = new Game();
    }
    return m_Instance;
}

Game::Game() :
m_BackGround(NULL),
m_LoadStep(0)
{
    if(m_BackGround == NULL)
    {
        m_BackGround = new OpenGLTexture("images/BackGround");
    }
    std::vector<OpenGLTexture*> Textures;
    for(int i = 0; i < SEGMENT_COUNT; i++)
    {
        OpenGLTexture* stars = new OpenGLTexture(STAR_LAYER[i]);
        Textures.push_back(stars);
    }
    fillLayers(Textures, 0.3f);
    clearTextures(Textures);
    for(int i = 0; i < SEGMENT_COUNT; i++)
    {
        OpenGLTexture* mountains = new OpenGLTexture(MOUNTAIN_LAYER[i]);
        Textures.push_back(mountains);
    }
    fillLayers(Textures, 0.6f);
    clearTextures(Textures);
    for(int i = 0; i < SEGMENT_COUNT; i++)
    {
        OpenGLTexture* cloud = new OpenGLTexture(CLOUDS_LAYER[i]);
        Textures.push_back(cloud);
    }
    fillLayers(Textures, 0.5f);
    clearTextures(Textures);
    for(int i = 0; i < SEGMENT_COUNT; i++)
    {
        OpenGLTexture* ground = new OpenGLTexture(GROUND_LAYER[i]);
        Textures.push_back(ground);
    }
    fillLayers(Textures, 2.0f);
    clearTextures(Textures);
    for(int i = 0; i < SEGMENT_COUNT; i++)
    {
        OpenGLTexture* path = new OpenGLTexture(PATH_LAYER[i]);
        Textures.push_back(path);
    }
    fillLayers(Textures, 4.0f);
    clearTextures(Textures);
    
    
    
}

Game::~Game()
{
    //TODO: Delete objects used in game here
    if(m_BackGround != NULL)
    {
        delete m_BackGround;
        m_BackGround = NULL;
    }
    
    m_Layer.clear();
    
}

void Game::load()
{
    
}

void Game::update(double aDelta)
{
    //TODO: Add Game logic here
    for( int i = 0; i < SEGMENT_COUNT; i++)
    {
        m_Layer.at(i)->update(aDelta);
    }

}

void Game::paint()
{
    //TODO: Render you game logic here
    
    OpenGLRenderer::getInstance()->drawTexture(m_BackGround, 0.0f, 0.0f, Game::getInstance()->getScreenWidth(), Game::getInstance()->getScreenHeight());
    for( int i = 0; i < SEGMENT_COUNT; i++)
    {
        m_Layer.at(i)->paint();

    }


}

void Game::touchEvent(TouchEvent aTouchEvent, float aLocationX, float aLocationY)
{
    //TODO: Handle touch events here
}

void Game::reset()
{
    //TODO: Reset all game content here
}

float Game::getScreenWidth()
{
    return DeviceUtils::getScreenResolutionWidth();
}

float Game::getScreenHeight()
{
    return DeviceUtils::getScreenResolutionHeight();
}

float Game::getScale()
{
    return DeviceUtils::getContentScaleFactor();
}

bool Game::isLoading()
{
    return m_LoadStep < GameLoadStepCount;
}
void Game::fillLayers(std::vector<OpenGLTexture*> textures, float speed)
{
    ParallaxLayer* fill = new ParallaxLayer(textures, speed);
    m_Layer.push_back(fill);
}
void Game::clearTextures(std::vector<OpenGLTexture*> &textures)
{
    textures.clear();
}
