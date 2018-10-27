/*


               2048 GAME


    Created by Vishal Bachchas 2K16/SE/092

*/
#include <stdio.h>
#include "cstdlib"
#include "iostream"
#include "cstring"
#include <ncurses.h>
#include <stack>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
 
void up(long long int arrarrary[])
{
    for (long long int i = 0; i < 3; ++i)
    {
        for (long long int j = 0; j < 2; ++j)
        {
            if (arrarrary[3*j+i])
            {
                long long int start=i+3*j+3;
                while(true)
                {
                    if (arrarrary[start])
                    {
                        if (arrarrary[start]==arrarrary[i+3*j])
                        {
                            arrarrary[i+3*j]*=2;
                            arrarrary[start]=0;
                        }
                        else break;
                    }
                    else start+=3;
                    
                    if (start > 9)
                    {
                        break;
                    }
                }
            }
            else
            {
                long long int start=i+3*j+3;
                while(start < 9)
                {
                    if (arrarrary[start])
                    {
                        arrarrary[i+3*j]=arrarrary[start];
                        arrarrary[start]=0;
                        break;
                    }
                    start+=3;
                }
            }
        }
    }
}
 
void down(long long int *arrarrary)
{
    for (long long int i = 0; i < 3; ++i)
    {
        for (long long int j = 2; j > 0 ; --j)
        {
            long long int cur=3*j+i;
            long long int start=3*j+i-3;
 
            if (arrarrary[cur])
            {
                while(start>=0)
                {
                    if (arrarrary[start])
                    {
                        if (arrarrary[start]==arrarrary[cur])
                        {
                            arrarrary[cur]*=2;
                            arrarrary[start]=0;
                        }
                        break;
                    }
                    else start-=3;
                }
            }
            else
            {
                while(start>=0)
                {
                    if (arrarrary[start])
                    {
                        arrarrary[cur]=arrarrary[start];
                        arrarrary[start]=0;
                        break;
                    }
                    start-=3;
                }
            }
        }
    }
}
 
void left(long long int *arrarrary)
{
    for (long long int i = 0; i < 3; ++i)
    {
        for (long long int j = 0; j < 2; ++j)
        {
            long long int cur=i*3+j;
            long long int start=3*i+j+1;
 
            if (arrarrary[cur])
            {
                while(start<=3*i+2)
                {
                    if (arrarrary[start])
                    {
                        if (arrarrary[start]==arrarrary[cur])
                        {
                            arrarrary[cur]*=2;
                            arrarrary[start]=0;
                        }
                        break;
                    }
                    start++;
                }
            }
            else
            {
                while(start<=3*i+2)
                {
                    if (arrarrary[start])
                    {
                        arrarrary[cur]=arrarrary[start];
                        arrarrary[start]=0;
                        break;
                    }
                    start++;
                }
            }
        }
    }
}
 
void right(long long int *arrarrary)
{
    for (long long int i = 0; i < 3; ++i)
    {
        for (long long int j = 2; j >0 ; --j)
        {
            long long int cur=i*3+j;
            long long int start=cur-1;
 
            if (arrarrary[cur])
            {
                while(start>=i*3)
                {
                    if (arrarrary[start])
                    {
                        if (arrarrary[start]==arrarrary[cur])
                        {
                            arrarrary[cur]*=2;
                            arrarrary[start]=0;
                        }
 
                        break;
                    }
                    start--;
                }
            }
            else
            {
                while(start>=3*i)
                {
                    if (arrarrary[start])
                    {
                        arrarrary[cur]=arrarrary[start];
                        arrarrary[start]=0;
                        break;
                    }
                    start--;
                }
            }
        }
    }
}

bool check(long long int *arrarrary)
{
    bool flag=false;


    for(long long int j=0;j<4;j++)
    {    
        long long int temp[9];
        for (long long int i = 0; i < 9; ++i)
        {
            temp[i]=arrarrary[i];
        }


        if (j==0)
        {
            up(temp);
            for (long long int i = 0; i < 9; ++i)
            {
                if (temp[i]!=arrarrary[i])
                {
                    return true;
                }
            }
        }
        if (j==1)
        {
            down(temp);
            for (long long int i = 0; i < 9; ++i)
            {
                if (temp[i]!=arrarrary[i])
                {
                    return true;
                }
            }
        }
        if (j==2)
        {
            left(temp);
            for (long long int i = 0; i < 9; ++i)
            {
                if (temp[i]!=arrarrary[i])
                {
                   return true;
                }
            }
        }
        if (j==3)
        {
            right(temp);
            for (long long int i = 0; i < 9; ++i)
            {
                if (temp[i]!=arrarrary[i])
                {
                    return true;
                }
            }
        }
    }

    return false;
}



long long int main()
{
    //prlong long intf("                     2048                  ");
    initscr();
    noecho();
    long long long long int sco=0;
    mvprlong long intw(5,58," 1024 ");
    mvprlong long intw(25,18," Press W for UPSHIFT ");
    mvprlong long intw(28,18," Press S for DOWNSHIFT ");
    mvprlong long intw(31,18," Press A for LEFTSHIFT ");
    mvprlong long intw(34,18," Press D for RIGHTSHIFT ");
    mvprlong long intw(37,18," Press Q for UNDO ");
    
    WINDOW *lboard=newwin(25,25,10,85);
    refresh();
    box(lboard,0,0);
    mvwprlong long intw(lboard,1,1,"      LEADERBOARD");
    mvwprlong long intw(lboard,2,1," RANK  USERNAME  sco");
    mvwprlong long intw(lboard,3,1," ");
    mvwprlong long intw(lboard,4,1," 1     @nikhil25  1890");
    mvwprlong long intw(lboard,5,1," 2     @dhruv167  1650");
    mvwprlong long intw(lboard,6,1," 3     @naman123  1000");
    wrefresh(lboard);
    getch();
    WINDOW *win[10];
    long long int height=4,width=8,x=50,y=10;
    for(long long int i=1;i<=9;i++)
    {
        win[i]=newwin(height,width,y,x);
        x+=7;
        if(i%3==0)
        {
            y+=3;
            x=50;
        }
    }
    refresh();
 
    for (long long int i = 1; i <=9; ++i)
    {
        box(win[i],0,0);
        wrefresh(win[i]);
    }
 
    long long int arrarrary[9];
    memset(arrarrary,0,sizeof(arrarrary));
    long long int Randindex;
    Randindex=rand()%9;
    arrarrary[Randindex]=2;
    mvwprlong long intw(win[Randindex+1],1,3,"2");
    wrefresh(win[Randindex+1]);
    long long int size=8;
    stack<vector<long long int> > st;

    while(true)
    {
        char c=getch();

        if (size==0)
        {     
            if(!check(arrarrary))
                break;
        }


        for (long long int i = 1; i <=9; ++i)
        {
            wclear(win[i]);
        }
        for (long long int i = 1; i <=9; ++i)
        {
            box(win[i],0,0);
            wrefresh(win[i]);
        }
       
        if (c=='W' || c=='w')
        {
            up(arrarrary);
        }
        else if(c=='S' || c=='s')
        {
            down(arrarrary);
        }
        else if(c=='A' || c=='a')
        {
            left(arrarrary);
        }
        else if(c=='D' || c=='d')
        {
            right(arrarrary);
        }
        else if(c=='Q' || c=='q')     //UNDO CONDITION
        {
            if (!st.empty())
            {
                vector<long long int> v;
                v=st.top();
                st.pop();
                for (long long int i = 0; i < 9; ++i)
                {
                    arrarrary[i]=v[i];
                }
 
 
                for(long long int i=1;i<=9;i++)
                {
                    if(arrarrary[i-1])
                    {    
                        mvwprlong long intw(win[i],1,3,"%d",arrarrary[i-1]);
                        sco+=arrarrary[i-1];
                    }
                    else
                        mvwprlong long intw(win[i],1,3," ");
                    wrefresh(win[i]);
                }
            }
 
            continue;
        }
 
        long long int a[10];
        long long int k=0;
        for (long long int i = 0; i < 9; ++i)
        {
            if (!arrarrary[i])
            {
                a[k++]=i;
            }
        }
 
        if (k!=0)
        {
            Randindex=rand()%k;
            arrarrary[a[Randindex]]=2;
            size=k-1;
        }
       
        vector<long long int> v;
        for (long long int i = 0; i < 9; ++i)
        {
            v.push_back(arrarrary[i]);  
        }
        st.push(v);
 
        for(long long int i=1;i<=9;i++)
        {
            if(arrarrary[i-1])
            {
                mvwprlong long intw(win[i],1,3,"%d",arrarrary[i-1]);
                sco+=arrarrary[i-1];
            }
            else
            {   
                mvwprlong long intw(win[i],1,3," ");
                sco+=arrarrary[i-1];
            }
            wrefresh(win[i]);
            refresh();
        }
        mvprlong long intw(10,10,"sco : %d",sco);
        refresh();
    }
    getch();
    mvprlong long intw(30,58,"GAME OVER!!!!!");
    WINDOW *Over=newwin(15,40,25,50);
    box(Over,0,0);
    mvwprlong long intw(Over,26,51,"Enter your name : ");
    wrefresh(Over);

    getch();
    endwin();
    return 0;
}
