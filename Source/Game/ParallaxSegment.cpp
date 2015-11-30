//
//  ParallaxSegment.cpp
//  GameDevFramework
//
//  Created by Cavan Macphail on 2/27/2014.
//  Copyright (c) 2014 Algonquin College. All rights reserved.
//

#include "ParallaxSegment.h"
#include "Game.h"

ParallaxSegment::ParallaxSegment(ParallaxLayer* layer, OpenGLTexture* texture, float speed) :
    m_Layer(NULL),
    m_Texture(NULL),
    m_X(0.0),
    m_Y(0.0f),
    m_Speed(0.0)
{
    m_Layer = layer;
    m_Texture = texture;
    m_Speed = speed;
    
}
ParallaxSegment::~ParallaxSegment()
{
    if(m_Layer != NULL)
    {
        delete m_Layer;
        m_Layer = NULL;
    }
    if(m_Texture != NULL)
    {
        delete m_Texture;
        m_Texture = NULL;
    }
}
void ParallaxSegment::update(double delta)
{
    m_X -= m_Speed;
}
void ParallaxSegment::paint()
{
    OpenGLRenderer::getInstance()->drawTexture(m_Texture, m_X, m_Y, Game::getInstance()->getScreenWidth(), Game::getInstance()->getScreenHeight());
}
float ParallaxSegment::getX()
{
    return m_X;
}
void ParallaxSegment::setX( float x)
{
    m_X = x;
}