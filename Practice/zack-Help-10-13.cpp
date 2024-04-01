#include <iostream>

using namespace std;


int main()
{
    int input;
    cout << "input a num";
    cin >> input;
    do 
    {
        cout << "input a num ";
        cin >> input;
        switch (input)
            {
            case 1:
                cout << "\n\tcase1\n" << endl;
                break;
            case 2:
                cout << "\n\tcase2\n" << endl;
                break;
            case 3:
                cout << "\n\tcase3\n" << endl;
                break;
            case 4:
                cout << "\n\tendProg\n" << endl;
                return 0;
            
            default:
                cout << "you are stupid" << endl;
                break;
            }
        input = 0;
    } while (input == 0);



    return 0;
}