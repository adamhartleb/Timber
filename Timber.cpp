#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	/*VideoMode vm(1920, 1080);*/
	VideoMode vm = VideoMode(1920, 1080);

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

	bool isBeeActive = false;
	bool isCloud1Active = false, isCloud2Active = false, isCloud3Active = false;
	float beeSpeed = 0.0f;
	srand((int)time(0));

	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		window.clear();

		window.draw(spriteBackground);

		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);

		window.draw(spriteTree);

		window.draw(spriteBee);

		window.display();
	}

	return 0;
}