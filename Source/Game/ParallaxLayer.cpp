//
//  ParallaxLayer.cpp
//  GameDevFramework
//
//  Created by Cavan Macphail on 2/27/2014.
//  Copyright (c) 2014 Algonquin College. All rights reserved.
//

#include "ParallaxLayer.h"
#include "Utils.h"
#include "Game.h"

ParallaxLayer::ParallaxLayer(std::vector<OpenGLTexture*> &segments, float speed) :
    m_Segments(NULL)
{
    for(int i = 0; i < segments.size(); i++)
    {
        ParallaxSegment* newSegement = new ParallaxSegment(this,segments.at(i), speed);
        m_Segments.push_back(newSegement);
    }
    m_Random.randomizeSeed();
    
    m_ActiveSegments[0] = m_Segments.at(m_Random.random(SEGMENT_COUNT));
    
    do {
        m_ActiveSegments[1] = nextSegment();
    } while (m_ActiveSegments[0] == m_ActiveSegments[1]);
    
    reset();
}
ParallaxLayer::~ParallaxLayer()
{
    for (int i = 0; i < 2; i++)
    {
        if(m_ActiveSegments[i] != NULL)
        {
            delete [] m_ActiveSegments[i];
            m_ActiveSegments[i] = NULL;
        }
    }
    
    m_Segments.clear();

}
void ParallaxLayer::update(double delta)
{

    for(int i = 0; i < 2; i++)
    {
        m_ActiveSegments[i]->update(delta);
        
        if(m_ActiveSegments[0]->getX() < -DeviceUtils::getScreenResolutionWidth())
        {
            m_ActiveSegments[0] = m_ActiveSegments[1];
            do {
                m_ActiveSegments[1] = nextSegment();
            } while (m_ActiveSegments[1] == m_ActiveSegments[0]);
            m_ActiveSegments[1]->setX(DeviceUtils::getScreenResolutionWidth());
        }
    }

}
void ParallaxLayer::paint()
{
    for ( int i = 0 ; i < 2;i++)
    {
        m_ActiveSegments[i]->paint();
    }
}
void ParallaxLayer::reset()
{
    m_ActiveSegments[0]->setX(0.0f);
    m_ActiveSegments[1]->setX(DeviceUtils::getScreenResolutionWidth());
}

ParallaxSegment* ParallaxLayer::nextSegment()
{
    return m_Segments.at(m_Random.random(SEGMENT_COUNT));
}