// Game 6: Blackjack card game
// In this simplified console-based Blackjack game, the player faces off against the dealer with the objective of achieving a hand value as close to 21 as possible without exceeding it. The game begins with the initial dealing of two cards to both the player and the dealer. The player must decide whether to "hit" (receive another card) or "stand" (keep their current hand) while carefully managing their hand's total value. Blackjack (an Ace and a 10-point card) results in an instant win, but exceeding 21 results in a "bust" and a loss. The player competes against the dealer's hand, which follows specific rules, aiming to beat the dealer and win the round. The game continues until the player decides to "stand" or specific win/lose conditions are met

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Card structure
struct Card
{
    string suit;
    string rank;
    int value;
};

// Function to initialize a standard deck of cards
vector<Card> initializeDeck()
{
    vector<Card> deck;
    string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

    for (const string &suit : suits)
    {
        for (const string &rank : ranks)
        {
            int value = (rank == "Ace") ? 11 : (isdigit(rank[0]) ? rank[0] - '0' : 10);
            deck.push_back({suit, rank, value});
        }
    }

    return deck;
}

// Function to shuffle the deck
void shuffleDeck(vector<Card> &deck)
{
    int n = deck.size();
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(deck[i], deck[j]);
    }
}

// Function to deal a card from the deck
Card dealCard(vector<Card> &deck)
{
    Card card = deck.back();
    deck.pop_back();
    return card;
}

// Function to calculate the total value of a hand
int calculateHandValue(const vector<Card> &hand)
{
    int value = 0;
    int numAces = 0;

    for (const Card &card : hand)
    {
        value += card.value;
        if (card.rank == "Ace")
        {
            numAces++;
        }
    }

    while (value > 21 && numAces > 0)
    {
        value -= 10;
        numAces--;
    }

    return value;
}

int main()
{
    srand(static_cast<unsigned>(time(0)));

    vector<Card> deck = initializeDeck();
    shuffleDeck(deck);

    vector<Card> playerHand, dealerHand;
    playerHand.push_back(dealCard(deck));
    dealerHand.push_back(dealCard(deck));
    playerHand.push_back(dealCard(deck));
    dealerHand.push_back(dealCard(deck));

    while (true)
    {
        int playerValue = calculateHandValue(playerHand);
        int dealerValue = calculateHandValue(dealerHand);

        cout << "Player's hand: ";

        for (const Card &card : playerHand)
        {
            cout << card.rank << " of " << card.suit << ", ";
        }
        cout << "Total value: " << playerValue << endl;

        if (playerValue == 21)
        {
            cout << "Player wins with Blackjack!" << endl;
            break;
        }
        else if (playerValue > 21)
        {
            cout << "Player busts! Dealer wins." << endl;
            break;
        }

        cout << "Dealer's hand: " << dealerHand[0].rank << " of " << dealerHand[0].suit << " and an unknown card" << endl;

        cout << "Do you want to 'hit' or 'stand'? ";
        string choice;
        cin >> choice;

        if (choice == "hit")
        {
            playerHand.push_back(dealCard(deck));
        }
        else if (choice == "stand")
        {
            while (dealerValue < 17)
            {
                dealerHand.push_back(dealCard(deck));
                dealerValue = calculateHandValue(dealerHand);
            }

            cout << "Dealer's hand: ";
            for (const Card &card : dealerHand)
            {
                cout << card.rank << " of " << card.suit << ", ";
            }
            cout << "Total value: " << dealerValue << endl;

            if (dealerValue > 21)
            {
                cout << "Dealer busts! Player wins." << endl;
            }

            else if (playerValue > dealerValue)
            {
                cout << "Player wins!" << endl;
            }

            else if (playerValue < dealerValue)
            {
                cout << "Dealer wins." << endl;
            }

            else
            {
                cout << "It's a tie!" << endl;
            }

            break;
        }
    }

    return 0;
}
