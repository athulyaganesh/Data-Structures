#include <heap.h>
#include <iostream>
#include <ctime>

using namespace std;

int main() {
JobNode arr[100];
srand((unsigned)time(0));

cout<<"Enter the number of available machines: "<<endl;
int m;
cin>>m;
cout<<endl<<"Enter the number of jobs: "<<endl;
int p;
cin>>p;
cout<<"Do you wish to enter the time stamps manually(Y/N)?: "<<endl;
char t;
cin>>t;
if(t=='Y'||t=='y')
{
cout<<"\nEnter times for each job(in minutes): "<<endl;

int time;
for(int i = 0; i<p;i++)
{
    cout<<"Job "<<i+1<<": ";
    cin>>time;
    arr[i].time = time;
    arr[i].ID=i+1;
}
}
else if(t=='N'||t=='n')
{
    cout<<"\nUsing a random number generator to generate timestamps between 1 and 20 minutes\n"<<endl;

    for(int i=0; i<p; i++){
            arr[i].time = (rand()%21)+1;
            arr[i].ID = i+1;
            cout <<"Job "<<i+1<<": "<< arr[i].time << endl;
}
}
else
{
    cout<<"Incorrect option.."<<endl;
    exit(0);
}
cout<<endl<<"Schedule: "<<endl<<endl;
LPT (arr,p,m);
cout<<endl;
}
