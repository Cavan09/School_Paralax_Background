//
//  ParallaxSegment.h
//  GameDevFramework
//
//  Created by Cavan Macphail on 2/27/2014.
//  Copyright (c) 2014 Algonquin College. All rights reserved.
//

#ifndef __GameDevFramework__ParallaxSegment__
#define __GameDevFramework__ParallaxSegment__

#include <iostream>
#include "../OpenGL/OpenGL.h"

class OpenGLTexture;
class ParallaxLayer;
class ParallaxSegment
{
public:
    
    ParallaxSegment(ParallaxLayer* layer, OpenGLTexture* texture, float speed);
    ~ParallaxSegment();
    void update(double delta);
    void paint();
    
    float getX();
    void setX(float x);
    
private:
    
    ParallaxLayer* m_Layer;
    OpenGLTexture* m_Texture;
    float m_X;
    float m_Y;
    float m_Speed;
    
};

#endif /* defined(__GameDevFramework__ParallaxSegment__) */
