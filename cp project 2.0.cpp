#include<iostream>
using namespace std;
int main(){
    cout<<"Enter number of candidates (1-10): ";
    int candidate_num;

    do{
        cin >> candidate_num;
        if(candidate_num < 1 || candidate_num > 10)
            cout << "Invalid Number! Please enter a number between 1 and 10: ";
    }
    while(candidate_num < 1 || candidate_num > 10);

    string candidate_name[10];

    cout<<"\n Enter candidate names one by one."<<endl;
        for(int i=0; i<candidate_num; i++){
            int j=i+1;
            cout<<"Candidate "<<j<<" : ";
            cin>>candidate_name[i];
        }

    cout<<"\n ----------------------------- ";
        cout<<"\n Selected Candidates: ";
        for(int j=0; j<candidate_num; j++){
            cout<<"\n "<< candidate_name[j];

        }

    cout<<"\n Enter number of voters: ";
    int voter_count;
    cin>> voter_count;

    cout<<"\n Number of voters is: "<<voter_count;

    cout<<"\n *************************************** ";
    cout<<"\n Elections Begin!!! "<<endl;

        //Code runs perfectly til this point

    // need to place loop here
    int votes[voter_count][candidate_num];
    cout<<"\n Selected Candidates: ";
    for(int j=0; j<candidate_num; j++){
        cout<<"\n "<< candidate_name[j];
    }
    //taking input per preference
    for(int i=0 ; i < voter_count ; i++){
        
        cout<<"\nVoter No. "<< (i+1) << " \nVote for candidates as per preference!";

       
            for(int k=0; k<candidate_num ; k++){
                 cout<<"\n Preference No. "<< (k+1) <<" :";
                cin>>votes[i][k];
            }
    }
    //Points as per preference
    int points[candidate_num];
    for(int i=0 ; i< candidate_num; i++){
    points[i]=0;
    }

    for(int j=0; j < voter_count; j++){
        for(int k=0 ; k < candidate_num; k++){
            int candidate_index = votes[j][k] - 1;
            int points_awarded = candidate_num -k;
            points[candidate_index] += points_awarded;

    }
}

    //displaying points
    int max_points = points[0];
    int winner_index = 0;
        for(int i= 1; i < candidate_num ; i++){
            if(points[i] > max_points){
                max_points = points[i];
                winner_index = i;
            }
        }
    cout<<"\n *******************************************"<<endl;
    cout<<"Winning candidate by points is: "<< candidate_name[winner_index] << " winning by "<< max_points << " Points !!!!\n Congratulations!";

    return 0;
}