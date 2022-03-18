#ifndef TSP_H_INCLUDED
#define TSP_H_INCLUDED

#include<iostream>
#include<math.h>
#include<fstream>

#define NUM 48
#define T0 10000
#define T 0.95
#define Tf 0.01
#define IN_loop 10000

#define NINT(a) ((a) >= 0.0 ? (int)((a)+0.5) : (int)((a)-0.5))

double D_length[NUM][NUM]={0};

using namespace std;

struct path
{
    int citys[NUM];
    double length;
}D_bestpath;

struct point
{
    double x;
    double y;
}D_point[NUM];

void point_dist()     //read data file and get distance matrix from the point
{
    ifstream file_in("att48_me.txt");
    int i,j;
    double dist;

    for(j=0;j<NUM;j++)
    {
        file_in>>i;
        file_in>>D_point[i-1].x>>D_point[i-1].y;
    }

    for(i=0;i<NUM;i++)
    {
        for(j=i+1;j<NUM;j++)
        {
            dist = (D_point[i].x - D_point[j].x) * (D_point[i].x - D_point[j].x);
            dist += (D_point[i].y - D_point[j].y) * (D_point[i].y - D_point[j].y);
			// dividing 10 is specified in att48's documents
            D_length[i][j] = D_length[j][i] = NINT(sqrt(dist/10.0));
        }
    }
}

void init()
{
    int i;
    D_bestpath.length = 0;

    for(i=0;i<NUM;i++)
    {
        D_bestpath.citys[i] = i;
    }

    for(i=0;i<NUM-1;i++)
    {
        D_bestpath.length += D_length[i][i+1];
    }
    D_bestpath.length += D_length[NUM-1][0];
}

void copy_path(path orig_path, path *new_path)
{
    int i;
    for(i=0;i<NUM;i++)
    {
        new_path->citys[i] = orig_path.citys[i];
    }
    new_path->length = orig_path.length;
}

void reverse(path *p, int begin, int end)
{
	int i, j;
	int temp;
	for (i = begin, j = end; i < j; i++, j--)
	{
		temp = p->citys[i];
		p->citys[i] = p->citys[j];
		p->citys[j] = temp;
	}
}


void getnextpath(path p, path * new_path)
{
    int i,x=0,y=0;

    copy_path(p,new_path);
    do
    {
        x = rand()%NUM;
        y = rand()%NUM;
    }while(x==y);

    /*// first method
    temp=new_path->citys[x];
    new_path->citys[x]=new_path->citys[y];
    new_path->citys[y]=temp;*/

    //second method
    /*if(x>y){temp=x;x=y;y=temp;}
    for(i=x,j=y;i<j;i++,j--)
    {
        temp = new_path->citys[i];
        new_path->citys[i] = new_path->citys[j];
        new_path->citys[j] = temp;
    }*/

    //third method
    /*if(x>y){temp=x;x=y;y=temp;}
    temp = new_path->citys[x];
    for(i=x;i<y;i++)
    {
        //temp = new_path->citys[i];
        new_path->citys[i] = new_path->citys[i+1];
        //new_path->citys[i+1] = temp;
    }
    new_path->citys[y]=temp;*/

    //forth method
    if(x<y) { reverse(new_path,x,y);}
    else
    {
        reverse(new_path,0,y);
        reverse(new_path,x,NUM-1);
    }


    new_path->length = 0;
    for(i=0;i<NUM-1;i++)
    {
        new_path->length += D_length[new_path->citys[i]][new_path->citys[i+1]];
    }
    new_path->length += D_length[new_path->citys[NUM-1]][new_path->citys[0]];
}

int SA()
{
	double t = T0;
	double delta, p;
	int i, loop_counter = 0;
	path newpath, curpath;

	copy_path(D_bestpath, &curpath);
	while (t > Tf)
	{
		for (i = 0; i < IN_loop; i++)
		{
			loop_counter++;

			getnextpath(curpath, &newpath);
			delta = newpath.length - curpath.length;
			if (delta < 0)
			{
				copy_path(newpath, &curpath);
			}
			else
			{
				p = rand()*1.0 / RAND_MAX;
				if (exp(-delta / t) > p)
					copy_path(newpath, &curpath);
			}
		}
		cout << curpath.length << endl;
		if (curpath.length < D_bestpath.length)
		{
			copy_path(curpath, &D_bestpath);
		}
		t = t*T;
	}
	return loop_counter;
}

#endif // TSP_H_INCLUDED
