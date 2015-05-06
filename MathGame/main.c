//
//  main.c
//  MathGame
//
//  Created by Vineet Tiwari on 2015-05-05.
//  Copyright (c) 2015 vinny.co. All rights reserved.
//

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {

  int id;
  int numberOfLives;
  int score;
  int answer;
  char loseLife;
} Player;

int randomNumber();
int generateQuestionAndAnswer();
void playTurn(Player *player);
void showScore(Player *player1, Player *player2);

int main() {
  srand((unsigned int)time(NULL));

  Player player1;
  Player *p_player1;
  p_player1 = &player1;
  player1.id = 1;
  player1.numberOfLives = 3;
  player1.score = 0;
  player1.answer = 0;
  player1.loseLife = 'N';

  Player player2;
  Player *p_player2;
  p_player2 = &player2;
  player2.id = 2;
  player2.numberOfLives = 3;
  player2.score = 0;
  player2.answer = 0;
  player2.loseLife = 'N';

  while (player1.numberOfLives > 0 && player2.numberOfLives > 0) {
    playTurn(&player1);
    showScore(&player1, &player2);
    playTurn(&player2);
    showScore(&player1, &player2);
  }

  if (player1.numberOfLives == 0 && player2.numberOfLives == 0) {
    printf("Tie Game\n");
  } else if (player1.numberOfLives == 0) {
    printf("Player 2 Wins\n");
  } else {
    printf("Player 1 Wins\n");
  }

  return 0;
}

int randomNumber() {
  int r = rand() % 20 + 1;
  return r;
}

int generateQuestionAndAnswer(playerId) {
  int number1 = randomNumber();
  int number2 = randomNumber();
  printf("Player %d: What does %d pluse %d equal do?\n", playerId, number1, number2);
  return number1 + number2;
}

void playTurn(Player *player){

  int rightAnswer = generateQuestionAndAnswer(player ->id);
  int givenAnswer;
  scanf("%d", &givenAnswer);
  player ->answer = givenAnswer;
  if (player ->answer == rightAnswer) {

    player ->score++;
    player -> loseLife = 'N';
  } else {

    //player -> score--;
    player -> loseLife = 'Y';
  }

}

void showScore(Player *player1, Player *player2) {
  if (player1->loseLife == 'Y' || player2->loseLife == 'Y') {
    printf("Player 1 Score: %d, Player 2 Score: %d\n", player1->score, player2->score);
    player1->loseLife = 'N';
    player2->loseLife = 'N';
  }

}






















