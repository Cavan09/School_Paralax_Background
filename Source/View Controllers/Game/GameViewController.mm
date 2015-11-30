//
//  GameViewController.m
//  GameDevFramework
//
//  Created by Bradley Flood on 12-08-30.
//  Copyright (c) 2012 Algonquin College. All rights reserved.
//

#import "GameViewController.h"
#import "OpenGLView.h"
#include "Game.h"
#include "OpenGLRenderer.h"
#include "Constants.h"
#include "LogUtils.h"
#import "DeviceUtils.h"
#import <OpenGLES/EAGLDrawable.h>
#import <QuartzCore/QuartzCore.h>


@interface GameViewController()

- (void)handleTouchEvent:(UITouch *)aTouch event:(TouchEvent)aTouchEvent;

@end


@implementation GameViewController

@synthesize openGLView = m_OpenGLView;

- (void)dealloc
{
    //release the display link
    [m_DisplayLink release];
    
    //Release the rest of the objects
    [m_OpenGLContext release];
    [m_OpenGLView release];
    [super dealloc];
}

- (void)viewDidLoad
{
    //Create the OpenGL context, set the OpenGL view's OpenGL context
    m_OpenGLContext = [[EAGLContext alloc] initWithAPI:OPENGL_RENDERING_API];
    if(m_OpenGLContext != nil && [EAGLContext setCurrentContext:m_OpenGLContext] == YES)
    {
        //Set the OpenGL view's context, this allows us to draw to the screen with OpenGL
        [m_OpenGLView setOpenGLContext:m_OpenGLContext];
    }
    
    m_DisplayLink = [[CADisplayLink displayLinkWithTarget:self selector:@selector(gameLoop)] retain];
    [m_DisplayLink setFrameInterval:FramePerSecond60];
    
    [super viewDidLoad];
}

-(void)viewWillAppear:(BOOL)aAnimated
{
    [m_DisplayLink addToRunLoop:[NSRunLoop mainRunLoop] forMode:NSDefaultRunLoopMode];
    [super viewWillAppear:aAnimated];
}

-(void)viewWillDisappear:(BOOL)aAnimated
{
    [m_DisplayLink removeFromRunLoop:[NSRunLoop mainRunLoop] forMode:NSDefaultRunLoopMode];
    [super viewWillDisappear:aAnimated];
}

-(void)invalidateRunLoop
{
    [m_DisplayLink invalidate];
}

-(void)gameLoop
{
    // calculate the delta time
    float duration = [m_DisplayLink duration];
    float interval = [m_DisplayLink frameInterval];
    float delta = duration * interval;
    
    Game::getInstance()->update(delta);
    
    OpenGLRenderer::getInstance()->clear();
    
    [m_OpenGLView beginDraw];
    
    Game::getInstance()->paint();
    
    [m_OpenGLView endDraw];
}

-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    [self handleTouchEvent:[touches anyObject] event:TouchEventBegan];
}

-(void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    [self handleTouchEvent:[touches anyObject] event:TouchEventEnded];
}

-(void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
    [self handleTouchEvent:[touches anyObject] event:TouchEventCancelled];
}

-(void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
    [self handleTouchEvent:[touches anyObject] event:TouchEventMoved];
}

- (void)handleTouchEvent:(UITouch *)aTouch event:(TouchEvent)aTouchEvent
{
    CGPoint location = [aTouch locationInView:[self view]];
    location.x *= DeviceUtils::getContentScaleFactor();
    location.y *= DeviceUtils::getContentScaleFactor();
    Game::getInstance()->touchEvent(aTouchEvent, location.x, DeviceUtils::getScreenResolutionHeight() - location.y);
}

@end

