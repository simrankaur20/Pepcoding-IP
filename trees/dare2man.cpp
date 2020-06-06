#include<bits/stdc++.h>
using namespace std;
class Event{
public :
    string name;
    int id;
    int date;
    string typeofevent;
    Event(string x,int y,int z, string q)
    {

        name = x;
        id = y;
        date = z;
        typeofevent = q;
    }
};

bool mycomp(Event e1, Event e2)
{
    return e1.date < e2.date;
}

vector<Event> mainevent;

void displayevent(Event e)
{

    cout<<"NAME: "<< e.name <<endl;
    cout<<"ID : "<< e.id<<endl;
    cout<< "Type of event : "<< e.typeofevent<< endl;
    cout<<" Date: " <<e.date <<endl;
}
int counter = 1;
class organiser{
public:

    string name;
    Event addevent(string x,int y,int z, string q )
    {
        Event e(x,counter++,y,q);

        mainevent.push_back(e);
    }

    void viewevents()
    {
        for(int i = 0 ; i  < mainevent.size();i++)
        {
            displayevent(mainevent[i]);
        }
    }


};

int main()
{

    cout << "######################################################################################################################"<<endl;
    cout<<"\t\t\t\t\t COLLEGE EVENT MANAGEMENT SYSTEM"<<endl;
    cout << "######################################################################################################################"<<endl;
    string a;

    while(1)
    {

        cout<<"Are you a participant or an organiser"<<endl;
        cin>> a;

        if(a == "organiser")
        {
            cout<<"Options" << endl;
            cout<<"1.Add an Event"<<endl;
            cout<<"2.View All Events"<<endl;
            cout<<"3.See Number of events"<<endl;
            cout<<"4.Group events on the basis of category"<<endl;

            int op;
            cin>>op;
            organiser o;
            if(op == 1)
            {
                string x;
                int y, z;
                 string q;
                cout<<"enter name"<<endl;
                cin>>x;
                cout<<"enter date"<<endl;
                cin>>y;
                cout<<"Enter category of event"<<endl;
                cin>>q;

                o.addevent(x,y,0,q);
            }

            else if(op == 2){

                o.viewevents();
            }
            else if(op ==4)
            {
                string cat;
                cout<<"Enter category"<<endl;
                cin>>cat;
                for(int i=0; i< mainevent.size(); i++)
                {
                    if(mainevent[i].typeofevent == cat)
                    {
                        displayevent(mainevent[i]);
                    }
                }
            }
            else{
                cout<<" Total Number of events are : "<<mainevent.size()<<endl;
            }

        }

        else{

            cout<<"options"<<endl;
            cout<<"1.View all events"<<endl;
            cout<<"2.Sort on the basis of Date"<<endl;
            cout<<"3.View total number of events: "<<endl;
            cout<<"4.Exit"<<endl;
            int op;
            cin>>op;
            if(op == 1)
            {
                organiser o;
                o.viewevents();
            }
            else if(op == 2)
            {
                sort(mainevent.begin() , mainevent.end(),mycomp);
            }

            else if(op == 3){
                cout<<" Total Number of events are : "<<mainevent.size()<<endl;
            }
            else{
                return 0;
            }
        }
        char c;
        cout<<" do you want to exit" << endl;
        cin>>c;
        if(c == 'y')
        {
            break;
        }
    }
}
