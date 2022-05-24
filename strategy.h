#pragma once
#include <iostream>
#include <fstream>



class DivideStrategy
{
public:
    virtual void Divide() = 0;
};

class DivideByScreenWidth: public DivideStrategy
{
public:
    void Divide()
    {
        std::cout << "DivideByScreenWidth by screen width = " << std::endl;
    }
};

class DivideBySentence: public DivideStrategy
{
public:
    void Divide()
    {
        std::cout << "Divided by Sentences" << std::endl;
    }
};

class DivideByUserWidth: public DivideStrategy
{
public:
    void Divide()
    {
        std::cout << "DivideByScreenWidth by screen width = " << std::endl;
    }
};

class Data
{
public:
    virtual ~Data() {}
    virtual void userStrategy() = 0;
    virtual void setStrategy(DivideStrategy *) = 0;
};

class DivideData: public Data
{
private:
    DivideStrategy *divideStrategy;
public:
    void userStrategy() override
    {
        divideStrategy->Divide();
    }

    void setStrategy(DivideStrategy *strategy) override
    {
        divideStrategy = strategy;
    }

};




/*
enum class DivideMethod{
    ByScreenWidth,
    ByUserWidth,
    BySentence
};

class ITextWork{
    public:
    virtual void Divide(DivideMethod) = 0;
};

class TextEditor: ITextWork{
private:
    size_t EditorWidth;
    std::string all_text;
public:
    TextEditor(){};
    TextEditor(const std::string &text) : all_text(text) {};

    TextEditor(std::ifstream& file) {
        std::string line;
        if (file.is_open()){
            while (getline(file, line))
            {
                all_text+=line;
            }
        }
    }

    void PrintText() const{
        std::cout << all_text << std::endl;
    }

    void Divide(DivideMethod method) override {
        switch (method) {
            case DivideMethod::ByScreenWidth:
                DivideByScreenWidth();
                break;
            case DivideMethod::BySentence:
                DivideBySentence();
                break;
            case DivideMethod::ByUserWidth:
                DivideByUserWidth();
                break;
            default:
                DivideByScreenWidth();
        }
    }

    void DivideByScreenWidth(){
        std::cout << "DivideByScreenWidth by screen width = " << EditorWidth << std::endl;
    }

    void DivideBySentence(){
        std::cout << "Divided by Sentences" << std::endl;
    }

    void DivideByUserWidth(int userWidth){
        std::cout << "DivideByScreenWidth by screen width = " << userWidth << std::endl;
    }
};
*/
