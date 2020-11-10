#include <iostream>
#include <string>
#include <vector>
#include <math.h>



auto sumof(std::vector<std::pair<int,int>> we, char option) -> int          //Sum of squares of vectors
{
    int sumx=0,sumy=0;
    if(option=='A') //A is x<0
    {
        for(int i=0;i<=we.size();i++)
        {
            if(we[i].first<=0 )
            {sumx=sumx+we[i].first; sumy=sumy+we[i].second;}
        }
    }
    if(option=='B') //B is +-
    for(int i=0;i<=we.size();i++)
        {
            if(we[i].first>0 )
            {sumx=sumx+we[i].first; sumy=sumy+we[i].second;}
        }
    if(option=='C') //C is --
    for(int i=0;i<=we.size();i++)
        {
            if(we[i].second<0)
            {sumx=sumx+we[i].first; sumy=sumy+we[i].second;}
        }
    if(option=='D') //D is ++
    for(int i=0;i<=we.size();i++)
        {
            if(we[i].second>0)
            {sumx=sumx+we[i].first; sumy=sumy+we[i].second;}
        }
    return pow(sumx,2)+pow(sumy,2);
}

auto main() -> int
{

    int n,x,y;
    std::vector<std::pair<int,int>> wektor(5);
    std::vector<double> l;
    printf("Number of vectors:");                   //Initialize
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
    printf("Vector number:%d - ",i+1);
    scanf("%d %d",&x,&y);
    wektor.push_back(std::make_pair(x,y));          //Set values for vectors
    }

    l.push_back(sqrt(fabs(sumof(wektor,'A'))));           //Set l as a sum of all squares of vectors with negative x and positive y
    l.push_back(sqrt(fabs(sumof(wektor,'B'))));           //Set l as a sum of all squares of vectors with positive x and negative y
    l.push_back(sqrt(fabs(sumof(wektor,'C'))));           //Set l as a sum of all squares of vectors with negative x and y          
    l.push_back(sqrt(fabs(sumof(wektor,'D'))));           //Set l as a sum of all squares of vectors with positive x and y
    std::cout<<"1:"<<l[0]<<std::endl;
    std::cout<<"2:"<<l[1]<<std::endl;
    std::cout<<"3:"<<l[2]<<std::endl;
    std::cout<<"4:"<<l[3]<<std::endl;
    if(l[0]>l[1] && l[0]>l[2] && l[0]>l[3])
    {printf("Length:%f",l[0]);}
    else 
    if(l[1]>l[2] && l[1]>l[3])
    {printf("Length:%f",l[1]);}
    else                                    //Print out the biggest sum
    if(l[2]>l[3])
    {printf("Length:%f",l[2]);}
    else
    {printf("Length:%f",l[3]);}
    
    
    return 0;
}
