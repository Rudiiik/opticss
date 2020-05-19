 #include "device.h"

Device::Device() 
{

}

void Device::setParam(string name, double value)
{
    params[name] = value;
}

// LineOfSources ModifyLine (LineOfSources prevLine){
        /* вычисляем на уровне Y значение теущей линии источников; потом ищем расстояние между источниками l; цикл из N итераций внутри него (d-b)/l
         * раз зануляем амлитуду и b/l раз ничего не трогаем. Все начинаем с X и считаем что решетка начинается с темной полосы*/



