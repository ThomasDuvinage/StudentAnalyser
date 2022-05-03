#include "analyser.h"

#include <iostream>

using namespace std;

Analyser::Analyser(QObject *parent) : QObject(parent)
{
}

Analyser::~Analyser(){
}

void Analyser::stopScan(){
    emit log("stop_scan");
}

void Analyser::scan(){
    emit log("I scan");
}





