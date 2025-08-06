#include <iostream>
#include <map>
#include <random>
#include <string>
using namespace std;

bool dealerAce = false;
bool playerAce = false;

int dealerCount = 0;
int playerCount = 0;

string dealer_first_card;

map<int, int> deck = {
	{2, 4 },
	{3, 4 },
	{4, 4 },
	{5, 4 },
	{6, 4 },
	{7, 4 },
	{8, 4 },
	{9, 4 },
	{10, 4 },
	{11, 4 },
	{12, 4 },
	{13, 4 },
	{14, 4 }
};

bool isEmpty(){
	for( const auto& x : deck) {
		if(x.second != 0){
	 	return false;
		}
	}
	return true;
		
}


int newCard(){
	if(isEmpty()){
		cout << "Deck is empty" << endl;
		return 0;
	}
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(2, 14);
	int card = distr(gen);
	return card;
}
string dealCard(){
	
	string yourCard = "";
	int card_idx = newCard();
	while(deck[card_idx == 0]){
		card_idx = newCard();
	}
  	deck[card_idx]--;
	if( card_idx < 11 ){
		yourCard = to_string(card_idx);
	}
	else if (card_idx == 11){
		yourCard = "J";
	}
	else if (card_idx == 12){
		yourCard = "Q";
	}
	else if (card_idx == 13){
		yourCard = "K";
	}
	else{
		yourCard = "A";
	}
	
	return yourCard;
}


void getDealerCount(string x){
	if(x == "2" || x == "3" || x == "4" || x == "5" || x == "6" || x == "7" || x == "8" || x == "9" || x == "10"){
		dealerCount += stoi(x);
	}
	else if (x == "A") {
		dealerCount += 11;
		dealerAce = true;
	}
	else{
		dealerCount += 10;
	}

}

void getPlayerCount(string y){
	if(y == "2" || y == "3" || y == "4" || y == "5" || y == "6" || y == "7" || y == "8" || y == "9" || y == "10"){
		playerCount += stoi(y);
	}
	else if (y == "A") {
		playerCount += 11;
		playerAce = true;
	}
	else{
		playerCount += 10;
	}
}

void newHand(){
	playerCount = 0;
	dealerCount = 0;
	string x;	
	cout << "Dealer: ";
	x = dealCard();
	getDealerCount(x);
	cout << x << endl;
	cout << "You: ";
	x = dealCard();
	getPlayerCount(x);
	cout << x;
	cout << " "; 
	x = dealCard(); 	
	getPlayerCount(x);
	cout << x << endl;

	dealer_first_card = dealCard();
	getDealerCount(dealer_first_card);
	if(dealerCount == 21){
		cout << "Dealer BlackJack" << endl;
		cout << "Dealer had a " << dealer_first_card << endl;
		cout << endl;
		newHand();
	}

}


void yourTurn(){


		string x;
		string y;
		cout << "1: Hit, 2: Stand ::: ";
		cin >> y;
		while(y=="1"){
			x = dealCard();
			getPlayerCount(x);
			cout << x << endl;			
			if(playerCount > 21){
				if(playerAce){
					playerCount -= 10;
					playerAce = false;
					cout << "1: Hit, 2: Stand ::: ";
					cin >> y;
					continue;
				}
				cout << "Busted" << endl;
				break;
			}			
			cout << "1: Hit, 2: Stand ::: ";
			cin >> y;
		}
		if ( y =="2"){
			cout << dealer_first_card << endl;
				while(dealerCount < 17){
					x = dealCard();
					getDealerCount(x);
					if(dealerCount == 21){
						cout << x << endl;
						cout << "multi-card blackjack" << endl;
					}
					else if(dealerCount > 21){
						if ( dealerAce ){
							dealerCount -= 10;
							dealerAce = false;
							continue;
						}
						cout << x << endl;
						cout << "Dealer Bust" << endl;
					}
					else{
						cout << x << endl;
					}
				
			}
	
		}

}

int main(){
	cout << "Welcome to BlackJack" << endl;
	while(!isEmpty()){
		newHand();
		if(playerCount == 21){
			cout << "BlackJack!" << endl;
			continue;
		}

		yourTurn();

		cout << "your score : " << playerCount << endl;
		cout << "dealer score : " << dealerCount << endl;

		if ( dealerCount < playerCount && playerCount < 22) cout << "you win" << endl;
		if (playerCount < dealerCount && dealerCount < 22) cout << "you lose" << endl;
		if (playerCount == dealerCount && dealerCount < 22 && playerCount < 22) cout << "push" << endl;
		cout << endl;
	
		for( const auto x : deck){
			cout << x.first << x.second <<endl;
		}
	} 

	cout << "Deck is empty" << endl;
	return 0;
}
