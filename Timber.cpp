#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

int main()
{
	/*VideoMode vm(1920, 1080);*/
	VideoMode vm = VideoMode(1920, 1080);
	Font font;
	font.loadFromFile("./fonts/KOMIKAB_.ttf");

	Text myText;
	myText.setString("Hello, World!");
	myText.setCharacterSize(75);
	myText.setFillColor(Color::White);
	myText.setFont(font);

	RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

	Texture textureBackground, textureTree, textureBee, textureCloud;

	textureBackground.loadFromFile("graphics/background.png");
	textureTree.loadFromFile("graphics/tree.png");
	textureBee.loadFromFile("graphics/bee.png");
	textureCloud.loadFromFile("graphics/cloud.png");

	Sprite spriteBackground, spriteTree, spriteBee, spriteCloud1, spriteCloud2, spriteCloud3;

	spriteBackground.setTexture(textureBackground);
	spriteTree.setTexture(textureTree);
	spriteBee.setTexture(textureBee);
	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);

	spriteBackground.setPosition(0, 0);
	spriteTree.setPosition(810, 0);
	spriteBee.setPosition(0, 800);
	spriteCloud1.setPosition(0, 0);
	spriteCloud2.setPosition(0, 250);
	spriteCloud3.setPosition(0, 500);

	bool paused = true;
	bool isBeeActive = false;
	bool isCloud1Active = false, isCloud2Active = false, isCloud3Active = false;
	float beeSpeed = 0.0f;
	

	float cloud1Speed = 0, cloud2Speed = 0, cloud3Speed = 0;

	Clock clock;

	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			paused = false;
		}

		if (!paused)
		{
			window.clear();

			Time dt = clock.restart();

			if (!isBeeActive)
			{
				srand((int)time(0));
				beeSpeed = (rand() % 200) + 200;

				srand((int)time(0) * 10);
				float height = (rand() % 500) + 500;
				spriteBee.setPosition(2000, height);
				isBeeActive = true;
			}
			else
			{
				spriteBee.setPosition(
					spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()),
					spriteBee.getPosition().y
				);

				if (spriteBee.getPosition().x < -100)
				{
					isBeeActive = false;
				}
			}

			if (!isCloud1Active)
			{
				srand((int)time(0) * 10);
				cloud1Speed = (rand() % 200);
				srand((int)time(0) * 10);
				float height = (rand() % 150);
				spriteCloud1.setPosition(-200, height);
				isCloud1Active = true;
			}
			else
			{
				spriteCloud1.setPosition(
					spriteCloud1.getPosition().x + (dt.asSeconds() * cloud1Speed),
					spriteCloud1.getPosition().y
				);

				if (spriteCloud1.getPosition().x > 1920)
				{
					isCloud1Active = false;
				}
			}

			if (!isCloud2Active)
			{
				srand((int)time(0) * 20);
				cloud2Speed = (rand() % 200);
				srand((int)time(0) * 20);
				float height = (rand() % 300) - 150;
				spriteCloud2.setPosition(-200, height);
				isCloud2Active = true;
			}
			else
			{
				spriteCloud2.setPosition(
					spriteCloud2.getPosition().x + (dt.asSeconds() * cloud2Speed),
					spriteCloud2.getPosition().y
				);

				if (spriteCloud2.getPosition().x > 1920)
				{
					isCloud2Active = false;
				}
			}

			if (!isCloud3Active)
			{
				srand((int)time(0) * 30);
				cloud3Speed = (rand() % 200);
				srand((int)time(0) * 30);
				float height = (rand() % 450) - 150;
				spriteCloud3.setPosition(-200, height);
				isCloud3Active = true;
			}
			else
			{
				spriteCloud3.setPosition(
					spriteCloud3.getPosition().x + (dt.asSeconds() * cloud3Speed),
					spriteCloud3.getPosition().y
				);

				if (spriteCloud3.getPosition().x > 1920)
				{
					isCloud3Active = false;
				}
			}
		}

		myText.setPosition(250, 250);

		window.draw(spriteBackground);

		window.draw(myText);

		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);

		window.draw(spriteTree);

		window.draw(spriteBee);

		window.display();
		
	}

	return 0;
}