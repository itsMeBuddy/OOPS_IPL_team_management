
//Yesterday, I knew what I have done
//Today, only God knows


#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

/*

                                                           
                           IPL
                            |
                        Franchise




      Health      Fitness   Practice    Statistics   Selection
        \            |         |            /           /
          \          |         |          /          /
            \        |         |        /         /
              \      |         |      /        /
               \     \         /     /       /
                \     \       /     /      /
                    FranchiseMembers
                            |
          ---------------------------------------
          |            |           |            |
        Player      Selector     Coach      GroundStaff

*/


class IPL{
    public:
    //DataMembers
        string titleSponsor;
        int year;
    //MemberFunctions
        IPL(string _titleSponsor,int _year){
            titleSponsor=_titleSponsor;
            year=_year;
            cout<<titleSponsor<<" IPL "<<year<<endl<<endl;
        }
};

class Franchise:public IPL{
    public:
    //DataMembers
        string franchiseName;
        int matchesWon;
        int matchesLost;
        
    //MemberFunctions

};



class Health{
    public:
    //DataMembers
        int healthPoints;
    //MemberFunctions
        Health(){
            healthPoints=0;
        }
        void generateHealthReport(){
            cout<<"healthPoints : "<<healthPoints<<endl;
        }
        void uploadHealthReport(int points,bool positive){
            if(positive==true)
                healthPoints+=points;
            else
                healthPoints-=points;
        }
};

class Fitness{
    public:
    //DataMembers
        int fitnessLevel;
        vector<string> injuries;
    //MemberFunctions
        Fitness(){
            fitnessLevel=100;
        }
        void uploadInjuries(string injury,int severity){
            injuries.push_back(injury);
            fitnessLevel-=severity;
            //displayInjuries();
        }
        void uploadFitness(string injury,int level){
            injuries.erase(find(injuries.begin(),injuries.end(),injury));
            fitnessLevel+=level;
            if(fitnessLevel>100)
                fitnessLevel=100;
            //displayInjuries();
        }
        void displayInjuries(){
            cout<<"Current Fitness Level = "<<fitnessLevel<<endl;
            for(int i=0;i<injuries.size();i++){
                cout<<"\t •"<<injuries[i]<<endl;                        // Alt+0149
            }
        }

};

class Practice{
    public:
    //DataMembers
        float timePracticed[3];
        float practicePoints;
    //MemberFunctions
        Practice(){
            timePracticed[0]=0;
            timePracticed[1]=0;
            timePracticed[2]=0;
        }
                                                                        //type=0 ->intensive (100% efficiency)
                                                                        //type=1 ->moderate (75% efficiency)
                                                                        //type=2 ->low (50% efficiency)
        float calcPracticePoints(){
            if((timePracticed[0]+timePracticed[1]+timePracticed[2])==0){
                return 0.0;
            }
            else
                return 100*((((100/100)*timePracticed[0])+((75/100)*timePracticed[1])+((50/100)*timePracticed[2]))/(timePracticed[0]+timePracticed[1]+timePracticed[2]));
        }
        void uploadTimePracticed(float time,int type){
            timePracticed[type]+=time;
            practicePoints=calcPracticePoints();
            cout<<"Updated Practice Points = "<<practicePoints;
        }
        void displayPracticePoints(){
            cout<<practicePoints<<endl;
        }
};

class Statistics{
    public:
    //DataMembers
        int matchesPlayed=0;
        int runsScored=0;
        int ballsTaken=0;
        int countOut=0;
        int ballsBowled=0;
        int runsConceded=0;
        int countWicket=0;
    //MemberFunctions
        void updateStatistics(int mP,int rS,int bT,int cO,int bB,int rC,int cW){
            //cout<<"\n\tupdateStatistics\n";
            matchesPlayed+=mP;
            runsScored+=rS;
            ballsTaken+=bT;
            countOut+=cO;
            ballsBowled+=bB;
            runsConceded+=rC;
            countWicket+=cW;
        }
        void initialStatistics(int mP,int rS,int bT,int cO,int bB,int rC,int cW){
            //cout<<"\n\tinitialStatistics\n";
            matchesPlayed=mP;
            runsScored=rS;
            ballsTaken=bT;
            countOut=cO;
            ballsBowled=bB;
            runsConceded=rC;
            countWicket=cW;
        }
        float battingAverage(){
            if(countOut==0)
                return (float)runsScored/1;
            return (float)runsScored/(float)countOut;
        }
        float battingStrikeRate(){
            if(ballsTaken==0)
                return ((float)runsScored/1)*100;
            return ((float)runsScored/(float)ballsTaken)*100;
        }
        float bowlingAverage(){
            if(matchesPlayed==0)
                return (float)runsConceded/1;
            return (float)runsConceded/(float)matchesPlayed;
        }
        float bowlingEconomy(){
            if(ballsBowled==0)
                return (((float)runsConceded/(float)1)*(float)6);;
            return (((float)runsConceded/(float)ballsBowled)*(float)6);
        }
        void showStatistics(){
            cout<<"\t\t"<<"Batting Average : "<<battingAverage()<<endl;
            cout<<"\t\t"<<"Batting Strike Rate : "<<battingStrikeRate()<<endl;
            cout<<"\t\t"<<"Bowling Average : "<<bowlingAverage()<<endl;
            cout<<"\t\t"<<"Bowling Economy : "<<bowlingEconomy()<<endl;
        }

};

class Selection{
    public:
    //DataMembers
        vector<int> Playing11;
    //MemberFunctions
        //vector<int> generateRanks(){


        //    return Palying11;
        //}
};



class FranchiseMembers: public Health,
                        public Fitness, 
                        public Practice, 
                        public Statistics, 
                        public Selection
{
    public:
    //DataMembers
    string franchiseName;
        int category;
                        //1 --Player 
                        //2 --Selector
                        //3 --Coach
                        //4 --GroundStaff
    //MemberFunctions
    FranchiseMembers(){

    }
        
};


class Player:public FranchiseMembers{
    public:
    //DataMembers
        string name;
        int age;
        string discription;
        int id;
    //MemberFunctions
        Player(){
            cout<<"Enter name of the player : ";
            cin>>name;
            cout<<"Enter Age of the player : ";
            cin>>age;
            cout<<"Enter discription about the player : ";
            cin>>discription;
            cout<<"Enter the id of player : ";
            cin>>id;
        }
        Player(string _name,int _age,string _discription,int _id){
            name=_name;
            age=_age;
            discription=_discription;
            id=_id;
        }
        void display(){
            cout<<name<<"\t"<<age<<"\t"<<discription<<"\t"<<id<<endl;
        }
    
};

class Selector:public FranchiseMembers{
    public:
    //DataMembers
        string name;
        int age;
        float rating;
    //MemberFunctions
        Selector(){
            cout<<"Enter name of the Selector : ";
            cin>>name;
            cout<<"Enter Age of the Selector : ";
            cin>>age;
            cout<<"Enter rating of the Selector : ";
            cin>>rating;
        }
        Selector(string _name,int _age,float _rating){
            name=_name;
            age=_age;
            rating=_rating;
        }
        void display(){
            cout<<name<<"\t"<<age<<"\t"<<rating<<endl;
        }
    
};

class Coach:public FranchiseMembers{
    public:
    //DataMembers
        string name;
        int age;
        int experience;
    //MemberFunctions
        Coach(){
            cout<<"Enter name of the Coach : ";
            cin>>name;
            cout<<"Enter Age of the Coach : ";
            cin>>age;
            cout<<"Enter experience of the Coach : ";
            cin>>experience;
        }
        Coach(string _name,int _age,float _experience){
            name=_name;
            age=_age;
            experience=_experience;
        }
        void display(){
            cout<<name<<"\t"<<age<<"\t"<<experience<<endl;
        }
    
};

class GroundStaff:public FranchiseMembers{
    public:
    //DataMembers
        string name;
        int age;
        string designation;
    //MemberFunctions
        GroundStaff(){
            cout<<"Enter name of the GroundStaff : ";
            cin>>name;
            cout<<"Enter Age of the GroundStaff : ";
            cin>>age;
            cout<<"Enter designation of the GroundStaff : ";
            cin>>designation;
        }
        GroundStaff(string _name,int _age,float _designation){
            name=_name;
            age=_age;
            designation=_designation;
        }
        void display(){
            cout<<name<<"\t"<<age<<"\t"<<designation<<endl;
        }
    
};

                            void displayDatabase(vector<Player>,vector<Selector>,vector<Coach>,vector<GroundStaff>);
                            void databaseAdd(vector<Player> &,vector<Selector> &,vector<Coach> &,vector<GroundStaff> &);
                            void changeDetails(vector<Player> &,vector<Selector> &,vector<Coach> &,vector<GroundStaff> &);
                            void addSpecific(vector<Player> &,vector<Selector> &,vector<Coach> &,vector<GroundStaff> &);
                            
                    void changePlayerDetails(vector<Player> &);
                    void changeSelectorDetails(vector<Selector> &);
                    void changeCoachDetails(vector<Coach> &);
                    void changeGroundStaffDetails(vector<GroundStaff> &);



int main(){
    IPL edition("Vivo",2021);


    
    vector<Player> vPlayer;
    vector<Selector> vSelector;
    vector<Coach> vCoach;
    vector<GroundStaff> vGroundStaff;

    /*
    Player temp("Dhoni",39,"Batsmen",7);
    temp.display();
    temp.uploadInjuries("Hamstring",10);
    temp.uploadInjuries("Elbow",10);
    temp.uploadInjuries("Fracture",50);
    temp.uploadFitness("Elbow",45);
    temp.displayInjuries();
    temp.initialStatistics(10,953,806,7,41,246,9);
    temp.showStatistics();
    vPlayer.push_back(temp);
    */


    while(true){
        system("CLS");
        cout<<"1. Add Specific (Player/Selector/Coach/GroundStaff)\n"
            <<"2. Add all data from the database\n"
            <<"3. Display all of the Specifics(Player/Selector/Coach/GroundStaff)\n"
            <<"4. Change/Show Details\n"
            <<"5. Generate playing 11(developement in progress)\n";
        cout<<"0 to exit\n";
        
        int choice;
        cin>>choice;
        switch(choice){
            case 0: {   
                        cout<<"...Terminating the Program";
                        exit(0);
                        break;
                    }
            case 1: {
                        system("CLS");
                        addSpecific(vPlayer,vSelector,vCoach,vGroundStaff);
                        system("CLS");
                        break;
                    }
            case 2: {
                        system("CLS");
                        databaseAdd(vPlayer,vSelector,vCoach,vGroundStaff);
                        break;
                    }
            case 3: {
                        displayDatabase(vPlayer,vSelector,vCoach,vGroundStaff);
                        getch();
                        system("CLS");
                        break;
                    }
            case 4: {
                        system("CLS");
                        changeDetails(vPlayer,vSelector,vCoach,vGroundStaff);
                    }
            case 5: {
                        //GeneratePlaying11
                    }
            default:{
                        system("CLS");
                        cout<<"Invalid choice...try again";
                        break;
                    }
        }
    }
    return 0;
}

void addSpecific(vector<Player> &vPlayer,vector<Selector> &vSelector,vector<Coach> &vCoach,vector<GroundStaff> &vGroundStaff){
    int ch;
    cout<<"1. Add Player\n"
        <<"2. Add Selector\n"
        <<"3. Add Coach\n"
        <<"4. Add GroundStaff\n";
    cin>>ch;
    switch(ch){
        case 1: {
                    Player x;
                    vPlayer.push_back(x);
                    break;
                }
        case 2: {   
                    Selector x;
                    vSelector.push_back(x);
                    break;
                }
        case 3: {
                    Coach x;
                    vCoach.push_back(x);
                    break;
                }
        case 4: {
                    GroundStaff x;
                    vGroundStaff.push_back(x);
                    break;
                }
        default:{
                    cout<<"...Wrong Choice\n\tGoing Back...\n";
                    break;
                }
    }
}

void databaseAdd(vector<Player> &vPlayer,vector<Selector> &vSelector,vector<Coach> &vCoach,vector<GroundStaff> &vGroundStaff){
    cout<<"...Reading Database and creating objects\n";

    string name;
    int age;
    string discription;
    int id;
    string team;

    ifstream fin;
    fin.open ("Player.txt",ifstream::in);

    while(!fin.eof()) {
        fin>>name>>age>>discription>>id>>team;
        Player temp(name,age,discription,id);
        temp.franchiseName=team;
        vPlayer.push_back(temp);
    }
    cout<<"Done reading database\n";
    getch();
}

void displayDatabase(vector<Player> vPlayer,vector<Selector> vSelector,vector<Coach> vCoach,vector<GroundStaff> vGroundStaff){
    int ch;
    cout<<"1. Display Player\n"
        <<"2. Display Selector\n"
        <<"3. Display Coach\n"
        <<"4. Display GroundStaff\n";
    cin>>ch;
    switch(ch){
        case 1: {
                    cout<<"Total Players = "<<vPlayer.size()<<endl;
                    for(int i=0;i<vPlayer.size();i++){
                        vPlayer[i].display();
                    }
                    break;
                }
        case 2: {
                    cout<<"Total Selectors = "<<vSelector.size()<<endl;
                    for(int i=0;i<vSelector.size();i++){
                        vSelector[i].display();
                    }
                    break;
                }
        case 3: {
                    cout<<"Total Coaches = "<<vCoach.size()<<endl;
                    for(int i=0;i<vCoach.size();i++){
                        vCoach[i].display();
                    }
                    break;
                }
        case 4: {
                    cout<<"Total Ground Staffs = "<<vGroundStaff.size()<<endl;
                    for(int i=0;i<vGroundStaff.size();i++){
                        vGroundStaff[i].display();
                    }
                    break;
                }
        default:{
                    cout<<"...Wrong Choice\n\tGoing Back...\n";
                    break;
                }
    }


    
}

void changeDetails(vector<Player> &vPlayer,vector<Selector> &vSelector,vector<Coach> &vCoach,vector<GroundStaff> &vGroundStaff){
    system("CLS");
    int ch;
    cout<<"1. Player\n"
        <<"2. Selector\n"
        <<"3. Coach\n"
        <<"4. GroundStaff\n";
    cin>>ch;
    switch(ch){
        case 1: {
                    changePlayerDetails(vPlayer);
                    break;
                }
        case 2: {
                    changeSelectorDetails(vSelector);
                    break;
                }
        case 3: {
                    changeCoachDetails(vCoach);
                    break;
                }
        case 4: {
                    changeGroundStaffDetails(vGroundStaff);
                    break;
                }
        default:{
                    cout<<"...Wrong Choice\n\tGoing Back...\n";
                    break;
                }
    }
}

void changePlayerDetails(vector<Player> &vPlayer){
    
    string _name;
    int itr=-1;
    cout<<"Enter the Name of the player to modify details : ";
    cin>>_name;
    transform(_name.begin(), _name.end(), _name.begin(), ::tolower);
    for(int i=0;i<vPlayer.size();i++){
        string temp=vPlayer[i].name;
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        if(temp==_name){
            itr=i;
            break;
        }
    }

    if(itr==-1){
        cout<<"...No data found\n\tReturning to main menu...";
        getch();
        return;
    }

    int ch;
    cout<<"1. Update Health Report\n"
        <<"2. Generate Health Report\n"
        <<"3. Add Injuries\n"
        <<"4. Remove Injuries\n"
        <<"5. Display Injuries\n"
        <<"6. Upload Practice Time\n"
        <<"7. Display Practice Points\n"
        <<"8. Update Statistics\n"
        <<"9. Show Statistics\n";

    cin>>ch;
    system("CLS");
    switch(ch){
        case 1: {
                    int ch=false;
                    cout<<"1. Credit\n"
                        <<"2. Deduct\n";
                    cin>>ch;
                    if(ch==1)
                        ch=true;
                    cout<<"Enter points : ";
                    int points;
                    cin>>points;
                    vPlayer[itr].uploadHealthReport(points,ch);
                    getch();
                    break;
                }
        case 2: {
                    vPlayer[itr].generateHealthReport();
                    getch();
                    break;
                }
        case 3: {
                    cout<<"Enter Injury Name : ";
                    string str;
                    cin>>str;
                    cout<<"Enter Severity : ";
                    int severity;
                    cin>>severity;
                    vPlayer[itr].uploadInjuries(str,severity);
                    getch();
                    break;
                }
        case 4: {
                    cout<<"Enter Injury Name to be removed : ";
                    string str;
                    cin>>str;
                    cout<<"Enter level of fitness : ";
                    int level;
                    cin>>level;
                    vPlayer[itr].uploadFitness(str,level);
                    getch();
                    break;
                }
        case 5: {
                    vPlayer[itr].displayInjuries();
                    getch();
                    break;
                }
        case 6: {
                    float time;
                    cout<<"Enter Practice time : ";
                    cin>>time;
                    cout<<"\ttype=0 ->intensive (100% efficiency)\n"
                        <<"\ttype=1 ->moderate (75% efficiency)\n"
                        <<"\ttype=2 ->low (50% efficiency)\n"
                        <<"Enter type of practice : \n";
                    int type;
                    cin>>type;
                    vPlayer[itr].uploadTimePracticed(time,type);
                    getch();
                    break;
                }
        case 7: {
                    vPlayer[itr].displayPracticePoints();
                    getch();
                    break;
                }
        case 8: {
                    int matchesPlayed;
                    int runsScored;
                    int ballsTaken;
                    int countOut;
                    int ballsBowled;
                    int runsConceded;
                    int countWicket;

                    cout<<"Enter total no of new matches played : ";
                    cin>>matchesPlayed;
                    cout<<"Enter Runs Scored : ";
                    cin>>runsScored;
                    cout<<"Enter Balls taken to make "<<runsScored<<" Runs : ";
                    cin>>ballsTaken;
                    cout<<"Enter wickets falled : ";
                    cin>>countOut;
                    cout<<"Enter Balls bowled : ";
                    cin>>ballsBowled;
                    cout<<"Enter how many runs conceded in balling "<<ballsBowled<<" balls : ";
                    cin>>runsConceded;
                    cout<<"Enter how much wicket taken in "<<matchesPlayed<<" matches : ";
                    cin>>countWicket;

                    vPlayer[itr].updateStatistics(matchesPlayed,runsScored,ballsTaken,countOut,ballsBowled,runsConceded,countWicket);
                    getch();
                    break;
                }
        case 9: {
                    vPlayer[itr].showStatistics();
                    getch();
                    break;
                }
        default:{
                    cout<<"...Wrong choice\n\tReturning to main menu\n";
                    getch();
                    break;
                }
    }


}
void changeSelectorDetails(vector<Selector> &vSelector){
    string _name;
    int itr=-1;
    cout<<"Enter the Name of the  to modify details : ";
    cin>>_name;
    transform(_name.begin(), _name.end(), _name.begin(), ::tolower);
    for(int i=0;i<vSelector.size();i++){
        string temp=vSelector[i].name;
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        if(temp==_name){
            itr=i;
            break;
        }
    }

    if(itr==-1){
        cout<<"...No data found\n\tReturning to main menu...";
        getch();
        return;
    }

    int ch;
    cout<<"1. Update Health Report\n"
        <<"2. Generate Health Report\n";
    cin>>ch;
    system("CLS");
    switch(ch){
        case 1: {
                    int ch=false;
                    cout<<"1. Credit\n"
                        <<"2. Deduct\n";
                    cin>>ch;
                    if(ch==1)
                        ch=true;
                    cout<<"Enter points : ";
                    int points;
                    cin>>points;
                    vSelector[itr].uploadHealthReport(points,ch);
                    getch();
                    break;
                }
        case 2: {
                    vSelector[itr].generateHealthReport();
                    getch();
                    break;
                }
        default:{
                    cout<<"...Wrong choice\n\tReturning to main menu\n";
                    getch();
                    break;
                }
    }
}
void changeCoachDetails(vector<Coach> &vCoach){
    string _name;
    int itr=-1;
    cout<<"Enter the Name of the  to modify details : ";
    cin>>_name;
    transform(_name.begin(), _name.end(), _name.begin(), ::tolower);
    for(int i=0;i<vCoach.size();i++){
        string temp=vCoach[i].name;
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        if(temp==_name){
            itr=i;
            break;
        }
    }

    if(itr==-1){
        cout<<"...No data found\n\tReturning to main menu...";
        getch();
        return;
    }

    int ch;
    cout<<"1. Update Health Report\n"
        <<"2. Generate Health Report\n";
    cin>>ch;
    system("CLS");
    switch(ch){
        case 1: {
                    int ch=false;
                    cout<<"1. Credit\n"
                        <<"2. Deduct\n";
                    cin>>ch;
                    if(ch==1)
                        ch=true;
                    cout<<"Enter points : ";
                    int points;
                    cin>>points;
                    vCoach[itr].uploadHealthReport(points,ch);
                    getch();
                    break;
                }
        case 2: {
                    vCoach[itr].generateHealthReport();
                    getch();
                    break;
                }
        default:{
                    cout<<"...Wrong choice\n\tReturning to main menu\n";
                    getch();
                    break;
                }
    }
}
void changeGroundStaffDetails(vector<GroundStaff> &vGroundStaff){
    string _name;
    int itr=-1;
    cout<<"Enter the Name of the  to modify details : ";
    cin>>_name;
    transform(_name.begin(), _name.end(), _name.begin(), ::tolower);
    for(int i=0;i<vGroundStaff.size();i++){
        string temp=vGroundStaff[i].name;
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        if(temp==_name){
            itr=i;
            break;
        }
    }

    if(itr==-1){
        cout<<"...No data found\n\tReturning to main menu...";
        getch();
        return;
    }

    int ch;
    cout<<"1. Update Health Report\n"
        <<"2. Generate Health Report\n";
    cin>>ch;
    system("CLS");
    switch(ch){
        case 1: {
                    int ch=false;
                    cout<<"1. Credit\n"
                        <<"2. Deduct\n";
                    cin>>ch;
                    if(ch==1)
                        ch=true;
                    cout<<"Enter points : ";
                    int points;
                    cin>>points;
                    vGroundStaff[itr].uploadHealthReport(points,ch);
                    getch();
                    break;
                }
        case 2: {
                    vGroundStaff[itr].generateHealthReport();
                    getch();
                    break;
                }
        default:{
                    cout<<"...Wrong choice\n\tReturning to main menu\n";
                    getch();
                    break;
                }
    }

}
