#include <iostream>
#include <map>
#include <random>
#include <string>
using namespace std;

map<string, int> deck = {
	{"1", 4 },
	{"2", 4 },
	{"3", 4 },
	{"4", 4 },
	{"5", 4 },
	{"6", 4 },
	{"7", 4 },
	{"8", 4 },
	{"9", 4 },
	{"10", 4 },
	{"J", 4 },
	{"Q", 4 },
	{"K", 4 },
	{"A", 4 }
};

bool isEmpty(){
	for( const auto& [key, value] : deck) {
		if(value != 0){
	 	return false;
		}
	}
	return true;
		
}

void dealCard(){

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(1, 14);
	if (isEmpty()){
		cout << "Deck is Empty" << endl;
		return ;
	}

	int card = distr(gen);
	if( card < 11 ){
		cout<< to_string(card);
		deck[to_string(card)]--;
	}
	else if (card == 11){
		cout << "J";
		deck["J"]--;
	}
	else if (card == 12){
		cout << "Q";
		deck["Q"]--;
	}
	else if (card == 13){
		cout << "K";
		deck["K"]--;
	}
	else{
		cout << "A";
		deck["A"]--;
	}
	
}


int main(){
	
	cout << "Welcome to BlackJack" <<endl;
	cout << "Dealer: "; 
	dealCard();
	cout << endl;
	cout << "You: "; 
	dealCard(); 
	cout<< " "; 
	dealCard();
	cout << endl;




	return 0;
}
