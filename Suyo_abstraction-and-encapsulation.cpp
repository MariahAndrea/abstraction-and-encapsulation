#include <iostream>
using namespace std;

class Account{
	private:
		float deposit, withdraw, balance;
	
	public: 
		Account(float d, float w, float b){
			deposit = d;
			withdraw = w;
			balance = b;
		}
		
		float getDeposit(){ return deposit; }
		float getWithdraw(){ return withdraw; }
		float getBalance(){ return balance; }		
};

class SavingsAccount{
	private:

		float balance = 1000;
		
	public:
		bool savingsValid = true;
		
		void depositToSavings(){
			float deposit = 0;
			
			
			cout << "\n	========== D E P O S I T ==========" << endl << endl;
			do{
				cout << "	Enter amount: ";
				cin >> deposit;
				
				if (cin.fail()) {
					cout << "	Invalid input. Please enter an integer." << endl << endl;
					cin.clear();
					cin.ignore(1000, '\n');
				} else if (deposit < 1){
					cout << "	Invalid input. Must be more than 0." << endl << endl;
					cin.clear(); 	
				} else {
					cout << "	Amount successfully deposited!" << endl << endl;
					balance += deposit;
				}		
			}	while (deposit < 1 || !savingsValid);
			
			system("PAUSE");
			system("CLS");
		}
		
		void withdrawFromSavings(){
			float withdraw = 0;
			char option;
				
			cout << "\n	========== W I T H D R A W ==========" << endl << endl;
			cout << "	-------------------------------------" << endl << endl;
			cout << "	Balance: " << balance  << endl << endl;
			cout << "	-------------------------------------" << endl << endl;
			
			if (balance == 0){
				cout << "	There is nothing to withdraw."<< endl;
				cout << "	Make a deposit first." << endl << endl;
			} else{
				do{
					cout << "	Enter amount: ";
					cin >> withdraw;	
				
					if (cin.fail()) {
						cout << "	Invalid input. Please enter an integer." << endl << endl;
						cin.clear();
						cin.ignore(1000, '\n');
					} else if (withdraw > balance){
						cout << "	Invalid input. Must not exceed balance." << endl << endl;
						cin.clear();
					} else if (withdraw < 1){
						cout << "	Invalid input. Must be greater than 0." << endl << endl;
						cin.clear();
					}else if (withdraw < balance){	
						cout << "	Amount successfully withdrawn!" << endl << endl;
						balance -= withdraw;
						break;
					} else if (withdraw == balance){
							cout << "\n	Withdrawing all of your remaining balance will close your account." <<endl;
							do{
								cout << "	Proceed? [Y/N]: ";
								cin >> option;
								
								if (option == 'Y' || option == 'y'){
									cout << "	Amount successfully withdrawn! Account closed." << endl << endl;
									balance -= withdraw;
									break;
								} else if (option == 'N' || option == 'n'){
									cout << "\n	Withdraw Unsucessful. The account was not closed." << endl << endl;
									break;
								} else {
									cout << "	Invalid input. Must be either 'Y' or 'N' only.'" << endl << endl;
								}			
							}	while (option != 'Y' || option != 'y' || option != 'N' || option != 'n' );
							break;
					}	
				}	while (withdraw < 1 || withdraw > balance || !savingsValid);
			}
			
			system("PAUSE");
			system("CLS");
		}
		
		void checkSavingsBalance(){
			
			cout << "\n	========== B A L A N C E ==========" << endl << endl;
			cout << "	Balance: " << balance << endl << endl;
			
			system("PAUSE");
			system("CLS");
		}
			
};

class CurrentAccount{
	private:
		
		float balance = 0;
		
	public: 
		bool currentValid = true;
		
		void depositToCurrent(){
			float deposit = 0;
			
			cout << "\n	========== D E P O S I T ==========" << endl << endl;
			do{
				cout << "	Enter amount: ";
				cin >> deposit;
			
				if (cin.fail()) {
					cout << "	Invalid input. Please enter an integer." << endl << endl;
					cin.clear();
					cin.ignore(1000, '\n');
				} else if (deposit < 1){
					cout << "	Invalid input. Must be more than 0." << endl << endl;
					cin.clear();
					balance = 0;
				} else {
					cout << "	Amount successfully deposited!" << endl << endl;
					balance += deposit;
				}
			}	while (deposit < 1 || !currentValid);
			
			system("PAUSE");
			system("CLS");
		}
		
		void withdrawFromCurrent(){
			float withdraw = 0;
			char option;
			
			cout << "\n	========== W I T H D R A W ==========" << endl << endl;
			cout << "	-------------------------------------" << endl << endl;
			cout << "	Balance: " << balance  << endl << endl;
			cout << "	-------------------------------------" << endl << endl;
			
			if (balance == 0){
				cout << "	There is nothing to withdraw."<< endl;
				cout << "	Make a deposit first." << endl << endl;
			} else{
				do{
					cout << "	Enter amount: ";
					cin >> withdraw;	
				
					if (cin.fail()) {
						cout << "	Invalid input. Please enter an integer." << endl << endl;
						cin.clear();
						cin.ignore(1000, '\n');
					} else if (withdraw > balance){
						cout << "	Invalid input. Must not exceed balance." << endl << endl;
						cin.clear();
					} else if (withdraw < 1){
						cout << "	Invalid input. Must be greater than 0." << endl << endl;
						cin.clear();
					}else if (withdraw < balance){	
						cout << "	Amount successfully withdrawn!" << endl << endl;
						balance -= withdraw;
						break;
					} else if (withdraw == balance){
							cout << "\n	Withdrawing all of your remaining balance will close your account." <<endl;
							do{
								cout << "	Proceed? [Y/N]: ";
								cin >> option;
								
								if (option == 'Y' || option == 'y'){
									cout << "	Amount successfully withdrawn! Account closed." << endl << endl;
									balance -= withdraw;
									break;
								} else if (option == 'N' || option == 'n'){
									cout << "\n	Withdraw Unsucessful. The account was not closed." << endl << endl;
									break;
								} else {
									cout << "	Invalid input. Must be either 'Y' or 'N' only.'" << endl << endl;
								}			
							}	while (option != 'Y' || option != 'y' || option != 'N' || option != 'n' );
							break;
					}	
				}	while (withdraw < 1 || withdraw > balance || !currentValid);
			}
			
			system("PAUSE");
			system("CLS");
		}
		
		void checkCurrentBalance(){
			
			cout << "\n	========== B A L A N C E ==========" << endl << endl;
			cout << "	Balance: " << balance << endl << endl;
			
			system("PAUSE");
			system("CLS");
		}
};

int main(){
	SavingsAccount sav;
	CurrentAccount cur;
	int choice, savoption, curoption;
	bool menuvalid = false;
	
	do{
		cout << "\n	------ R I V E R   B A N K ------" << endl << endl;
		cout << "	[1] Savings Account" << endl;
		cout << "	[2] Current Account" << endl;
		cout << "	[3] Exit" << endl << endl;
		
		do{
			cout << "	Enter option: ";
				cin >> choice;
				
			if (cin.fail()) {
				cout << "	Invalid input. Please enter an integer." << endl << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			} else if (choice > 3 || choice < 1 ){
				cout << "	Invalid input. Please choose from 1 to 3 only." << endl << endl;
			} else{
				break;
			}
		} while (choice != 3 || !menuvalid);
		system("CLS");
		
		switch (choice){ //submenu
			case 1:
				do {	
					cout << "\n	---------- S A V I N G S ----------" << endl << endl;
					cout << "	[1] Deposit" << endl;
					cout << "	[2] Withdraw" << endl;
					cout << "	[3] Check Balance" << endl;
					cout << "	[4] Back" << endl << endl;
					
					do{
						cout << "	Enter option: ";
						cin >> savoption;
								
						if (cin.fail()) {
							cout << "	Invalid input. Please enter an integer." << endl << endl;
							cin.clear();
							cin.ignore(1000, '\n');
						} else if (savoption > 4 || savoption < 1 ){
							cout << "	Invalid input. Please choose from 1 to 4 only." << endl << endl;
						} else{
							break;
						}
					} while (!menuvalid);
					system("CLS");
						
					switch (savoption){ 
						case 1:
							sav.depositToSavings();
							break;
						case 2:
							sav.withdrawFromSavings();
							break;
						case 3: 
							sav.checkSavingsBalance();
							break;
						case 4:
							break;
						default:
							cout << "	Invalid input. Try again." << endl << endl;
							break;
					}
				} while (savoption != 4);
				break;
				
			case 2:
				do{
					cout << "\n	---------- C U R R E N T ----------" << endl << endl;
					cout << "	[1] Deposit" << endl;
					cout << "	[2] Withdraw" << endl;
					cout << "	[3] Check Balance" << endl;
					cout << "	[4] Back" << endl << endl;
					
					do{
						cout << "	Enter option: ";
						cin >> curoption;	
							
						if (cin.fail()) {
							cout << "	Invalid input. Please enter an integer." << endl << endl;
							cin.clear();
							cin.ignore(1000, '\n');
						} else if (curoption > 4 || curoption < 1 ){
							cout << "	Invalid input. Please choose from 1 to 4 only." << endl << endl;
						} else{
							break;
						}
					} while (!menuvalid);
		
					system("CLS");
					
						switch (curoption){
						case 1:
							cur.depositToCurrent();
							break;
						case 2:
							cur.withdrawFromCurrent();
							break;
						case 3: 
							cur.checkCurrentBalance();
							break;
						case 4:
							break;
						default:
							cout << "	Invalid input. Try again." << endl << endl;
							break;
						}
				} while (curoption != 4);
				
				break;
			case 3:
				system("CLS");
				cout << "\n	------ F I S H E R - Y   B A N K ------" << endl << endl;
				cout << "	Exiting..." << endl;
				exit(0);
				break;
			default:
				cout << "	Invalid input. Try again." << endl << endl;	
			}	
		
	}	while (choice != 3);
	
}