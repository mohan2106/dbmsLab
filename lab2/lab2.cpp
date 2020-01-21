#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include<fstream>
#include <cmath>
using namespace __gnu_pbds;
using namespace std;

typedef long long lli;
typedef long li;
typedef pair<int,int> PI;
typedef pair<long,int> PLI;
typedef pair<int,long> PIL;
typedef pair<long, long> PL;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<long> VL;
typedef vector<long long> VLL;
typedef priority_queue<int> PQ;
typedef priority_queue<long> PQL;
typedef priority_queue<long long> PQLL;
#define FAST ios::sync_with_stdio(0)
#define forz(n) for (long i = 0; i < n; i++)
#define forv(i,x,y) for (long i=x; i<y; i++)
#define rforz(a,n) for (long i = a; i < n; i++)
#define forlz(n) for (long int i = 0; i < n; i++)
#define TRAV(it, v) for(auto it = v.begin(); it != v.end(); it++) 
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define SQ(a) (a)*(a)
#define UM unordered_map
#define US unordered_set
#define LB(v,x) lower_bound(v.begin(),v.end(),x);
#define UB(v,x) upper_bound(v.begin(),v.end(),x);
#define CUBE(a) (a)*(a)*(a)
#define SORT(v) sort(v.begin(),v.end());
#define SORTC(v,c) sort(v.begin(),v.end(),c);


struct course{
    string name;
    string code;
    int sem;
    string credit;
};
struct grades{
    vector<pair<string,string>> g; //coursename, grades
};

struct student{
    string name;
    string rollno;
    vector<pair<string,string>> semsters[8];
};

struct inputgrades{
    string course;
    string grade;
};

string cutString(string s){
    string temp = "";
    forz(s.length()){
        if(s[i]!=' '){
            temp+=s[i];
        }
    }
    return temp;
}

UM<string,int> credit;

UM<string,course> coursemap;    //coursename vs courses
UM<string,student> studentsmap; //roll no vs studentslist

UM<string,vector<pair<string,string>>> localgrades;

void readUsername(){
    ifstream ip("students.csv");
    if(!ip.is_open()) cout<<"ERROR: can't open students.csv";
    while(ip.good()){
        string nm,rol;
        getline(ip,nm,',');
        getline(ip,rol,'\n');
        student st;
        st.name = nm;
        st.rollno = rol;
        forz(localgrades[rol].size()){
            course cc = coursemap[localgrades[rol][i].F];
            if(cc.sem < 1 || cc.sem >8) continue;
            st.semsters[cc.sem -1].PB(MP(localgrades[rol][i].F,localgrades[rol][i].S));
        }
        studentsmap[rol] = st;
        // cout<<"yes\n";
    }
    ip.close();
}
void readGrades(){
    ifstream ip("grades.csv");
    if(!ip.is_open()) cout<<"ERROR: can't open grades.csv";
    while(ip.good()){
        string rol,cs,gd;
        getline(ip,rol,',');
        getline(ip,cs,',');
        getline(ip,gd,'\n');
        course cc = coursemap[cs];
        // if(cc.sem >=1 && cc.sem<=8){
        string temp = cutString(cs);
        
        localgrades[rol].PB(MP(temp,gd));
        // }
            //studentsmap[rol].semsters[cc.sem -1].PB(MP(cs,gd));
        // cout<<"yes\n";
    }
    ip.close();
    // cout<<localgrades.size()<<'\n';
    // for(auto xx:localgrades){
    //     cout<<xx.F<<"\n";
    //     forz(xx.S.size()){
    //         cout<<xx.S[i].F<<" "<<xx.S[i].S<<'\n';
    //     }
    //     cout<<'\n';
    // }
}
void readCources(){
    ifstream ip("courses.csv");
    if(!ip.is_open()) cout<<"ERROR: can't open courses.csv";
    while(ip.good()){
        string s,cno,cn,n1,n2,n3,tc;
        getline(ip,s,',');
        getline(ip,cno,',');
        getline(ip,cn,',');
        getline(ip,n1,',');
        getline(ip,n2,',');
        getline(ip,n3,',');
        getline(ip,tc,'\n');
        course crs;
        crs.name = cn;
        crs.code = cno;
        crs.sem = s[0]-'0';
        crs.credit = tc;
        coursemap[cno] = crs;
        // cout<<"yes\n";
    }
    ip.close();
}

void generateTranscript(){
    // freopen("outputq.txt", "w", stdout);
    for(auto x:studentsmap){
        string roll = x.F;
        int l = roll.length();
        char rollchar[l+5];
        forz(l+1){
            rollchar[i] = roll[i];
        }
        rollchar[l] = '.';
        rollchar[l+1] = 't';
        rollchar[l+2] = 'x';
        rollchar[l+3] = 't';
        rollchar[l+4] = '\0';
        freopen(rollchar, "w", stdout);
        student st = x.S;
        cout<<"Name: "<<st.name<<'\n';
        cout<<"Roll Number: "<<st.rollno<<'\n';
        cout<<'\n';

        vector<double> spi(8);
        vector<double> cpi(8);
        vector<int> semcredit(8);
        
        forz(8){
            cout<<"\n";
            cout<<"Semester "<<i+1<<'\n';
            cout<<"Course Number    |   Course Name     |   C   |   grade\n";
            // cout<<st.semsters[i].size()<<'\n';
            forv(j,0,localgrades[st.rollno].size()){
                course cc = coursemap[localgrades[st.rollno][j].F];
                // if(cc.sem < 1 || cc.sem >8) continue;
                if(cc.sem-1 == i){
                    semcredit[i] += (cc.credit[0] - '0');
                    if(credit.find(localgrades[st.rollno][j].S) != credit.end())
                        spi[i] += ((0.1*(credit[localgrades[st.rollno][j].S])))*(cc.credit[0] - '0')*10;
                    cout<<cc.code<<'\t'<<cc.name<<'\t'<<cc.credit<<'\t'<<localgrades[st.rollno][j].S<<'\n';
                }
                // st.semsters[cc.sem -1].PB(MP(localgrades[rol][i].F,localgrades[rol][i].S));
            }
            
        }
        cout<<'\n';
            

        cout<<'\n';
        cout<<"SPI: ";
        forz(8){
            cout<<spi[i]/semcredit[i]<<" ";
        }

    }
}

int main(){
    //=====================================code starts here
    credit["AS"] = 10;
    credit["AA"] = 10;
    credit["AB"] = 9;
    credit["BB"] = 8;
    credit["BC"] = 7;
    credit["CC"] = 6;
    credit["CD"] = 5;
    credit["DD"] = 4;

    readCources();
    readGrades();
    readUsername();
    generateTranscript();
    return 0;
}