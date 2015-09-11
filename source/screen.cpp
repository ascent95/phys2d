/*
 * Everything relating to drawing to the screen. This means all
 * interaction with SDL.
 */

#include "screen.h"
#include <SDL2/SDL.h>
#include <stdio.h>

bool Screen::init()
{
  bool success = true;

  if( SDL_Init( SDL_INIT_VIDEO ) )
  {
      printf( "SDL could not initialise! SDL Error: %s\n", SDL_GetError() );
      success = false;
  }
  else
  {
      m_window = SDL_CreateWindow( "Circles!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
      if( m_window == NULL )
      {
	  printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
	  success = false;
      }
      else
      {
	  m_renderer = SDL_CreateRenderer( m_window, -1, SDL_RENDERER_ACCELERATED );
	  if( m_renderer == NULL )
	  {
	      printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
	      success = false;
	  }
	  else
	  {
	      SDL_SetRenderDrawColor( m_renderer, 0xFF, 0xFF, 0xFF, 0xFF );
	  }
      }
  }
  return success;
}
