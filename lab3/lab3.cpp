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

struct studentrecord{
    string name;
    string course;
    string grade;
};

vector<studentrecord> array2,array3;

UM<string,int> credit;

UM<string,course> coursemap;    //coursename vs courses


UM<string,vector<pair<string,string>>> localgrades;
UM<string,string> rollName;

//==============================================================QUICK SORT 1

long partition1 (vector<studentrecord> &arr,long low,long high)
{
    studentrecord pivot = arr[high];  
 
    long i = (low - 1); 

    for (long j = low; j <= high- 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j].name < pivot.name)
        {
            i++;    // increment index of smaller element
            swap( arr[i], arr[j]);
        }
    }
    swap( arr[i + 1] , arr[high]);
    return (i + 1);
}
 
void quickSort1(vector<studentrecord> &arr,long low,long high){
    if (low < high)
    {
        long pi = partition1(arr, low, high);
        quickSort1(arr, low, pi - 1);  // Before pi
        quickSort1(arr, pi + 1, high); // After pi
    }
}

//===============================================================QUICK SORT 2
long partition2(vector<studentrecord> &arr,long low,long high)
{
    studentrecord pivot = arr[high];  
 
    long i = (low - 1); 

    for (long j = low; j <= high- 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j].course > pivot.course)
        {
            i++;    // increment index of smaller element
            swap( arr[i], arr[j]);
        }
    }
    swap( arr[i + 1] , arr[high]);
    return (i + 1);
}
 
void quickSort2(vector<studentrecord> &arr,long low,long high){
    if (low < high)
    {
        long pi = partition2(arr, low, high);
        quickSort2(arr, low, pi - 1);  // Before pi
        quickSort2(arr, pi + 1, high); // After pi
    }
}
//==============================================================QUICK SORT 3
long partition3 (vector<studentrecord> &arr,long low,long high)
{
    studentrecord pivot = arr[high];
 
    long i = (low - 1); 

    for (long j = low; j <= high- 1; j++)
    {
        // If current element is smaller than the pivot
        if (credit[arr[j].grade] > credit[pivot.grade])
        {
            i++;    // increment index of smaller element
            swap( arr[i], arr[j]);
        }
    }
    swap( arr[i + 1] , arr[high]);
    return (i + 1);
}
 
void quickSort3(vector<studentrecord> &arr,long low,long high){
    if (low < high)
    {
        long pi = partition3(arr, low, high);
        quickSort3(arr, low, pi - 1);  // Before pi
        quickSort3(arr, pi + 1, high); // After pi
    }
}

//===============================================================MERGE SORT
void merge1(vector<studentrecord> &array,long l,long r){
	long p=(l+r)/2;
	long x=p-l+1;
	long y=r-p;
	studentrecord A[x+1],B[y+1];
	for(long i=0;i<x;i++){
		A[i]=array[l+i];
	}
	A[x].name="zzzzzzzzz";
	for(long i=0;i<y;i++){
		B[i]=array[p+1+i];
	}
	B[y].name = "zzzzzzzzz";
	long a=0,b=0;
	for(long i=l;i<=r;i++){
		if(A[a].name >= B[b].name){
			array[i]=B[b];
			b++;
		}else{
			array[i]=A[a];
			a++;
		}
		//printf("%d ",array[i]);
	}
}
void mergeSort1(vector<studentrecord> &array,long l,long r){
	if(l==r){
		return;  
	}else{
		int p=(l+r)/2;
		mergeSort1(array,l,p);
		mergeSort1(array,p+1,r);
		merge1(array,l,r);
	}
}

//================================================MERGE SORT 2
void merge2(vector<studentrecord> &array,long l,long r){
	long p=(l+r)/2;
	long x=p-l+1;
	long y=r-p;
	studentrecord A[x+1],B[y+1];
	for(long i=0;i<x;i++){
		A[i]=array[l+i];
	}
	A[x].course="AAAAAAAAA";
	for(long i=0;i<y;i++){
		B[i]=array[p+1+i];
	}
	B[y].course = "AAAAAAAAAA";
	long a=0,b=0;
	for(long i=l;i<=r;i++){
		if(A[a].course <= B[b].course){
			array[i]=B[b];
			b++;
		}else{
			array[i]=A[a];
			a++;
		}
		//printf("%d ",array[i]);
	}
}
void mergeSort2(vector<studentrecord> &array,long l,long r){
	if(l==r){
		return;  
	}else{
		int p=(l+r)/2;
		mergeSort2(array,l,p);
		mergeSort2(array,p+1,r);
		merge2(array,l,r);
	}
}


//================================================MERGE SORT 3

void merge3(vector<studentrecord> &array,long l,long r){
	long p=(l+r)/2;
	long x=p-l+1;
	long y=r-p;
	studentrecord A[x+1],B[y+1];
	for(long i=0;i<x;i++){
		A[i]=array[l+i];
	}
	A[x].grade="FG";
	for(long i=0;i<y;i++){
		B[i]=array[p+1+i];
	}
	B[y].grade = "FG";
	long a=0,b=0;
	for(long i=l;i<=r;i++){
		if(credit[A[a].grade] <= credit[B[b].grade]){
			array[i]=B[b];
			b++;
		}else{
			array[i]=A[a];
			a++;
		}
		//printf("%d ",array[i]);
	}
}
void mergeSort3(vector<studentrecord> &array,long l,long r){
	if(l==r){
		return;  
	}else{
		int p=(l+r)/2;
		mergeSort3(array,l,p);
		mergeSort3(array,p+1,r);
		merge3(array,l,r);
	}
}


//================================================READ FUNCTION START


void readGrades(){
    ifstream ip("grades01.csv");
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

void readname2(){
    ifstream ip("students01.csv");
    if(!ip.is_open()) cout<<"ERROR: can't open students.csv";
    while(ip.good()){
        string nm,rol;
        getline(ip,nm,',');
        getline(ip,rol,'\n');
        rollName[rol] = nm;
        // cout<<"yes\n";
    }
    ip.close();
}

void readCources(){
    ifstream ip("courses01.csv");
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
    for(auto x:rollName){
        string roll = x.F;
        
        string st = x.S;
        
        forv(j,0,localgrades[roll].size()){
            course cc = coursemap[localgrades[roll][j].F];
            studentrecord ss;
            ss.name = st;
            ss.course = cc.name;
            ss.grade = localgrades[roll][j].S;
            array2.PB(ss);
            array3.PB(ss);
            // cout<<ss.name<<" "<<ss.course<<" "<<ss.grade<<'\n';
        }
    }
}

void firstOperation(){
    mergeSort1(array2,0,array2.size()-1);
    quickSort1(array3,0,array3.size()-1);
}
void secondOperation(){
    long start=0;
    for(long i=0;i<array2.size();i++){
        while(array2[i].name == array2[start].name){
            i++;
        }
        mergeSort2(array2,start,i-1);
        start = i;
    }
    start=0;
    for(long i=0;i<array3.size();i++){
        while(array3[i].name == array3[start].name){
            i++;
        }
        quickSort2(array3,start,i-1);
        start = i;
    }
    // for(studentrecord x:array2){
    //     cout<<x.name<<","<<x.course<<","<<x.grade<<'\n';
    // }
}
void thirdOperation(){
    // freopen("input.txt", "r", stdin);
    freopen("grades-sorted-M.csv", "w", stdout);
    long start=0;
    for(long i=0;i<array2.size();i++){
        while(array2[i].course == array2[start].course){
            i++;
        }
        mergeSort3(array2,start,i-1);
        start = i;
    }
    
    for(studentrecord x:array2){
        
        cout<<x.name<<","<<x.course<<","<<x.grade<<'\n';
    }
    freopen("grades-sorted-Q.csv", "w", stdout);
    start=0;
    for(long i=0;i<array3.size();i++){
        while(array3[i].course == array3[start].course){
            i++;
        }
        quickSort3(array3,start,i-1);
        start = i;
    }
    
    for(studentrecord x:array3){
        cout<<x.name<<","<<x.course<<","<<x.grade<<'\n';
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
    credit["FF"] = 0;
    credit["FG"] = -1;

    readCources();
    readGrades();
    // readUsername();
    readname2();
    generateTranscript();
    firstOperation();
    secondOperation();
    thirdOperation();

    return 0;
}