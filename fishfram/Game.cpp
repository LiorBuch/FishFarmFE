#include "Game.h"
#include <string>
//Private functions.

void Game::initVars()
{
	this->window = nullptr;
	this->http.setHost("http://localhost",8000);
	this->deltaTime = 0.f;
	this->toolBarTexture.loadFromFile("assets/toolbartexture.png");
	this->toolBar.setTexture(toolBarTexture);
	this->toolBar.setPosition(1217,653);
	//this->currentPlayer.loadPlayer();
}
void Game::updateCuesor()
{
}
void Game::initWindow()
{
	this->videoMode.height = 768;
	this->videoMode.width = 1366;
	//get desktop mode for user res.
	this->window = new sf::RenderWindow(this->videoMode, "Fish Farm", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
	this->window->setFramerateLimit(60);
	this->mouseCursor.loadFromFile("assets/cursor1.png");
	this->cursor.setTexture(this->mouseCursor);
	this->window->setMouseCursorVisible(false);
}
void Game::initFish()
{
}
void Game::initTank()
{
	sf::Http::Request request("/logi/reqtank/", sf::Http::Request::Get);
	sf::Http::Response response = http.sendRequest(request);
	std::string str = response.getBody();
	this->json = nlohmann::json::parse(str.substr(1, str.length() - 2));
	new(&currentTank) Tank(json["numberOfDecorations"].get<int>(), json["numberOfFish"].get<int>(), json, deltaTime);
}


//Constructors
Game::Game()
{
	this->initVars();
	this->initWindow();
	this->initTank();
	this->initFish();
}
Game::~Game()
{
	delete this->window;
}

//Accsesors

const bool Game::running() const
{
	return this->window->isOpen();
}

//Functions.
void Game::update()
{
	this->pollEvents();
	this->currentTank.update(this->deltaTime);
	this->deltaTime = this->clock.restart().asSeconds();
	this->cursor.setPosition(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
	

}
void Game::render() 
{
	this->window->clear(sf::Color::Black);
	// Renders the game Objects
	currentTank.draw(*window);
	this->window->draw(this->toolBar);
	this->window->draw(this->cursor);

	//Draw Game
	this->window->display();
}

void Game::pollEvents()
{
	//Event polling event controlling
	while (this->window->pollEvent(this->event)) {
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
			}
		}
	}
}


