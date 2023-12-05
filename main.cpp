#include "adder.h"

int main() {
    srand((unsigned) time(0));
    int cap = 0;
    cout << "Podaj capacity" << endl;
    cin >> cap;
    MaxHeap<int> test(cap);
    int exit = 0;


    do {
        int choice;
        cout << "\tMax Heap" << endl;
        cout << "Choose option" << endl;
        cout << "1. Add (Capacity: "<< cap << " )"<< endl;
        cout << "2. Delete Max" << endl;
        cout << "3. Show" << endl;
        cout << "4. Delete Heap" << endl;
        cout << "5. Info" << endl;
        cout << "6. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                int choice2 = 0;
                cout << "(1) Randomowe n" << endl;
                cout << "(2) Wlasna wartosc" << endl;
                cin >> choice2;
                if(choice2 == 1) {
                        int amount;
                        cout << "Podaj ilosc" << endl;
                        cin >> amount;
                    auto start = high_resolution_clock::now();
                        for (int i = 0; i < amount; ++i) {
                            test.add(rand()%10000);
                        }
                    auto stop = high_resolution_clock::now();
                    chrono::duration<double> duration = stop - start;
                    cout << "Time taken by add: " << duration.count() << " milliseconds" << endl;
                    }else if (choice2 == 2)
                     {
                        int s;
                        cout << "Podaj wartosc" << endl;
                        cin >> s;
                        test.add(s);
                        break;
                    }
                break;
            }
            case 2:{
                test.del();
                break;
            }
            case 3:{
                test.show();
                break;
            }
            case 4:{
                auto start = high_resolution_clock::now();
                test.clear();
                auto stop = high_resolution_clock::now();
                chrono::duration<double> duration = stop - start;
                break;
            }
            case 5:{
                test.info();
                break;
            }
            case 6:{
                 exit++;
                 break;
            }
        }
    }while(exit == 0);

}
