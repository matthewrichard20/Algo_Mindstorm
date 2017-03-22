//
//  bfs.c
//  Algo_Mindstorm
//
//  Created by Richard Matthew on 3/21/17.
//  Copyright © 2017 MatthewRichard20. All rights reserved.
//

#include "bfs.h"

void mainbfs()
{
  Stack S;
  boolean win = false;
  
  bfs(&S);
  while (IsEmpty(S))
  {
    bfs(&S, win);
  }
  
}
void bfs(Stack S, boolean win)
{
  paddress Pt;
  float sudut;
  boolean found = false;
  if (!win)
  {
    
    while (color==black)
    {
      move();
    }
    
    switch (color) {
      case Yellow:
      {
        win == true // indicator win
        moveback();
      }
        break;
      case red:
      {
        moveback();
      }
        break;
      case green:
      {
        Add_to_tree(); // masih bingung
        if (!win)
        {
          float sudut == 0;
          while(sudut<360)
          {
            rotate(sudut);
            if(( color == black) && (sudut != 180))
            {
              InsertAfter(P, sudut, &Pt);
              found = true;
            }
            
          }
          
          if (found)
          {
            if (Next1(P) != Nil)
            {
              bfs(Next1(P));
            }
            if (Next2(P) != Nil)
            {
              bfs(Next2(P));
            }
            if (Next3(P) != Nil)
            {
              bfs(Next3(P));
            }
          }

        }
      }
        break;
      default:
        break;
    }
    
    
    
    
    
    
      }
}

void move()
{
  //follow line;
}

void moveback()
{
  //follow line move backward;
}
