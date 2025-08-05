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

int dealerCount = 0;
int playerCount = 0;


//bool isEmpty(){
//	for( const auto& [key, value] : deck) {
//		if(value != 0){
//	 	return false;
//		}
//	}
//	return true;
		
//}

int newCard(){
//	if(isEmpty()){
//		return 0;
//	}
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(1, 14);
	int card = distr(gen);
	return card;
}
string dealCard(){
	
	string yourCard = "";
	int card_idx = newCard();
//	while(deck[card_idx == 0]){
//		card_idx = newCard();
//	}

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


void getDealerCount(string x){
	if(x == "1" || x == "2" || x == "3" || x == "4" || x == "5" || x == "6" || x == "7" || x == "8" || x == "9" || x == "10"){
		dealerCount += stoi(x);
	}
	else{
		dealerCount += 10;
	}

}

void getPlayerCount(string y){
	if(y == "1" || y == "2" || y == "3" || y == "4" || y == "5" || y == "6" || y == "7" || y == "8" || y == "9" || y == "10"){
		playerCount += stoi(y);
	}
	else {
		playerCount += 10;
	}
}

int main(){
	string x;	
	cout << "Welcome to BlackJack" <<endl;
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


	
		string y;
		cout << "1: Hit, 2: Stand ::: ";
		cin >> y;
		while(y=="1"){
			x = dealCard();
			getPlayerCount(x);
			cout << x << endl;			
			if(playerCount > 21){
				cout << "Busted" << playerCount << endl;
				return 0;
			}
			
			cout << "1: Hit, 2: Stand" << endl;
			cin >> y;
		}
		if ( y =="2"){
			x = dealCard();
			getDealerCount(x);
			cout << x;
	
		}
	


	return 0;
}
