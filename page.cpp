#include "page.h"
#include <iostream>
using namespace std;

Page::Page() 
{
    
}

void Page::setTotal(int totalX)
{
    total = totalX;
}

void Page::setID(int idX)
{
    id = idX;
}

int Page::getTotal()
{
    return total;
}

int Page::getID()
{
    return id;
}

void Page::setURL(string urlX)
{
    url = urlX;
}

string Page::getURL()
{
    return url;
}

void Page::setRank(double rankX)
{
    rank = rankX;
}

double Page::getRank()
{
    return rank;
}

void Page::setOutbound(vector<int> links)
{
    //set vectors to vectors
    for(unsigned int i = 0; i < links.size(); i++){
        outLink.push_back(links[i]);

    }
    outLink = links;
}

vector<int> Page::getOutbound()
{
    //access the vectors
    return outLink; 
}
