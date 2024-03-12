#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Player {
  public:
    Player(); // Constructor
    virtual ~Player(); // Deconstructor

    std::string Format();
    void Display();
    void SetGetData();
  protected:
    const static int MAX = 2;
    std::string nickname = "";
    int age = 0;
    double scores[MAX] = {};
  private:
};

#endif // !PLAYER_H#define PLAYER_H
