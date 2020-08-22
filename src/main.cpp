#include "particle.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Particles");
    window.setFramerateLimit(60);

    ParticleSystem particles(5000);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2i mouse = sf::Mouse::getPosition(window);
        particles.setEmitter(window.mapPixelToCoords(mouse));

        sf::Time elapsed = clock.restart();
        particles.update(elapsed);

        window.clear();
        window.draw(particles);
        window.display();
    }

    return 0;
}