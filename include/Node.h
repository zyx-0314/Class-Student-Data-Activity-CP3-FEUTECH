#ifndef NODE_H
#define NODE_H

#include "Player.h"

struct Node
{
  Node *next;

  Player player;
};

#endif
