
#include <iostream>
#include <inttypes.h>
#include <SFML/Graphics.hpp>



int main()
{
    //some C++14 example
    auto doubleValue{[](auto t)->uint32_t{return t *2;}};
    
    std::cout << "5 * 2 ist " << doubleValue(5) << std::endl;
    
    //here starts the SFML example 
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
