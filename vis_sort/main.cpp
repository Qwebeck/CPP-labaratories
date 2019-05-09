#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>
#include <stdlib.h>
#include <iostream>
const unsigned int C_WIDTH = 5;
const unsigned int C_HEIGHT = 5;

using ::std::vector;

void draw(vector<unsigned int>& numbers , vector<sf::RectangleShape>& shapes ,int  current_el ,  const unsigned int W_H, sf::RenderWindow &wn);

void bubble_sort(vector<unsigned int>& numbers , vector<sf::RectangleShape>& shapes ,  const unsigned int W_H , sf::RenderWindow &wn)
{
    for( int i = 0; i < numbers.size(); i++ )
    {

        for( int j = 0; j < numbers.size() - 1; j++ )
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            if( numbers[ j ] > numbers[ j + 1 ] )std::swap( numbers[ j ], numbers[ j + 1 ] );
//                draw(numbers ,(j+1),W_H ,wn);
            draw(numbers , shapes ,j,W_H ,wn);
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }

    }
}



vector<sf::RectangleShape> init(vector<unsigned int>& numbers);

int main()
{

    srand (time(NULL));
    vector<unsigned int>vec {10,3,4,5 , 20 , 1 , 3 ,10,3};
    /*initialize array with random values*/
    for (int i = 0 ; i < 100; ++i)
    {
        vec.emplace_back(rand() % 100 + 10);
    }
    /*set the most optimal window size*/
    unsigned int max = *max_element(vec.begin(),vec.end());
    const unsigned int W_H =  max * C_HEIGHT + 100;
    sf::RenderWindow window(sf::VideoMode(static_cast<unsigned int>(vec.size() * C_WIDTH),W_H), "SFML works!");
    //init vector of shapes connected with numbers
    vector<sf::RectangleShape> shapes = init(vec);

    bool running = true;
    while (running)
    {

        bubble_sort(vec ,  shapes ,W_H , window);
        break;

    }
    sf::Event event{};
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    return 0;
}


vector<sf::RectangleShape> init(vector<unsigned int>& numbers)
{
    vector<sf::RectangleShape> shapes;
    shapes.reserve(numbers.size());
    for (unsigned int number : numbers)shapes.emplace_back(sf::Vector2f(C_WIDTH, number * C_HEIGHT));
    return shapes;

}


void draw(vector<unsigned int>& numbers , vector<sf::RectangleShape>& shapes ,int  current_el ,  const unsigned int W_H, sf::RenderWindow &wn)
{
    wn.clear();
    for(int i = 0 ; i < numbers.size() ; ++i)
    {
        shapes[i].setSize(sf::Vector2f(C_WIDTH, numbers[i] * C_HEIGHT));
        shapes[i].setPosition(i * C_WIDTH  , W_H - numbers[i] * C_HEIGHT );
        shapes[i].setFillColor(sf::Color(255,255,255));
        if(i==current_el)
        {
            shapes[i].setFillColor(sf::Color(150,50,250));
        }
        wn.draw(shapes[i]);

    }
    wn.display();

};

