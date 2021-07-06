#pragma once
#include "../HyperEngine.hpp"
#include <iostream>


class Utility{
public:
    template <typename t>
    static void Log(t object){
        printf("INFO : %s\n", object);
    }


    static Utility& getInstance(){
        static Utility temp;
        return temp;
    }

};