//
//  Game.h
//  GameDevFramework
//
//  Created by Bradley Flood on 12-08-30.
//  Copyright (c) 2012 Algonquin College. All rights reserved.
//

#ifndef GAME_H
#define GAME_H

#include "Constants.h"
#include "OpenGL.h"
#include "ParallaxLayer.h"
#include <vector>

class ParallaxLayer;
class Game
{
public:
    //Singleton instance methods
    static Game* getInstance();
    
    //Update, paint and touch event (lifecycle) methods
    void update(double delta);
    void paint();
    void touchEvent(TouchEvent touchEvent, float locationX, float locationY);
    
    //Reset methods
    void reset();
    
    //Conveniance methods to access the screen's width and height
    float getScreenWidth();
    float getScreenHeight();
    float getScale();

    //Loading methods
    bool isLoading();
    
private:
    //Private constructor and destructor ensures the singleton instance
    Game();
    ~Game();
    
    //Load method, called once every load step
    void load();
    void fillLayers(std::vector<OpenGLTexture*> textures, float speed);
    void clearTextures(std::vector<OpenGLTexture*> &textures);
    
    //Singleton instance static member variable
    static Game* m_Instance;
    OpenGLTexture* m_BackGround;
    std::vector<ParallaxLayer*> m_Layer;
    
    //Load step member variable
    int m_LoadStep;
};

#endif
