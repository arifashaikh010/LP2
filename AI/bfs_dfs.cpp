#include<iostream>
#include<string>
#include<queue>
using namespace std;
int admj[50][50]={0,0};
int visited[50]={0};
void dfs(int s, int v, string arr[])
{
    visited[s]=true;
    cout<<arr[s]<<" ";
    for (int i=0; i<v; i++)
    {
        if (admj[s][i] && !visited[i] )
        {
            dfs(i,v,arr);
        }
    }
}
void bfs(int s, int v, string arr[])
{
    bool visited[v];
    for (int i=0; i<v; i++)
    {
        visited[i]=false;
    }
int v2;
queue<int>bfsq;
if(!visited[s])
{
cout<<arr[s]<<" ";
visited[s]=true;
bfsq.push(s);
while(!bfsq.empty())
{
v2=bfsq.front();
for (int i=0; i<v; i++)
{
if (admj[v2][i] && !visited[i] )
{
cout<<arr[i]<<" ";
visited[i]=true;
bfsq.push(i);
}
}
bfsq.pop();
}
}
}
int main()
{
int v1,c;
cout<<"Enter the number of vertices :";
cin>>v1;
string city[v1];
for (int i=0; i<v1; i++)
{
cout<<"Enter the name of the vertices :"<<" ";cin>>city[i];
}
cout<<"Enter the distance between cities :";
for (int i=0; i<v1; i++)
{
for (int j=i+1; j<v1; j++)
{
cout<<"\nEnter 1 if edge exists between "<<city[i]<<" and "<<city[j]<<": ";
cin>>c;
admj[i][j]=admj[j][i]=c;
}
}
cout<<endl;
for (int i=0; i<v1; i++)
{
cout<<"\t"<<city[i];
}
cout<<endl;
for (int i=0; i<v1; i++)
{
cout<<city[i]<<"\t";
for (int j=0; j<v1; j++)
{
cout<<admj[i][j]<<"\t";
}
cout<<endl;
}
cout<<"Enter the starting vertex ";
int n; 
cin>>n;
cout<<"DFS" <<endl;
dfs(n,v1,city);
cout<<endl;
cout<<"BFS"<<endl;
bfs(n,v1,city);
return 0;
}
/*
Output 1 :
Enter the number of vertices :7
Enter the name of the vertices : A
Enter the name of the vertices : B
Enter the name of the vertices : C
Enter the name of the vertices : D
Enter the name of the vertices : E
Enter the name of the vertices : F
Enter the name of the vertices : G
Enter the distance between cities :
Enter 1 if edge exists between A and B: 1

Enter 1 if edge exists between A and C: 1

Enter 1 if edge exists between A and D: 0

Enter 1 if edge exists between A and E: 0

Enter 1 if edge exists between A and F: 0

Enter 1 if edge exists between A and G: 0

Enter 1 if edge exists between B and C: 0

Enter 1 if edge exists between B and D: 1

Enter 1 if edge exists between B and E: 1

Enter 1 if edge exists between B and F: 0

Enter 1 if edge exists between B and G: 0

Enter 1 if edge exists between C and D: 0

Enter 1 if edge exists between C and E: 0

Enter 1 if edge exists between C and F: 1

Enter 1 if edge exists between C and G: 1

Enter 1 if edge exists between D and E: 0

Enter 1 if edge exists between D and F: 0

Enter 1 if edge exists between D and G: 0

Enter 1 if edge exists between E and F: 0

Enter 1 if edge exists between E and G: 0

Enter 1 if edge exists between F and G: 0

        A       B       C       D       E       F       G
A       0       1       1       0       0       0       0
B       1       0       0       1       1       0       0
C       1       0       0       0       0       1       1
D       0       1       0       0       0       0       0
E       0       1       0       0       0       0       0
F       0       0       1       0       0       0       0
G       0       0       1       0       0       0       0
Enter the starting vertex A
DFS
A B D E C F G
BFS
A B C D E F G

-------------------------------------------------------------------------------------------------------

Output 2 :
Enter the number of vertices :11
Enter the name of the vertices : A
Enter the name of the vertices : B
Enter the name of the vertices : C
Enter the name of the vertices : D
Enter the name of the vertices : E
Enter the name of the vertices : F
Enter the name of the vertices : G
Enter the name of the vertices : H
Enter the name of the vertices : I
Enter the name of the vertices : J
Enter the name of the vertices : K
Enter the distance between cities :
Enter 1 if edge exists between A and B: 1

Enter 1 if edge exists between A and C: 1

Enter 1 if edge exists between A and D: 0

Enter 1 if edge exists between A and E: 0

Enter 1 if edge exists between A and F: 0

Enter 1 if edge exists between A and G: 0

Enter 1 if edge exists between A and H: 0

Enter 1 if edge exists between A and I: 0

Enter 1 if edge exists between A and J: 0

Enter 1 if edge exists between A and K: 0

Enter 1 if edge exists between B and C: 0

Enter 1 if edge exists between B and D: 1

Enter 1 if edge exists between B and E: 1

Enter 1 if edge exists between B and F: 0

Enter 1 if edge exists between B and G: 0

Enter 1 if edge exists between B and H: 0

Enter 1 if edge exists between B and I: 0

Enter 1 if edge exists between B and J: 00

Enter 1 if edge exists between B and K: 0

Enter 1 if edge exists between C and D: 0

Enter 1 if edge exists between C and E: 0

Enter 1 if edge exists between C and F: 1

Enter 1 if edge exists between C and G: 1

Enter 1 if edge exists between C and H: 0

Enter 1 if edge exists between C and I: 0

Enter 1 if edge exists between C and J: 0

Enter 1 if edge exists between C and K: 0

Enter 1 if edge exists between D and E: 0

Enter 1 if edge exists between D and F: 0

Enter 1 if edge exists between D and G: 0

Enter 1 if edge exists between D and H: 1

Enter 1 if edge exists between D and I: 1

Enter 1 if edge exists between D and J: 0

Enter 1 if edge exists between D and K: 0

Enter 1 if edge exists between E and F: 0

Enter 1 if edge exists between E and G: 0

Enter 1 if edge exists between E and H: 0

Enter 1 if edge exists between E and I: 0

Enter 1 if edge exists between E and J: 1

Enter 1 if edge exists between E and K: 1

Enter 1 if edge exists between F and G: 0

Enter 1 if edge exists between F and H: 0

Enter 1 if edge exists between F and I: 0

Enter 1 if edge exists between F and J: 0

Enter 1 if edge exists between F and K: 0

Enter 1 if edge exists between G and H: 0

Enter 1 if edge exists between G and I: 0

Enter 1 if edge exists between G and J: 0

Enter 1 if edge exists between G and K: 0

Enter 1 if edge exists between H and I: 0

Enter 1 if edge exists between H and J: 0

Enter 1 if edge exists between H and K: 0

Enter 1 if edge exists between I and J: 00

Enter 1 if edge exists between I and K: 0

Enter 1 if edge exists between J and K: 0

        A       B       C       D       E       F       G       H       I       J       K
A       0       1       1       0       0       0       0       0       0       0       0
B       1       0       0       1       1       0       0       0       0       0       0
C       1       0       0       0       0       1       1       0       0       0       0
D       0       1       0       0       0       0       0       1       1       0       0
E       0       1       0       0       0       0       0       0       0       1       1
F       0       0       1       0       0       0       0       0       0       0       0
G       0       0       1       0       0       0       0       0       0       0       0
H       0       0       0       1       0       0       0       0       0       0       0
I       0       0       0       1       0       0       0       0       0       0       0
J       0       0       0       0       1       0       0       0       0       0       0
K       0       0       0       0       1       0       0       0       0       0       0
Enter the starting vertex A
DFS
A B D H I E J K C F G
BFS
A B C D E F G H I J K
*/