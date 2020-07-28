/* 
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char [],char [],const char [],const char []);//Replace sort order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }
    //Exit
    return 0;
}


int read(char array[][COLMAX], int &rowDet)
{
    string input;
    int colLength = 0;
    getline(std::cin, input);
    
    do
    {
        getline(std::cin, input);
        if (input.length() > 0)
        {
            if(input.length() > colLength){
                colLength = input.length();
            }
            
            for(int i=0;i<input.length();i++){
                array[rowDet][i] = input.at(i);
            }
            rowDet++;
        }
        
    } while (input.length() > 0);
    return colLength;

} //Outputs row and columns detected from input
int strcmp(const char *X, const char *Y)
{
	while(*X)
	{
		// if characters differ or end of second string is reached
		if (*X != *Y)
			break;

		// move to next pair of characters
		X++;
		Y++;
	}

	// return the ASCII difference after converting char* to unsigned char*
	return *(const unsigned char*)X - *(const unsigned char*)Y;
}
void sort(char arr[][COLMAX], int rowIn, int colIn, const char x[],const char y[])
{
    int i, j, min;  
    for (i = 0; i < rowIn-1; i++)  
    {  
        min = i;  
        for (j = i+1; j < rowIn; j++){
            if (strcmp(arr[j], arr[min]) < 0)  
                min = j;  
        }
        char temp[COLMAX];
        strcpy(temp, arr[min]);
        strcpy(arr[min],  arr[i] );
        strcpy( arr[i],temp );
        
        /*
         int temp = in[min];  
        in[min] = in[i];  
        in[i] = temp; /
        */
        
    }
} //Sort by row
void print(const char input[][COLMAX], int rowIn, int colIn)
{
    for (int i = 0; i < rowIn; i++)
    {
        string s(input[i]);
        
        cout << s <<endl;
    }
} //Print the sorted 2-D array