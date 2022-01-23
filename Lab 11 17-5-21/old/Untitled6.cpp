#include <iostream>
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

int main() {
  int choice;
  int i,j,k,n,m,sum=0,x,y,h,temp,ele,count;
  vector <int> a(n),b,l;
  map <int,int> mp;
  cout << "Enter 1 for SCAN,2 for FCFS,3 for SSTF,4 for CSCAN,5 for LOOK,6 for CLOOK \n";
  cin>>choice;
  switch (choice) {
  case 1://SCAN
  system("cls");
   cout<<"Enter the size of disk\n";
    cin>>m;
    cout<<"Enter number of requests\n";
    cin>>n;
    cout<<"Enter the requests\n";
    //vector <int> a(n),b;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        if(a[i]>m){
            cout<<"Error, Unknown position "<<a[i]<<"\n";
            return 0;
        }
    }
    cout<<"Enter the head position\n";
    cin>>h;
    //int temp=h;
    temp=h;
    a.push_back(h);
    a.push_back(m);
    a.push_back(0);
    sort(a.begin(),a.end());
    for(i=0;i<a.size();i++){
        if(h==a[i])
            break;
    }
    k=i;
    if(k<n/2){
        for(i=k;i<a.size();i++){
            b.push_back(a[i]);
        }
        for(i=k-1;i>=0;i--){
            b.push_back(a[i]);
        }
    }
    else{    
        for(i=k;i>=0;i--){
            b.push_back(a[i]);
        }
        for(i=k+1;i<a.size();i++){
            b.push_back(a[i]);
        }
    }
    temp=b[0];
    cout<<temp;
    for(i=1;i<b.size();i++){
        cout<<" -> "<<b[i];
        sum+=abs(b[i]-temp);
        temp=b[i];
    }
    cout<<'\n';
    cout<<"Total head movements = "<< sum<<'\n';
    cout<<"Average head movement = "<<(float)sum/n<<'\n';
    break;
  case 2://FCFS
  system("cls");
     cout<<"Enter the size of disk\n";
    cin>>m;
    cout<<"Enter number of requests\n";
    cin>>n;
    cout<<"Enter the requests\n";

    // creating an array of size n
    //vector <int> a(n);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        if(a[i]>m){
            cout<<"Error, Unknown position "<<a[i]<<"\n";
            return 0;
        }
    }
    cout<<"Enter the head position\n";
    cin>>h;
    
    // head will be at h at the starting
    temp=h;
    cout<<temp;
    for(i=0;i<n;i++){
        cout<<" -> "<<a[i]<<' ';
        // calculating the difference for the head movement
        sum+=abs(a[i]-temp);
        // head is now at the next I/O request
        temp=a[i];
    }
    cout<<'\n';
    cout<<"Total head movements = "<< sum<<'\n';
    break;
  case 3://SSTF
  system("cls");
    cout<<"Enter the size of disk\n";
    cin>>m;
    cout<<"Enter number of requests\n";
    cin>>n;
    cout<<"Enter the requests\n";

    //creating two arrays, array a will store the input
    //I/O requests and array b will store the output
    //vector <int> a(n),b;

    //creating a map to store the count of each element
    //in the array a.
    //map <int,int> mp;
    for(i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    for(i=0;i<n;i++){
        if(a[i]>m){
            cout<<"Error, Unknown position "<<a[i]<<"\n";
            return 0;
        }
    }
    cout<<"Enter the head position\n";
    cin>>h;
    //int temp=h;
    temp=h;
    //int ele;
    b.push_back(h);
    //int count=0;
    count=0;
    while(count<n){
        //initially taking diff to be very large.
        int diff=999999;

        //traversing in map to find the least difference
        for(auto q:mp){
            if(abs(q.first-temp)<diff){
                ele=q.first;
                diff=abs(q.first-temp);
            }
        }
        //deleting the element that has the least
        //difference from the map
        mp[ele]--;
        if(mp[ele]==0){
            mp.erase(ele);
        }
        //adding that element to our output array.
        b.push_back(ele);
        temp=ele;
        count++;
    }

    //printing the output array
    cout<<b[0];
    temp=b[0];
    for(i=1;i<b.size();i++){
        cout<<" -> "<<b[i];
        sum+=abs(b[i]-temp);
        temp=b[i];
    }
    cout<<'\n';
    cout<<"Total head movements = "<< sum<<'\n';
    cout<<"Average head movement = "<<(float)sum/n<<'\n';
    break;
  case 4://CSCAN
    //int i,j,k,n,m,sum=0,x,y,h;
    system("cls");
    cout<<"Enter the size of disk\n";
    cin>>m;
    cout<<"Enter number of requests\n";
    cin>>n;
    cout<<"Enter the requests\n";
    //vector <int> a(n),b;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        if(a[i]>m){
            cout<<"Error, Unknown position "<<a[i]<<"\n";
            return 0;
        }
    }
    cout<<"Enter the head position\n";
    cin>>h;
    //int temp=h;
    temp=h;
    a.push_back(h);
    a.push_back(m);
    a.push_back(0);
    sort(a.begin(),a.end());
    for(i=0;i<a.size();i++){
        if(h==a[i])
            break;
    }
    k=i;
    if(k<n/2){
        for(i=k;i<a.size();i++){
            b.push_back(a[i]);
        }
        for(i=0;i<=k-1;i++){
            b.push_back(a[i]);
        }
    }
    else{    
        for(i=k;i>=0;i--){
            b.push_back(a[i]);
        }
        for(i=a.size()-1;i>=k+1;i--){
            b.push_back(a[i]);
        }
    }
    temp=b[0];
    cout<<temp;
    for(i=1;i<b.size();i++){
        cout<<" -> "<<b[i];
        sum+=abs(b[i]-temp);
        temp=b[i];
    }
    cout<<'\n';
    cout<<"Total head movements = "<< sum<<'\n';
    cout<<"Average head movement = "<<(float)sum/n<<'\n';
    break;
  case 5://LOOK
    //int i,j,k,n,m,sum=0,x,y,h;
    system("cls");
    cout<<"Enter the size of disk\n";
    cin>>m;
    cout<<"Enter number of requests\n";
    cin>>n;
    cout<<"Enter the requests\n";
    //vector <int> a(n),l;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        if(a[i]>m){
            cout<<"Error, Unknown position\n";
            return 0;
        }
    }
    cout<<"Enter the head position\n";
    cin>>h;

    a.push_back(h);
    sort(a.begin(),a.end());

    for(i=0;i<a.size();i++){
        if(h==a[i])
            break;
    }
    k=i;
    if(k<n/2){
        for(i=k;i<a.size();i++){
            l.push_back(a[i]);
        }
        for(i=k-1;i>=0;i--){
            l.push_back(a[i]);
        }
    }
    else{
        for(i=k;i>=0;i--){
            l.push_back(a[i]);
        }
        for(i=k+1;i<a.size();i++){
            l.push_back(a[i]);
        }
    }
    //int temp=l[0];
    temp=l[0];
    cout<<temp;
    for(i=1;i<l.size();i++){
        cout<<" -> "<<l[i]<<' ';
        sum+=abs(l[i]-temp);
        temp=a[i];
    }
    cout<<'\n';
    cout<<"Total head movements = "<< sum<<'\n';
    break;
  case 6://CLOOK
  system("cls");
     int i,j,k,n,m,sum=0,x,y,h;
    cout<<"Enter the size of disk\n";
    cin>>m;
    cout<<"Enter number of requests\n";
    cin>>n;
    cout<<"Enter the requests\n";
    vector <int> a(n),l;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        if(a[i]>m){
            cout<<"Error, Unknown position\n";
            return 0;
        }
    }
    cout<<"Enter the head position\n";
    cin>>h;

    a.push_back(h);
    sort(a.begin(),a.end());

    for(i=0;i<a.size();i++){
        if(h==a[i])
            break;
    }
    k=i;
    if(k<n/2){
        for(i=k;i<a.size();i++){
            l.push_back(a[i]);
        }
        for(i=0;i<k;i++){
            l.push_back(a[i]);
        }
    }
    else{
        for(i=k;i>=0;i--){
            l.push_back(a[i]);
        }
        for(i=a.size()-1;i>k;i--){
            l.push_back(a[i]);
        }
    }
    int temp=l[0];
    cout<<temp;
    for(i=1;i<l.size();i++){
        cout<<" -> "<<l[i]<<' ';
        sum+=abs(l[i]-temp);
        temp=a[i];
    }
    cout<<'\n';
    cout<<"Total head movements = "<< sum<<'\n';
   break;
  }
  return 0;
}
