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
  if (!win)
  {
    while (color=black)
    {
      move();
    }
    
    switch (color) {
        case Yellow:
          {
            win = true // indicator win
            Add_to_tree();
          
          }
          break;
        case red:
        {
          Add_to_tree();
          return false;
        }
          break;
        case green:
        {
          Add_to_tree(); // masih bingung
          if (!win)
          {
            while (sudut < 360) // mengecek 1 putaran)
            {
              rotate(sudut);
              if (color = black)
              {
                dfs();
                moveback();
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
