#pragma once
#include <iostream>
#include <mutex>

std::mutex m1;

class S_ChocolateBoiler
{
private:
    bool _empty;
    bool _boiled;
    S_ChocolateBoiler()
    {
        _empty  = true;
        _boiled = false; 
    }
    static S_ChocolateBoiler *_sChoclolate;

public:
    S_ChocolateBoiler(S_ChocolateBoiler &other) = delete;
    void operator=(S_ChocolateBoiler &) = delete;

    static S_ChocolateBoiler *create();

    const bool &isEmpty() const;
    const bool &isBoiled() const;
    void fill();
    void drain();
    void boil();

 };

S_ChocolateBoiler *S_ChocolateBoiler::_sChoclolate = nullptr;

S_ChocolateBoiler *S_ChocolateBoiler::create()
{
    m1.lock();
    if(_sChoclolate == nullptr)
    {
        _sChoclolate = new S_ChocolateBoiler();
    }
    m1.unlock();
    return _sChoclolate;
}

const bool &S_ChocolateBoiler::isEmpty() const
{
    return _empty;
}

const bool &S_ChocolateBoiler::isBoiled() const
{
    return _boiled;
}

void S_ChocolateBoiler::fill()
{
    if(isEmpty())
    {
        _empty = false;
        _boiled = false;
    }
}

void S_ChocolateBoiler::drain()
{
    if(!isEmpty() && isBoiled())
    {
        _empty = true;
    }
}

void S_ChocolateBoiler::boil()
{
    if(!isEmpty() && !isBoiled())
    {
        _boiled = true;
    }
}




