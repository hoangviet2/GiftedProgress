#include<bits/stdc++.h>
using namespace std;

//comparator function
bool comp(const vector<int>&a,const vector<int>&b)
{
    return a[1]<b[1];
}


//function for binary search
int bs(int pos,int val,vector<int>&end)
{
    int l=0,r=pos,mid,ans=-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(end[mid]<val)
        {
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}
int maxValue(vector<vector<int> > events) {
    //calculating total no. of events
    int n=events.size();


    //sorting the events on the basis of end time
    //event which is ending at earliest is placed at front
    //event which is having maximum end time is at last
    sort(events.begin(),events.end(),comp);


    //this event is just holding end time of all events in sorted order of events
    vector<int>end(n);
    for(int i=0;i<n;i++)
    {
        end[i]=events[i][1];
    }


    //this our dp array 
    //dp[i][j] represents the max value of attending 'j+1' till ith event
    vector<int>dp(n+1);

    //in this we are calculating dp[i][0] which represents max value for attending 1 event till ith event
    dp[0] = events[0][2];
    for(int i=1;i<n;i++)
    {
        dp[i] = max(dp[i-1],events[i][2]);
    }

    //we have two options at every pair of (i,j) index
    //wether include ith event or don't
    for(int i=1;i<n;i++)
    {
            //we are calculating position of event which is having end time just lesser than start time of ith event
            //we are using binary search to find this position
            int pos=bs(i-1,events[i][0],end);

            //this is case we are not including ith event in our answer
            //when ith even is not included then 
            //answer till i-1 events for jth index will be answer
            dp[i]=max(dp[i],dp[i-1]);

            //now we are checking wether
            //max ans comes when we include or when we don't
            if(pos!=-1)
            {
                dp[i]=max(dp[i], dp[pos]+events[i][2]);
            }
    }


    //now we are just calculating max answer possible for attending at most k events
    /// it is not compulsory to attend k events 
    //our final answer may contain total events less than k
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,dp[i]);
    }
    return ans;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    vector<vector<int> > events;
    int n;cin>>n;
    for(int i=0;i<n;++i){
        vector<int> temp;
        int start,end;
        cin>>start>>end;
        temp.push_back(start);
        temp.push_back(end);
        events.push_back(temp);
    }
    cout<<maxValue(events);
    return 0;
}