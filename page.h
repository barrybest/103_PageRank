#ifndef PAGE_H
#define PAGE_H
#include <string>
using std::string;
#include<vector>
using std::vector;
class Page { 
public:
  Page(); //could the constructor take place of all setters? or do we just initialize individually
  
    //setters
    void setTotal(int totalX);
    void setID(int idX);
    void setURL(string urlX);
    void setRank(double rankX);
    void setOutbound(vector<int>links);
    
    //getters
    int getTotal();
    int getID();
    string getURL();
    double getRank();
    vector<int> getOutbound();
    
    
private:
  //Data members: id, url, pagerank, links , .. etc
    int total; //get total number at the top of the page;
    int id; //id of page
    string url; //url of page
    double rank; //rank of page
    vector<int> outLink; //vector to store outbound links
    //object to store file??
};  
#endif
