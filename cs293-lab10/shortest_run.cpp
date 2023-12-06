#include "shortest_walk.cpp"

struct user{
    int arrival;
    int source;
    int destination;
};

void shortest_run(vector<user>& users, Graph& g,vector<vector<int>>& paths)
{
    // we will store the paths in a matrix such that the columns denote the time stamp and the rows denote the users
    vector<vector<int>> timetable;

    for(int i = 0; i<users.size(); i++){
        vector<int> temp = {0};
        timetable.push_back(temp);
    }

    for(int i = 0; i<users.size();i++){
        //the first index gets the arrival time -- we want to start storing into the timetable at that specific index
        for(int j = 0; j< users[i].arrival-1; j++){
            timetable[j].push_back(0);  //push a zero
        } //put -1 because one index is already taken

        //now we can call the shortest walk
        vector<int> path;
        vector<int> sourceanddestination;
        sourceanddestination.push_back(users[i].source);
        sourceanddestination.push_back(users[i].destination);

        shortest_walk(g,sourceanddestination,path);

        // now that we have the path, we must cleverly insert it into the timetable. 
        // the caveat being that if the user just before it is at the same index and is going to the same next index 
        // we wait on the index
        int sz = path.size();
        for(int j = 0; j<sz; j++){
            if(i == 0){
                timetable[i].push_back(path[j]);
            }
            else if(timetable[i][j+users[i].arrival] == timetable[i-1][j+users[i].arrival] && timetable[i][j+users[i].arrival+1] == timetable[i-1][j+users[i].arrival+1]){
                timetable[i].push_back(path[j]);
                timetable[i].push_back(path[j]);
            }
            else{
                timetable[i].push_back(path[j]);
            }
        }

    }

    for(int i = 0; i<timetable.size(); i++){
        vector<int> temp;
        for(int j = users[i].arrival; j<timetable[i].size(); j++){
            temp.push_back(timetable[i][j]);
        }
        paths.push_back(temp);
    }


    return;
}