#include "Player.h"

Player::Player() {
  std::cout << "Player is Getting Constructed\n\n";
}

Player::~Player() { std::cout << "Player is Getting Constructed\n\n"; }

std::string Player::Format() {
  std::string data = "";

  data = "Name: " + this->nickname + "\n"
        + "Age: " + std::to_string(this->age) + "\n"
        + "Scores: ";
  for (size_t i = 0; i < this->MAX; i++) {
    data += std::to_string(this->scores[i]);

    if (i == this->MAX - 1)
      data += "\n";
    else
      data += ", ";
  }

  return data;
}

void Player::Display() { std::cout << this->Format(); }

void Player::SetGetData() {
  std::cout << "Enter Player Name: ";
  std::cin >> this->nickname;

  std::cout << "Enter Player Age: ";
  std::cin >> this->age;

  for (size_t i = 0; i < this->MAX; i++)
  {
    std::cout << "Enter Player Scores " << i + 1 << ": ";
    std::cin >> this->scores[i];
  }

}
