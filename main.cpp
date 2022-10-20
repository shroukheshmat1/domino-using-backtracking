#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct dominoT
{
    int leftDots;
    int rightDots;
};
vector<dominoT>ans;
map <int,bool> decision_of_taking;
bool FormsDominoChain(vector<dominoT> & dominos)
{
    if (ans.size()==dominos.size())
    {
        return true;
    }
    for (int i=0;i<dominos.size();i++)
    {
        if ((ans.empty()) || (dominos[i].leftDots == ans.back().rightDots))
        {
            if (!decision_of_taking[i])
            {
                ans.push_back(dominos[i]);
                decision_of_taking[i]=true;
                if(FormsDominoChain(dominos))  return true;
                ans.pop_back();
                decision_of_taking[i]=false;
            }
        }
    }
    return false;
}
int main()
{
     int number_of_pieces;
     cout<<"how much domino pieces you'll enter?"<<endl;
     cin>>number_of_pieces;
     dominoT mydomino;
     vector<dominoT>dominoSet;
     for (int i=0;i<number_of_pieces;i++)
     {
         cout<<"please enter the number of dots of your "<<i+1<<" piece from left to right"<<endl;
         cin>>mydomino.leftDots>>mydomino.rightDots;
         dominoSet.push_back(mydomino);
     }
     bool chain_or_not= FormsDominoChain(dominoSet);
     if (chain_or_not==0)
         cout<<"can't form a chain";
     else
     {
         cout<<"yes it can form at least one chain,one of its shapes:"<<endl;
         for (int i=0;i<number_of_pieces;i++)
         {
             cout<<ans[i].leftDots<<"-"<<ans[i].rightDots<<"|";
         }
     }
}
