#pragma once 
#include <iostream>
using namespace std;

class Commentator
{
public:
    static void AddComment(string comment);
    static void Comment();
    static void ClearComment();
protected:
    static string text;
};