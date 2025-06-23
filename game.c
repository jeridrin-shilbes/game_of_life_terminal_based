#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 100
#define GENERATION_LIMIT 100

void grid_init(bool *grid,int *alive,int size);
void display_grid(bool *grid);
void update(bool *grid);
void copy_grid(bool *temp_grid,bool *grid);
int neighbour_check(bool *grid,int col,int row);
int rule(int n);

int main(void)
{
    int alive[]={5054,5055,5056,5163,5164,5165};
    bool *grid=malloc(GRID_SIZE*GRID_SIZE*sizeof(bool));
    for(int i=0;i<GRID_SIZE;i++)
    {
        for(int j=0;j<GRID_SIZE;j++)
        {
            grid[i*GRID_SIZE+j]=false;
        }
    }

    grid_init(grid,alive,sizeof(alive)/sizeof(int));

    struct timespec delay;
    delay.tv_sec=0;
    delay.tv_nsec=500000000;
    
    display_grid(grid);
    for(int generation=0;generation<GENERATION_LIMIT;generation++)
    {
        update(grid);
        display_grid(grid);
        nanosleep(&delay,NULL);
    }
    fflush(stdout);
    free(grid);
    return 0;
}

void grid_init(bool *grid,int *alive,int size)
{
    for(int i=0;i<size;i++)
    {
        grid[(alive[i]/GRID_SIZE)*GRID_SIZE + ((alive[i])%GRID_SIZE)]=true;
    }
}

void display_grid(bool *grid)
{

    printf("\n\n\n");
    for(int i=0;i<GRID_SIZE;i++)
    {
        for(int j=0;j<GRID_SIZE;j++)
        {
            if(grid[(i*GRID_SIZE+j)])printf("\033[42m   ");
            else printf("\033[41m   ");
            printf("\033[0m");
        }
        printf(" %i\n",i);
    }
}


void update(bool *grid)
{
    bool *temp_grid=malloc(GRID_SIZE*GRID_SIZE*sizeof(bool));
    for(int col=0;col<GRID_SIZE;col++)
    {
        for(int row=0;row<GRID_SIZE;row++)
        {
            int neighbours=neighbour_check(grid,col,row);
            if(rule(neighbours))
            {
                if(rule(neighbours)>0)temp_grid[(col*GRID_SIZE+row)]=true;
                else temp_grid[col*GRID_SIZE+row]=false;
            }
        }
    }
    copy_grid(temp_grid,grid);
    free(temp_grid);
}
void copy_grid(bool *temp_grid,bool *grid)
{
    for(int col=0;col<GRID_SIZE;col++)
    {
        for(int row=0;row<GRID_SIZE;row++)
        {
            grid[col*GRID_SIZE+row]=temp_grid[col*GRID_SIZE+row];
        }
    }
}
int neighbour_check(bool *grid,int col,int row)
{
    int neighbours=0;
        /*n_col and n_row stands for neighbour_column and neighbour_row respectively...*/
            for(int n_col=-1;n_col<2;n_col++)
            {
                for(int n_row=-1;n_row<2;n_row++)
                {
                    if
                        (
                            ((col+n_col) < GRID_SIZE) && 
                            ((col+n_col) >= 0)&&
                            ((row+n_row) < GRID_SIZE)&&
                            ((row+n_row) >= 0) &&
                            !((n_row==n_col)&&!(n_col))
                        )
                    {
                        if(grid[(col+n_col)*GRID_SIZE+(row+n_row)])
                        {
                            neighbours++;
                        }
                    }
                }
            }
            return neighbours;
}

int rule(int n)
{
    if(n>3 || n<2)return -1;
    if(n==3)return 1;
    return 0;
}