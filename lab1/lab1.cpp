#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace __gnu_pbds;
using namespace std;

#define forz(n) for (long i = 0; i < n; i++)
#define forv(i,x,y) for (long i=x; i<y; i++)
#define rforz(a,n) for (long i = a; i < n; i++)

struct data{
    string type;
    string value;
    double t1;
    double t2;
};

vector<struct data> A,B;

//========================================================================QUICK SORT

long partition (vector<long> &arr,long low,long high)
{
    long pivot = arr[high];  
 
    long i = (low - 1);  

    for (long j = low; j <= high- 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++;    // increment index of smaller element
            swap( arr[i], arr[j]);
        }
    }
    swap( arr[i + 1] , arr[high]);
    return (i + 1);
}
 
void quickSort(vector<long> &arr,long low,long high){
    if (low < high)
    {
        long pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);  // Before pi
        quickSort(arr, pi + 1, high); // After pi
    }
}
//===================================================================quick sort for double
long partition_d (vector<double> &arr,long low,long high)
{
    double pivot = arr[high];  
 
    long i = (low - 1);  

    for (long j = low; j <= high- 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++;    // increment index of smaller element
            swap( arr[i], arr[j]);
        }
    }
    swap( arr[i + 1] , arr[high]);
    return (i + 1);
}
 
void quickSort_d(vector<double> &arr,long low,long high){
    if (low < high)
    {
        long pi = partition_d(arr, low, high);
        quickSort_d(arr, low, pi - 1);  // Before pi
        quickSort_d(arr, pi + 1, high); // After pi
    }
}
//========================================================================MERGE SORT

void merge(vector<long> &array,long l,long r){
	long p=(l+r)/2;
	long x=p-l+1;
	long y=r-p;
	long A[x+1],B[y+1];
	for(long i=0;i<x;i++){
		A[i]=array[l+i];
	}
	A[x]=9999999;
	for(long i=0;i<y;i++){
		B[i]=array[p+1+i];
	}
	B[y]=9999999;
	long a=0,b=0;
	for(long i=l;i<=r;i++){
		if(A[a]>=B[b]){
			array[i]=B[b];
			b++;
		}else{
			array[i]=A[a];
			a++;
		}
		//printf("%d ",array[i]);
	}
}
void mergeSort(vector<long> &array,long l,long r){
	if(l==r){
		return;  
	}else{
		int p=(l+r)/2;
		mergeSort(array,l,p);
		mergeSort(array,p+1,r);
		merge(array,l,r);
	}
}
//=================================================================merge sort for double
void merge_d(vector<double> &array,long l,long r){
	long p=(l+r)/2;
	long x=p-l+1;
	long y=r-p;
	double A[x+1],B[y+1];
	for(long i=0;i<x;i++){
		A[i]=array[l+i];
	}
	A[x]=9999999.0;
	for(long i=0;i<y;i++){
		B[i]=array[p+1+i];
	}
	B[y]=9999999.0;
	long a=0,b=0;
	for(long i=l;i<=r;i++){
		if(A[a]>=B[b]){
			array[i]=B[b];
			b++;
		}else{
			array[i]=A[a];
			a++;
		}
		//printf("%d ",array[i]);
	}
}
void mergeSort_d(vector<double> &array,long l,long r){
	if(l==r){
		return;  
	}else{
		int p=(l+r)/2;
		mergeSort_d(array,l,p);
		mergeSort_d(array,p+1,r);
		merge_d(array,l,r);
	}
}

//========================================================================RANDOM SINGLE STRING GENERATOR

string geneString(){
    string x="";
    
    for(int i=0;i<10;i++){
        int a = rand()%26;
        char z = a+'a';
        x += z;
    }
    return x;
}

//========================================================================RANDOM INT GENERATOR IN FILE

void generateInputFileInt(int i,string &s){
    int l = s.length();
    long x = i*10000;
    char m[l+1];
    for(int i=0;i<l;i++){
        m[i] = s[i];
    }
    m[l] = '\0';
    freopen((char*)m, "w", stdout);
    for(long j=0;j<x;j++){
        long z = rand()%1000000;
        cout<<z<<'\n';
    }
    // cout<<m<<'\n';
}

//========================================================================RANDOM STRING GENERATOR IN FILE


void generateInputFileString(int i,string s){
    int l = s.length();
    long x = i*10000;
    char m[l+1];
    for(int i=0;i<l;i++){
        m[i] = s[i];
    }
    m[l] = '\0';
    freopen((char*)m, "w", stdout);
    for(long j=0;j<x;j++){
        string z = geneString();
        cout<<z<<'\n';
    }
}

//========================================================================RANDOM FLOAT GENERATOR IN FILE

void generateInputFileFloat(int i,string s){
    int l = s.length();
    long x = i*10000;
    char m[l+1];
    for(int i=0;i<l;i++){
        m[i] = s[i];
    }
    m[l] = '\0';
    freopen((char*)m, "w", stdout);
    for(long j=0;j<x;j++){
        double z = ((rand())*0.1/((long)RAND_MAX))*10000;
        cout<<z<<'\n';
    }
}

void generateInt(){
    
    for(int i=0;i<10;i++){
        string str="i";
        int x = 1<<i;
        str+=to_string(x*10);
        str+="k.txt";

        generateInputFileInt(x,str);
    }
}

//========================================================================READ INT FILE AND SORT

void push_sorted_int_infile(vector<long> arr,int i){
    i = i;
    string str="qi";
    int x = 1<<i;
    str+=to_string(x*10);
    str+="k.txt";
    int l = str.length();
    long tt = (x)*10000;
    char m[l+1];
    for(long i=0;i<l;i++){
        m[i] = str[i];
    }
    m[l] = '\0';
    freopen(m, "w", stdout);
    forz(tt){
        cout<<arr[i]<<'\n';
    }

}

void push_sorted_int_infile_m(vector<long> arr,int i){
    i = i;
    string str="mi";
    int x = 1<<i;
    str+=to_string(x*10);
    str+="k.txt";
    int l = str.length();
    long tt = (x)*10000;
    char m[l+1];
    for(long i=0;i<l;i++){
        m[i] = str[i];
    }
    m[l] = '\0';
    freopen(m, "w", stdout);
    forz(tt){
        cout<<arr[i]<<'\n';
    }

}

void readSortInt(){
    forz(7){
        string str="i";
        int x = 1<<i;
        str+=to_string(x*10);
        str+="k.txt";
        int l = str.length();
        long tt = (x)*10000;
        char m[l+1];
        for(int i=0;i<l;i++){
            m[i] = str[i];
        }
        m[l] = '\0';
        freopen(m, "r", stdin);
        vector<long> arr1,arr2;
        forz(tt){
            long temp;
            cin>>temp;
            arr1.push_back(temp);
            arr2.push_back(temp);
        }
        clock_t c1 = clock();
        quickSort(arr1,0,tt-1);
        clock_t c2 = clock();
        double zzz1 = ((c2-c1)*0.1)/100000 ;
       
        mergeSort(arr2,0,tt-1);
        clock_t c3 = clock();
        double zzz2 = ((c3-c2)*0.1)/100000;
        
        push_sorted_int_infile(arr1,i);
        clock_t c4 = clock();
        double zzz3 = ((c4-c3)*0.1)/100000;
        struct data p3;
        p3.type = "Integer";
        p3.value = to_string(x) + "0K";
        p3.t1 = zzz1;
        p3.t2 = zzz1 + zzz3;
        push_sorted_int_infile_m(arr2,i);
        clock_t c5 = clock();
        double zzz4 = ((c5-c4)*0.1)/100000;
        struct data p4;
        p4.type = "Integer";
        p4.value = to_string(x) + "0K";
        p4.t1 = zzz2;
        p4.t2 = zzz2 + zzz4;
        A.push_back(p3);
        B.push_back(p4);
    }
}
void generateString(){
    for(int i=0;i<10;i++){
        string str="s";
        int x = 1<<i;
        str+=to_string(x*10);
        str+="k.txt";

        generateInputFileString(x,str);
    }
}
//========================================================================READ STRING FILE AND SORT

void readSortString(){

}
void generateFloat(){
    for(int i=0;i<10;i++){
        string str="f";
        int x = 1<<i;
        str+=to_string(x*10);
        str+="k.txt";

        generateInputFileFloat(x,str);
    }
}

void push_sorted_int_infile_forfloat(vector<double> arr,int i){
    i = i;
    string str="qi";
    int x = 1<<i;
    str+=to_string(x*10);
    str+="k.txt";
    int l = str.length();
    long tt = (x)*10000;
    char m[l+1];
    for(long i=0;i<l;i++){
        m[i] = str[i];
    }
    m[l] = '\0';
    freopen(m, "w", stdout);
    forz(tt){
        cout<<arr[i]<<'\n';
    }

}

void push_sorted_int_infile_m_forfloat(vector<double> arr,int i){
    i = i;
    string str="mi";
    int x = 1<<i;
    str+=to_string(x*10);
    str+="k.txt";
    int l = str.length();
    long tt = (x)*10000;
    char m[l+1];
    for(long i=0;i<l;i++){
        m[i] = str[i];
    }
    m[l] = '\0';
    freopen(m, "w", stdout);
    forz(tt){
        cout<<arr[i]<<'\n';
    }

}
void readSortFloat(){
    forz(7){
        string str="f";
        int x = 1<<i;
        str+=to_string(x*10);
        str+="k.txt";
        int l = str.length();
        long tt = (x)*10000;
        char m[l+1];
        for(int i=0;i<l;i++){
            m[i] = str[i];
        }
        m[l] = '\0';
        freopen(m, "r", stdin);
        vector<double> arr1,arr2;
        forz(tt){
            long temp;
            cin>>temp;
            arr1.push_back(temp);
            arr2.push_back(temp);
        }
        clock_t c1 = clock();
        quickSort_d(arr1,0,tt-1);
        clock_t c2 = clock();
        double zzz1 = ((c2-c1)*0.1)/100000 ;
       
        mergeSort_d(arr2,0,tt-1);
        clock_t c3 = clock();
        double zzz2 = ((c3-c2)*0.1)/100000;
        
        push_sorted_int_infile_forfloat(arr1,i);
        clock_t c4 = clock();
        double zzz3 = ((c4-c3)*0.1)/100000;
        struct data p3;
        p3.type = "Float";
        p3.value = to_string(x) + "0K";
        p3.t1 = zzz1;
        p3.t2 = zzz1 + zzz3;
        push_sorted_int_infile_m_forfloat(arr2,i);
        clock_t c5 = clock();
        double zzz4 = ((c5-c4)*0.1)/100000;
        struct data p4;
        p4.type = "Float";
        p4.value = to_string(x) + "0K";
        p4.t1 = zzz2;
        p4.t2 = zzz2 + zzz4;
        A.push_back(p3);
        B.push_back(p4);
    }
}

void final_output(){
    freopen("outputq.txt", "w", stdout);
    forz(A.size()){
        cout<<A[i].type<<" "<<A[i].value<<" "<<A[i].t1<<" "<<A[i].t2<<'\n';
    }
}
 
int main(){
    //=====================================code starts here
    generateInt();
    // readSortInt();
    generateString();
    generateFloat();
    // vector<long> arr = {5,4,7,8,5,6,9,4,1,2,3,6,5,9,8,15};
    // clock_t c = clock();
    // quickSort(arr,0,arr.size()-1);
    // mergeSort(arr,0,arr.size()-1);
    // for(long x:arr){
    //     cout<<x<<" ";
    // }
    // cout<<'\n';
    // cout<<clock()-c<<'\n';
    // final_output();
    return 0;
}