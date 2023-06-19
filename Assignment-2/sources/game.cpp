#include "game.hpp"
#include <string>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

namespace ariel
{
    Player player = Player();
    std::string lastTurn = "";
    std::string log = "";

    Game::Game() : player1(player), player2(player), tie(false), numOfTie(0), draws(0), turns(0), p1Wins(0), p2Wins(0), p1CardsWon(0), p2CardsWon(0)
    {
        throw std::invalid_argument("Missing players!");
    }

    void printVector(std::vector<Card> &deck)
    {
        for (size_t i = 0; i < deck.size(); i++)
        {
            std::cout << deck[i].toString() << std::endl;
        }
    }

    Game::Game(Player &p1, Player &p2) : player1(p1), player2(p2), tie(false), numOfTie(0), draws(0), turns(0), p1Wins(0), p2Wins(0), p1CardsWon(0), p2CardsWon(0)
    {
        int index = 0;
        std::vector<Card> deck;
        for (Rank rank : {Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King})
        {
            for (Shape shape : {Hearts, Diamonds, Clubs, Spades})
                deck.push_back(Card(rank, shape));
        }
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 theSeed(seed);
        std::shuffle(deck.begin(), deck.end(), theSeed);
        std::vector<Card> p1Vector(deck.begin(), deck.begin() + 26);
        player1.setCards(&p1Vector);
        std::vector<Card> p2Vector(deck.begin() + 26, deck.end());
        player2.setCards(&p2Vector);
        player1.setStackSize(26);
        player2.setStackSize(26);
    }

    int Game::playTurn()
    {
        if (&player1 == &player2)
        {
            throw std::invalid_argument("Cannot play with one player\n");
            return 1;
        }
        else if (((player1.stacksize() <= 0 && player2.stacksize() <= 0) || turns >= 26) && !tie)
        {
            throw std::exception();
            return 1;
        }
        else
        {
            if (tie)
            {
                player1.getCards().pop_back();
                player1.setStackSize(player1.stacksize() - 1);

                player2.getCards().pop_back();
                player2.setStackSize(player2.stacksize() - 1);

                draws++;
            }

            Card c1 = player1.getCards().back();
            Card c2 = player2.getCards().back();

            player1.getCards().pop_back();
            player1.setStackSize(player1.stacksize() - 1);

            player2.getCards().pop_back();
            player2.setStackSize(player2.stacksize() - 1);

            if (c1.getRank() > c2.getRank())
            {
                player1.setCardsTaken(player1.cardesTaken() + 2 + 4 * numOfTie);
                lastTurn = player1.getName() + " " + c1.toString() + ", " + player2.getName() + " " + c2.toString() + ", " + player1.getName() + " wins!\n";
                log += lastTurn;
                tie = false;
                numOfTie = 0;
                lastTurn = "";
                turns++;

                player1.setStackSize(player1.getCards().size());
                player2.setStackSize(player2.getCards().size());
            }
            else if (c1.getRank() < c2.getRank())
            {
                player2.setCardsTaken(player2.cardesTaken() + 2 + 4 * numOfTie);
                lastTurn += player1.getName() + " " + c1.toString() + ", " + player2.getName() + " " + c2.toString() + ", " + player2.getName() + " wins!\n";
                log += lastTurn;
                tie = false;
                numOfTie = 0;
                lastTurn = "";
                turns++;

                player1.setStackSize(player1.getCards().size());
                player2.setStackSize(player2.getCards().size());
            }
            else
            {
                tie = true;
                numOfTie++;
                lastTurn += player1.getName() + " " + c1.toString() + ", " + player2.getName() + " " + c2.toString() + ", tie.\n";
                playTurn();
            }
        }
        return 0;
    }

    void Game::playAll()
    {
        while (player1.getCards().size() != 0 && player2.getCards().size() != 0 && turns < 26)
        {
            playTurn();
        }
        player1.setStackSize(0);
        player2.setStackSize(0);
    }

    void Game::printWiner()
    {
        std::cout << player1.cardesTaken() << " " << player2.cardesTaken() << "\n";
        if (player1.cardesTaken() > player2.cardesTaken())
        {
            std::cout << player1.getName() << " wins!\n";
        }
        else if (player1.cardesTaken() < player2.cardesTaken())
        {
            std::cout << player2.getName() << " wins!\n";
        }
        else if (player1.cardesTaken() != 0 && player2.cardesTaken() != 0)
        {
            std::cout << "Its a tie" << std::endl;
        }
    }

    void Game::printLastTurn() { std::cout << lastTurn << std::endl; }

    void Game::printLog() { std::cout << log << std::endl; }

    void Game::printStats() {}

    Player Game::getFirstPlayer() { return player1; }

    Player Game::getSecondPlayer() { return player2; }

    Game::~Game() {}
}