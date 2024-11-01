// COMSC-210 | 210-lab-27 | Daniil Malakhov
// IDE used: Codeblocks
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

void addVillager(map<string, tuple<int, string, string>>&);
void deleteVillager(map<string, tuple<int, string, string>>&);
void increaseFrlevel(map<string, tuple<int, string, string>>&);
void decreaseFrlevel(map<string, tuple<int, string, string>>&);
void searchVillager(map<string, tuple<int, string, string>>&);
void print(map<string, tuple<int, string, string>>&);

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerStats;

    // user choice
    int value = 0;

    // menu system
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
        cout << endl;
        if (value == 1)
            addVillager(villagerStats);
        else if (value == 2)
            deleteVillager(villagerStats);
        else if (value == 3)
            increaseFrlevel(villagerStats);
        else if (value == 4)
            decreaseFrlevel(villagerStats);
        else if (value == 5)
            searchVillager(villagerStats);

        print(villagerStats);
    }

    return 0;
}

// adds villagers to the map, prompts user for details about villager creates a key value pair and inserts it into map
// arguments: address to the villagerStats map
// returns: none
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

    cin.ignore();

    cout << "Catchphrase: ";
    getline(cin, catchphrase);

    tuple<int, string, string> temp(frlevel, species, catchphrase);

    villagerStats[name] = temp;
}

// deletes a villager from map by asking user which user to delete, if user not found returns error statement
// arguments: address to the villagerStats map
// returns: none
void deleteVillager(map<string, tuple<int, string, string>>& villagerStats)
{
    string name;
    cout << "Which villager would you like to remove: ";
    cin >> name;

    string searchKey = name;
    auto it = villagerStats.find(searchKey);
    if (it != villagerStats.end())
    {
        villagerStats.erase(searchKey);
    }
    else
        cout << endl << searchKey << " not found." << endl;
}

// increases the friendship of a specific villager in the map
// arguments: address to the villagerStats map
// returns: none
void increaseFrlevel(map<string, tuple<int, string, string>>& villagerStats)
{
    string name;
    cout << "Which villager would you like to increase friendship with: ";
    cin >> name;

    // search for an element using .find() to avoid errors
    string searchKey = name;
    auto it = villagerStats.find(searchKey);
    if (it != villagerStats.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        if(get<0>(it->second) != 10)
        {
            int frlevel = get<0>(it->second) + 1;
            string species = get<1>(it->second);
            string catchphrase = get<2>(it->second);

            tuple<int, string, string> temp(frlevel, species, catchphrase);

            villagerStats[it->first] = temp;
        }
    } else
        cout << endl << searchKey << " not found." << endl;
}

// decreases the friendship of a specific villager in the map
// arguments: address to the villagerStats map
// returns: none
void decreaseFrlevel(map<string, tuple<int, string, string>>& villagerStats)
{
    string name;
    cout << "Which villager would you like to decrease friendship with: ";
    cin >> name;

    // search for an element using .find() to avoid errors
    string searchKey = name;
    auto it = villagerStats.find(searchKey);
    if (it != villagerStats.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        if(get<0>(it->second) != 0)
        {
            int frlevel = get<0>(it->second) - 1;
            string species = get<1>(it->second);
            string catchphrase = get<2>(it->second);

            tuple<int, string, string> temp(frlevel, species, catchphrase);

            villagerStats[it->first] = temp;
        }
    } else
        cout << endl << searchKey << " not found." << endl;
}

// finds the user inputted villager in map and tells user if villager exists or not
// arguments: address to the villagerStats map
// returns: none
void searchVillager(map<string, tuple<int, string, string>>& villagerStats)
{
    string name;
    cout << "Which villager would you like to find: ";
    cin >> name;

    // search for an element using .find() to avoid errors
    string searchKey = name;
    auto it = villagerStats.find(searchKey);
    if (it != villagerStats.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << searchKey << " was found." << endl;
    }
    else
        cout << endl << searchKey << " not found." << endl;
}

// prints all the villagers in the map
// arguments: address to the villagerStats map
// returns: none
void print(map<string, tuple<int, string, string>>& villagerStats)
{
    cout << endl;
    // access the map using a range-based for loop
    cout << "Villagers details:" << endl;
    for (auto it : villagerStats) {
        cout << it.first << " [";
        cout << get<0>(it.second) << ", ";
        cout << get<1>(it.second) << ", ";
        cout << get<2>(it.second) << "] ";
        cout << endl;
    }

    cout << endl;
}
