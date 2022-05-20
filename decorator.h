#pragma once
#include <iostream>



class Beverage{            // Абстрактный класс
public:
   virtual std::string getDescription() const;
   virtual double cost() const = 0;
   virtual ~Beverage() {}
};

class HouseBlend: public Beverage{   // Молотый
public:
    std::string getDescription() const override
    {
        return "HouseBlend";
    }
   double cost() const override {
       return 5.5;
   }
};

class DarkRoast: public Beverage{  // Темной обжарки
public:
    std::string getDescription() const override
    {
        return "DarkRoast";
    }
   double cost() const override {
       return 6.0;
   }

};
 
class Decaf: public Beverage{    // Без кофеина
public:
  std::string getDescription() const override
    {
        return "Decaf";
    }
   double cost() const override {
       return 7.3;
   }

};

class Espresso: public Beverage{  // Эспрессо
public:
      std::string getDescription() const override
    {
        return "Espresso";
    }
   double cost() const override {
       return 3.5;
   }

};

class Decorator: public Beverage
{
private:
    Beverage *_beverage;
public:
    Decorator(Beverage *beverage) : _beverage(beverage){}

    std::string getDescription() const override
    {
        _beverage->getDescription();
    } 

    double cost() const override
    {
        _beverage->cost();
    }
};

class BeverageDecorator: public Decorator
{
private:
    double _price;
public:
    BeverageDecorator(Beverage *beverage, double price): Decorator(beverage), _price(price) {}

    double cost()
    {
        Decorator::cost();
    }
    std::string getDescription()
    {
        Decorator::getDescription();
    }
};


