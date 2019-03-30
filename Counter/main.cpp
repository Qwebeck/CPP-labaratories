/*
#include <string>
#include <memory>
#include <map>
#include <iostream>
struct Counter{
    std::string key;
    int index;
};


std::unique_ptr<Counter> Init(std::string key);
void Inc( std::unique_ptr<Counter> counter);
int Counts(const std::unique_ptr<Counter> &counter);
void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> &counter);

int main(void) {
    std::string hello = " hello";

    std::map <std::string , std::unique_ptr<Counter>> counter_map;
    std::unique_ptr <Counter> counter = std::make_unique<Counter>();
    Inc(move(counter));
    std::cout << Counts(counter_map[hello]);

    return 0;
}

std::unique_ptr<Counter> Init(std::string key)
{
    std::unique_ptr <Counter> counter = std::make_unique<Counter>();
    counter -> key = key;
    counter -> index = 0;
    return counter;
};

void Inc( std::unique_ptr<Counter> counter)
{
   counter -> index += 1;
};

int Counts(const std::unique_ptr<Counter> &counter)
{
    return counter -> index;
};

void SetCountsTo( int value, std::unique_ptr<Counter>& counter)
{
    counter -> index =value;
};
// C++ program to illustrate the use of unique_ptr
#include<iostream>
#include<memory>
#include<map>
using namespace std;

class A
{
private:
    int key;
public:
    void show()
    {
        cout<<key<<endl;
    }
    void init()
    {
        key = 15;
    }
};

int main()
{
    map<int , A> map1;
    unique_ptr< map <int, A> > p1 (new  map);
    p1[1].init();
    p1[1].show();
    p1[0].show();
    return 0;
}
*/
#include <string>
#include <memory>
#include <map>
#include <iostream>

using namespace std;

class Counter{
private:
    int iterator = 0;
    pair<std::string ,int> object;
    std::map<std::string, int > objects;
public:

    Counter(){
        cout<<"Counter created" << endl;
    }

    ~Counter(){
        cout<<"Counter dies " << endl;
    }
    std::map<std::string, int > * GetValue(){
        return &objects;
    };
    void AddValue(std::string key );

};
void Counter::AddValue(std::string key) {
     objects.insert(make_pair(key, iterator));
}

std::unique_ptr<Counter> Init();
void Inc(std::string key, std::unique_ptr<Counter>* counter);
int Counts(const std::unique_ptr<Counter> &counter, std::string key);
void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter);

int main()
{
    std::string law = "hello";
    std::unique_ptr<Counter> counter = Init();
    counter-> GetValue();
    std::unique_ptr<Counter> * p_counter = new std::unique_ptr<Counter>;
    *p_counter = move(counter);


    bool running = true;
    int option ;
    std::string key;
    while (running)
    {
        cout << "1 - Add / 2 - Counts / 3 - SetCountsTo / 4 - Inc / 5 - exit " << endl;
        cin >> option;
        switch (option){
            case 1:
                cin >> key;
                (*p_counter) -> AddValue(key);
                break;
            case 2:
                cin >> key;
                cout << Counts((*p_counter),key) << endl;
                break;
            case 3:
                int set;
                cout<<"Key"<< endl;
                cin >> key;
                cout<<"Value" << endl;
                cin >> set;
                SetCountsTo(key,set,p_counter);
                break;
            case 4:
                cin >> key;
                Inc(key,p_counter);
                break;
            case 5:
                running = false;
                break;
            default:
                cout << "Wrong option" << endl;
                break;
        }
    }

    cout << "Hello" << endl;
    return 0;
}
std::unique_ptr<Counter> Init(){
    return std::make_unique<Counter>();
};


void Inc(std::string key, std::unique_ptr<Counter>* counter){
    (*counter) -> GetValue()[key] += 1;
    std::cout << "Value of counter : " <<  counter << std::endl;

};

int Counts(const std::unique_ptr<Counter> &counter, std::string key){
    return counter -> GetValue()[key];

};
void SetCountsTo(std::string key, int value, std::unique_ptr<Counter> *counter)
{
    (*counter)->GetValue()[key] = value;
};