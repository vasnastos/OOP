/*
In this exercise, you will create a class hierarchy for a simple e-commerce system. The goal is to demonstrate how inheritance can be used to model real-world problems.
Create a base class called Product that includes the following attributes:
    name: a string that represents the name of the product.
    price: a float that represents the price of the product.
    description: a string that describes the product.

Create a method called display in the Product class that prints the name, price, and description of the product.

Create subclasses for specific types of products that inherit from the Product class. For example:
    Book: a subclass of Product that includes an additional attribute author.
    Electronic: a subclass of Product that includes an additional attribute brand.
    Clothing: a subclass of Product that includes an additional attribute size.

Override the display method in each subclass to display the additional attributes specific to that type of product.

Create a class called ShoppingCart that represents a shopping cart in an e-commerce system. The class should include the following attributes:
    products: a list of Product objects that are added to the cart.
    total: a float that represents the total cost of the products in the cart.

Create methods in the ShoppingCart class to perform the following actions:
    add_product: a method that adds a product to the products list.
    remove_product: a method that removes a product from the products list.
    calculate_total: a method that calculates the total cost of the products in the cart.
    display_cart: a method that prints the name, price, and description of each product in the products list and the total cost of the products in the cart.

Test your implementation by creating instances of the classes and adding products to the shopping cart. 
Verify that the total cost of the products is calculated correctly and that the products are displayed correctly.
This exercise should give you hands-on experience with inheritance in object-oriented programming and help you understand how inheritance can be used to model real-world problems.
*/



#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;


class Product
{
    protected:
        string name;
        string description;
        double price;
    public:
        Product(string pname,string pdesc,double pprice):name(pname),description(pdesc),price(pprice) {}
        ~Product() {cout<<"~Product Destructed:"<<this<<endl;}
        void display() {
            cout<<"Name:"<<this->name<<"\t"<<"Description:"<<this->description<<"\t"<<"Price:"<<this->price<<endl;
        }

        // setters-getters
        void set_name(string pname) {this->name=pname;}
        void set_description(string pdesc) {this->description=pdesc;}
        void set_price(double pprice) {this->price=pprice;}

        string get_name()const {return this->name;}
        string get_description()const {return this->description;}
        double get_price()const {return this->price;}

        virtual void show() {cout<<this->name<<"\t"<<this->description<<"\t"<<this->price;} 
        virtual double value() {return this->price;}
};

class Book:public Product
{
    string author;
    int copies;
    public:
        Book(string bname,string bdesc,double bprice,string bauthor,int bcopies):Product(bname,bdesc,bprice),author(bauthor),copies(bcopies) {}
        ~Book() {cout<<"~Book Destructed:"<<this<<endl;}

        void set_author(string bauthor) {this->author=bauthor;}
        void set_copies(int bcopies) {this->copies=bcopies;}

        string get_author()const {return this->author;}
        int get_copies()const {return this->copies;}

        double value() {return this->price+(this->copies%100)*12+0.005*this->copies;}
        void show() {
            Product::show();
            cout<<"\t"<<this->author<<"\t"<<this->copies<<endl;
        }
};

class Electronics:public Product
{
    string brand; 
    int sales;
    public:
        Electronics(string ename,string edesc,double eprice,string ebrand,int esales):Product(ename,edesc,eprice),brand(ebrand),sales(esales) {}
        ~Electronics() {cout<<"~Electronics Destructed:"<<this<<endl;}

        void set_brand(string ebrand) {this->brand=ebrand;}
        void set_sales(int esales) {this->sales=esales;}

        string get_brand()const {return this->brand;}
        int get_sales()const {return this->sales;}

        double value() {return this->price+0.06*this->sales;}
        void show() {
            Product::show();
            cout<<"\t"<<this->brand<<"\t"<<this->sales<<endl;
        }
};

int  main()
{
    vector <Product*> shopping_cart;
    srand(123456);

    int j;
    for(int i=0;i<10;i++)
    {
        j=rand()%2;
        if(j==0)
        {
            shopping_cart.push_back(new Book("Product_"+std::to_string(i+1),"Description_"+std::to_string(i+1),rand()%(301),"Author"+std::to_string(rand()%10),rand()%200));
        }
        else if(j==1)
        {
            shopping_cart.push_back(new Electronics("Product_"+std::to_string(i+1),"Description_"+std::to_string(i+1),rand()%(301),"Brand_"+std::to_string(rand()%10),rand()%200));
        }
    }
    // Total cart value
    double total_cart_values=0;
    for(auto &product:shopping_cart)
    {
        product->show();
        total_cart_values+=product->value();
    }
    cout<<"Total shopping cart value:"<<total_cart_values<<endl;

    for(auto &x:shopping_cart)
    {
        delete x;
    }

    Product total("Product_total","Shopping chart",total_cart_values);
    total.show();
    cout<<endl;
    return 0;
}

// Product_1       Description_1   243     Brand_0 17
// Product_2       Description_2   201     Author8 141
// Product_3       Description_3   80      Author3 35
// Product_4       Description_4   197     Brand_4 199
// Product_5       Description_5   190     Brand_4 154
// Product_6       Description_6   23      Brand_5 112
// Product_7       Description_7   233     Brand_8 62
// Product_8       Description_8   266     Author1 164
// Product_9       Description_9   184     Author0 88
// Product_10      Description_10  76      Brand_2 19
// Total shopping cart value:4464.92
// ~Product Destructed:0x1f20d4b7b60
// ~Product Destructed:0x1f20d4b7be0
// ~Product Destructed:0x1f20d4b7c60
// ~Product Destructed:0x1f20d4b7d10
// ~Product Destructed:0x1f20d4b7d90
// ~Product Destructed:0x1f20d4b7e10
// ~Product Destructed:0x1f20d4b7e90
// ~Product Destructed:0x1f20d4b7f10
// ~Product Destructed:0x1f20d4b2270
// ~Product Destructed:0x1f20d4b2380
// Product_total   Shopping chart  4464.92
// ~Product Destructed:0x2a8a3ff8f0