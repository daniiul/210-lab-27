#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

void addVillager(map<string, tuple<int, string, string>>&);
void increaseFrlevel(map<string, tuple<int, string, string>>&);

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerStats;

    int value = 0;

    while(value != 6)
    {
        cout << "1. Add Villager" << endl;
        cout << "2. Delete Villager" << endl;
        cout << "3. Increase Friendship" << endl;
        cout << "4. Decrease Friendship" << endl;
        cout << "5. Search for Villager" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter a choice: ";

        cin >> value;
        if (value == 1)
            addVillager(villagerStats);
        else if (value == 2)
            increaseFrlevel(villagerStats);

    }


    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Audie"] = {"Orange", "Yellow", "Red"};
    villagerColors["Raymond"] = {"Black", "Gray", "White"};
    villagerColors.insert({"Marshal", {"Blue", "White", "Black"}});

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerColors) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin();
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}

void addVillager(map<string, tuple<int, string, string>>& villagerStats)
{
    string name;
    int frlevel;
    string species;
    string catchphrase;

    cout << "Villager Name: ";
    cin >> name;

    do
    {
        cout << "Friendship level (0-10): ";
        cin >> frlevel;
    } while(frlevel < 0 || frlevel > 10);

    cout << "Species: ";
    cin >> species;

    cout << "Catchphrase: ";
    getline(cin, catchphrase);

    tuple<int, string, string> temp(frlevel, );

}

void increaseFrlevel(map<string, tuple<int, string, string>>& villagerStats)
{

}
