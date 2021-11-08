#include "commentator.h"
string Commentator::text = "";

void Commentator::AddComment(string comment)
{
    text+=comment + "\n";
}

void Commentator::Comment()
{
    if (text=="")return;
    cout << text;
}

void Commentator::ClearComment()
{
    text = "";
}