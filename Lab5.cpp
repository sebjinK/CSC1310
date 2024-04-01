/*                                    *
 *    Filename: Lab5                  *
 *    Author: Ethan Byker             *
 *    Date: 2/27/23                   *
 *    Purpose: Menu for Restaurant    *
 *                                    */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main(){

    //preparing the restaurant.txt for output
    ofstream reciept;
    reciept.open("restaurant.txt");
    if (!reciept.is_open()){
        cout << "Critical Failure! Please make sure restaurant.txt is in your folder!" << endl;
        exit(0);
    }

    //Declaration of variables
    int order = 0;
    int amount = 0;
    double toppings = 0;
    double pizzaCost;
    double cost;

    //Welcoming
    cout << "Welcome to The Cauldron Restaurat!" << endl;
    //Do-while statement for ordering and outputting results in the text file
    do {
        order = 0;
        cout << "Please choose one of the following options: \n1 - PIZZA \n2 - BURGER \n3 - SANDWICH \n4 - Done Ordering" << endl;
        //while loop with nested if statment to insure user puts in number 1-4
        while (order < 1 || order > 4){
            cout << "Choice: ";
            cin >> order;
            cout << endl;
            if (order < 1 || order > 4){
                cout << "Oops!  That is not a valid choice. Choose 1-4.";
            }
        }
        // switch statment for the selected order from user
        switch(order){
            case 1:{

                cout << "How  many pizzas do you want to order? ";
                cin >> amount;
                cout << endl;
                // for statment for each pizza
                for(int i = 1; i < amount + 1; i++){
                    cout << "For pizza " << i << ", how many toppings? ";
                    cin >> toppings;
                    pizzaCost = 20.00 + (toppings * 2.00);
                    //if statment for discount
                    if (i == 1){
                        pizzaCost = pizzaCost - (pizzaCost * .20);
                    }
                    cout << fixed << setprecision(2) << "This pizza cost $" << pizzaCost << endl;
                    cost += pizzaCost;
                }
                // outputs price to user in terminal and in the text file
                cout << fixed << setprecision(2) << amount << " Pizza(s) were added and the total is now $ " << cost << endl;
                reciept << fixed << setprecision(2) << amount << " Pizza(s) were added and the total is now $ " << cost << endl;
                break;

            }
            // simple math equation to give a discount and effictly price each burger
            // also outputs price to the text file
            case 2:{

                cout << "How many burgers do you want to order? ";
                cin >> amount;
                cout << endl;
                
                cost = cost + ((amount * 15.00) - 2.25);

                cout << fixed << setprecision(2) << amount << " burger(s) were added and the total is now $" << cost << endl;
                reciept << fixed << setprecision(2) << amount << " burger(s) were added and the total is now $" << cost << endl;

                break;

            }
            case 3:{
                

            //same equation used for burgers included the same output to text file
                cout << "How many sandwiches do you want to order? ";
                cin >> amount;
                cout << endl;
                
                cost = cost + ((amount * 10.00) - 2);

                cout << fixed << setprecision(2) << amount << " sandwhich(es) were added and the total is now $" << cost << endl;
                reciept << fixed << setprecision(2) << amount << " sandwhich(es) were added and the total is now $" << cost << endl;

                break;

            }
            //if user selected to finish ordering it prints out the added cost and prints it to the text file
            case 4:{

                cout << fixed << setprecision(2) << "The total for your order is " << cost << endl;
                
                reciept << fixed << setprecision(2) << "\n\n" <<  "The total for your order is $" << cost << endl;
                break;

            }
            default:{

                cout << "Critical Error! Please Try Again!" << endl;
                exit(0);

            }

        }
    //do while end
    } while (order != 4);
    //closing reciept
    reciept.close();
    
}