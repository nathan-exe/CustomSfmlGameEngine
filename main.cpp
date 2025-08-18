

#include "Game/Game.h"

int main()
{
    /*Node player = Node("Player");
    player.AddChild(new Node("Collider"));
    player.AddChild(new Node("SpriteRenderer"));
    player.AddChild(new Node("InputManager"));
    (*player.Children.begin())->AddChild(new Node("RigidBody"));
    (*player.Children.begin())->AddChild(new Node("PlayerMovement"));

    player.PrintTree();
    player.FindChildAtPath("Collider/RigidBodys");

    return 0;*/

    Game game = Game();
    game.run();

    return 0;
}

    //std::array<int, 3> arr = {1, 2, 3};
    // dico[cléPasDejaDansLeDico] -> ajoute automatiquement la clé avec une valeur nulle. utiliser 'at()' plutot

    //void f(int a) => copie a dans la fonction sur la pile, on peut en changer la valeur
    //void f(int &a) => passe a par reference, on peut en changer la valeur
    //void f(const int &a) => passe a par reference, on peut pas en changer la valeur mais ça bouffe moins de memoire

    //bien penser à mettre les destructor en virtual

    //const int* i; => pointer to const int
    //int const* i; => pointer to const int
    //int *const i; => const pointer to int