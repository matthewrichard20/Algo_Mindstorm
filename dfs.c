//
//  dfs.c
//  Algo_Mindstorm
//
//  Created by Richard Matthew on 3/21/17.
//  Copyright © 2017 MatthewRichard20. All rights reserved.
//

#include "dfs.h"

void dfs()
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
        return false;
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
              rotate(Next1(P).sudut);

              dfs(Next1(P));
              moveback();
              rotate(-(Next1(P).sudut));
            }
            if (Next2(P) != Nil)
            {
              rotate(Next2(P).sudut);
              
              dfs(Next2(P));
              moveback();
              rotate(-(Next2(P).sudut));
            }
            if (Next3(P) != Nil)
            {
              rotate(Next3(P).sudut);
              
              dfs(Next3(P));
              moveback();
              rotate(-(Next3(P).sudut));
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
