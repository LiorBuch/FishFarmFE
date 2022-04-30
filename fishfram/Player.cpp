#include "Player.h"

Player::Player(std::string playerTOKEN)
{
	this->TOKEN = playerTOKEN;
}

Player::~Player()
{
	this->TOKEN = "";
}

void Player::loadPlayer()
{
	
	this->http.setHost("http://localhost", 8000);
	this->request = sf::Http::Request("/logi/log/dev/", sf::Http::Request::Get);
	sf::Http::Response response = http.sendRequest(request);
	std::string str = response.getBody();
	nlohmann::json json = nlohmann::json::parse(str.substr(1, str.length() - 2));
	this->xp = json["xp_points"].get<int>();
	this->numberOFTanks = json["number_of_tanks"].get<int>();
}
