#include <iostream>
#include "Dictionary.h"

int main() {
    Dictionary<int, float> dictionary;
    //dictionary.addElementByKey(228, 22.8);
    //dictionary.addElementByKey(322, 32.2);
    //dictionary.addElementByKey(184, 18.4);

    auto b1 = dictionary.isElementStored(228);
    auto b2 = dictionary.isElementStored(1337);

    dictionary.getElementByKey(228);

    return 0;
}
