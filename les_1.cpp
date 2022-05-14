#include <iostream>
#include <map>
#include <ctime>
#include <unistd.h>
#include "singleton.h"

class ChocolateBoiler{
private:
   bool _empty;
   bool _boiled;
public:
   ChocolateBoiler(){
       _empty = true;
       _boiled = false;
   }
    
   bool isEmpty() const{
       return _empty;
   }

   bool isBoiled() const{
       return _boiled;
   }

   void fill(){
       if (isEmpty()){
           _empty = false;
           _boiled = false;
       }
   }

   void drain(){
       if (!isEmpty() && isBoiled()){
           _empty = true;
       }
   }

   void boil(){
       if (!isEmpty() && !isBoiled()){
           _boiled = true;
       }
   }
};


class ISellSystem{
public:
   virtual void changePrice(std::string, float) = 0;
   virtual void sellProduct(std::string) = 0;
   virtual void addProduct(std::string, size_t) = 0;
};


class Automaton: ISellSystem {                      // Refactored
private:
   std::string location;
   double recieved_money;
   double spent_money;
   std::map <std::string, float> goods_price;
   std::map <std::string, size_t> goods_count;
   time_t current_time;                             // Added

public:
   Automaton(const std::string &location, double recievedMoney) : location(location), recieved_money(recievedMoney) {
       spent_money = 0.0;
       time(&current_time);                         // Added
   }

   void changePrice(std::string name, float newPrice) override {
       goods_price[name] = newPrice;
   }

   void sellProduct(std::string name){
       if(goods_count[name] > 0){
           recieved_money += goods_price[name];
       }
       else{
           std::cerr << "Not enough goods" << std::endl;
       }
   }

   void addProduct(std::string name, size_t count){      
       goods_count[name] += count;
   }

    bool check_time()                               // Added
    {
        time_t new_time;
        time(&new_time);
        if(difftime(new_time, current_time) > 3600)
        {
            return true;
        }
        return false;
    }

   double allMoneyReport() const{
        if(check_time())                                  // Added
        {
           time(&current_time);
           return recieved_money;
        }
       return recieved_money - spent_money;
   }

   const std::string& getLocationReport() const {
       return location;
   }

   std::map <std::string, size_t> goodsCountReport(){
       
        if(check_time())                                  // Added
        {
           addProduct(_value1, _value2);
           time(&current_time);
        }
        return goods_count;
   };

   std::map <std::string, float> goodsPriceReport(){

       if(check_time())                                  // Added
       {
           sellProduct(_value);
           time(&current_time);
       }

       return goods_price;
   };

};



int main()
{
    //--------Ex_1--------
    std::cout << "--------Ex_1--------" << std::endl;
    ChocolateBoiler C1;
    ChocolateBoiler C2;

    C1.fill();
    std::cout << C1.isEmpty() << " " << C1.isBoiled() << std::endl;
    std::cout << C2.isEmpty() << " " << C2.isBoiled() << std::endl;
    
    S_ChocolateBoiler *S_C1 = S_ChocolateBoiler::create();
    S_ChocolateBoiler *S_C2 = S_ChocolateBoiler::create();

    std::cout << S_C1->isEmpty() << " " << S_C1->isBoiled() << std::endl;
    std::cout << S_C2->isEmpty() << " " << S_C2->isBoiled() << std::endl;

    S_C1->fill();

    std::cout << S_C1->isEmpty() << " " << S_C1->isBoiled() << std::endl;
    std::cout << S_C2->isEmpty() << " " << S_C2->isBoiled() << std::endl;

    S_C2->boil();

    std::cout << S_C1->isEmpty() << " " << S_C1->isBoiled() << std::endl;
    std::cout << S_C2->isEmpty() << " " << S_C2->isBoiled() << std::endl;
    

    //--------Ex_2--------
    std::cout << "\n--------Ex_2--------" << std::endl;


  

    return 0; 
}