#include <SFML/Graphics.hpp>

int main(int /*argc*/, char* /*argv*/[])
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "Hello World - SFML");
  sf::CircleShape shape(100.0f);
  shape.setFillColor(sf::Color::Green);
  //
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if ((event.type == sf::Event::Closed) ||
          ((event.type == sf::Event::KeyPressed) &&
           (event.key.code == sf::Keyboard::Escape)))
        window.close();
    }
    //
    window.clear(sf::Color(0, 0, 255, 10));
    window.draw(shape);
    window.display();
  }
  //
  return 0;
}
