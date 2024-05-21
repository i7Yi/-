#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
public:
    Controller() : speed(200), key(1), score(0) {}
    bool enter_interface();
    void Start();
    void Select();
    void DrawGame(int);
    int PlayGame(int);
    void UpdateScore(const int&);
    void RewriteScore();
    int Menu();
    void Game();
    int GameOver();
    void RewriteFoot();
private:
    int speed;
    int key;
    int score;
    int foot;
    int key_map;
};
#endif
