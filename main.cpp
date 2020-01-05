#include <iostream>
#include "World.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

int main(){
	cout<<"main"<<endl;
	sf::RenderWindow window(sf::VideoMode(400,400),"PhyG");
	sf::Event event;
	World world;
	world.createBody(Body(100,200,10,10,0));
	world.createBody(Body(5,200,10,400,0));
	world.createBody(Body(395,200,10,400,0));
	world.createBody(Body(200,5,400,10,0));
	world.createBody(Body(200,395,400,10,0));
	world.createBody(Body(200,200,10,100,0));
	world.createBody(Body(300,200,20,20,30));
	sf::Vector2i mxy=sf::Mouse::getPosition(window);
	while(window.isOpen()){
		while(window.pollEvent(event)){
			switch(event.type){
				case sf::Event::Closed:
					window.close();
					break;
			}
		}
		auto mxy2=sf::Mouse::getPosition(window);
		Vector v(mxy2.x-mxy.x,mxy2.y-mxy.y);
		mxy=mxy2;
		world.moveBody(0,v);
		window.clear(sf::Color::White);
		for(const auto &element:world.getBodies()){
			const Body &body=element.second;
			sf::RectangleShape rect;
			rect.setPosition(body.position);
			rect.setSize(body.size);
			rect.setOrigin(body.size/2);
			rect.setRotation(body.rotation);
			rect.setFillColor(element.first==0?sf::Color::Green:sf::Color::Blue);
			window.draw(rect);
		}
		window.display();
	}
	return 0;
}
