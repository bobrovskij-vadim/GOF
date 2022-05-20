#include <iostream>
#include "abstract_factory.h"
#include "decorator.h"


int main(void)
{
    //-----------Ex_1-----------
    // std::cout << "-----------Ex_1-----------" << std::endl;
    // Pizzaria newOrder;

    // CheesePizzaFactory ch_pizza;
    // GreekPizzaFactory gr_pizza;

    // orderPizza *pCheesePizza = newOrder.createPizzaOrder(ch_pizza);
    // pCheesePizza->info();

    // orderPizza *pGreekPizza = newOrder.createPizzaOrder(gr_pizza);
    // pGreekPizza->info();

    //-----------Ex_3-----------
    std::cout << "\n-----------Ex_3-----------" << std::endl;

    Espresso *espresso = new Espresso();
    Decorator *beverageDecorator = new BeverageDecorator(espresso, espresso->cost());

    std::cout << beverageDecorator->cost();
    


  


    return 0;
}