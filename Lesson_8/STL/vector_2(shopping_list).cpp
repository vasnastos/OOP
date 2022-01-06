// Imagine you are writing a program to manage a shopping list. Each shopping list item is represented by a string stored in a container. Your design requires a print function that prints out the contents of the shopping list.

// Using a vector to hold the shopping list items, write a print function to print out the contents of a vector of strings. Test your print function with a main program that does the following:

//     Create an empty vector. Print it.
//     Append the items, "eggs," "milk," "sugar," "chocolate," and "flour" to the list. Print it.
//     Remove the last element from the vector. Print it.
//     Append the item, "coffee" to the vector. Print it.
//     Write a loop that searches for the item, "sugar" and replace it with "honey." Print the vector.
//     Write a loop that searches for the item, "milk," and then remove it from the vector. (You are permitted to reorder the vector to accomplish the removal, if you want.) Print the vector.
//     Search for the item, "milk" and find a way to remove it without changing the order of the rest of the vector. (This is not necessarily an efficient operation.) Print the vector one more time.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// write a print function to print out the contents of a vector of strings
void print_shopping_list(vector <string> &sl)
{
    cout<<"=== Shopping List ==="<<endl;
    for(auto &x:sl)
    {
        cout<<"* "<<x<<endl;
    }
    cout<<endl;
}


int main()
{
    vector <string> shopping_list;
    // Create an empty vector. Print it.
    cout<<"Checkpoint 1"<<endl;
    print_shopping_list(shopping_list);

    //  Append the items, "eggs," "milk," "sugar," "chocolate," and "flour" to the list. Print it.
    cout<<"Checkpoint 2"<<endl;
    for(auto &item:{"eggs", "milk", "sugar", "chocolate","flour"})
    {
        shopping_list.push_back(item);
    }
    print_shopping_list(shopping_list);

    // Remove the last element from the vector. Print it.
    cout<<"Checkpoint 3"<<endl;
    shopping_list.pop_back();
    print_shopping_list(shopping_list);

    //  Append the item, "coffee" to the vector. Print it.
    cout<<"Checkpoint 4"<<endl;
    shopping_list.push_back("coffee");
    print_shopping_list(shopping_list);

    // Write a loop that searches for the item, "sugar" and replace it with "honey." Print the vector.
    cout<<"Checkpoint 5"<<endl;
    auto itr=find(shopping_list.begin(),shopping_list.end(),"sugar");
    *itr="honey";
    print_shopping_list(shopping_list);

    // Write a loop that searches for the item, "milk," and then remove it from the vector. (You are permitted to reorder the vector to accomplish the removal, if you want.) Print the vector.
    // Search for the item, "milk" and find a way to remove it without changing the order of the rest of the vector. (This is not necessarily an efficient operation.) Print the vector one more time.
    cout<<"Checkpoint 6-7"<<endl;
    shopping_list.erase(find(shopping_list.begin(),shopping_list.end(),"milk"));
    print_shopping_list(shopping_list);

    // Sort the emenents of the list and display the final view
    cout<<"Checkpoint 8"<<endl;
    sort(shopping_list.begin(),shopping_list.end());
    print_shopping_list(shopping_list);

    return EXIT_SUCCESS;
}

