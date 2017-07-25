// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

// prototypes
void shuffle(unsigned int wDeck[][ FACES ] ); // shuffling modifies wDeck
void deal( unsigned int wDeck[][ FACES ], unsigned int hand[][2], const char *wFace[], const char *wSuit[]); // dealing doesn't modify the arrays

//functions to write
void pair(unsigned int hand[][2], const char *suit[], const char *face[]);
void threeOfKind(unsigned int hand[][2], const char *suit[],const char *face[]);
void fourOfKind(unsigned int hand[][2],const char *suit[],const char *face[]);
void straightHand( unsigned int hand[][2],const char *suit[],const char *face[]);
void flushHand(unsigned int hand[][2],const char *suit[],const char *face[]);

int main( void )
{
    // initialize suit array
    const char *suit[ SUITS ] =
    { "Hearts", "Diamonds", "Clubs", "Spades" };
// initialize face array
    const char *face[ FACES ] =
    {   "Ace", "Deuce", "Three", "Four",
        "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Jack", "Queen", "King"
    };
// initialize deck array
   unsigned int deck[ SUITS ][ FACES ] = { 0 };
   unsigned int hand[5][2];

   srand( time( NULL ) ); // seed random-number generator 32
   for (int i = 0; i < 3; ++i)
   {
    shuffle( deck ); // shuffle the deck
    deal( deck, hand,  face, suit ); // deal the deck/
   }
   
}//endmain

// shuffle cards in deck
void shuffle( unsigned int wDeck[][ FACES ] )
{
    size_t row; // row number
    size_t column; // column number
    size_t card; // counter

// for each of the cards, choose slot of deck randomly

// initialize face array
    const char *face[ FACES ] =
    {   "Ace", "Deuce", "Three", "Four",
        "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Jack", "Queen", "King"
    };
    for (card = 1; card <= CARDS; ++card ) {
        // choose new random location until unoccupied slot found
        do {
            row = rand() % SUITS;
            column = rand() % FACES;
        } while(wDeck[row][column] != 0);

        // place card number in chosen slot of deck
        wDeck[ row ][ column ] = card;
    } // end for
} // end function shuffle

//deal cards in deck
void deal( unsigned int wDeck[][FACES],unsigned int hand[][2], const char *face[],const char *suit[] )
{
    size_t card; // card counter
    size_t row; // row counter
    size_t column; // column counter
   
/*    // deal each of the cards
    for ( card = 1; card <= CARDS; ++card ) {
// loop through rows of wDeck
        for ( row = 0; row < SUITS; ++row ) {
            // loop through columns of wDeck for current row
            for ( column = 0; column < FACES; ++column ) {
// if slot contains current card, display card
                if(wDeck[row][column]==card) {
                    printf( "%5s of %-8s%c", face[ column ], suit[ row ],
                            card % 2 == 0 ? '\n' : '\t' ); // 2-column format
                }//endif } // end for
            } // end for
        } // end for
    } // end function deal

*/
       printf("Five cards given: \n"); //five cards for user
   for ( card = 1; card <= 5; ++card ) {
      // loop through rows of wDeck
      for ( row = 0; row < SUITS; ++row ) {
         // loop through columns of wDeck for current row
         for ( column = 0; column < FACES; ++column ) {
            // if slot contains current card, display card
            if (wDeck[row][column]==card) {
               printf( "%5s of %-8s\n", face[ column ], suit[ row ]); 
         	
               hand[card][0] = row ;
               hand[card][1] = column ;
            } // end if
         } // end for
      } // end for
   } // end for

    pair(hand, suit, face);
    threeOfKind(hand, suit, face);
    straightHand(hand, suit, face);
    
    flushHand(hand, suit, face);
}

void pair(unsigned int hand[][2],const char *suit[],const char *face[]){
	  //counter that records how many cards of each rank are in the hand
    unsigned int counter[FACES] = {};

    //records how many cards of each rank are in teh hand
    for (size_t i = 1; i < 6; ++i)
    {
        counter[hand[i][1]]++;
        printf("%d\n",hand[i][1] );
    }

    //print result if there is a three of a kind
    for (size_t i = 0; i < FACES; ++i)
    {
        if (counter[i] == 2)
            {
                printf("The hand contains two %ss.\n", face[i]);
            }    
    }
	}

void threeOfKind(unsigned int hand[][2],const char *suit[],const char *face[]){
    //counter that records how many cards of each rank are in the hand
   unsigned int counter[FACES] = {};

    //records how many cards of each rank are in teh hand
    for (size_t i = 1; i < 6; ++i)
    {
        counter[hand[i][1]]++;
        printf("%d\n",hand[i][1] );
    }

    //print result if there is a three of a kind
    for (size_t i = 0; i < FACES; ++i)
    {
        if (counter[i] == 3)
            {
                printf("The hand contains three %ss.\n", face[i]);
            }    
    }
}

void fourOfKind(unsigned int hand[][2],const char *suit[],const char *face[]){
	    //counter that records how many cards of each rank are in the hand
   unsigned int counter[FACES] = {};

    //records how many cards of each rank are in teh hand
    for (size_t i = 1; i < 6; ++i)
    {
        counter[hand[i][1]]++;
        printf("%d\n",hand[i][1] );
    }

    //print result if there is a three of a kind
    for (size_t i = 0; i < FACES; ++i)
    {
        if (counter[i] == 4)
            {
                printf("The hand contains four %ss.\n", face[i]);
            }    
    }
}


//determine if there is straight in hand
void straightHand(unsigned int hand[][2], const char *suit[], const char *face[]){
	unsigned int s[5] = {}; //array that holds a copy of hand
	unsigned int temp; //temp int

	//copy column locations to sort
	for (size_t r = 0; r < 5; ++r)
	{
		s[r] = hand[r][1];
	}

	//bubble sort column locations
	for (size_t pass = 1; pass < 5; ++pass)
	{
		for (size_t comp = 0; comp < 4; ++comp)
		{
			if (s[comp] > s[comp + 1])
			{
				temp = s[comp];
				s[comp] = s[comp + 1];
				s[comp + 1] = temp;
			}
		}
	}

	//check if sorted columns are a straight
	if (s[4] - 1 == s[3] && s[3] -1 == s[2] && s[2] - 1 == s[1] && s[1] - 1 == s[0])
	{
		printf("The hand contains a straight from %s to %s.\n", face[s[0]], face[s[4]]);
	}
}

void flushHand(unsigned int hand[][2],const char *suit[],const char *face[]){
		    //counter that records how many cards of each rank are in the hand
   unsigned int counter[SUITS] = {};

    //records how many cards of each rank are in teh hand
    for (size_t i = 1; i < 6; ++i)
    {
        counter[hand[i][0]]++;
        printf("%d\n",hand[i][0] );
    }

    //print result if there is a three of a kind
    for (size_t i = 0; i < FACES; ++i)
    {
        if (counter[i] == 5)
            {
                printf("The hand contains four %ss.\n", face[i]);
            }    
    }
}


