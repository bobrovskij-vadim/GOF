#include <iostream>
#include "strategy.h"
#include "adapter.h"


int main()
{
    //-------Ex_1-------
    std::cout << "-------Ex_1-------" << std::endl;
    DivideData dd;
    DivideBySentence *dbs = new DivideBySentence;
    dbs->Divide();

    //-------Ex_2-------
    std::cout << "-------Ex_2-------" << std::endl;

    //-------Ex_3-------
    std::cout << "-------Ex_3-------" << std::endl;
    Figure figure;
    Text text;

    //text.rotate();

    Figure *textAdapter = new TextAdapter(text);

    textAdapter->flip();

    return 0;
}