#include <bits/stdc++.h>
using namespace std;
map<string,int> mapple;


void preprocess(){
    mapple["Timur"]++;
    mapple["Timru"]++;
    mapple["Tiumr"]++;
    mapple["Tiurm"]++;
    mapple["Tirum"]++;
    mapple["Tirmu"]++;
    mapple["Tmiur"]++;
    mapple["Tmiru"]++;
    mapple["Tmuir"]++;
    mapple["Tmuri"]++;
    mapple["Tmrui"]++;
    mapple["Tmriu"]++;
    mapple["Tumir"]++;
    mapple["Tumri"]++;
    mapple["Tuimr"]++;
    mapple["Tuirm"]++;
    mapple["Turim"]++;
    mapple["Turmi"]++;
    mapple["Trmui"]++;
    mapple["Trmiu"]++;
    mapple["Trumi"]++;
    mapple["Truim"]++;
    mapple["Trium"]++;
    mapple["Trimu"]++;
    mapple["iTmur"]++;
    mapple["iTmru"]++;
    mapple["iTumr"]++;
    mapple["iTurm"]++;
    mapple["iTrum"]++;
    mapple["iTrmu"]++;
    mapple["imTur"]++;
    mapple["imTru"]++;
    mapple["imuTr"]++;
    mapple["imurT"]++;
    mapple["imruT"]++;
    mapple["imrTu"]++;
    mapple["iumTr"]++;
    mapple["iumrT"]++;
    mapple["iuTmr"]++;
    mapple["iuTrm"]++;
    mapple["iurTm"]++;
    mapple["iurmT"]++;
    mapple["irmuT"]++;
    mapple["irmTu"]++;
    mapple["irumT"]++;
    mapple["iruTm"]++;
    mapple["irTum"]++;
    mapple["irTmu"]++;
    mapple["miTur"]++;
    mapple["miTru"]++;
    mapple["miuTr"]++;
    mapple["miurT"]++;
    mapple["miruT"]++;
    mapple["mirTu"]++;
    mapple["mTiur"]++;
    mapple["mTiru"]++;
    mapple["mTuir"]++;
    mapple["mTuri"]++;
    mapple["mTrui"]++;
    mapple["mTriu"]++;
    mapple["muTir"]++;
    mapple["muTri"]++;
    mapple["muiTr"]++;
    mapple["muirT"]++;
    mapple["muriT"]++;
    mapple["murTi"]++;
    mapple["mrTui"]++;
    mapple["mrTiu"]++;
    mapple["mruTi"]++;
    mapple["mruiT"]++;
    mapple["mriuT"]++;
    mapple["mriTu"]++;
    mapple["uimTr"]++;
    mapple["uimrT"]++;
    mapple["uiTmr"]++;
    mapple["uiTrm"]++;
    mapple["uirTm"]++;
    mapple["uirmT"]++;
    mapple["umiTr"]++;
    mapple["umirT"]++;
    mapple["umTir"]++;
    mapple["umTri"]++;
    mapple["umrTi"]++;
    mapple["umriT"]++;
    mapple["uTmir"]++;
    mapple["uTmri"]++;
    mapple["uTimr"]++;
    mapple["uTirm"]++;
    mapple["uTrim"]++;
    mapple["uTrmi"]++;
    mapple["urmTi"]++;
    mapple["urmiT"]++;
    mapple["urTmi"]++;
    mapple["urTim"]++;
    mapple["uriTm"]++;
    mapple["urimT"]++;
    mapple["rimuT"]++;
    mapple["rimTu"]++;
    mapple["riumT"]++;
    mapple["riuTm"]++;
    mapple["riTum"]++;
    mapple["riTmu"]++;
    mapple["rmiuT"]++;
    mapple["rmiTu"]++;
    mapple["rmuiT"]++;
    mapple["rmuTi"]++;
    mapple["rmTui"]++;
    mapple["rmTiu"]++;
    mapple["rumiT"]++;
    mapple["rumTi"]++;
    mapple["ruimT"]++;
    mapple["ruiTm"]++;
    mapple["ruTim"]++;
    mapple["ruTmi"]++;
    mapple["rTmui"]++;
    mapple["rTmiu"]++;
    mapple["rTumi"]++;
    mapple["rTuim"]++;
    mapple["rTium"]++;
    mapple["rTimu"]++;
    return;
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(mapple[s]){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    preprocess();
    //t = 1;
    while(t--){
        solve();
    }
    return 0;
}