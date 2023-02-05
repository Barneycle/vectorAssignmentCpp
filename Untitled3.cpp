#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

struct User {

    string name;
    int age;
    string address;
    int id;

};

int findUserIndexById(int id, vector<User> users) {

    for(int i = 0; i < users.size(); i++) {

        if(users[i].id == id) {

            return i;

        }
    }

    return -1;
}


vector<User> users;

void registerUser() {
    User newUser;

    cout << "Enter your name: ";
    getline(cin >> ws, newUser.name);

    cout << "Enter your age: ";
    cin >> newUser.age;

    cout << "Enter your address: ";
    getline(cin >> ws, newUser.address);

    srand(time(0));

    int randomId = rand() % 100000000 + 900000000;

    bool hasExistingId = true;

    while(hasExistingId) {

        int userIndex = findUserIndexById(randomId, users);

        if(userIndex == -1) {

            hasExistingId = false;

        } else {

            randomId = rand() % 100000000 + 900000000;

        }
    }

    newUser.id = randomId;

    cout << "Your ID number: " << newUser.id << endl;

    users.push_back(newUser);
    cout << "User registered successfully!" << endl;

    return;
}

void updateUser(){

    int userId;

    cout << "Please enter your ID number: ";
    cin >> userId;

    int index = findUserIndexById(userId, users);

    if(index == -1) {

        cout << "ID number not found!" << endl;

    }

    else{

        User currentUser = users[index];

        cout << "Enter your new name: ";
        getline(cin >> ws, users[index].name);

        cout << "Enter your new age: ";
        cin >> users[index].age;

        cout << "Enter your new address: ";
        getline(cin >> ws, users[index].address);

        cout << "User updated successfully!" << endl;
    }
}

void showUser(){

    for(User user : users){

        cout << "Name: " << user.name << endl;
        cout << "Age: " << user.age << endl;
        cout << "Address: " << user.address << endl;
        cout << "ID Number: " << user.id << endl;

    }

}

int main() {
    int choice;

    while (true) {
        cout << "[1] Register User" << endl;
        cout << "[2] Update User" << endl;
        cout << "[3] Show List" << endl;
        cout << "[4] Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {

            registerUser();

        } else if (choice == 2) {

            updateUser();

        } else if (choice == 3) {

            showUser();

        } else if (choice == 4){

        break;

        }

        else {

            cout << "Invalid choice!\n";
        }
    }
    return 0  ;
}
