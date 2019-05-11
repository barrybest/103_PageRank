#include "web.h"
#include "page.h"
#include <iostream>
#include <fstream>
#include <sstream>

int total;


Web::Web() //constructor
{   
}

Web::~Web() //destructor
{ 
}

bool Web::read_graph(const char *filename)
{ 
    ifstream ifile(filename);
    
    if(ifile.fail())
    {
        return false;
    }

    ifile >> total; //stores number at the top of the list;
    
    if(ifile.fail())
    {
        return false;
    }
    
    Page work;
    
    work.setTotal(total);
    
    while(!ifile.fail())
    {
        //store id number
        int idX;
        ifile >> idX;
        work.setID(idX);
        //store url
        string urlX;
        ifile >> urlX;
        work.setURL(urlX);
        //store rank
        double rankX;
        ifile >> rankX;
        work.setRank(rankX);
        //store outbound links in vectors
        vector<int>links;
        string holder = "";
        getline(ifile, holder);
        getline(ifile, holder); //CP told me to put twice, sometimes gets skipped
        stringstream ss;
        ss << holder;
        int xqwerty;
        while(ss >> xqwerty)
        {
            links.push_back(xqwerty);
        }
        work.setOutbound(links);
        pagelist.push_back(work);
        
    }
    
    ifile.close();
    
    return true;
    
}

bool Web::write_graph(const char *filename)
{ 
    ofstream ofile(filename);
    
    //input information gathered in read_graph
    ofile << total << endl;
    
    for(int i = 0; i < total; i++)
    {
        ofile << pagelist[i].getID() << endl;
        ofile << '\t' << pagelist[i].getURL() << endl;
        ofile << '\t' << pagelist[i].getRank() << endl;
        vector<int> finish = pagelist[i].getOutbound();
        ofile << '\t';
        for(int j = 0; j < finish.size(); j++)
        {
            ofile << finish[j] << " ";
        }
        ofile << endl;
    }
        
    ofile.close();
    return true;
}

void Web::calculate_rank(int S,int N)
{
    //int S = number of simulations ... use a for loop to run the simulations
    //int N = number of walkers to start ... use rand() % work.getTotal;
   
    vector<int> walkers;
    vector<int>  temp_walkers;
    
    //initialize each page with workers
    for(int i = 0; i < total; i++)
    {
        walkers.push_back(N / total);
        
        if(N % total > 1)
        {
            walkers[i]++;
        }
    
        temp_walkers.push_back(walkers[i]);
        
    }
    
    //update the ranks
    for(int i = 0; i < S; i++)
    {
        for(int j = 0; j < total; j++)
        {
            vector<int> temp = pagelist[j].getOutbound();
            
            //make the boys walk
            for(int q = 0; q < walkers[j]; q++)
            {
                int rando = rand() % temp.size();
                temp_walkers[temp[rando]]++;
                temp_walkers[j]--;
            }
        }
        
        //reset for next simulations
        for(int z = 0; z < total; z++)
        {
            walkers[z] = temp_walkers[z];
        }
    }
    
    //calculate the new rank
    for(int i = 0; i < total; i++)
    {
        pagelist[i].setRank((double)walkers[i]/N);
    }
    
}
