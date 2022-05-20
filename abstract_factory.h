#pragma once
#include <iostream>
#include <vector>


class Pizza
{
public:
    virtual void prepare(std::string){};
    virtual void bake() {};
    virtual void cut() {};
    virtual void box() {};
    virtual void info() const = 0;
    virtual ~Pizza(){};
};

class CheesePizza: public Pizza
{
public:    
    void info() const override
    {
        std::cout << "CheesePizza" << std::endl;
    }
};
class GreekPizza: public Pizza
{
public:
    void info() const override
    {
        std::cout << "GreekPizza" << std::endl;
    }
};
class PepperoniPizza: public Pizza
{
public:    
    void info() const override
    {
        std::cout << "GreekPizza" << std::endl;
    }
};

class PizzaFactory
{
public:
    virtual Pizza *createPizza() = 0;
    virtual ~PizzaFactory() {};
};

class CheesePizzaFactory: public PizzaFactory
{
public:
    Pizza *createPizza() override
    {
        return new CheesePizza;
    }
};

class GreekPizzaFactory: public PizzaFactory
{
public:
    Pizza *createPizza() override
    {
        return new GreekPizza;
    }
};

class PepperoniPizzaFactory: public PizzaFactory
{
public:
    Pizza *createPizza() override
    {
        return new PepperoniPizza;
    }
};

class orderPizza
{
public:
    std::vector<Pizza *> order;
    void info() const 
    {
        for(const auto &i: order) i->info();
    }

    virtual ~orderPizza()
    {
        for(const auto &i: order) delete i;
    }
};

class Pizzaria
{
public:
    orderPizza *createPizzaOrder(PizzaFactory &factory)
    {
        orderPizza *p = new orderPizza;
        p->order.push_back(factory.createPizza());

        return p;
    }
};



// class Pizza{
// public:
//    virtual void prepare(std::string);
//    virtual void bake() {};
//    virtual void cut() {};
//    virtual void box() {};
// };

// class CheesePizza:public Pizza{};
// class GreekPizza:public Pizza{};
// class PepperoniPizza:public Pizza{};

// Pizza* orderPizza(std::string type){
//    Pizza* pizza = nullptr;
//    if (type == "cheese")
//    {
//        pizza = new CheesePizza;
//    }
//    else if (type == "greek")
//    {
//        pizza = new GreekPizza;
//    }
//    else if (type == "pepperoni")
//    {
//        pizza = new PepperoniPizza;
//    }


//    return pizza;
// }

