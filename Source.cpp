#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include "Board.hpp"

using namespace sf;

int main() {

    RenderWindow window(VideoMode(1000, 1000), "CHESS 2");
    Texture chessBoard;
    Font font;
    chessBoard.loadFromFile("board.png");
    font.loadFromFile("OldLondon.ttf");
    Sprite boardImage;
    boardImage.setTexture(chessBoard);
    Board actualBoard;
    Text text;
    text.setFont(font);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                Vector2i mousePos = Mouse::getPosition(window);
                actualBoard.handleClick(mousePos.x, mousePos.y);
            }
        }

        window.clear();
        window.draw(boardImage);
        actualBoard.RenderBoard(window);
        window.display();
        if (actualBoard.isGameFinished()) {
            if (actualBoard.didWhiteWin()) text.setString("WHITE WINS");
            else text.setString("BLACK WINS");
            text.setCharacterSize(24);
            window.draw(text);
        }
    }

    return 0;
}
