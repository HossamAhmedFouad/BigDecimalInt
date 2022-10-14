/*
*    Name : Mohamed Waleed Mohamed
*    ID  : 20210362
*    Assignment : 1
*    Problem : 5
*/
#include <iostream>
#include <vector>
using namespace std;


struct dominoT{
    int leftDots;
    int rightDots;
};

vector<pair<dominoT,int>> path;

bool FormsDominoChain(vector<dominoT> dominos)
{
    static dominoT current = {-1, -1};
    for (int i = 0; i <= dominos.size(); i++)
    {

        if (path.size() == dominos.size()){return true;} //path made

        // check if the domino was visited
        // and if it was visited skip the current for loop
        bool visited = false;
        for (int j = 0; j < path.size(); j++){
            if (path[j].second == i)
            {
                visited = true;
                break;
            }
        }
        if (visited)
            continue;
        // initializing the first domino, inserting it
        // then the function calls itself again
        if (current.leftDots == -1){
            current.leftDots = dominos[i].leftDots;
            current.rightDots = dominos[i].rightDots;
            path.push_back(make_pair(current,i));
            FormsDominoChain(dominos);
        }
        // matching the dominos eg. 1|2  with  2|3 
        // then the function calls itself again
        else if(current.rightDots == dominos[i].leftDots)
        {
            current.leftDots = dominos[i].leftDots;
            current.rightDots = dominos[i].rightDots;
            path.push_back(make_pair(current,i));
            FormsDominoChain(dominos);
        }
    }
    // if a path isn't made with all of the dominos
    // we reset the current domino and empty the vector to try a path 
    // with another initialized domino
    current = {-1,-1};
    path.clear();
    return false;
}
    


int main()
{

    
    int n;
    vector<dominoT> pile;

    cout<<"Enter the number of dominos: "; cin>>n; cout<<endl;
    for(int i=0;i<n;i++){
        dominoT domino{};
        cout<<"Enter the left dots: "; cin>>domino.leftDots;
        cout<<"Enter the right dots: "; cin>>domino.rightDots; cout<<endl;
        pile.push_back(domino);
    }

    if(FormsDominoChain(pile) ) {
        cout<<"The dominos form a chain: ";
        for (int i = 0; i < path.size() - 1; i++)
            cout << path[i].first.leftDots << "|" << path[i].first.rightDots << "-";
        cout <<path[path.size()-1].first.leftDots << "|" << path[path.size()-1].first.rightDots << endl;
    }
    else{
        cout<<"The dominos do not form a chain"<<endl;
    }

    return 0;
    
}
