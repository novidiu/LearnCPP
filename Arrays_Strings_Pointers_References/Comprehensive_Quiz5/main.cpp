/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ovidiu Nitescu
 *
 * Created on February 28, 2018, 10:42 AM
 */

#include <cstdlib>
#include <iostream>
#include <array>
#include <cmath>

using namespace std;

enum CardSuit
{
    SUIT_CLUB,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_SPADE,
    MAX_SUITS
};

enum CardRank
{
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,
    MAX_RANKS
};


struct Card
{
    CardRank rank;
    CardSuit suit;
};

void printCard (const Card &card)
{
    switch(card.rank)
    {
        case RANK_2:         cout << '2';   break;
        case RANK_3:         cout << '3';   break;
        case RANK_4:         cout << '4';   break;
        case RANK_5:         cout << '5';   break;
        case RANK_6:         cout << '6';   break;
        case RANK_7:         cout << '7';   break;
        case RANK_8:         cout << '8';   break;
        case RANK_9:         cout << '9';   break;
        case RANK_10:        cout << 'T';   break;
        case RANK_JACK:      cout << 'J';   break;
        case RANK_QUEEN:     cout << 'Q';   break;
        case RANK_KING:      cout << 'K';   break;
        case RANK_ACE:       cout << 'A';   break;    
    }
    
    switch(card.suit)
    {
        case SUIT_CLUB:      cout << 'C'; break;
        case SUIT_DIAMOND:   cout << 'D'; break;
        case SUIT_HEART:     cout << 'H'; break;
        case SUIT_SPADE:     cout << 'S'; break;
    }
    
}

void printDeck(const array<Card, 52> &deck)
{
    for(const auto &card : deck)
    {
        printCard(card);
        cout << ' ';
    }
    cout << '\n';
}

void swapCards(Card &a, Card &b)
{
    Card temp = a;
    a = b;
    b = temp;
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand()* fraction * (max - min + 1) + min);
}

void shuffleDeck( array<Card, 52> &deck)
{
    for (int index = 0; index < 52; ++index)
    {
        int swapIndex = getRandomNumber(0, 51);
        swapCards(deck[index], deck[swapIndex]);
    }
}

int getCardValue(const Card &card)
{
    switch(card.rank)
    {
        case RANK_2:    return 2; break;
        case RANK_3:    return 3; break;
        case RANK_4:    return 4; break;
        case RANK_5:    return 5; break;
        case RANK_6:    return 6; break;
        case RANK_7:    return 7; break;
        case RANK_8:    return 8; break;
        case RANK_9:    return 9; break;
        case RANK_10:   return 10; break;
        case RANK_JACK: return 10; break;
        case RANK_QUEEN:return 10; break;        
        case RANK_KING: return 10; break;
        case RANK_ACE:  return 11; break;
    }
}

char getPlayerChoice()
{
    cout << "(h) to hit, or (s) to stand: ";
    char choice;
    do
    {
        cin >> choice;
    }while(choice != 'h' && choice != 's');
    
    return choice;
}

enum BalckjackResults
{
    BLACKJACK_PLAYER_WIN,
    BLACKJACK_DEALER_WIN,
    BLACKJACK_TIE
};

BalckjackResults plyBlackjack(const array<Card, 52> &deck)
{
    const Card *cardPtr = &deck[0];
    
    int playerTotal = 0;
    int dealerTotal = 0;
    
    dealerTotal += getCardValue(*cardPtr++);
    cout << "The dealer is showing: " << dealerTotal << '\n';
    
    playerTotal += getCardValue(*cardPtr++);
    dealerTotal += getCardValue(*cardPtr++);
    
    while(true)
    {
        cout << "You have: " << playerTotal << '\n';
        
        if (playerTotal > 21)
            return BLACKJACK_DEALER_WIN;
        
        char choice = getPlayerChoice();
        if (choice == 's')
            break;
        
        playerTotal += getCardValue(*cardPtr++);
    }
    
    while(dealerTotal < 17)
    {
        dealerTotal += getCardValue(*cardPtr++);
        cout << "The dealer has now: " << dealerTotal << '\n';
    }
    
    if (dealerTotal > 21)
        return BLACKJACK_PLAYER_WIN;
    
    if(playerTotal > dealerTotal)
        return BLACKJACK_PLAYER_WIN;
    else
        return BLACKJACK_DEALER_WIN;
    
    if (playerTotal == dealerTotal)
        return BLACKJACK_TIE;
}

/*
 * 
 */
int main(int argc, char** argv) 
{
    srand(static_cast<unsigned int>(time(0))); //set initial seed value to system clock
    
    array<Card, 52> deck;
    
    int card = 0;
    for(int suit = 0; suit < MAX_SUITS; ++suit)
    {
        for(int rank = 0; rank < MAX_RANKS; ++rank)
        {
            deck[card].suit = static_cast<CardSuit>(suit);
            deck[card].rank = static_cast<CardRank>(rank);
            ++card;
        }
    }
    printDeck(deck);
    
    shuffleDeck(deck);
    
    printDeck(deck);
    
    BalckjackResults game = plyBlackjack(deck);
    
    if (game == BLACKJACK_PLAYER_WIN)
        cout << "You win!!!";
    if (game == BLACKJACK_DEALER_WIN) 
        cout << "You lose!!!";
    if (game == BLACKJACK_TIE)
        cout << "TIE!!!!";
    return 0;
}

