#include "Tank.h"

Tank::Tank(int numberDecoration, int numberFish,nlohmann::json json , float deltaTime)
{
	this->props = json;
	this->tankHttp.setHost("http://localhost", 8000);
	this->deltaTime = deltaTime;
	this->numberOfFish = this->props["numberOfFish"].get<int>();
	this->numberOfDecorations = this->props["numberOfDecorations"].get<int>();
	this->maxSize = this->props["size"].get<int>();
	this->tankLoc = this->props["tankLoc"].get<std::string>();
	initDecoration();
	initFish();
}

Tank::Tank()
{
}

Tank::~Tank()
{
}

void Tank::initFish()
{
	sf::Http::Request request("/logi/reqfish/tank1/fish1/", sf::Http::Request::Get);
	sf::Http::Response response = this->tankHttp.sendRequest(request);
	std::string str = response.getBody();
	nlohmann::json fishJson = nlohmann::json::parse(str.substr(1, str.length() - 2));

	for (int i = 1; i <= this->numberOfFish; i++)
	{
		string fishPNG = fishJson["fishPNG"].get<std::string>();
		int imageCountX = fishJson["imageCountX"].get<int>();
		int imageCountY = fishJson["imageCountY"].get<int>();
		float speed = fishJson["speed"].get<float>();
		int xPos = fishJson["xPos"].get<float>();
		int yPos = fishJson["yPos"].get<float>();
		float singleImageWidth = fishJson["texturePartWidth"].get<float>();
		float singleImageHeight = fishJson["texturePartHeight"].get<float>();
		int numberInTank = fishJson["idnum"].get<int>();

		Fish* fish = new Fish(fishPNG, sf::Vector2u(imageCountX, imageCountY), 0.1f, speed, xPos, yPos, singleImageWidth, singleImageHeight, numberInTank);
		this->fishList.push_back(shared_ptr<Fish>(fish));
	}
}

void Tank::initDecoration()
{
	this->wallPaperTexture.loadFromFile("assets/" + this->props["wallpaper"].get<std::string>());
	this->tankWallpaper.setTexture(wallPaperTexture);
	this->toolBarTexture.loadFromFile("assets/toolbartexture.png");
	this->toolBar.setTexture(toolBarTexture);
	this->toolBar.setPosition(sf::Vector2f(1224.f, 659.f));
	this->gravelTexture.loadFromFile("assets/" + this->props["gravel"].get<std::string>());
	this->gravel.setTexture(gravelTexture);
}

void Tank::changeDecoration()
{
}

void Tank::changeFish()
{
}

void Tank::update(float delta)
{
	this->deltaTime = delta;
	for (shared_ptr<Fish> fish : this->fishList)
	{
		fish->update(this->deltaTime);
	}
}

void Tank::draw(sf::RenderWindow& window)
{
	window.draw(this->tankWallpaper);
	window.draw(this->gravel);
	for (shared_ptr<Fish> fish : this->fishList)
	{
		fish->draw(window);
	}
	
}
