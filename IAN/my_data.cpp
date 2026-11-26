
#include "my_data.h"

/**
    CLASS      :
    NAME       :
    STUDENT ID :
**/

mytype create_data() {
    /**
     TODO:  receive input FROM USER
            and assign the value of new data
    */
    mytype d;
    // ===========================
    // YOUR CODE HERE
    cout << "Input ID    : ";
    cin >> d.ID;
    cin.ignore(10000, '\n');
    cout << "Input name  : ";
    getline(cin, d.name);
    cout << "Input rank  : ";
    cin >> d.rank;
    cout << "Input score : ";
    cin >> d.score;
    // ===========================
    return d;
}

void view_data(mytype d) {
    /**
     TODO:  view the content of data d
     it will be called when print_info function is invoked
    */

    // ===========================
    // YOUR CODE HERE
    cout << "ID    : " << d.ID << endl;
    cout << "Name  : " << d.name << endl;
    cout << "Rank  : " << d.rank << endl;
    cout << "Score : " << d.score << endl;
    cout << "-------------------------" << endl;
    // ===========================
}


void edit_data(mytype &d) {
    /**
     * TODO:  edit the value of data d,
     *       receive input FROM USER
     *       the ID must NOT be modified
    */

    // ===========================
    // YOUR CODE HERE
    cout << "ID " << d.ID << " cannot be changed" << endl;
    cin.ignore(10000, '\n');
    cout << "Input new name  : ";
    getline(cin, d.name);
    cout << "Input new rank  : ";
    cin >> d.rank;
    cout << "Input new score : ";
    cin >> d.score;
    // ===========================
}