//
//  ParallaxLayer.h
//  GameDevFramework
//
//  Created by Cavan Macphail on 2/27/2014.
//  Copyright (c) 2014 Algonquin College. All rights reserved.
//

#ifndef __GameDevFramework__ParallaxLayer__
#define __GameDevFramework__ParallaxLayer__

#include <iostream>
#include "GDRandom.h"
#include "ParallaxSegment.h"
#include <vector>
#include "Constants.h"

class OpenGLTexture;
class ParallaxSegment;

class ParallaxLayer
{
public:
    ParallaxLayer(std::vector<OpenGLTexture*> &segments, float speed);
    ~ParallaxLayer();
    void update(double delta);
    void paint();
    void reset();
    ParallaxSegment* nextSegment();
    
private:
    
    std::vector<ParallaxSegment*> m_Segments;
    ParallaxSegment* m_ActiveSegments[2];
    GDRandom m_Random;
};

#endif /* defined(__GameDevFramework__ParallaxLayer__) */
