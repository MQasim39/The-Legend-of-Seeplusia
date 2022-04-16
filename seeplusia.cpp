#include "mover.hpp"
#include "seeplusia.hpp"

// Initializing Variables
string direction;
int applesLeft = 20;  
int nCrystalsFound = 0;
string gameState  = "Running";
string currentState = "EnchantedForest";

// Initialzing Crystals (So, Crystal can only be taken once)
int marshCrystal = 0;
int eistenCrystal = 0;
int swampsCrystal = 0;
int werewolfCrystal = 0;

// Functions for direction
void WampireCove(string direction);
void WerewolfHill(string direction);
void EistenTunnel(string direction);
void MarshOfUndead(string direction);
void ApplesOrchard(string direction);
void BridgeOfDeath(string direction);
void ElvinWaterfall(string direction);
void EnchantedForest(string direction);
void SwampsOfDespair(string direction);

// Functions for Crystal can only be taken once
int MarshCrystal();
int SwampsCrystal();
int EistenCrystal();
int WerewolfCrystal();

// Functions for improving code
int Invalid();
int YouLost();

//********************* make Move Function ***********************

void makeMove(string direction){
	if (currentState == "EnchantedForest"){
		EnchantedForest(direction);
	}
	else if (currentState == "WampireCove"){
		WampireCove(direction);
	}
	else if (currentState == "MarshOfUndead"){
		MarshOfUndead(direction);
	}
	else if (currentState == "ApplesOrchard"){
		ApplesOrchard(direction);
	}
	else if (currentState == "WerewolfHill"){
		WerewolfHill(direction);
	}
	else if (currentState == "SwampsOfDespair"){
		SwampsOfDespair(direction);
	}
	else if (currentState == "ElvinWaterfall"){
		ElvinWaterfall(direction);
	}
	else if (currentState == "EistenTunnel"){
		EistenTunnel(direction);
	}
	else if (currentState == "BridgeOfDeath"){
		BridgeOfDeath(direction);
	}
	else{
		Invalid();
	}
}

//********************** Functions for direction ****************************

// Enchanted Forest
void EnchantedForest(string direction){
	if (direction == "East"){					
		if (applesLeft >= 1){							                  
			currentState = "SandsOfQuick";               
			cout<<"You are arrived at Sands of Quick."<<endl;			// Sands of quick
			moveEast();													// Player is strucked in quick sand
			gameState = "Lost"; 										// Lost
			applesLeft --;
		}
		else{
			YouLost();
		}
	}
	else if (direction == "South"){
		if (applesLeft >= 3){
			currentState = "WampireCove";
			cout<<"You are arrived at Wampire Cove."<<endl;
			moveSouth();
			gameState = "Running"; 
			applesLeft -= 3;
		}
		else{
			YouLost();
		}
	}
	else{
		Invalid();
	}
}

// Wampire Cove
void WampireCove(string direction){
	if (direction == "East"){					
		if (applesLeft >= 1){							
			currentState = "MarshOfUndead";
			cout<<"You are arrived at Marsh of Undead."<<endl;
			moveEast(); 
			gameState = "Running"; 
			applesLeft --;			
			MarshCrystal();													
		}
		else{
			YouLost();
		}
	}
	else if (direction == "North"){
		if (applesLeft >= 3){
			currentState = "EnchantedForest";
			cout<<"You are arrived at Enchanted Forest."<<endl;
			moveNorth();
			gameState = "Running"; 
			applesLeft -= 3;
		}
		else{
			YouLost();
		}
	}
	else if (direction == "West"){
		if (applesLeft >= 1){
			currentState = "SwampsOfDespair";
			cout<<"You are arrived at Swamps of Despair."<<endl;
			moveWest(); 
			gameState = "Running"; 
			applesLeft --;
			SwampsCrystal();
		}
		else{
			YouLost();
		}
	}
	else if (direction == "South"){
		if (applesLeft >= 3){
			currentState = "WerewolfHill";					
			cout<<"You are arrived at Werewolf Hill."<<endl;
			moveSouth(); 
			gameState = "Running"; 
			applesLeft -= 3;
			WerewolfCrystal();
		}
		else{
			YouLost();
		}
	}
	else { 
		Invalid();
	}
}

// Marsh of Undead
void MarshOfUndead(string direction){
	if (direction == "West"){
		if (applesLeft >= 1){								
			currentState = "WampireCove";
			cout<<"You are arrived at Wampire Cove."<<endl;
			moveWest(); 
			gameState = "Running"; 
			applesLeft --;
		}
		else{
			YouLost();
		}
	}
	else if (direction == "South"){
		if (applesLeft >= 1){								
			currentState = "ApplesOrchard";				
			cout<<"You are arrived at Apples Orchard."<<endl;			// Apples Orchard
			moveSouth(); 												// Gain 6 Apples
			gameState = "Running"; 					
			applesLeft += 5;
		}
		else{
			YouLost();
		}
	}
	else { 
		Invalid();
	}
}

//Apples Orchard
void ApplesOrchard(string direction){
	if (direction == "West"){
		if (applesLeft >= 1){							
			currentState = "WerewolfHill";
			cout<<"You are arrived at Werewolf hill."<<endl;
			moveWest(); 
			gameState = "Running"; 
			applesLeft --;
			WerewolfCrystal();
		}
		else{
			YouLost();
		}
	}
	else { 
		Invalid();
	}
}

// Werewolf Hill
void WerewolfHill(string direction){
	if (direction == "West"){
		if (applesLeft >= 2){									
			currentState = "ElvinWaterfall";
			cout<<"You are arrived at Elvin Waterfall."<<endl;
			moveWest(); 						
			gameState = "Running"; 
			applesLeft -= 2;
		}
		else{
			YouLost();
		}
	}
	else if (direction == "North"){
		if (applesLeft >= 3){
			currentState = "WampireCove";
			cout<<"You are arrived at Wampire Cove."<<endl;
			moveNorth(); 
			gameState = "Running"; 
			applesLeft -= 3;
		}
		else{
			YouLost();
		}
	}
	else { 
		Invalid();
	}
}

// Swamps of Despair
void SwampsOfDespair(string direction){
	if (direction == "North"){
		if (applesLeft >= 1){
			currentState = "BridgeOfDeath";
			cout<<"You are arrived at Bridge of Death."<<endl;
			moveNorth(); 
			gameState = "Running"; 
			applesLeft --;
		}
		else{
			YouLost();
		}
	}
	else if (direction == "East"){
		if (applesLeft >= 1){
			currentState = "WampireCove";
			cout<<"You are arrived at Wampire Cove."<<endl;
			moveEast(); 
			gameState = "Running"; 
			applesLeft --;
		}
		else{
			YouLost();
		}
	}
	else { 
		Invalid();
	}
}

// Elvin Waterfall
void ElvinWaterfall(string direction){
	if (direction == "West"){
		if (applesLeft >= 2){
			currentState = "EistenTunnel";
			cout<<"You are arrived at Eisten Tunnel."<<endl;
			moveWest(); 
			gameState = "Running"; 
			applesLeft -= 2;
			EistenCrystal();
		}
		else{
			YouLost();
		}
	}
	else if (direction == "East"){
		if (applesLeft >= 2){
			currentState = "WerewolfHill";					
			cout<<"You are arrived at Werewolf Hill."<<endl;
			moveEast(); 
			gameState = "Running"; 
			applesLeft -= 2;
		}
		else{
			YouLost();
		}
	}
	else { 
		Invalid();
	}
}

// Eisten Tunnel
void EistenTunnel(string direction){
	if (direction == "East"){
		if (applesLeft >= 2){
			currentState = "ElvinWaterfall";						
			cout<<"You are arrived at Elvin Waterfall."<<endl;
			moveEast(); 
			gameState = "Running"; 
			applesLeft -= 2;
		}
		else{
			YouLost();
		}
	}
	else if (direction == "North"){									
		if (nCrystalsFound >= 3 && applesLeft >= 10){
			currentState = "WizardCastle";									// To cross Eisten Tunnell
			cout<<"You are arrived at Wizard Castle."<<endl;				// Need 3 Crystals & 10 apples
			moveNorth();
			moveNorth();
			gameState = "Won";
			applesLeft -= 10;
		}
		else if (applesLeft == 0){			
			YouLost();	
		}
		else{
			cout<<"You require 3 crystals and 10 apples to cross Eisten Tunnel"<<endl;		
		}
	}
	else { 
		Invalid();
	}
}

// Bridge of Death
void BridgeOfDeath(string direction){
	if (direction == "West"){
		if (nCrystalsFound >= 4 && applesLeft >= 5){			
			currentState = "WizardCastle";
			cout<<"You are arrived at Wizard Castle."<<endl;		
			moveWest();												// To cross bridge of Death
			gameState = "Won"; 										// Need 4 Crystals & 5 apples 
			applesLeft -= 5;										
		}
		else if (applesLeft == 0){	
			YouLost();
		}
		else{
			cout<<"You require 4 Crystals to cross bridge of Death."<<endl;
		}
	}
	else { 
		Invalid();												
	}
}

// ***************** Functions for Crystal can only be taken once ********************

// Marsh of Undead Crystal
int MarshCrystal(){
	if(marshCrystal == 0){				
		nCrystalsFound ++;					
		marshCrystal ++;
	}
	else{
		cout << "You have already collected the crystal from here."<<endl;	
	}
}

// Swamps of Despair Crystal
int SwampsCrystal(){
	
	if (swampsCrystal == 0){
		nCrystalsFound ++;					
		swampsCrystal ++;
	}
	else{
		cout << "You have already collected the crystal from here."<<endl;  
	}
}

// Werewolf Crystal
int WerewolfCrystal(){
	if (werewolfCrystal == 0){					
		nCrystalsFound ++;						
		werewolfCrystal ++;
	}
	else{
		cout << "You have already collected the crystal from here."<<endl;		
	}
}

// Eisten Crystal
int EistenCrystal(){
	if (eistenCrystal == 0){
		nCrystalsFound ++;							
		eistenCrystal ++;
	}
	else{
		cout << "You have already collected the crystal from here."<<endl;	
	}
}

// ********************* Functions for improving code **********************

// Invalid Function
int Invalid(){
	if (applesLeft >= 1){
		cout<<"Invalid move."<<endl;  						
		gameState = "Running";
		applesLeft --;
	}
	else{
		YouLost();
	}
}

// You Lost Function
int YouLost(){
	gameState = "Lost";
	cout<<"You run out of food and died of starvation"<<endl;
}	



