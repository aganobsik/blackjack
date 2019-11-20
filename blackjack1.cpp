/*
  int vector of size 312 (52*6)
  %52 + 1 to get value of card
  /52 to get suit
    [0,1) Clubs
    [1,2) Diamonds
    [2,3) Hearts
    [3,4) Spades

    Randomize array
    If conditions for 10-14
    Ace = 1 (or 11, add 10)

    Jack = 11, Queen = 12, King = 13 -> if > 12 then = 10

    Suit variable
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Random generator function from c++ documentation:
int myrandom(int i){
  return std::rand()%i;
}

// Randomly shuffles order of deck
void shuffle(vector<int> &cards){
  random_shuffle(cards.begin(), cards.end(), myrandom);
}

int getValue(int card){
  int counter = card/52; // Figure out card in deck
  int deck = card - counter*52;
  counter = deck/13; // Figure out value of card
  return deck - counter*13 + 1;
}


string getSuit(int card){
        if (card <= 13){
        return "Heart";
        }
        else if (card <=26){
        return "Diamond";
        }
        else if (card <=39) {
        return "Club";
        }
        else if (card <= 52){
        return "Spade";
        }
}


int main(){
  srand(time(NULL)); // Set seed
  int numDecks = 6;
  int wallet;
  vector<int> cards;
  vector<int> playerHand;
  vector<int> dealerHand;
  vector<string> playerSuit;
  vector<string> dealerSuit;
  int currentCard = 0;


  for (int i = 0; i < numDecks * 52; ++i){ // Creates deck in order
    cards.push_back(i);
  }

  shuffle(cards);
/*
// Disp Deck
  for (const auto &card : cards){
   cout << card << " ";
  }
        cout << endl << endl;
*/
  // Deal
  playerHand.push_back(cards[currentCard++]);
  dealerHand.push_back(cards[currentCard++]);
  playerHand.push_back(cards[currentCard++]);
  dealerHand.push_back(cards[currentCard++]);
/*
  for (const auto &card : playerHand){
    cout << getValue(card) << " ";
  }
  cout << endl;

  for (const auto &card : dealerHand){
    cout << getValue(card) << " ";
  }
  cout << endl;
*/

 //Determine Suits
int  i=1;
 for (const auto &card : playerHand){
 playerSuit.push_back(getSuit(getValue(card)));

 }
 for (const auto &card : dealerHand){
 dealerSuit.push_back(getSuit(getValue(card)));
 }

// Begin Game
 //Disp Dealer Card
 cout << "The Dealer Has Been Dealt a " << getValue(dealerHand[1]);
 cout << " of " << dealerSuit[0] << "s" << endl << endl;
 cout << "Your Cards are:" << endl;
 cout << getValue(playerHand[0]) << " of " << playerSuit[0] << "s" << endl;
 cout << getValue(playerHand[1]) << " of " << playerSuit[1] << "s" << endl;

 return 0;
}
// Need Program to recognize A,K,Q,J


/*
   * Old syntax.
   *
  for (int i = 0; i < words.size(); ++i){
    cout << words[i] << endl;
  }

  // Ranged-for syntax
  for (const string &temp : words){
    cout << temp << endl;
  }
  */
