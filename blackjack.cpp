#include <iostream>
#include <map>
#include <random>
#include <string>
using namespace std;

map<int, int> deck = {
	{1, 4 },
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
	for( const auto& [key, value] : deck) {
		if(value != 0){
	 	return false;
		}
	}
	return true;
		
}

int newCard(){
	if(isEmpty()){
		return 0;
	}
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(1, 14);
	int card = distr(gen);
	return card;
}
string dealCard(){
	
	string yourCard = "";
	int card_idx = newCard();
	while(deck[card_idx == 0]){
		card_idx = newCard();
	}

	if( card_idx < 11 ){
		yourCard = to_string(card_idx);
		deck[card_idx]--;
	}
	else if (card_idx == 11){
		yourCard = "J";
		deck[11]--;
	}
	else if (card_idx == 12){
		yourCard = "Q";
		deck[12]--;
	}
	else if (card_idx == 13){
		yourCard = "K";
		deck[13]--;
	}
	else{
		yourCard = "A";
		deck[14]--;
	}
	
	return yourCard;
}

int main(){
	
	cout << "Welcome to BlackJack" <<endl;
	cout << "Dealer: " << dealCard() << endl;
	cout << "You: " << dealCard() << " " << dealCard() << endl;




	return 0;
}
