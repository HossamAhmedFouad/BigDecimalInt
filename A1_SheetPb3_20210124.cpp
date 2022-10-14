/**
 * author. Hossam Ahmed Fouad
 * Date: 14.10.22.
 * CS213 Assignment 1 - Sheet 1 problem 03
 */

#include <bits/stdc++.h>
using namespace std;

struct Player{
    int score{};
    string name{};
    Player(string pName="NA",int pScore=0){
        name = pName;
        score = pScore;
    }
};

bool cmp(Player& a ,Player& b){
    return a.score > b.score;
}

void PrintMenu(){
    cout<<"Select an option 1->4"<<endl;
    cout<<"1-Print Score Board"<<endl;
    cout<<"2-Enter new score"<<endl;
    cout<<"3-Print Player Highest Score"<<endl;
    cout<<"4-Exit"<<endl;
    cout<<">>";
}
vector<Player>scoreboard{};
vector<string>names{};

void AddPlayer(){
    string name{};
    int score{0};
    cout<<"Name: "; cin>>name; cout<<endl;
    names.push_back(name);
    cout<<"Score: "; cin>>score; cout<<endl;
    Player player(name,score);
    scoreboard.push_back(player);
    cout<<"Player Has Been Added!"<<endl;
    sort(scoreboard.begin(),scoreboard.end(), cmp);
}
void ShowScoreboard(){
    cout<<"SCORE BOARD"<<endl;
    for(int i=0;i<min(10,(int)scoreboard.size());i++){
        cout<<i+1<<"- "<<scoreboard[i].name<<" : "<<scoreboard[i].score<<endl;
    }
}

void search(string& name){
    for(int i=0;i<scoreboard.size();i++){
        if(name == scoreboard[i].name){
            cout<<"Player's Highest Score: "<<scoreboard[i].score<<endl;
            if(i>9){
                cout<<"Player is not in the top 10 players"<<endl;
            }
            return;
        }
    }
}

void PrintPlayerHighScore(){
    string name;
    cout<<"Name: ";cin>>name;
    bool found{false};
    for(auto& n : names){
        if(name==n){
            found = true;
            break;
        }
    }
    if(!found) cout<<"The player’s name has not been input"<<endl;
    else{
        search(name);
    }

}

int main(){
    while (true){
        PrintMenu();
        int n;cin>>n;
        if(n==1) {
            ShowScoreboard();
        }else if(n==2){
            AddPlayer();
        }else if(n==3){
            PrintPlayerHighScore();
        }else if(n==4){
            cout<<"GOODBYE!"<<endl;
            break;
        }else{
            cout<<"Wrong Input,please try again"<<endl;
        }
    }

    return 0;
}